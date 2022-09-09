#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object.hpp"

class Sphere : public Object  {
    private:
        Vector center; // Centro
        double radius, specular; // raio
        Color kd, ka, ke;
        
    public:
        Sphere();
        Sphere(Vector i, double j, Color kd, Color ka, Color ke, double s);

        std::tuple<double, double> intersect(Vector o, Vector d);
        Vector get_normal(Vector P);

        Vector get_center();
        void set_center(Vector center);
        double get_radius();
        void set_radius(double radius);
};

#endif