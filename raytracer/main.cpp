#include <fstream>
#include <cmath>
#include <stdio.h>
#include <iostream>


#define W 200
#define H 200


typedef struct Color {
    double r, g, b;
    Color() {r=g=b=0;}
    Color(double i, double j, double k) {r = i, g = j, b = k;}
} Color;

typedef struct Vector {
    double x, y, z;
    Vector() {x=y=z=0;}
    Vector(double a, double b, double c) {x = a, y = b, z = c;}
    Vector operator - (Vector v) {return Vector(x - v.x, y - v.y, z - v.z);}
} Vector;

double dot(Vector v, Vector b) {
    return (v.x * b.x + v.y * b.y + v.z + b.z);
}

typedef struct Ray {
    Vector o; // Origem
    Vector d; // Direção
    Ray(Vector i, Vector j) { o = i, d = j; }
} Ray;

typedef struct Sphere {
    Vector c; // Centro
    double r; // raio

    Sphere(Vector i, double j) {c = i; r = j;}
    bool intersection(Ray ray, double &t) {
        Vector o = ray.o;
        Vector d = ray.d;
        Vector oc = o - c; // vetor w
        double b = 2 * dot(oc, d);
        double c = dot(oc, oc) - r*r; // (P0 - C) * (P0 - C) - R² = 0 #Equação do Raio
        
        double delta = b*b - 4 * c;
        if(delta < 0) return false;
        else {
            delta = sqrt(delta);
            double t0 = - b - delta; // raiz 1
            double t1 = - b + delta; // raiz 2

            t = (t0 < t1) ? t0 : t1; // retorna o ponto mais próximo do observador 
            return true;
        }
    }
} Sphere;

int main() {
    Color pixel_col[H][W];
    Color white(255, 255, 255);
    Sphere sphere(Vector(W/2, H/2, 100), 20);

    std::ofstream out("out.ppm");
    
    out << "P3";
    out << std::endl;
    out << W << std::endl;
    out << H << std::endl;
    out << 255 << std::endl;


    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            Ray ray(Vector(y, x, 0), Vector(0, 0, 1));
            double t = 20;

            if(sphere.intersection(ray, t)) {
                // pintar o pixel do círculo
                pixel_col[y][x] = white;
            }
            out << pixel_col[y][x].r << std::endl;
            out << pixel_col[y][x].g << std::endl;
            out << pixel_col[y][x].b << std::endl;
        }
    }

    return 0;
}