#include "../header/mesh.hpp"
#include <cmath>
#include <iostream>

Mesh::Mesh() {}
Mesh::Mesh(Vector p1, Vector p2, Vector p3): p1(p1), p2(p2), p3(p3) {
    this->set_r1(this->p2 - this->p1);
    this->set_r2(this->p3 - this->p1);
    this->normal = (this->r1) % (this->r2);
}

Vector Mesh::get_n() { 
    return this->normal;
}

double Mesh::get_t_intersection(Vector O, Vector D) { 
    Vector N = this->get_n();
    return ((this->p1 - O) * N) / (D * N);
}

bool Mesh::intersect_with_face(Vector P) {
    double t = INFINITY;
    Vector N = this->get_n();

    double c1 = ((this->p1 - P) % (this->p2 - P) * (N/~N)) / (~N);
    double c2 = ((this->p3 - P) % (this->p1 - P) * (N/~N)) / (~N);
    double c3 = 1 - c1 - c2;

    return (c1+EPS > 0.0) && (c2+EPS > 0.0)  && (c3+EPS > 0.0);
}

std::tuple<double, Vector> Mesh::intersect(Vector O, Vector D, double t_min, double t_max) {
    Plan plan(this->p1, this->get_n());

    double t; 
    Vector n; 
    std::tie(t, n) = plan.intersect(O, D, t_min, t_max);
    Vector P = (O + D*t);

    t = (intersect_with_face(P) ? t : INFINITY);
    return {t, this->get_n()};
}

void Mesh::set_p1(Vector v) { this->p1 = v; }
void Mesh::set_p2(Vector v) { this->p2 = v; }
void Mesh::set_p3(Vector v) { this->p3 = v; }

void Mesh::set_r1(Vector v) { this->r1 = v; }
void Mesh::set_r2(Vector v) { this->r2 = v; }

Vector Mesh::get_p1() { return this->p1; }
Vector Mesh::get_p2() { return this->p2; }
Vector Mesh::get_p3() { return this->p3; }

Vector Mesh::get_r1() { return this->r1; }
Vector Mesh::get_r2() { return this->r2; }