#ifndef MESH_HPP
#define MESH_HPP

#include "object.hpp"
#include "plan.hpp"

class Mesh {
    private:
        Vector p1, p2, p3;
        Vector r1, r2;
        Vector normal;
    public:
        Mesh();
        Mesh(Vector p1, Vector p2, Vector p3);

        Vector get_n();
        double get_t_intersection(Vector O, Vector D);
        bool intersect_with_face(Vector O);
        std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);
        
        void set_p1(Vector v);
        void set_p2(Vector v);
        void set_p3(Vector v);

        void set_r1(Vector v);
        void set_r2(Vector v);

        Vector get_p1();
        Vector get_p2();
        Vector get_p3();

        Vector get_r1();
        Vector get_r2();
};

#endif