#include "../header/plan.hpp"
#include <cmath>

Plan::Plan(){}
Plan::Plan(Vector p, Vector n, Color kd, Color ka, Color ke, double s) : P(p), N(n), Object(kd, ka, ke, s) {}

std::tuple<double, double> Plan::intersect(Vector O, Vector D) {
    Vector W = O - P;
    double ti = -(W * N) / (D * N); 
    if(ti < 0) return {INFINITY, INFINITY};

    return {ti, INFINITY};
}

Vector Plan::get_normal(Vector P) {
    return N;
}


void Plan::set_p(Vector ponto) { P = ponto; }
Vector Plan::get_p() { return P; }
void Plan::set_n(Vector normal) { N = normal; }
Vector Plan::get_n() { return N; }