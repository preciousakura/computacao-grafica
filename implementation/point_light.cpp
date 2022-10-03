#include "../header/point_light.hpp"
#include <iostream>

PointLight::PointLight(Color intensity, Vector position) : Light(intensity), position(position){}

Color PointLight::calculate_intensity(Vector P, Vector N, Vector V, double s,  Object* o, bool has_shadow){ 
    Color i;
    if(has_shadow) return i;
    Vector L = this->get_position()-P;  
    L = L/~L;
    double fd = N*L;
    if(fd > 0.0) i = i + ((this->get_intensity()) * o->get_kd()) * fd;

    double fs = specular(N, L, V, s);
    if(fs > 0.0) i = i + ((this->get_intensity()) * o->get_ke()) * fs;

    return i;
}

Vector PointLight::get_l(Vector P) { return this->position - P; }
Vector PointLight::get_position(){ return this->position; }
void PointLight::set_position(Vector position) { this->position = position; }
