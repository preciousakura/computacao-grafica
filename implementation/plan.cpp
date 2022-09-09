#include "../header/plan.hpp"
#include <cmath>

Plan::Plan(Vector p, Vector n, Color color, double s) : P(p), N(n), color(color), specular(s) {}
Plan::Plan() {}

double Plan::intersectRayPlan(Vector O, Vector D) {
    Vector W = O - P;
    double ti = -(W * N) / (D * N); 
    if(ti < 0) return INFINITY;

    return ti;
}

void Plan::set_p(Vector ponto) { P = ponto; }
Vector Plan::get_p() { return P; }
void Plan::set_n(Vector normal) { N = normal; }
Vector Plan::get_n() { return N; }
void Plan::set_color(Color color) { color = color; }
Color Plan::get_color() { return color; }
double Plan::get_specular(){ return this->specular; }
void Plan::set_specular(double specular){ this->specular = specular; }