#include "../header/ambient_light.hpp"

AmbientLight::AmbientLight(Color intensity) : Light(intensity){} 

Color AmbientLight::calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o, bool has_shadow){ 
    return this->get_intensity() * o->get_ka(); 
}

Vector AmbientLight::get_l(Vector P) { return Vector(); }
