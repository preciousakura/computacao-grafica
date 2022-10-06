#include "../header/plan.hpp"
#include <cmath>

Plan::Plan(){}
Plan::Plan(Vector p, Vector n, Color kd, Color ka, Color ke, double s) : P(p), N(n), Object(kd, ka, ke, s) {}
Plan::Plan(Vector p, Vector n, const char * name, double s): P(p), N(n), Object(name, s) {}
Plan::Plan(Vector P, Vector N): P(P), N(N), Object() {}

std::tuple<double, Vector> Plan::intersect(Vector O, Vector D, double t_min, double t_max) {
    Vector W = O - P;
    double ti = -(W * N) / (D * N); 
    if(ti < 0.0) return {INF, Vector()};

    return {ti, this->N};
}

Vector Plan::get_normal(Vector O, Vector D, double &t) {
    return N;
}


void Plan::set_p(Vector ponto) { P = ponto; }
Vector Plan::get_p() { return P; }
void Plan::set_n(Vector normal) { N = normal; }
Vector Plan::get_n() { return N; }