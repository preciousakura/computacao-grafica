#include "../header/mesh.hpp"
#include <cmath>
#include <iostream>

Mesh::Mesh() {}
Mesh::Mesh(Vector center, Color kd, Color ka, Color ke, double s): center(center), Object(kd, ke, ka, s) {}

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
Mesh::Face::Face(Vector p1, Vector p2, Vector p3): p1(p1), p2(p2), p3(p3) {
    Vector N = (this->p2 - this->p1) % (this->p3 - this->p1);
    this->normal = N / ~N;
}

bool Mesh::Face::in_face(Vector P) {
    double t = INF;
    Vector N = this->get_normal();

    double area_total = ((this->p2 - this->p1) % (this->p3 - this->p1)) * N;

    double c1 = ((this->p1 - P) % (this->p2 - P) * N) / area_total;
    double c2 = ((this->p3 - P) % (this->p1 - P) * N) / area_total;
    double c3 = 1 - c1 - c2;

    return (c1 > 0.0-EPS) && (c2 > 0.0-EPS) && (c3-EPS > 0.0);
}

std::tuple<double, Vector> Mesh::Face::intersect(Vector O, Vector D) {
    Plan plan(this->p1, this->get_normal());

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

void Mesh::set_center(Vector c) { this->center = c; }
Vector Mesh::get_center() { return this->center; }