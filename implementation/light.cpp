#include <cmath>
#include "../header/light.hpp"

Light::Light(Color intensity) : intensity(intensity){}

double Light::specular(Vector N, Vector L, Vector V, double s) {
    double fs = 0.0;
    if(s > 0.0) {
        Vector R = (N*(N*L))*2 - L;
        fs = R*V;
        fs =  pow(fs, s);
    }
    return fs;
}

Color Light::get_intensity(){ return intensity; }
void Light::set_intensity(Color intensity){ this->intensity = intensity; }
