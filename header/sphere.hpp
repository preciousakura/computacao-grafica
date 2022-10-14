#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object.hpp"

class Sphere : public Object  {
    private:
        Vector center; // Centro
        double radius; // raio
        
    public:
        Sphere();
        Sphere(Vector i, double j, Color kd, Color ka, Color ke, double s);
        Sphere(Vector i, double j, const char * name, double s);

        std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);
        Vector get_normal(Vector O, Vector D, double &t);
        void transform();
        void rotation_x(double angle);
        void rotation_y(double angle);
        void rotation_z(double angle);
        void translation(Vector v);
        void scaling(double x, double y, double z);
        void scaling(double size);

        Vector get_center();
        void set_center(Vector center);
        double get_radius();
        void set_radius(double radius);
};

#endif