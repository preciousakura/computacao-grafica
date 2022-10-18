#include "../header/cone.hpp"
#include "../header/plan.hpp"
#include <bits/stdc++.h>

Cone::Cone(){}
Cone::Cone(Vector c, Vector dc, double r, double h, const char* name, double s, bool has_base): has_base(has_base), center(c), dc(dc/~dc), radius(r), height(h), Object(name, s){ V = c + (dc/~dc * h); }
Cone::Cone(Vector c, Vector dc, double r, double h, Color kd, Color ka, Color ke, double s, bool has_base): has_base(has_base), center(c), dc(dc/~dc), radius(r), height(h), Object(ka, kd, ke, s){ V = c + (dc/~dc * h); }
Cone::Cone(Vector c, Vector v, double r, Color kd, Color ka, Color ke, double s, bool has_base) : has_base(has_base), center(c), V(v), radius(r), Object(ka, kd, ke, s){ 
    Vector vc = (V-c); 
    dc = vc / ~vc; 
    height = ~vc; 
}

Cone::Cone(Vector c, Vector v, double r, const char* name, double s, bool has_base) : has_base(has_base), center(c), V(v), radius(r), Object(name, s){ 
    Vector vc = (V-c); 
    dc = vc / ~vc; 
    height = ~vc; 
}

bool Cone::in_shell(Vector P) {
    double projection = ((P - this->center) * this->dc);
    return ((projection > 0) && (projection < this->height));
}

bool Cone::in_base(Vector P, Vector PI, Vector DC) {
    Vector CP = P - PI;
    double cp_x_n = CP * this->dc;
    bool is_zero = (cp_x_n+EPS > 0.0) && (cp_x_n < EPS - 0.0);
    bool is_radius = (~CP) <= this->radius;
    return (is_zero && is_radius);
}

std::tuple<double, double> Cone::intersect_cone_shell_vector(Vector O, Vector D){
    double t1 = INF, t2 = INF;
    Vector W = this->V - O;
    
    double h2 = this->height * this->height;
    double cos2 = (h2) / ((this->radius * this->radius) + h2);
    double dr_dc = (D * this->dc);
    double w_dc = W * this->dc;

    double a = (dr_dc*dr_dc) - ((D * D) * cos2);
    double b = (((W * D) * cos2) - ((w_dc) * (dr_dc))) * 2;
    double c = (w_dc * w_dc) - ((W * W) * cos2);
    double delta = b*b - 4*a*c;

    if(delta*EPS < 0.0) return {t1, t2};

    t1 = (-b+sqrt(delta))/(2*a);
    t2 = (-b-sqrt(delta))/(2*a);

    Vector P1 = O + D*t1;
    t1 = (in_shell(P1)) ? t1 : INF;
    Vector P2 = O + D*t2;
    t2 = (in_shell(P2)) ? t2 : INF;
    return {t1, t2};
}

double Cone::ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC) {
    double t; 
    Vector aux;
    Plan plan(PI, DC);
    std::tie(t, aux) = plan.intersect(O, D, -1, -1);
    Vector P = O + D*t;
    return (in_base(P, PI, DC)) ? t : INF;
}

std::tuple<double, Vector> Cone::intersect(Vector O, Vector D, double t_min, double t_max) {
    double t1 = INF, t2 = INF, t = INF; 
    Vector n; 
    bool invert = false;

    std::tie(t1, t2) = intersect_cone_shell_vector(O, D);
    if(t1-EPS > t_min && t1 < t_max && t1 < t) t = t1, n = this->get_normal(O, D, t1);
    if(t2-EPS > t_min && t2 < t_max && t2 < t) t = t2, n = this->get_normal(O, D, t2);

    t1 = ray_intersect_base(O, D, this->center, this->dc);
    if(t1-EPS > t_min && t1 < t_max && t1 < t){
        if(this->has_base) t = t1, n = -this->dc;
        else invert = true;
    }

    if(invert) n = -n;

    return {t, n};
}

Vector Cone::get_normal(Vector O, Vector D, double &t) {
    Vector P = O + D*t;
    Vector w = this->V - P;
    Vector n_barra = w % this->dc;
    Vector N = n_barra % w;

    return (N/~N);
}

void Cone::transform() {
    Matrix M = Matrix::identity(4);
    for(Matrix m:this->get_transformation()) M = M * m;

    this->center = (M * Matrix::vector_to_matrix(this->center)).matrix_to_vector();  
    this->V = (M * Matrix::vector_to_matrix(this->V)).matrix_to_vector(); 
    
    this->clear_transform();
}
void Cone::translate(Vector v) {
    Matrix translation = Matrix::translation_matrix(v - this->center);
    this->set_transformation(translation);
    this->transform();
    this->update_normals();
}
void Cone::update_normals() {
    Vector vc = (V-this->center); 
    dc = vc / ~vc; 
    height = ~vc;
}
void Cone::update_normals(Matrix m) {
    dc = (~m * Matrix::vector_to_matrix(dc)).matrix_to_vector();
}

Vector Cone::get_center() { return this->center; }
Vector Cone::get_v() { return this->V; }
double Cone::get_radius() { return this->radius; }
double Cone::get_height() { return this->height; }

void Cone::set_center(Vector c) { this->center = c; }
void Cone::set_v(Vector v) { this->V = v; }
void Cone::set_radius(double r) { this->radius = r; }
void Cone::set_height(double h) { this->height = h; }