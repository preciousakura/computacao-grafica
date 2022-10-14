#include "../header/mesh.hpp"
#include <cmath>

Mesh::Mesh() {}
Mesh::Mesh(Vector center, Color kd, Color ka, Color ke, double s): center(center), Object(kd, ke, ka, s) {}
Mesh::Mesh(Vector center, const char* name, double s): center(center), Object(name, s) {}

std::tuple<double, Vector> Mesh::intersect(Vector O, Vector D, double t_min, double t_max) {
    double t = INF, t_aux; 
    Vector normal, normal_aux;
    
    for(Face * f: this->faces) {
        if(f->get_normal() * D > 0.0) continue;
        std::tie(t_aux, normal_aux) = f->intersect(O, D);
        if(t_aux > t_min && t_aux < t_max && t_aux < t)
            t = t_aux, normal = normal_aux; 
    }
    
    return {t, normal};
}

Mesh::Face::Face() {}
Mesh::Face::Face(Vector *&p1, Vector *&p2, Vector *&p3): p1(p1), p2(p2), p3(p3) {
    this->update_normal();
}

void Mesh::Face::update_normal() {
    Vector N = (*this->p2 - *this->p1) % (*this->p3 - *this->p1);
    this->normal = N / ~N;
}

void Mesh::update_normals() {
    for(Face * f: this->faces) f->update_normal();
}

bool Mesh::Face::in_face(Vector P) {
    Vector N = this->get_normal();

    double area_total = ((*this->p2 - *this->p1) % (*this->p3 - *this->p1)) * N;

    double c1 = ((*this->p1 - P) % (*this->p2 - P) * N) / area_total;
    double c2 = ((*this->p3 - P) % (*this->p1 - P) * N) / area_total;
    double c3 = 1 - c1 - c2;

    return (c1 > 0.0-EPS) && (c2 > 0.0-EPS) && (c3 > 0.0-EPS);
}

std::tuple<double, Vector> Mesh::Face::intersect(Vector O, Vector D) {
    Plan plan(*this->p1, this->get_normal());

    double t; 
    Vector n; 
    std::tie(t, n) = plan.intersect(O, D, -1, -1);
    Vector P = (O + D*t);

    t = (this->in_face(P) ? t : INF);
    return {t, this->get_normal()};
}

Vector Mesh::Face::get_normal() {
    return this->normal;
}

void Mesh::transform() {
    if(this->get_transformation().size() > 0) {
        Matrix M = Matrix::identity(4);
        for(Matrix m:this->get_transformation()) M = M * m;

        for(Vector *&vertice : this->vertices) {
            Vector v = (Matrix::vector_to_matrix(*vertice) * M).matrix_to_vector();  

            vertice->set_x(v.get_x());
            vertice->set_y(v.get_y()); 
            vertice->set_z(v.get_z());
            vertice->set_a(v.get_a());
        }
        this->update_normals();
    }
}

void Mesh::rotation_x(double angle) {
    Matrix r_x = Matrix::rotation_x_matrix(angle);
    this->set_transformation(r_x);
}
void Mesh::rotation_y(double angle) {
    Matrix r_y = Matrix::rotation_y_matrix(angle);
    this->set_transformation(r_y);
}
void Mesh::rotation_z(double angle) {
    Matrix r_z = Matrix::rotation_z_matrix(angle);
    this->set_transformation(r_z);
}
void Mesh::translation(Vector v) {
    Matrix translation = Matrix::translation_matrix(v.get_x(), v.get_y(), v.get_z());
    this->set_transformation(translation);
}
void Mesh::scaling(double x, double y, double z) {
    Matrix scaling = Matrix::scaling_matrix(x, y, z);
    this->set_transformation(scaling);
}
void Mesh::scaling(double size) {
    Matrix scaling = Matrix::scaling_matrix(size, size, size);
    this->set_transformation(scaling);
}
void Mesh::set_center(Vector c) { this->center = c; }
Vector Mesh::get_center() { return this->center; }

void Mesh::set_vertices(std::vector<Vector*> vertices) { this->vertices = vertices; }
std::vector<Vector*> Mesh::get_vertices() { return this->vertices; }