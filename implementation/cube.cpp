#include "../header/cube.hpp"

Cube::Cube() {}
Cube::Cube(Vector center, int size, Color kd, Color ka, Color ke, double s): center(center), size(size), Object(kd, ka, ke, s) {
    std::vector<Vector> vertices = {  
        Vector(center.get_x() - size/2, center.get_y() - size/2, center.get_z() + size/2),
        Vector(center.get_x() + size/2, center.get_y() - size/2, center.get_z() + size/2),
        Vector(center.get_x() + size/2, center.get_y() + size/2, center.get_z() + size/2),
        Vector(center.get_x() - size/2, center.get_y() + size/2, center.get_z() + size/2),
        Vector(center.get_x() - size/2, center.get_y() + size/2, center.get_z() - size/2),
        Vector(center.get_x() - size/2, center.get_y() - size/2, center.get_z() - size/2),
        Vector(center.get_x() + size/2, center.get_y() - size/2, center.get_z() - size/2),
        Vector(center.get_x() + size/2, center.get_y() + size/2, center.get_z() - size/2)
    };
    
    this->faces = {
        Mesh(vertices[0], vertices[3], vertices[1]), Mesh(vertices[1], vertices[2], vertices[3]),
        Mesh(vertices[6], vertices[2], vertices[1]), Mesh(vertices[6], vertices[7], vertices[2]),
        Mesh(vertices[5], vertices[6], vertices[7]), Mesh(vertices[7], vertices[4], vertices[5]),
        Mesh(vertices[0], vertices[5], vertices[4]), Mesh(vertices[4], vertices[3], vertices[0]),
        Mesh(vertices[4], vertices[7], vertices[2]), Mesh(vertices[4], vertices[3], vertices[2]),
        Mesh(vertices[5], vertices[0], vertices[1]), Mesh(vertices[1], vertices[6], vertices[5])
    };
}

std::tuple<double, Vector> Cube::intersect(Vector O, Vector D, double t_min, double t_max) {
    double t = INFINITY, t_aux; 
    Vector normal, normal_aux;

    for(Mesh m : this->faces){
        std::tie(t_aux, normal_aux) = m.intersect(O, D, t_min, t_max);
        if(t_aux > t_min && t_aux < t_max && t_aux < t)
            t = t_aux, normal = normal_aux; 
    }
    return {t, normal_aux};
}

Vector Cube::get_normal(Vector O, Vector D, double &t) {
    return Vector();
}

void Cube::set_center(Vector c) { this->center = c; }
void Cube::set_size(int size) { this->size = size; }
void Cube::set_faces(std::vector<Mesh> faces) { this->faces = faces; }

Vector Cube::get_center() { return this->center; }
int Cube::get_size() { return this->size; }
std::vector<Mesh> Cube::get_faces() { return this->faces; }