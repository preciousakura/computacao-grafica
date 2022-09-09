#include "../header/point_light.hpp"

PointLight::PointLight(Vector intensity, Vector position) : Light(intensity), position(position){}

Vector PointLight::calculate_intensity(Vector P, Vector N, Vector V, int s){ 
    Vector i;
    Vector L = this->get_position()-P;  
    double ndl = N*L;
    if(ndl > 0.0) i = i + (this->get_intensity()*ndl)/((~N)*(~L));
    i = i + specular(N, L, V, s);
    return i;
}

Vector PointLight::get_position(){ return this->position; }
void PointLight::set_position(Vector position) { this->position = position; }
