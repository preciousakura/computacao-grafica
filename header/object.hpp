#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "color.hpp"
#include "vector.hpp"
#include <tuple>

class Object {
    private:
        double specular;
        Color kd, ka, ke;
    public:

        Object();
        Object(Color kd, Color ka, Color ke, double s);
        virtual std::tuple<double, double> intersect(Vector p, Vector d) = 0;
        virtual Vector get_normal(Vector P) = 0;

        void set_kd(Color color);
        Color get_kd();
        void set_ka(Color color);
        Color get_ka();
        void set_ke(Color color);
        Color get_ke();

        double get_specular();
        void set_specular(double specular);

};

#endif