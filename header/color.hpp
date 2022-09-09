#ifndef COLOR_HPP
#define COLOR_HPP

#include "vector.hpp"

class Color {
    private:
        double r, g, b;
    public:
        Color();
        Color(double r, double g, double b);

        Color operator * (double n);
        Color operator * (Vector v);

        unsigned int convert_red();
        unsigned int convert_green();
        unsigned int convert_blue();

        static Color convert_rgb(int r, int g, int b) {
            return Color(1.0 * r/255,1.0 * g/255, 1.0 * b/255);
        }

        double get_r();
        void set_r(double r);
        double get_g();
        void set_g(double g);
        double get_b();
        void set_b(double b);
};

#endif