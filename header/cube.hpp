#ifndef CUBE_HPP
#define CUBE_HPP

#include "object.hpp"
#include "vector.hpp"
#include "mesh.hpp"
#include <bits/stdc++.h>

class Cube: public Object {
    private:
        Vector center;
        int size; 

        std::vector<Mesh> faces;

        double specular; 
        Color kd, ka, ke;
    public:
        Cube();
        Cube(Vector center, int size, Color kd, Color ka, Color ke, double s);

        std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);
        Vector get_normal(Vector O, Vector D, double &t);

        void set_center(Vector c);
        void set_size(int size);
        void set_faces(std::vector<Mesh> faces);

        Vector get_center();
        int get_size();
        std::vector<Mesh> get_faces();
};

#endif