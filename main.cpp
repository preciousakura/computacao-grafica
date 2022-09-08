#include "header/vector.hpp"
#include "header/color.hpp"
#include "header/viewport.hpp"
#include "header/canva.hpp"
#include "header/sphere.hpp"
#include "header/scene.hpp"
#include "header/light.hpp"
#include "header/ambient_light.hpp"
#include "header/point_light.hpp"
#include "header/direction_light.hpp"

#include <iostream>
using namespace std;

int main(){
    Vector O(0, 0, 0); 
    Viewport viewport(1, 1, 1);
    Canva canva(500, 500, Color::convert_rgb(255, 255, 255)); 

    Scene scene(O, viewport, canva);
    
    scene.add_sphere(Sphere(Vector(0, -1, 3), 1, 500, Color::convert_rgb(255, 0, 0))); 
    scene.add_sphere(Sphere(Vector(2, 0, 4), 1, 500, Color::convert_rgb(0, 0, 255))); 
    scene.add_sphere(Sphere(Vector(-2, 0, 4), 1, 10, Color::convert_rgb(0, 255, 0))); 
    scene.add_sphere(Sphere(Vector(0, -5001, 0), 5000, 1000, Color::convert_rgb(255, 255, 0))); 
    
    scene.add_light(new AmbientLight(0.2)); 
    scene.add_light(new PointLight(0.6, Vector(2, 1, 0))); 
    scene.add_light(new DirectionLight(0.2, Vector(1, 4, 4))); 
     
    scene.draw_scenario(); 

    scene.save_scenario("sphere.png");

    return 0;
}
