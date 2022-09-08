#include "../header/point_light.hpp"

PointLight::PointLight(double intensity, Vector position) : Light(intensity), position(position){}

double PointLight::calculate_intensity(Vector P, Vector N, Vector V, int s){ 
    double i = 0.0;
    Vector L = this->get_position()-P;  
    double ndl = N*L;
    if(ndl > 0.0) i += (this->get_intensity()*ndl)/((~N)*(~L));
    i += specular(N, L, V, s);
    return i;
}

Vector PointLight::get_position(){ return this->position; }
void PointLight::set_position(Vector position) { this->position = position; }
