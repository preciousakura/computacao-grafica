#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "object.hpp"
#include "plan.hpp"
#include <vector>

class Cylinder : public Object {
    private:
        Vector center, dc;
        double height;

        bool has_base, has_top;

        double radius;

        bool in_shell(Vector P);
        bool in_base(Vector P, Vector PI, Vector DC);
        std::tuple<double, double> intersect_cylinder_shell_vector(Vector O, Vector D);
        double ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC);

    public:
        Cylinder();
        Cylinder(Vector center, Vector dc, double radius, double h, Color kd, Color ka, Color ke, double s, bool has_base, bool has_top);
        Cylinder(Vector center, Vector dc, double radius, double h, const char * name, double s, bool has_base, bool has_top);

        std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);
        Vector get_normal(Vector O, Vector D, double &t);

        void set_dc(Vector c);
        Vector get_dc();
        
        void set_center(Vector c);
        Vector get_center();

        void set_height(double h);
        double get_height();

        void set_radius(double r);
        double get_radius();
};

#endif
