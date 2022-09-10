#ifndef DIRECTION_LIGHT_HPP
#define DIRECTION_LIGHT_HPP

#include "light.hpp"

class DirectionLight : public Light {
    private:
        Vector direction; 
        
    public:
        DirectionLight(Color intensity, Vector direction);

        Color calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o, bool has_shadow);
        Vector get_l(Vector P);

        Vector get_direction();
        void set_direction(Vector direction);
};

#endif

