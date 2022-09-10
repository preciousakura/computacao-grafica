#include "../header/ambient_light.hpp"

AmbientLight::AmbientLight(Color intensity) : Light(intensity){} 

Color AmbientLight::calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o){ 
    return this->get_intensity() * o->get_ka(); 
}
