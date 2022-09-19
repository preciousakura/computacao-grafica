#include "header/vector.hpp"
#include "header/color.hpp"
#include "header/viewport.hpp"
#include "header/canva.hpp"
#include "header/sphere.hpp"
#include "header/cone.hpp"
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

    double r = 40;
    
    scene.add_object(new Sphere(Vector(0, 0, -100), r, Color(0.7, 0.2, 0.2), Color(0.7, 0.2, 0.2), Color(0.7, 0.2, 0.2), 10)); 
    scene.add_object(new Cylinder(Vector(0, 0, -100), Vector(-1/sqrt(3), 1/sqrt(3), -1/sqrt(3)), r/3, 3 * r, Color(0.2, 0.3, 0.8), Color(0.2, 0.3, 0.8), Color(0.2, 0.3, 0.8), 10, true, true)); 
    scene.add_object(new Cone(Vector(-69.282, 69.282, -169.282), Vector(-1/sqrt(3.0), 1/sqrt(3.0), -1/sqrt(3.0)), 1.5*r, r/3, Color(0.8, 0.3, 0.2), Color(0.8, 0.3, 0.2), Color(0.8, 0.3, 0.2), 10, false));

    scene.add_object(new Plan(Vector(0, -40, 0), Vector(0, 1, 0), Color(0.2, 0.7, 0.2), Color(0.2, 0.7, 0.2), Color(0.0, 0.0, 0.0), 1));
    scene.add_object(new Plan(Vector(0, 0, -200), Vector(0, 0, 1), Color(0.3, 0.3, 0.7), Color(0.3, 0.3, 0.7), Color(0.0, 0.0, 0.0), 1));
    
    scene.add_light(new AmbientLight(Color(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Color(0.7, 0.7, 0.7), Vector(0, 60, -30))); 
    scene.add_light(new DirectionLight(Color(0.0, 0.0, 0.0), Vector(0, 0, 0))); 
     
    scene.draw_scenario(); 

    scene.save_scenario("sphere.png");
    return 0;
}
