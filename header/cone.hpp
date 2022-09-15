#ifndef CONE_HPP
#define CONE_HPP

#include "object.hpp"

class Cone : public Object {
    private:
        Vector center, V, dc;
        double specular, radius, height; // raio
        Color kd, ka, ke;

        bool in_shell(Vector P);
        bool in_base(Vector P, Vector PI, Vector DC);
        std::tuple<double, double> intersect_cone_shell_vector(Vector O, Vector D);
        double ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC);

    public:
        Cone();
        Cone(Vector c, Vector dc, double r, double h, Color kd, Color ka, Color ke, double s);
        Cone(Vector c, Vector V, double r, Color kd, Color ka, Color ke, double s);

        std::tuple<double, double> intersect(Vector o, Vector d);
        Vector get_normal(Vector P);

        Vector get_center();
        Vector get_v();
        double get_radius();
        double get_height();

        void set_center(Vector c);
        void set_v(Vector v);
        void set_radius(double r);
        void set_height(double h);
};

#endif