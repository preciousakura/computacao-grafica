#ifndef CANVA_HPP
#define CANVA_HPP

#include "color.hpp"
#include <vector>
typedef unsigned char int8;

class Canva {
    private:
        int w, h;
        std::vector<std::vector<Color>> pixels; 
        Color background;

    public:
        Canva();
        Canva(int w, int h, Color bg);
        void write_image(const char* image_name);
        void to_color(int i, int j, Color color);

        int get_w();
        void set_w(int w);
        int get_h();
        void set_h(int m);
        Color get_background_color();
        void set_background_color(Color background_color);
};

#endif