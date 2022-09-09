#include "../header/direction_light.hpp"

DirectionLight::DirectionLight(Vector intensity, Vector direction) : Light(intensity), direction(direction){}

Vector DirectionLight::calculate_intensity(Vector P, Vector N, Vector V, int s){ 
    Vector i;
    Vector L = get_direction();  
    double ndl = N*L;
    if(ndl > 0.0) i = i + (this->get_intensity()*ndl)/((~N)*(~L));
    i = i + specular(N, L, V, s);
    return i;
}

Vector DirectionLight::get_direction(){ return this->direction; }
void DirectionLight::set_direction(Vector direction) { this->direction = direction; }
