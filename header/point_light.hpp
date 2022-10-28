#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include "light.hpp"

class PointLight : public Light {
    private:
        Vector position; 
        
    public:
        PointLight(Color intensity, Vector position);
        Color calculate_intensity(Vector P, Vector N, Vector V, double s,  Object* o, bool has_shadow);
        Vector get_l(Vector P);
        void transform();
    
        Vector get_position();
        void set_position(Vector position);
};

#endif
