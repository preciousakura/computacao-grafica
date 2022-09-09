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
    Viewport viewport(60, 60, -30);
    Canva canva(500, 500, Color::convert_rgb(100, 100, 100)); 

    Scene scene(O, viewport, canva);
    
    scene.add_sphere(Sphere(Vector(0, 0, -100), 40, 10, Color(0.7, 0.2, 0.2))); 

    scene.add_plan(Plan(Vector(0, -40, 0), Vector(0, 1, 0), Color(0.2, 0.7, 0.2), 1));
    scene.add_plan(Plan(Vector(0, 0, -200), Vector(0, 0, 1), Color(0.3, 0.3, 0.7), 1));
    
    scene.add_light(new AmbientLight(Vector(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Vector(0.7, 0.7, 0.7), Vector(0, 60, -30))); 
    scene.add_light(new DirectionLight(Vector(0.0, 0.0, 0.0), Vector(0, 0, 0))); 
     
    scene.draw_scenario(); 

    scene.save_scenario("sphere.png");

    return 0;
}
