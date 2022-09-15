#include "../header/cone.hpp"
#include "../header/plan.hpp"
#include <bits/stdc++.h>

Cone::Cone(){}
Cone::Cone(Vector c, Vector dc, double r, double h, Color kd, Color ka, Color ke, double s): center(c), dc(dc/~dc), radius(r), height(h), Object(ka, kd, ke, s){ V = c + (dc/~dc * h); }
Cone::Cone(Vector c, Vector v, double r, Color kd, Color ka, Color ke, double s) : center(c), V(v), radius(r), Object(ka, kd, ke, s){ 
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
    double t1 = INFINITY, t2 = INFINITY;
    Vector W = this->V - O;
    
    double h2 = this->height * this->height;
    double cos2 = (h2) / ((this->radius * this->radius) + h2);
    double dr_dc = (D * this->dc);
    double w_dc = W * this->dc;

    double a = (dr_dc*dr_dc) - (D * D) * cos2;
    double b = (((W * D) * cos2) - ((w_dc) * (dr_dc))) * 2;
    double c = (w_dc * w_dc) - ((W * W) * cos2);
    double delta = b*b - 4*a*c;

    if(delta*EPS < 0.0) return {t1, t2};

    t1 = (-b+sqrt(delta))/(2*a);
    t2 = (-b-sqrt(delta))/(2*a);

    Vector P1 = O + D*t1;
    t1 = (in_shell(P1)) ? t1 : INFINITY;
    Vector P2 = O + D*t2;
    t2 = (in_shell(P2)) ? t2 : INFINITY;
    return {t1, t2};
}

double Cone::ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC) {
    double t; 
    Plan plan(PI, DC);
    std::tie(t, t) = plan.intersect(O, D);
    Vector P = O + D*t;
    return (in_base(P, PI, DC)) ? t : INFINITY;
}

std::tuple<double, double> Cone::intersect(Vector O, Vector D) {
    std::vector<double> t;
    double t1, t2;
    t1 = ray_intersect_base(O, D, this->center, this->dc);
    t.push_back(t1);

    std::tie(t1, t2) = intersect_cone_shell_vector(O, D);
    t.push_back(t1);
    t.push_back(t2);
    

    sort(t.begin(), t.end());
    return {t[0], t[1]};
}

Vector Cone::get_normal(Vector P) {
    Vector w = this->V - P;
    Vector n_barra = w % this->dc;

    return (n_barra % w);
}