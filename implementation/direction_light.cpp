#include "../header/direction_light.hpp"

DirectionLight::DirectionLight(Color intensity, Vector direction) : Light(intensity), direction(direction){}

Color DirectionLight::calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o, bool has_shadow){ 
    Color i;
    if(has_shadow) return i;
    Vector L = get_direction();  
    double ndl = N*L;
    if(ndl > 0.0) i = i + (this->get_intensity()*ndl)/((~N)*(~L));
    i = i + specular(N, L, V, s) * o->get_ke();
    return i * o->get_kd();
}

Vector DirectionLight::get_l(Vector P) { return this->direction; }
Vector DirectionLight::get_direction(){ return this->direction; }
void DirectionLight::set_direction(Vector direction) { this->direction = direction; }
