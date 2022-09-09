#include <cmath>
#include "../header/object.hpp"

Object::Object(){}
Object::Object(Color kd, Color ka, Color ke, double s) : kd(kd), ka(ka), ke(ke), specular(s) {}

void Object::set_kd(Color color){ this->kd = kd; }
Color Object::get_kd(){ return kd; }
void Object::set_ka(Color color){ this->ka = ka; }
Color Object::get_ka(){ return ka; }
void Object::set_ke(Color color){ this->ke = ke; }
Color Object::get_ke(){ return ke; }

double Object::get_specular(){ return specular; }
void Object::set_specular(double specular){ this->specular = specular; }
