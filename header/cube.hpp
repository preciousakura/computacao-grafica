#ifndef CUBE_HPP
#define CUBE_HPP

#include "vector.hpp"
#include "mesh.hpp"
#include <bits/stdc++.h>

class Cube: public Mesh {
    private:
        double size; 

    public:
        Cube();
        Cube(Color kd, Color ka, Color ke, double s);
        Cube(const char * name, double s);

        void set_size(double size);
        int get_size();

        void set_faces();
};

#endif