#ifndef AMBIENT_LIGHT_HPP
#define AMBIENT_LIGHT_HPP

#include "light.hpp"

class AmbientLight : public Light {
    public:
        AmbientLight(Color intensity);
    
        Color calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o);
};

#endif
