#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define CHANNEL_NUM 3

#include "../header/canva.hpp"
#include "../header/stb_image.hpp"
#include "../header/stb_image_write.hpp"
#include <bits/stdc++.h>

Canva::Canva(){}
Canva::Canva(int n, int m, Color bg): w(n), h(m), background(bg), pixels(n, std::vector<Color>(m, bg)){}

void Canva::write_image(const char* image_name){
	int width = w, height = h;
  	int8 *imageW = new int8[width * height * CHANNEL_NUM];
	for(int i = 0, c = 0; i < height; i++)
		for(int j = 0; j < width; j++)
			imageW[c++] = pixels[i][j].convert_red(), imageW[c++] = pixels[i][j].convert_green(), imageW[c++] = pixels[i][j].convert_blue();
	stbi_write_png(image_name, width, height, CHANNEL_NUM, imageW, width * CHANNEL_NUM);
}

void Canva::to_color(int i, int j, Color color){ this->pixels[i][j] = color; }

int Canva::get_w(){ return this->w; }
void Canva::set_w(int w){ this->w = w; }
int Canva::get_h(){ return this->h; }
void Canva::set_h(int h){ this->h = h; }
Color Canva::get_background_color(){ return this->background; }
void Canva::set_background_color(Color background_color){ this->background = background_color; }
