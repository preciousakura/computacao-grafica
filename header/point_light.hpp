#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include "light.hpp"

class PointLight : public Light {
    private:
        Vector position; 
        
    public:
        PointLight(Vector intensity, Vector position);
    
        Vector calculate_intensity(Vector P, Vector N, Vector V, int s,  Object* o);
    
        Vector get_position();
        void set_position(Vector position);
};

#endif
