#include "../header/cube.hpp"

Cube::Cube() {}
Cube::Cube(Color kd, Color ka, Color ke, double s): size(1), Mesh(Vector(0, 0, 0, 1), kd, ka, ke, s) { set_faces();}
Cube::Cube(const char* name, double s): size(1), Mesh(Vector(0, 0, 0, 1), name, s) { set_faces();}

void Cube::set_faces() {
    std::vector<Vector*> vertices = {  
        new Vector(this->center.get_x() - this->size/2, this->center.get_y() - this->size/2, this->center.get_z() + this->size/2, 1.),
        new Vector(this->center.get_x() + this->size/2, this->center.get_y() - this->size/2, this->center.get_z() + this->size/2, 1.),
        new Vector(this->center.get_x() + this->size/2, this->center.get_y() + this->size/2, this->center.get_z() + this->size/2, 1.),
        new Vector(this->center.get_x() - this->size/2, this->center.get_y() + this->size/2, this->center.get_z() + this->size/2, 1.),
        new Vector(this->center.get_x() - this->size/2, this->center.get_y() + this->size/2, this->center.get_z() - this->size/2, 1.),
        new Vector(this->center.get_x() - this->size/2, this->center.get_y() - this->size/2, this->center.get_z() - this->size/2, 1.),
        new Vector(this->center.get_x() + this->size/2, this->center.get_y() - this->size/2, this->center.get_z() - this->size/2, 1.),
        new Vector(this->center.get_x() + this->size/2, this->center.get_y() + this->size/2, this->center.get_z() - this->size/2, 1.)
    };

    this->faces = {
        new Face(vertices[0], vertices[1], vertices[3]), new Face(vertices[1], vertices[2], vertices[3]),
        new Face(vertices[1], vertices[6], vertices[2]), new Face(vertices[2], vertices[6], vertices[7]),
        new Face(vertices[5], vertices[7], vertices[6]), new Face(vertices[5], vertices[4], vertices[7]),
        new Face(vertices[0], vertices[4], vertices[5]), new Face(vertices[3], vertices[4], vertices[0]),
        new Face(vertices[4], vertices[2], vertices[7]), new Face(vertices[4], vertices[3], vertices[2]),
        new Face(vertices[0], vertices[5], vertices[1]), new Face(vertices[1], vertices[5], vertices[6])
    };

    this->vertices = vertices;
}

void Cube::set_size(double size) { this->size = size; }
int Cube::get_size() { return this->size; }