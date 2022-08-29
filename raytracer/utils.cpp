#include <fstream>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>

typedef struct Vector {
    double x, y, z;
    Vector() {x=y=z=0;}
    Vector(double a, double b, double c) {x = a, y = b, z = c;}
    Vector operator - (Vector v) {return Vector(x - v.x, y - v.y, z - v.z);}
    double operator * (Vector v) {return v.x * x + v.y * y + v.z * z;}
} Vector;

typedef struct Color {
    double r, g, b;
    Color() {r=g=b=0;}
    Color(double i, double j, double k) {r = i, g = j, b = k;}
    bool operator == (Color c) {return r == c.r && g == c.g && b == c.b; }
} Color;

typedef struct Sphere {
    Vector c; // Centro
    double r; // raio
    Color color; // cor da esfera

    Sphere() { r = -1; }
    Sphere(Vector i, double j, Color s_color) {c = i; r = j; color = s_color;}

    void intersectRaysphere(Vector o, Vector d, double &t1, double &t2) {
        Vector co = o - c;

        double a = d * d;
        double b = 2 * (co * d);
        double c = co * co - r*r;

        double delta = b*b - 4 * a * c;
        if(delta < 0) {
            t1 = INFINITY;
            t2 = INFINITY;
        }

        t1 = (-b + std::sqrt(delta)) / 2 * a;
        t2 = (-b - std::sqrt(delta)) / 2 * a;
    }
} Sphere;

typedef struct Viewport {
    double w, h, d;
    Viewport(double vp_w, double vp_h, double vp_d) { w = vp_w, h = vp_h, d = vp_d; }
    Viewport(){}
} Viewport;

typedef struct Canvas {
    double w, h, dx, dy;
    Viewport vp;
    Color bg;
    Canvas(){}
    Canvas(double cw, double ch, Viewport c_vp, Color c_bg) { 
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
    std::vector<Sphere> spheres;
    Vector vector_camera;
    Canvas canva;

    Scene(std::vector<Sphere> scene_spheres, Vector cam, Canvas c) {
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

        return closest_sphere.color;
    }
} Scene;