#include "../header/spot_light.hpp"
#include <cmath>
#include <iostream>

SpotLight::SpotLight(Color intensity, Vector position, Vector direction, double grau) : Light(intensity), position(position), direction(direction), grau(grau){}

Color SpotLight::calculate_intensity(Vector P, Vector N, Vector V, double s,  Object* o, bool has_shadow){ 
    Color i;
    if(has_shadow) return i;

    Color kd = o->has_image() ? o->get_current_color() : o->get_kd(), 
          ke = o->has_image() ? o->get_current_color() : o->get_ke();
          
    Vector L = this->get_position()-P;  
    L = L/~L;

    Vector ds = this->direction / ~this->direction;
    double clds = L * (-ds);
    if(clds < cos(this->grau)) return i;

    double fd = N*L;
    if(fd > 0.0) i = i + ((this->get_intensity()) * kd) * fd;

    double fs = specular(N, L, V, s);
    if(fs > 0.0) i = i + ((this->get_intensity()) * ke) * fs;

    return i * clds;
}

Vector SpotLight::get_l(Vector P) { return this->position - P; }
Vector SpotLight::get_direction(){ return this->direction; }
void SpotLight::set_direction(Vector direction) { this->direction = direction; }

Vector SpotLight::get_position(){ return this->position; }
void SpotLight::set_position(Vector position) { this->position = position; }

