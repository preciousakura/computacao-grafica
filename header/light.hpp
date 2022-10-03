#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "object.hpp"

class Light {
    private:
        Color intensity;

    public:
        Light(Color i);
        virtual Color calculate_intensity(Vector P, Vector N, Vector V, double s, Object* o, bool has_shadow) = 0;
        virtual Vector get_l(Vector P) = 0;
        double specular(Vector N, Vector L, Vector V, double s);

        Color get_intensity();
        void set_intensity(Color intensity);
};

#endif