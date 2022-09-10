#include <cmath>
#include "../header/scene.hpp"
#include "bits/stdc++.h"

Scene::Scene(Vector O, Viewport vw, Canva c) : O(O), viewport(vw), canva(c) {
    this->dx = 1.0*vw.get_w()/c.get_w();
    this->dy = 1.0*vw.get_h()/c.get_h(); 
}


std::tuple<double, Object*> Scene::trace_ray_objects(Vector O, Vector D, double t_min, double t_max){
    Object *closest_sphere; 
    Color color = canva.get_background_color(); 
    bool nulo = true;

    double t1, t2, closest = INFINITY;
    for(Object *s : objects){
        std::tie(t1, t2) = s->intersect(O, D); 
        if(t1 >= t_min && t1 <= t_max && t1 < closest){
            closest = t1;
            closest_sphere = s;
            nulo = false;
        }
        if(t2 >= t_min && t2 <= t_max && t2 < closest){
            closest = t2;
            closest_sphere = s;
            nulo = false;
        }
    }

    if(nulo) return {INFINITY, closest_sphere};
    return {closest, closest_sphere};
}

bool Scene::has_shadow(Vector P, Light* l) {
    Object *closest_object;
    Vector L = l->get_l(P);
    Vector N_L = L / ~L;
    if(~L == 0.0) return true;
    double s;
    std::tie(s, closest_object) = this->trace_ray_objects(P, N_L, 1.0, INFINITY);
    if(s != INFINITY && s < ~L) return true;
    return false;
}

Color Scene::compute_lighting(Vector P, Vector N, Vector V, int s, Object* o) {
    Color i;
    for(Light* l : lights)
        i = i + l->calculate_intensity(P, N, V, s, o, has_shadow(P, l));
    return i;
}


Color Scene::trace_ray(Vector O, Vector D, double t_min, double t_max) {
    double closest_t;
    Object *closest_object;

    std::tie(closest_t, closest_object) = trace_ray_objects(O, D, 1.0, INFINITY);

    if(closest_t == INFINITY) return canva.get_background_color();
    

    Vector P = O + D * closest_t;
    return compute_lighting(P, closest_object->get_normal(P), -D, closest_object->get_specular(), closest_object);    
}

Vector Scene::canva_to_viewport(int i, int j){ 
    return Vector(-viewport.get_w()/2.0 + dx/2.0 + j*dx, viewport.get_h()/2.0 - dy/2.0 - i*dy, viewport.get_d());
}

void Scene::add_object(Object *o){ objects.push_back(o); }
void Scene::add_light(Light* l){ lights.push_back(l); }

void Scene::draw_scenario(){
    for(int i = 0; i < canva.get_w(); i++){
        for(int j = 0; j < canva.get_h(); j++){
            Vector D = canva_to_viewport(i, j); 
            Color color = trace_ray(this->O, D, 1.0, INFINITY);
            canva.to_color(i, j, color);
        }
    }
}

void Scene::save_scenario(const char* image_name) {
    canva.write_image(image_name);
}
