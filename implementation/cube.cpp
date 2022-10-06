#include "../header/cube.hpp"

Cube::Cube() {}
Cube::Cube(Vector center, double size, Color kd, Color ka, Color ke, double s): size(size), Mesh(center, kd, ka, ke, s) { set_faces();}
Cube::Cube(Vector center, double size, const char* name, double s): size(size), Mesh(center, name, s) { set_faces();}

void Cube::set_faces() {
    std::vector<Vector> vertices = {  
        Vector(this->center.get_x() - this->size/2, this->center.get_y() - this->size/2, this->center.get_z() + this->size/2),
        Vector(this->center.get_x() + this->size/2, this->center.get_y() - this->size/2, this->center.get_z() + this->size/2),
        Vector(this->center.get_x() + this->size/2, this->center.get_y() + this->size/2, this->center.get_z() + this->size/2),
        Vector(this->center.get_x() - this->size/2, this->center.get_y() + this->size/2, this->center.get_z() + this->size/2),
        Vector(this->center.get_x() - this->size/2, this->center.get_y() + this->size/2, this->center.get_z() - this->size/2),
        Vector(this->center.get_x() - this->size/2, this->center.get_y() - this->size/2, this->center.get_z() - this->size/2),
        Vector(this->center.get_x() + this->size/2, this->center.get_y() - this->size/2, this->center.get_z() - this->size/2),
        Vector(this->center.get_x() + this->size/2, this->center.get_y() + this->size/2, this->center.get_z() - this->size/2)
    };
    
    this->faces = {
        new Face(vertices[0], vertices[1], vertices[3]), new Face(vertices[1], vertices[2], vertices[3]),
        new Face(vertices[1], vertices[6], vertices[2]), new Face(vertices[2], vertices[6], vertices[7]),
        new Face(vertices[5], vertices[7], vertices[6]), new Face(vertices[5], vertices[4], vertices[7]),
        new Face(vertices[0], vertices[4], vertices[5]), new Face(vertices[3], vertices[4], vertices[0]),
        new Face(vertices[4], vertices[2], vertices[7]), new Face(vertices[4], vertices[3], vertices[2]),
        new Face(vertices[0], vertices[5], vertices[1]), new Face(vertices[1], vertices[5], vertices[6])
    };
}

void Cube::set_size(double size) { this->size = size; }
int Cube::get_size() { return this->size; }