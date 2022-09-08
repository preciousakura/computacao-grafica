#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>

typedef struct Vector {
    double x, y, z;
    Vector() {x=y=z=0;}
    Vector(double a, double b, double c) {x = a, y = b, z = c;}
    Vector operator * (double n) {return Vector(x * n, y * n, z * n);}    
    Vector operator / (double n) {return Vector(x / n, y / n, z / n);}
    Vector operator - (Vector v) {return Vector(x - v.x, y - v.y, z - v.z);}
    Vector operator + (Vector v) {return Vector(x + v.x, y + v.y, z + v.z);}
    double dot(Vector v) {return x * v.x + y * v.y + z * v.z;} 
    double length() {return std::sqrt(x * x + y * y + z * z);}
    Vector normalize() {
        double n = length();
        return Vector(x/n, y/n, z/n);
    }
} Vector;

typedef struct Color {
    double r, g, b;
    Color() {r=g=b=0;}
    Color(double i, double j, double k) {r = std::min(i, 1.0), g = std::min(j, 1.0), b = std::min(k, 1.0);}
    Color operator * (double c) { return Color(r * c, g * c, b * c); }
    static Color convert_rgb(int r, int g, int b) {return Color(1.0 * r / 255, 1.0 * g / 255, 1.0 * b / 255);}
    int convert_r() {return r * 255;}
    int convert_g() {return g * 255;}
    int convert_b() {return b * 255;}
} Color;


enum class LightType {point, ambient, directional};
typedef struct Light {
    LightType type;
    Vector position, direction;
    double intensity;

    Light() {}
    Light(double i, LightType type, Vector p_d = Vector(0, 0, 0)): intensity(i), type(type) { 
        if(type == LightType::point) position = p_d;
        else if(type == LightType::directional) direction = p_d;
    }
} Light;

typedef struct Sphere {
    Vector c; // Centro
    double r, specular; // raio
    Color color; // cor da esfera

    Sphere() { r = -1; }
    Sphere(Vector i, double j, double s, Color s_color) {c = i, r = j, specular = s, color = s_color;}

    void intersectRaysphere(Vector o, Vector d, double &t1, double &t2) {
        Vector co = o - c;

        double a = d.dot(d);
        double b = 2 * co.dot(d);
        double c = co.dot(co) - r*r;

        double delta = b*b - 4 * a * c;
        if(delta < 0) {
            t1 = INFINITY;
            t2 = INFINITY;
            return;
        }

        t1 = (-b + std::sqrt(delta)) / (2 * a);
        t2 = (-b - std::sqrt(delta)) / (2 * a);
    }

    Vector getNormal(Vector p_i) {return (p_i - c) / r;}
} Sphere;

typedef struct Plan {

} Plan;

typedef struct Viewport {
    double w, h, d;
    Viewport(double vp_w, double vp_h, double vp_d) { w = vp_w, h = vp_h, d = vp_d; }
    Viewport(){}
} Viewport;

typedef struct Canvas {
    int w, h;
    double dx, dy;
    Viewport vp;
    Color bg;

    Canvas(){}
    Canvas(int cw, int ch, Viewport c_vp, Color c_bg) { 
        w = cw;
        h = ch;
        dx = c_vp.w/cw;
        dy = c_vp.h/ch;
        vp = c_vp;
        bg = c_bg; 
    }

    Vector canvasToViewport(double x, double y) {
        return Vector(-vp.w/2.0 + dx/2.0 + y*dx, vp.h/2.0 - dy/2.0 - x * dy, vp.d);
    }

} Canvas;

typedef struct Scene {
    std::vector<Light> lights;
    std::vector<Sphere> spheres;
    Vector vector_camera;
    Canvas canva;

    Scene(std::vector<Light> scene_lights, std::vector<Sphere> scene_spheres, Vector cam, Canvas c) {
        lights = scene_lights;
        spheres = scene_spheres;
        vector_camera = cam;
        canva = c;
    }

    Color traceRay(Vector d, double t_min, double t_max) {
        double closest_t = INFINITY;
        Sphere closest_sphere;
        double t1, t2;

        for(int i = 0; i < spheres.size(); i++) {
            spheres[i].intersectRaysphere(vector_camera, d, t1, t2);
            if((t1 >= t_min && t1 <= t_max) && t1 < closest_t) {
                closest_t = t1;
                closest_sphere = spheres[i];
            }

            if((t2 >= t_min && t2 <= t_max) && t2 < closest_t) {
                closest_t = t2;
                closest_sphere = spheres[i];
            }
        }

        if(closest_sphere.r == -1) 
            return canva.bg; 
        
        Vector p_i = vector_camera + d * closest_t;
        Vector n = closest_sphere.getNormal(p_i);
        n = n.normalize();

        return closest_sphere.color * computeLighting(p_i, n,  d * -1, closest_sphere.specular);
    }

    double computeLighting(Vector p_i, Vector n, Vector v, double s) {
        double intensity = 0.0, n_dot_l, r_dot_v;
        Vector l, r;

        for(int i = 0; i < lights.size(); i++) {
            if(lights[i].type == LightType::ambient)
                intensity += lights[i].intensity;
            else {
                if(lights[i].type == LightType::point) l = lights[i].position - p_i;
                else l = lights[i].direction;

                // Difusa
                n_dot_l = n.dot(l);
                if(n_dot_l > 0)
                    intensity += lights[i].intensity * n_dot_l / (n.length() * l.length());

                // Specular
                if(s != -1) {
                    r = (n * (2 * n_dot_l)) - l;
                    r_dot_v = r.dot(v);
                    
                    if(r_dot_v > 0)
                        intensity += lights[i].intensity * std::pow((r_dot_v) / (r.length() * v.length()), s);
                }

            }
        }
        return intensity;
    }
} Scene;