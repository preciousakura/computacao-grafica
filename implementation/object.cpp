#include <cmath>
#include <iostream>
#include "../header/object.hpp"
#include "../header/stb_image.hpp"
#include "../header/stb_image_write.hpp"

Object::Object(){}
Object::Object(Color kd, Color ka, Color ke, double s) : kd(kd), ka(ka), ke(ke), specular(s) {}

Object::Object(const char* name, double s) { 
    this->has_img = true;
    this->specular = s;
    int8* image = stbi_load(name, &this->width, &this->height, &this->channel, 0);
    if(image == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    this->image_pixels.resize(this->height, std::vector<Color>(this->width));

    double r, g, b;
    for(int i = 0, c = 0; i < this->height; i++)  {
        for(int j = 0; j < this->width; j++) {
            r = 1.0 * image[c++]/255, g = 1.0 * image[c++]/255, b = 1.0 * image[c++]/255;
            this->image_pixels[i][j] = Color(r, g, b);
        }
    }
    stbi_image_free(image);
}

void Object::set_kd(Color color){ this->kd = kd; }
Color Object::get_kd(){ return kd; }
void Object::set_ka(Color color){ this->ka = ka; }
Color Object::get_ka(){ return ka; }
void Object::set_ke(Color color){ this->ke = ke; }
Color Object::get_ke(){ return ke; }

double Object::get_specular(){ return specular; }
void Object::set_specular(double specular){ this->specular = specular; }

// imagens

bool Object::has_image() { return this->has_img; }
int Object::get_width() { return this->width; }
void Object::set_width(int w) { this->width = w; }
int Object::get_height() { return this->height; }
void Object::set_height(int h) { this->height = h; }
void Object::set_current_color(int i, int j) { this->current_color = this->image_pixels[i%this->height][j%this->width]; }
Color Object::get_current_color() { return this->current_color; }