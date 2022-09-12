#include "header/vector.hpp"
#include "header/color.hpp"
#include "header/viewport.hpp"
#include "header/canva.hpp"
#include "header/sphere.hpp"
#include "header/scene.hpp"
#include "header/light.hpp"
#include "header/cylinder.hpp"
#include "header/ambient_light.hpp"
#include "header/point_light.hpp"
#include "header/direction_light.hpp"

#include <iostream>
using namespace std;

int main() {
    Vector O(0, 0, 0); 
    Viewport viewport(60, 60, -30);
    Canva canva(500, 500, Color::convert_rgb(100, 100, 100)); 

    Scene scene(O, viewport, canva);
    
    // scene.add_object(new Sphere(Vector(0, 0, -100), 40, Color(0.7, 0.2, 0.2), Color(0.7, 0.2, 0.2), Color(0.7, 0.2, 0.2), 10)); 
    scene.add_object(new Cylinder(Vector(0, 0, -100), Vector(0, 1, 1), 36, 30, Color(0.7, 0.2, 0.2), Color(0.7, 0.2, 0.2), Color(0.7, 0.2, 0.2), 10)); 

    scene.add_object(new Plan(Vector(0, -40, 0), Vector(0, 1, 0), Color(0.2, 0.7, 0.2), Color(0.2, 0.7, 0.2), Color(0.0, 0.0, 0.0), 1));
    scene.add_object(new Plan(Vector(0, 0, -200), Vector(0, 0, 1), Color(0.3, 0.3, 0.7), Color(0.3, 0.3, 0.7), Color(0.0, 0.0, 0.0), 1));
    
    scene.add_light(new AmbientLight(Color(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Color(0.7, 0.7, 0.7), Vector(0, 60, -30))); 
    scene.add_light(new DirectionLight(Color(0.0, 0.0, 0.0), Vector(0, 0, 0))); 
     
    scene.draw_scenario(); 

    scene.save_scenario("sphere.png");
    return 0;
}
