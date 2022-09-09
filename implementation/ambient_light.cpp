#include "../header/ambient_light.hpp"

AmbientLight::AmbientLight(Vector intensity) : Light(intensity){} 

Vector AmbientLight::calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o){ 
    return this->get_intensity(); 
}
