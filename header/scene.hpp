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

        Color compute_lighting(Vector P, Vector N, Vector V, double s, Object* o, double t_min, double t_max);
        Color trace_ray_objects(Vector O, Vector D, double t_min, double t_max, int i, int j);
        Vector canva_to_viewport(int x, int y);
        bool has_shadow(Vector P, Light* l, double t_min, double t_max);

    public:
        Scene(Vector O, Viewport vp, Canva c);
        void add_object(Object *s);
        void add_light(Light *l);
        void draw_scenario();
        void save_scenario(const char* image_name);
        void lookAt(Vector e, Vector at, Vector up);
        Color get_pixel(int i, int j);
};

#endif