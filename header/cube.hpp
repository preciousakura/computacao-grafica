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
        Cube(Vector center, double size, Color kd, Color ka, Color ke, double s);

        void set_size(int size);
        int get_size();
};

#endif