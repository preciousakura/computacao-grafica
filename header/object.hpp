#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "color.hpp"
#include "vector.hpp"
#include <tuple>
#include <cmath>
#include <vector>

typedef unsigned char int8;

class Object {
    private:
        int width, height, channel;
        std::vector<std::vector<Color>> image_pixels;

        double specular;
        Color kd, ka, ke;
        Color current_color;
        bool has_img = false;

    public:

        Object();
        Object(Color kd, Color ka, Color ke, double s);
        Object(const char * name, double s);
        
        virtual std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max) = 0;

        void set_kd(Color color);
        Color get_kd();
        void set_ka(Color color);
        Color get_ka();
        void set_ke(Color color);
        Color get_ke();

        double get_specular();
        void set_specular(double specular);

        int get_width();
        void set_width(int w);

        int get_height();
        void set_height(int h);

        void set_current_color(int i, int j);
        Color get_current_color();

        bool has_image();
};

#endif