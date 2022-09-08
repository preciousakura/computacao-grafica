#include <cmath>
#include "../header/sphere.hpp"

Sphere::Sphere(){}
Sphere::Sphere(Vector center, double r, double s, Color color) : center(center), radius(r), specular(s), color(color){}

std::tuple<double, double> Sphere::intersectRaysphere(Vector O, Vector D){
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

Vector Sphere::get_center(){ return this->center; }
void Sphere::set_center(Vector center){ this->center = center; }
double Sphere::get_radius(){ return this->radius; }
void Sphere::set_radius(double radius){ this->radius = radius; }
double Sphere::get_specular(){ return this->specular; }
void Sphere::set_specular(double specular){ this->specular = specular; }
Color Sphere::get_color(){ return this->color; }
void Sphere::set_color(Color color){ this->color = color; }
