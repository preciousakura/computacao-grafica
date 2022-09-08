#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector.hpp"

class Light {
    private:
        double intensity;

    public:
        Light(double i);
        virtual double calculate_intensity(Vector P, Vector N, Vector V, int s) = 0;
        double specular(Vector N, Vector L, Vector V, int s);

        double get_intensity();
        void set_intensity(double intensity);
};

#endif