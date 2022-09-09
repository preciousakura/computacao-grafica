#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector.hpp"
#include "color.hpp"

class Light {
    private:
        Color intensity;

    public:
        Light(Color intensity);
        virtual Color calculate_intensity(Vector P, Vector N, Vector V, int s) = 0;
        Color specular(Vector N, Vector L, Vector V, int s);

        Color get_intensity();
        void set_intensity(Color intensity);
};

#endif