#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector.hpp"
#include "color.hpp"
#include <tuple>

class Sphere {
    private:
        Vector center; // Centro
        double radius, specular; // raio
        Color color; // cor da esfera

    public:
        Sphere();
        Sphere(Vector i, double j, double s, Color s_color);

        std::tuple<double, double> intersectRaysphere(Vector o, Vector d);

        Vector get_center();
        void set_center(Vector center);
        double get_radius();
        void set_radius(double radius);
        double get_specular();
        void set_specular(double specular);
        Color get_color();
        void set_color(Color color);
};

#endif