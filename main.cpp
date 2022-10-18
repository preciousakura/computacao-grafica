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
    Viewport viewport(60, 60, -50);
    Canva canva(500, 500, Color::convert_rgb(100, 100, 100)); 

    Scene scene(O, viewport, canva);

    // teto forro
    
    Cube *left_roof = new Cube(Color(Color::convert_rgb(214, 214, 214)), Color(Color::convert_rgb(214, 214, 214)), Color(Color::convert_rgb(214, 214, 214)), 10);
    Cube *right_roof = new Cube(Color(Color::convert_rgb(214, 214, 214)), Color(Color::convert_rgb(214, 214, 214)), Color(Color::convert_rgb(214, 214, 214)), 10);

    left_roof->scaling(300, 50, 970);
    left_roof->shearing_yx(0.75);
    left_roof->translate(Vector(-150, 363, -665));

    right_roof->scaling(300, 50, 970);
    right_roof->shearing_yx(0.75);
    right_roof->translate(Vector(-150, 363, -665));
    right_roof->reflection_yz();

    scene.add_object(left_roof);
    scene.add_object(right_roof);

    // teto frontal

    Cube *front_left_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);
    Cube *front_right_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);

    front_left_roof->scaling(300, 50, 30);
    front_left_roof->shearing_yx(0.75);
    front_left_roof->translate(Vector(-150, 363, -165));

    front_right_roof->scaling(300, 50, 30);
    front_right_roof->shearing_yx(0.75);
    front_right_roof->translate(Vector(-150, 363, -165));
    front_right_roof->reflection_yz();
    
    scene.add_object(front_left_roof);
    scene.add_object(front_right_roof);

    // teto traseiro

    Cube *back_left_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);
    Cube *back_right_roof = new Cube(Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), Color(0.5882, 0.2941, 0), 10);

    back_left_roof->scaling(300, 50, 30);
    back_left_roof->shearing_yx(0.75);
    back_left_roof->translate(Vector(-150, 363, -1165));

    back_right_roof->scaling(300, 50, 30);
    back_right_roof->shearing_yx(0.75);
    back_right_roof->translate(Vector(-150, 363, -1165));
    back_right_roof->reflection_yz();

    
    scene.add_object(back_left_roof);
    scene.add_object(back_right_roof);

    // vigas frontais

    Cube *front_left_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);
    Cube *front_right_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);

    front_left_beam->scaling(50, 500, 30);
    front_left_beam->translate(Vector(-325, 0, -165));

    front_right_beam->scaling(50, 500, 30);
    front_right_beam->translate(Vector(325, 0, -165));

    scene.add_object(front_left_beam);
    scene.add_object(front_right_beam);

    // // vigas traseiras

    Cube *back_left_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);
    Cube *back_right_beam = new Cube(Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), Color(0.3725, 0.3058, 0.2784), 10);

    back_left_beam->scaling(50, 500, 30);
    back_left_beam->translate(Vector(-325, -0, -1165));

    back_right_beam->scaling(50, 500, 30);
    back_right_beam->translate(Vector(325, -0, -1165));

    scene.add_object(back_left_beam);
    scene.add_object(back_right_beam);

    // mesa

    Cube *table = new Cube(Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), 10);

    table->scaling(250, 5, 150);
    table->translate(Vector(0, -151, -665));

    scene.add_object(table);

    Cube *left_suport = new Cube(Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), 10);

    left_suport->scaling(5, 95, 150);
    left_suport->translate(Vector(-122.5, -202.5, -665));

    scene.add_object(left_suport);

    Cube *right_suport = new Cube(Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), 10);

    right_suport->scaling(5, 95, 150);
    right_suport->translate(Vector(122.5, -202.5, -665));

    scene.add_object(right_suport);

    // árvore de natal

    Sphere *ball_tree = new Sphere(Vector(0, 50, -665), 4.5, Color(1, 1, 0), Color(1, 1, 0), Color(1, 1, 0), 10);
    scene.add_object(ball_tree);

    Cone *tree = new Cone(Vector(0, -100, -665), Vector(0, 1, 0), 60, 150, Color(Color::convert_rgb(33, 112, 48)), Color(Color::convert_rgb(33, 112, 48)), Color(Color::convert_rgb(33, 112, 48)), 10, true);
    scene.add_object(tree);

    Cylinder *suport_tree = new Cylinder(Vector(0, -140, -665), Vector(0, 1, 0), 6, 40, Color(Color::convert_rgb(92, 79, 69)), Color(Color::convert_rgb(92, 79, 69)), Color(Color::convert_rgb(92, 79, 69)), 10, true, true);
    scene.add_object(suport_tree);

    Cylinder *suport_tree_table = new Cylinder(Vector(0, -148, -665), Vector(0, 1, 0), 30, 9, Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), Color(Color::convert_rgb(92, 63, 41)), 10, true, true);
    scene.add_object(suport_tree_table);

    Plan *floor = new Plan(Vector(0, -250, -165), Vector(0, 1, 0), Color(Color::convert_rgb(59, 158, 56)), Color(Color::convert_rgb(59, 158, 56)), Color(Color::convert_rgb(59, 158, 56)), 10);
    scene.add_object(floor);

    Plan *wall = new Plan(Vector(0, 0, -4000), Vector(0, 0, 1), "utils/montanhas.jpg", 10);
    scene.add_object(wall);

    // scene.lookAt(Vector(0, 800, -665), Vector(0, 0, -665), Vector(0, 800, -800)); // CIMA
    scene.lookAt(Vector(0, 0, 0), Vector(0, 0, -165), Vector(0, 90, -165)); // FRENTE
    // scene.lookAt(Vector(665, 0, -665), Vector(0, 0, -165), Vector(665, 90, -665)); // DIREITA
    
    scene.add_light(new AmbientLight(Color(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Color(1, 1, 0.7), Vector(0, 2000, 0))); 
    scene.add_light(new SpotLight(Color(1, 1, 0.7), Vector(0, 380, -665), Vector(0, -1, 0), 0.4)); 

    scene.draw_scenario(); 

    scene.save_scenario("out.png");
    return 0;
}
