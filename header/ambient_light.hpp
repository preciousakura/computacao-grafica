#ifndef AMBIENT_LIGHT_HPP
#define AMBIENT_LIGHT_HPP

#include "light.hpp"

class AmbientLight : public Light {
    public:
        AmbientLight(Color intensity);

        void transform();
    
        Color calculate_intensity(Vector P, Vector N, Vector V, double s,  Object* o, bool has_shadow);
        Vector get_l(Vector P);
};

#endif
