#include <cmath>
#include "../header/sphere.hpp"

Sphere::Sphere(){}
Sphere::Sphere(Vector center, double r, Color kd, Color ka, Color ke, double s) : center(center), radius(r), Object(kd, ka, ke, s){}
Sphere::Sphere(Vector center, double r, const char * name, double s) : center(center), radius(r), Object(name, s) {}

std::tuple<double, Vector> Sphere::intersect(Vector O, Vector D, double t_min, double t_max){
    Vector CO = O - this->center;
    double t = INF;
    Vector n;

    double a = D*D;
    double b = 2*(CO*D);
    double c = CO*CO - this->radius*this->radius;
    double delta = b*b - 4*a*c;
    
    if(delta < 0) return {INF, n};        
    double t1 = (-b + sqrt(delta))/(2*a);
    double t2 = (-b - sqrt(delta))/(2*a);

    if(t1-EPS > t_min && t1 < t_max && t1 < t) t = t1, n = this->get_normal(O, D, t1);
    if(t2-EPS > t_min && t2 < t_max && t2 < t) t = t2, n = this->get_normal(O, D, t2);

    return {t, n};
}

Vector Sphere::get_normal(Vector O, Vector D, double &t) {
    Vector P = O + D*t;
    return (P - center)/ radius;
}

void Sphere::transform() {

}

void Sphere::rotation_x(double angle) {}
void Sphere::rotation_y(double angle) {}
void Sphere::rotation_z(double angle) {}
void Sphere::translation(Vector v) {}
void Sphere::scaling(double x, double y, double z) {}
void Sphere::scaling(double size) {}
void Sphere::shearing_xy(double angle) {}
void Sphere::shearing_xz(double angle) {}
void Sphere::shearing_yx(double angle) {}
void Sphere::shearing_yz(double angle) {}
void Sphere::shearing_zx(double angle) {}
void Sphere::shearing_zy(double angle) {}
void Sphere::reflection_xy() {}
void Sphere::reflection_yz() {}
void Sphere::reflection_xz() {}
void Sphere::reflection_at(Vector p, Vector n) {}

Vector Sphere::get_center(){ return this->center; }
void Sphere::set_center(Vector center){ this->center = center; }
double Sphere::get_radius(){ return this->radius; }
void Sphere::set_radius(double radius){ this->radius = radius; }
