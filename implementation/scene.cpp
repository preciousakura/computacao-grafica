#include <cmath>
#include "../header/scene.hpp"

Scene::Scene(Vector O, Viewport vw, Canva c) : O(O), viewport(vw), canva(c) {
    this->dx = 1.0*vw.get_w()/c.get_w();
    this->dy = 1.0*vw.get_h()/c.get_h(); 
}

double Scene::compute_lighting(Vector P, Vector N, Vector V, int s) {
    double i = 0.0;
    for(Light* l : lights)
        i += l->calculate_intensity(P, N, V, s);
    return i;
}

Color Scene::trace_ray_spheres(Vector O, Vector D, double t_min, double t_max){
    Sphere closest_sphere; 
    Color color = canva.get_background_color(); 
    bool nulo = true;

    double t1, t2, closest = INFINITY;
    for(Sphere s : spheres){
        std::tie(t1, t2) = s.intersectRaysphere(O, D); 
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

    if(nulo) return canva.get_background_color();
    Vector P = O + D*closest;
    Vector N = (P-closest_sphere.get_center())/closest_sphere.get_radius();
    return closest_sphere.get_color() * compute_lighting(P, N, -D, closest_sphere.get_specular());
}

Vector Scene::canva_to_viewport(int i, int j){ 
    return Vector(-viewport.get_w()/2.0 + dx/2.0 + j*dx, viewport.get_h()/2.0 - dy/2.0 - i*dy, viewport.get_d());
}

void Scene::add_sphere(Sphere s){ spheres.push_back(s); }
void Scene::add_light(Light* l){ lights.push_back(l); }

void Scene::draw_scenario(){
    for(int i = 0; i < canva.get_w(); i++){
        for(int j = 0; j < canva.get_h(); j++){
            Vector D = canva_to_viewport(i, j); 
            Color color = trace_ray_spheres(this->O, D, 1.0, INFINITY);
            canva.to_color(i, j, color);
        }
    }
}

void Scene::save_scenario(const char* image_name) {
    canva.write_image(image_name);
}
