#ifndef PLAN_HPP
#define PLAN_HPP

#include "object.hpp"

class Plan : public Object {
    private:
        Vector P, N;

    public:
        Plan(Vector P, Vector N, Color kd, Color ka, Color ke, double s);
        Plan(Vector P, Vector N, const char * name, double s);
        Plan(Vector P, Vector N);
        Plan();

        std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);
        Vector get_normal(Vector O, Vector D, double &t);
        void transform();
        void rotation_x(double angle);
        void rotation_y(double angle);
        void rotation_z(double angle);
        void translation(Vector v);
        void scaling(double x, double y, double z);
        void scaling(double size);
        void shearing_xy(double angle);
        void shearing_xz(double angle);
        void shearing_yx(double angle);
        void shearing_yz(double angle);
        void shearing_zx(double angle);
        void shearing_zy(double angle);
        void reflection_xy();
        void reflection_yz();
        void reflection_xz();
        void reflection_at(Vector p, Vector n);

        void set_p(Vector ponto);
        Vector get_p();
        void set_n(Vector normal);
        Vector get_n();
};

#endif