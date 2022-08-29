#include <fstream>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>


#define Cw 300
#define Ch 300

#define Vw 1
#define Vh 1

#define D 1

typedef struct Color {
    double r, g, b;
    Color() {r=g=b=0;}
    Color(double i, double j, double k) {r = i, g = j, b = k;}
    bool operator == (Color c) {return r == c.r && g == c.g && b == c.b; }
} Color;

typedef struct Vector {
    double x, y, z;
    Vector() {x=y=z=0;}
    Vector(double a, double b, double c) {x = a, y = b, z = c;}
    Vector operator - (Vector v) {return Vector(x - v.x, y - v.y, z - v.z);}
} Vector;

typedef struct Sphere {
    Vector c; // Centro
    Color color;
    double r; // raio

    Sphere() { r = -1; }
    Sphere(Vector i, double j, Color clr) {c = i; r = j; color = clr;}
} Sphere;

Vector canvasToViewport(double x, double y) {
    return Vector(x * Vw/Cw, y * Vh/Ch, D);
}

double dot(Vector v, Vector b) {
    return (v.x * b.x + v.y * b.y + v.z * b.z);
}

void intersectRaysphere(Vector o, Vector d, Sphere sphere, double &t1, double &t2) {
    double r = sphere.r;
    Vector co = o - sphere.c;

    double a = dot(d, d);
    double b = 2 * dot(co, d);
    double c = dot(co, co) - r*r;

    double delta = b*b - 4 * a * c;
    if(delta < 0) {
        t1 = INFINITY;
        t2 = INFINITY;
    }

    t1 = (-b + std::sqrt(delta)) / 2 * a;
    t2 = (-b - std::sqrt(delta)) / 2 * a;
}

Color traceRay(Vector o, Vector d, double t_min, double t_max, std::vector<Sphere> scene) {
    double closest_t = INFINITY;
    Sphere closest_sphere;
    double t1, t2;

    for(int i = 0; i < scene.size(); i++) {
        intersectRaysphere(o, d, scene[i], t1, t2);
        if((t1 > t_min && t1 < t_max) && t1 < closest_t) {
            closest_t = t1;
            closest_sphere = scene[i];
        }

        if((t2 > t_min && t2 < t_max) && t2 < closest_t) {
            closest_t = t2;
            closest_sphere = scene[i];
        }

        if(closest_sphere.r == -1) {
            return Color(0, 0, 0);
        }
    }

    return closest_sphere.color;
}

int main() {
    Color pixels[Cw][Ch];
    int i = 0, j = 0;
    std::vector<Sphere> scene;
    
    Sphere red(Vector(0, -1, 3), 1, Color(255, 0, 0));
    Sphere blue(Vector(2, 0, 4), 1, Color(0, 0, 255));
    Sphere green(Vector(-2, 0, 4), 1, Color(0, 255, 0));

    scene.push_back(red);
    scene.push_back(blue);
    scene.push_back(green);

    std::ofstream out("out.ppm");
    
    out << "P3";
    out << std::endl;
    out << Cw << std::endl;
    out << Ch << std::endl;
    out << 255 << std::endl;

    Vector o(0, 0, 0);
    Color black(0, 0, 0);

    for(int x = -Cw/2; x < Cw/2; x++){
        for(int y = -Ch/2; y < Ch/2; y++) {
            Vector d = canvasToViewport(x, y);
            Color color = traceRay(o, d, 1, INFINITY, scene);

            out << color.r << std::endl;
            out << color.g << std::endl;
            out << color.b << std::endl;
        }
    }

    out.close();
    return 0;
}