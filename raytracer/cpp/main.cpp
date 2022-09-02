#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define CHANNEL_NUM 3

#include "utils.cpp"
#include "stb_image.hpp"
#include "stb_image_write.hpp"

using namespace std;
typedef unsigned char int8;

int main() {
    Viewport vp(1.0, 1.0, 1.0);

    std::vector<Sphere> spheres;
    
    Sphere red(Vector(0, -1, 3), 1, 500, Color::convert_rgb(255, 0, 0));
    Sphere blue(Vector(2, 0, 4), 1, 500, Color::convert_rgb(0, 0, 255));
    Sphere green(Vector(-2, 0, 4), 1, 10, Color::convert_rgb(0, 255, 0));
    Sphere yellow(Vector(0, -5001, 0), 5000, 1000, Color::convert_rgb(255, 255, 0));

    spheres.push_back(red);
    spheres.push_back(blue);
    spheres.push_back(green);
    spheres.push_back(yellow);

    std::vector<Light> lights;

    Light a_light(0.2, LightType::ambient);
    Light p_light(0.6, LightType::point, Vector(2, 1, 0));
    Light d_light(0.2, LightType::directional, Vector(1, 4, 4));

    lights.push_back(a_light);
    lights.push_back(p_light);
    lights.push_back(d_light);

    Canvas canva(500, 500, vp, Color::convert_rgb(255, 255, 255));
    Scene scene(lights, spheres, Vector(0, 0, 0), canva);

    int8 *imageW = new int8[canva.w * canva.h * CHANNEL_NUM];
    for(int x = 0, c = 0; x < canva.w; x++){
        for(int y = 0; y < canva.h; y++) {
            Vector d = canva.canvasToViewport(x, y);
            Color color = scene.traceRay(d, 1.0, INFINITY);
            imageW[c++] = color.convert_r(), imageW[c++] = color.convert_g(), imageW[c++] = color.convert_b();
        }
    }
    stbi_write_png("out.png", canva.w, canva.h, CHANNEL_NUM, imageW, canva.w * CHANNEL_NUM);
    return 0;
}