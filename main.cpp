#include "header/vector.hpp"
#include "header/color.hpp"
#include "header/viewport.hpp"
#include "header/canva.hpp"
#include "header/sphere.hpp"
#include "header/cone.hpp"
#include "header/scene.hpp"
#include "header/light.hpp"
#include "header/spot_light.hpp"
#include "header/cylinder.hpp"
#include "header/ambient_light.hpp"
#include "header/point_light.hpp"
#include "header/cube.hpp"
#include "header/direction_light.hpp"

#include <iostream>
using namespace std;

int main() {
    Vector O(0, 0, 0); 
    Viewport viewport(60, 60, -40);
    Canva canva(500, 500, Color::convert_rgb(100, 100, 100)); 

    Scene scene(O, viewport, canva);

 // teto forro
    
    Cube *left_roof = new Cube(Color(1., 0.078, 0.576), Color(1., 0.078, 0.576), Color(1., 0.078, 0.576), 10);
    Cube *right_roof = new Cube(Color(1., 0.078, 0.576), Color(1., 0.078, 0.576), Color(1., 0.078, 0.576), 10);

    left_roof->scaling(300, 50, 970);
    left_roof->shearing_yx(0.75);
    left_roof->translate(Vector(-125, 0, -665));

    right_roof->scaling(300, 50, 970);
    right_roof->shearing_yx(0.75);
    right_roof->translate(Vector(-175, 0, -665));
    right_roof->reflection_yz();

    scene.add_object(left_roof);
    scene.add_object(right_roof);

    // teto frontal

    Cube *front_left_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);
    Cube *front_right_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);

    front_left_roof->scaling(300, 50, 30);
    front_left_roof->shearing_yx(0.75);
    front_left_roof->translate(Vector(-125, 0, -165));

    front_right_roof->scaling(300, 50, 30);
    front_right_roof->shearing_yx(0.75);
    front_right_roof->translate(Vector(-175, 0, -165));
    front_right_roof->reflection_yz();

    
    scene.add_object(front_left_roof);
    scene.add_object(front_right_roof);

    // teto traseiro

    Cube *back_left_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);
    Cube *back_right_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);

    back_left_roof->scaling(300, 50, 30);
    back_left_roof->shearing_yx(0.75);
    back_left_roof->translate(Vector(-125, 0, -1165));

    back_right_roof->scaling(300, 50, 30);
    back_right_roof->shearing_yx(0.75);
    back_right_roof->translate(Vector(-175, 0, -1165));
    back_right_roof->reflection_yz();

    
    scene.add_object(back_left_roof);
    scene.add_object(back_right_roof);

    // vigas frontais

    Cube *front_left_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);
    Cube *front_right_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);

    front_left_beam->scaling(50, 500, 30);
    front_left_beam->translate(Vector(-300, -365, -165));

    front_right_beam->scaling(50, 500, 30);
    front_right_beam->translate(Vector(350, -365, -165));

    scene.add_object(front_left_beam);
    scene.add_object(front_right_beam);

    // vigas traseiras

    Cube *back_left_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);
    Cube *back_right_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);

    back_left_beam->scaling(50, 500, 30);
    back_left_beam->translate(Vector(-300, -365, -1165));

    back_right_beam->scaling(50, 500, 30);
    back_right_beam->translate(Vector(350, -365, -1165));

    scene.add_object(back_left_beam);
    scene.add_object(back_right_beam);

    scene.lookAt(Vector(0, 800, -665), Vector(0, 0, -665), Vector(0, 800, -800));
    
    scene.add_light(new AmbientLight(Color(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Color(0.7, 0.7, 0.7), Vector(0, 800, -20))); 

    scene.draw_scenario(); 

    scene.save_scenario("out.png");
    return 0;
}
