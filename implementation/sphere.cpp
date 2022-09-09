#include <cmath>
#include "../header/sphere.hpp"

Sphere::Sphere(){}
Sphere::Sphere(Vector center, double r, Color kd, Color ka, Color ke, double s) : center(center), radius(r), Object(kd, ka, ke, s){}

std::tuple<double, double> Sphere::intersect(Vector O, Vector D){
    Vector CO = O - this->center;

    double a = D*D;
    double b = 2*(CO*D);
    double c = CO*CO - this->radius*this->radius;
    double delta = b*b - 4*a*c;
    
    if(delta < 0) return {INFINITY, INFINITY};        
    double t1 = (-b + sqrt(delta))/(2*a);
    double t2 = (-b - sqrt(delta))/(2*a);

    return {t1, t2};
}

Vector Sphere::get_normal(Vector P) {
    return (P - center)/ radius;
}

Vector Sphere::get_center(){ return this->center; }
void Sphere::set_center(Vector center){ this->center = center; }
double Sphere::get_radius(){ return this->radius; }
void Sphere::set_radius(double radius){ this->radius = radius; }
