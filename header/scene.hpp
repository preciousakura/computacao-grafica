#ifndef SCENE_HPP
#define SCENE_HPP

#include "vector.hpp"
#include "canva.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "viewport.hpp"
#include "plan.hpp"
#include "object.hpp"

class Scene {
    private:
        Vector O;
        Viewport viewport;
        Canva canva;
        std::vector<Object*> objects;
        std::vector<Light*> lights;
        double dx, dy;

        Color compute_lighting(Vector P, Vector V, int s, Object* O);
        Color trace_ray(Vector O, Vector D, double t_min, double t_max);
        std::tuple<double, Object*> trace_ray_objects(Vector O, Vector D, double t_min, double t_max);
        Vector canva_to_viewport(int x, int y);
        bool has_shadow(Vector P, Light* l);

    public:
        Scene(Vector O, Viewport vp, Canva c);
        void add_object(Object *s);
        void add_light(Light *l);
        void draw_scenario();
        void save_scenario(const char* image_name);
};

#endif