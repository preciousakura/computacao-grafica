#include "../header/point_light.hpp"
#include <iostream>

PointLight::PointLight(Color intensity, Vector position) : Light(intensity), position(position){}

Color PointLight::calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o){ 
    Color i;
    Vector L = this->get_position()-P;  
    double ndl = N*L;
    if(ndl > 0.0) i = i + (this->get_intensity()*ndl)/((~N)*(~L));
    i = i + specular(N, L, V, s) * o->get_ke();
    return i * o->get_kd();
}

Vector PointLight::get_position(){ return this->position; }
void PointLight::set_position(Vector position) { this->position = position; }
