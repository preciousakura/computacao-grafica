#include <cmath>
#include "../header/scene.hpp"
#include "bits/stdc++.h"

Scene::Scene(Vector O, Viewport vw, Canva c) : O(O), viewport(vw), canva(c) {
    this->dx = 1.0*vw.get_w()/c.get_w();
    this->dy = 1.0*vw.get_h()/c.get_h(); 
}


std::tuple<Color, Object*> Scene::trace_ray_objects(Vector O, Vector D, double t_min, double t_max, int i, int j){
    Object *closest_object = nullptr; 
    Color color = canva.get_background_color(); 
    bool nulo = true;

    double t, closest = INF;
    Vector aux_N, N;

    for(Object *s : objects){
        std::tie(t, aux_N) = s->intersect(O, D, t_min, t_max); 
        if(t - EPS >= t_min && t <= t_max && t < closest){
            closest = t;
            closest_object = s;
            nulo = false;
            N = aux_N;
        }
    }

    
    if(closest == INF) return {canva.get_background_color(), closest_object};
    if(closest_object->has_image()) closest_object->set_current_color(i, j);

    Vector P = O + D * closest;

    return {compute_lighting(P, N, -D, closest_object->get_specular(), closest_object, t_min, t_max), closest_object};   
}

bool Scene::has_shadow(Vector P, Light* l, double t_min, double t_max) {
    Object *closest_object;
    Vector L = l->get_l(P);
    Vector N_L = L / ~L;
    if(~L == 0.0) return true;
    double t, closest = INF;
    Vector n;

    for(Object* o : objects) {
        std::tie(t, n) = o->intersect(P, N_L, t_min, t_max); 
        if(t-EPS > t_min && t < t_max && t < closest) closest = t;   
    }
    return !(closest >= (~L));
}

Color Scene::compute_lighting(Vector P, Vector N, Vector V, double s, Object* o, double t_min, double t_max) {
    Color i;
    for(Light* l : lights)
        i = i + l->calculate_intensity(P, N, V, s, o, false);
    return i;
}


Vector Scene::canva_to_viewport(int i, int j){ 
    return Vector(-viewport.get_w()/2.0 + dx/2.0 + j*dx, viewport.get_h()/2.0 - dy/2.0 - i*dy, viewport.get_d());
}

void Scene::lookAt(Vector e, Vector at, Vector up) {
    Matrix m = Matrix::world_to_camera_matrix(e, at, up);
    for(Object *s : objects) s->world_to_camera(m);  
    for(Light *l : lights) l->world_to_camera(m);  
}

Object* Scene::picking(int i, int j) { return canva.get_object(i, j); }

void Scene::add_object(Object *o){ objects.push_back(o); }
void Scene::add_light(Light* l){ lights.push_back(l); }

void Scene::erase_object(Object* o){  }

void Scene::draw_scenario(){
    Color color; 
    Object* obj;
    for(int i = 0; i < canva.get_w(); i++) {
        for(int j = 0; j < canva.get_h(); j++) {
            Vector D = canva_to_viewport(i, j); 
            std::tie(color, obj) = trace_ray_objects(this->O, (D/~D), 1.0, INF, i, j);
            canva.to_color(i, j, color);
            canva.to_buffer(i, j, obj);
        }
    }
}

void Scene::draw_scenario_parell(){
    Color color; 
    Object* obj;
    for(int i = 0; i < canva.get_w(); i++) {
        for(int j = 0; j < canva.get_h(); j++) {
            Vector D = Vector(0, 0, -1);
            std::tie(color, obj)  = trace_ray_objects(canva_to_viewport(i, j), (D/~D), 1.0, INF, i, j);
            canva.to_color(i, j, color);
            canva.to_buffer(i, j, obj);
        }
    }
}

Color Scene::get_pixel(int i, int j) { return canva.get_pixel(i, j); }
Object* Scene::get_object(int i, int j) { return canva.get_object(i, j); }

void Scene::save_scenario(const char* image_name) {
    canva.write_image(image_name);
}
