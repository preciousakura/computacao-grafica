#ifndef PLAN_HPP
#define PLAN_HPP

#include "vector.hpp"
#include "color.hpp"

class Plan {
    private:
        Vector P, N;
        Color color;
        double specular;
    public:
        Plan();
        Plan(Vector P, Vector N, Color color, double s);

        double intersectRayPlan(Vector p, Vector d);

        void set_p(Vector ponto);
        Vector get_p();
        void set_n(Vector normal);
        Vector get_n();
        void set_color(Color color);
        Color get_color();
        double get_specular();
        void set_specular(double specular);
};

#endif