#include <cmath>
#include "../header/light.hpp"

Light::Light(double intensity) : intensity(intensity){}

double Light::specular(Vector N, Vector L, Vector V, int s){
    if(s != -1){
        Vector R = (N*(N*L))*2 - L;
        double rdv = R*V;
        if(rdv > 0.0) return (this->get_intensity()*pow((rdv/((~R)*(~V))), s));
    }
    return 0.0;
}

double Light::get_intensity(){ return intensity; }
void Light::set_intensity(double intensity){ this->intensity = intensity; }
