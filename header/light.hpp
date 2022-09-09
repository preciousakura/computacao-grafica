#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "object.hpp"

class Light {
    private:
        Vector intensity;

    public:
        Light(Vector i);
        virtual Vector calculate_intensity(Vector P, Vector N, Vector V, int s, Object* o) = 0;
        Vector specular(Vector N, Vector L, Vector V, int s);

        Vector get_intensity();
        void set_intensity(Vector intensity);
};

#endif