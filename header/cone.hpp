#ifndef CONE_HPP
#define CONE_HPP

#include "object.hpp"

class Cone : public Object {
    private:
        Vector center, V, dc;
        double radius, height; // raio
        bool has_base;

        bool in_shell(Vector P);
        bool in_base(Vector P, Vector PI, Vector DC);
        std::tuple<double, double> intersect_cone_shell_vector(Vector O, Vector D);
        double ray_intersect_base(Vector O, Vector D, Vector PI, Vector DC);

    public:
        Cone();
        Cone(Vector c, Vector dc, double r, double h, Color kd, Color ka, Color ke, double s, bool has_base);
        Cone(Vector c, Vector dc, double r, double h, const char * name, double s, bool has_base);
        Cone(Vector c, Vector V, double r, Color kd, Color ka, Color ke, double s, bool has_base);
        Cone(Vector c, Vector V, double r, const char * name, double s, bool has_base);

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
        Vector get_v();
        double get_radius();
        double get_height();

        void set_center(Vector c);
        void set_v(Vector v);
        void set_radius(double r);
        void set_height(double h);
};

#endif