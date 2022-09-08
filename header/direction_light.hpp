#ifndef DIRECTION_LIGHT_HPP
#define DIRECTION_LIGHT_HPP

#include "light.hpp"

class DirectionLight : public Light {
    private:
        Vector direction; 
        
    public:
        DirectionLight(double intensity, Vector direction);
    
        double calculate_intensity(Vector P, Vector N, Vector V, int s);
    
        Vector get_direction();
        void set_direction(Vector direction);
};

#endif

