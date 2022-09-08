#include "../header/ambient_light.hpp"

AmbientLight::AmbientLight(double intensity) : Light(intensity){} 

double AmbientLight::calculate_intensity(Vector P, Vector N, Vector V, int s){ 
    return this->get_intensity(); 
}
