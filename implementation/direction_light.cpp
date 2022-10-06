#include "../header/direction_light.hpp"

DirectionLight::DirectionLight(Color intensity, Vector direction) : Light(intensity), direction(direction){}

Color DirectionLight::calculate_intensity(Vector P, Vector N, Vector V, double s,  Object* o, bool has_shadow){ 
    Color i;
    if(has_shadow) return i;

    Color kd = o->has_image() ? o->get_current_color() : o->get_kd(), 
          ke = o->has_image() ? o->get_current_color() : o->get_ke();

    Vector L = get_direction();  
    L = L/~L;
    double fd = N*L;
    if(fd > 0.0) i = i + ((this->get_intensity()) * kd) * fd;

    double fs = specular(N, L, V, s);
    if(fs > 0.0) i = i + ((this->get_intensity()) * ke) * fs;

    return i;
}

Vector DirectionLight::get_l(Vector P) { return this->direction; }
Vector DirectionLight::get_direction(){ return this->direction; }
void DirectionLight::set_direction(Vector direction) { this->direction = direction; }
