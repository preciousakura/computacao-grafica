#include "../header/color.hpp"
#include <algorithm>

Color::Color(){ r = g = b = 0; } 
Color::Color(double r, double g, double b): r(std::min(r, 1.0)), g(std::min(g, 1.0)), b(std::min(b, 1.0)){}

Color Color::operator*(double alp){ return Color(alp*this->r, alp*this->g, alp*this->b); }
Color Color::operator*(Color c){ return Color(c.get_r()*this->r, c.get_g()*this->g, c.get_b()*this->b); }
Color Color::operator/(double n){ return Color(1.0 * this->r/n, 1.0 * this->g/n, 1.0 * this->b/n); }
Color Color::operator+(Color c){ return Color(c.get_r() + this->r, c.get_g() + this->g, c.get_b() + this->b); }

unsigned int Color::convert_red() { return r * 255;}
unsigned int Color::convert_green(){ return g * 255; }
unsigned int Color::convert_blue(){ return b * 255; }

double Color::get_r(){ return this->r; }
void Color::set_r(double r) { this->r = r; }
double Color::get_g(){ return this->g; }
void Color::set_g(double g) { this->g = g; }
double Color::get_b(){ return this->b; }
void Color::set_b(double b) { this->b = b; }
