#ifndef MESH_HPP
#define MESH_HPP

#include "object.hpp"
#include "plan.hpp"
#include <bits/stdc++.h>

class Mesh : public Object {
    protected:
        Vector center;

        class Face {
            private:
                Vector p1, p2, p3;
                Vector normal;

                friend Mesh;

            public:
                Face();
                Face(Vector p1, Vector p2, Vector p3);

                bool in_face(Vector P);
                std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);

                void set_p1(Vector v);
                void set_p2(Vector v);
                void set_p3(Vector v);

                Vector get_p1();
                Vector get_p2();
                Vector get_p3();

                void set_normal(Vector n);
                Vector get_normal();
        };

        std::vector<Face*> faces;

    public:
        Mesh();
        Mesh(Vector center, Color kd, Color ka, Color ke, double s);
        std::tuple<double, Vector> intersect(Vector O, Vector D, double t_min, double t_max);

        Vector get_center();
        void set_center(Vector c);

};

#endif