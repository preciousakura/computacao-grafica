#include "../header/direction_light.hpp"

DirectionLight::DirectionLight(double intensity, Vector direction) : Light(intensity), direction(direction){}

double DirectionLight::calculate_intensity(Vector P, Vector N, Vector V, int s){ 
    double i = 0.0;
    Vector L = get_direction();  
    double ndl = N*L;
    if(ndl > 0.0) i += (this->get_intensity()*ndl)/((~N)*(~L));
    i += specular(N, L, V, s);
    return i;
}

Vector DirectionLight::get_direction(){ return this->direction; }
void DirectionLight::set_direction(Vector direction) { this->direction = direction; }
