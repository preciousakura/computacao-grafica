#include "../header/mesh.hpp"
#include <cmath>
#include <iostream>

Mesh::Mesh() {}
Mesh::Mesh(Vector center, Color kd, Color ka, Color ke, double s): center(center), Object(kd, ke, ka, s) {}

std::tuple<double, Vector> Mesh::intersect(Vector O, Vector D, double t_min, double t_max) {
    double t = INFINITY, t_aux; 
    Vector normal, normal_aux;
    
    for(Face * f: this->faces){
        std::tie(t_aux, normal_aux) = f->intersect(O, D, t_min, t_max);
        if(t_aux > t_min && t_aux < t_max && t_aux < t)
            t = t_aux, normal = normal_aux; 
    }
    return {t, normal_aux};
}

Mesh::Face::Face() {}
Mesh::Face::Face(Vector p1, Vector p2, Vector p3): p1(p1), p2(p2), p3(p3) {
    this->normal = (this->p2 - this->p1) % (this->p3 - this->p1);
}

bool Mesh::Face::in_face(Vector P) {
    double t = INFINITY;
    Vector N = this->get_normal();

    double c1 = ((this->p1 - P) % (this->p2 - P) * (N/~N)) / (~N);
    double c2 = ((this->p3 - P) % (this->p1 - P) * (N/~N)) / (~N);
    double c3 = 1 - c1 - c2;

    return (c1+EPS > 0.0) && (c2+EPS > 0.0)  && (c3+EPS > 0.0);
}

std::tuple<double, Vector> Mesh::Face::intersect(Vector O, Vector D, double t_min, double t_max) {
    Plan plan(this->p1, this->get_normal());

    double t; 
    Vector n; 
    std::tie(t, n) = plan.intersect(O, D, t_min, t_max);
    Vector P = (O + D*t);

    t = (this->in_face(P) ? t : INFINITY);
    return {t, this->get_normal()};
}

Vector Mesh::Face::get_normal() {
    return this->normal;
}

void Mesh::set_center(Vector c) { this->center = c; }
Vector Mesh::get_center() { return this->center; }