#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "object.hpp"
#include "plan.hpp"
#include <vector>

class Cylinder : public Object {
    private:
        Vector center, dc;
        int height;

        Color kd, ka, ke;
        double specular, radius;

        bool in_shell(Vector P);
        bool in_base(Vector P, Vector PI, Vector DC);
        std::tuple<double, double> intersect_cylinder_shell_vector(Vector O, Vector D);
        double ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC);

    public:
        Cylinder();
        Cylinder(Vector center, Vector dc, double radius, int h, Color kd, Color ka, Color ke, double s);

        std::tuple<double, double> intersect(Vector p, Vector d);
        Vector get_normal(Vector P);

        void set_dc(Vector c);
        Vector get_dc();
        
        void set_center(Vector c);
        Vector get_center();

        void set_height(int h);
        int get_height();

        void set_radius(int r);
        int get_radius();
};

#endif
