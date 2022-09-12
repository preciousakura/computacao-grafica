#ifndef PLAN_HPP
#define PLAN_HPP

#include "object.hpp"

class Plan : public Object {
    private:
        Vector P, N;
        Color kd, ka, ke;
        double specular;

    public:
        Plan(Vector P, Vector N, Color kd, Color ka, Color ke, double s);
        Plan(Vector P, Vector N);
        Plan();

        std::tuple<double, double> intersect(Vector p, Vector d);
        Vector get_normal(Vector P);

        void set_p(Vector ponto);
        Vector get_p();
        void set_n(Vector normal);
        Vector get_n();
};

#endif