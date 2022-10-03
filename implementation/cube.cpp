#include "../header/cube.hpp"

Cube::Cube() {}
Cube::Cube(Vector center, int size, Color kd, Color ka, Color ke, double s): size(size), Mesh(center, kd, ka, ke, s) {
    std::vector<Vector> vertices = {  
        Vector(center.get_x() - size/2, center.get_y() - size/2, center.get_z() + size/2),
        Vector(center.get_x() + size/2, center.get_y() - size/2, center.get_z() + size/2),
        Vector(center.get_x() + size/2, center.get_y() + size/2, center.get_z() + size/2),
        Vector(center.get_x() - size/2, center.get_y() + size/2, center.get_z() + size/2),
        Vector(center.get_x() - size/2, center.get_y() + size/2, center.get_z() - size/2),
        Vector(center.get_x() - size/2, center.get_y() - size/2, center.get_z() - size/2),
        Vector(center.get_x() + size/2, center.get_y() - size/2, center.get_z() - size/2),
        Vector(center.get_x() + size/2, center.get_y() + size/2, center.get_z() - size/2)
    };
    
    this->faces = {
        new Face(vertices[0], vertices[3], vertices[1]), new Face(vertices[1], vertices[2], vertices[3]),
        new Face(vertices[6], vertices[2], vertices[1]), new Face(vertices[6], vertices[7], vertices[2]),
        new Face(vertices[5], vertices[6], vertices[7]), new Face(vertices[7], vertices[4], vertices[5]),
        new Face(vertices[0], vertices[5], vertices[4]), new Face(vertices[4], vertices[3], vertices[0]),
        new Face(vertices[4], vertices[7], vertices[2]), new Face(vertices[4], vertices[3], vertices[2]),
        new Face(vertices[5], vertices[0], vertices[1]), new Face(vertices[1], vertices[6], vertices[5])
    };
}

void Cube::set_size(int size) { this->size = size; }
int Cube::get_size() { return this->size; }