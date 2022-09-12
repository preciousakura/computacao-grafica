#include "../header/cylinder.hpp"
#include <bits/stdc++.h>

Cylinder::Cylinder(){}
Cylinder::Cylinder(Vector center, Vector dc, double radius, int h, Color kd, Color ka, Color ke, double s): center(center), dc(dc/~dc), height(h), radius(radius), Object(kd, ka, ke, s){}

bool Cylinder::in_shell(Vector P) {
    double projection = ((P - this->center) * this->dc);
    return ((projection > 0) && (projection < this->height));
}

bool Cylinder::in_base(Vector P, Vector PI, Vector DC) {
    Vector CP = P - PI;
    double cp_x_n = CP * this->dc;
    bool is_zero = (cp_x_n+EPS > 0.0) && (cp_x_n < EPS - 0.0);
    bool is_radius = (~CP) <= this->radius;
    return (is_zero && is_radius);
}

std::tuple<double, double> Cylinder::intersect_cylinder_shell_vector(Vector O, Vector D){
    double t1 = INFINITY, t2 = INFINITY;
    Vector V = (O - this->center) - this->dc * ((O - this->center) * this->dc);
    Vector W = D - this->dc * (D * this->dc);

    double a = W*W;
    double b = V*W*2;
    double c = V*V - (this->radius*this->radius);


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

double Cylinder::ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC) {
    double t; 
    Plan plan(PI, DC);
    std::tie(t, t) = plan.intersect(O, D);
    Vector P = O + D*t;
    return (in_base(P, PI, DC)) ? t : INFINITY;
}

std::tuple<double, double> Cylinder::intersect(Vector O, Vector D) {
    std::vector<double> t;
    double t1, t2;
    t1 = ray_intersect_base(O, D, this->center, -this->dc);
    t2 = ray_intersect_base(O, D, this->center + (this->dc * this->height), this->dc);
    t.push_back(t1);
    t.push_back(t2);


    std::tie(t1, t2) = intersect_cylinder_shell_vector(O, D);
    t.push_back(t1);
    t.push_back(t2);
    

    sort(t.begin(), t.end());
    return {t[0], t[1]};
}

Vector Cylinder::get_normal(Vector P) {
    if(in_base(P, this->center, -this->dc)) return -this->dc;
    if(in_base(P, this->center + (this->dc * this->height), this->dc)) return this->dc;
    Vector CP = P - this->center;
    Vector AP = CP - (this->dc * (CP * dc));
    AP = AP / ~AP;
    return AP;
}

void Cylinder::set_center(Vector c) { center = c; }
void Cylinder::set_dc(Vector c) { dc = c; }
void Cylinder::set_height(int h) { height = h; }
void Cylinder::set_radius(int r) { radius = r; }

Vector Cylinder::get_center() { return center; }
Vector Cylinder::get_dc() { return dc; }
int Cylinder::get_height() { return height; }
int Cylinder::get_radius() { return radius; }