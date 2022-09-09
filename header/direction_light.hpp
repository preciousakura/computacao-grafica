#ifndef DIRECTION_LIGHT_HPP
#define DIRECTION_LIGHT_HPP

#include "light.hpp"

class DirectionLight : public Light {
    private:
        Vector direction; 
        
    public:
        DirectionLight(Vector intensity, Vector direction);
    
        Vector calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o);
    
        Vector get_direction();
        void set_direction(Vector direction);
};

#endif

