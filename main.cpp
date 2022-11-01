#include "header/vector.hpp"
#include "header/color.hpp"
#include "header/viewport.hpp"
#include "header/canva.hpp"
#include "header/sphere.hpp"
#include "header/cone.hpp"
#include "header/scene.hpp"
#include "header/light.hpp"
#include "header/spot_light.hpp"
#include "header/SDLEngine.hpp"
#include "header/cylinder.hpp"
#include "header/ambient_light.hpp"
#include "header/point_light.hpp"
#include "header/cube.hpp"
#include "header/direction_light.hpp"

#define LARGURA_TELA 500
#define ALTURA_TELA  500
#define LARGURA_CANVAS 500
#define ALTURA_CANVAS  500

#include <iostream>
using namespace std;

int main() {
    Vector O(0, 0, 0); 
    Viewport viewport(60, 60, -20);
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

    Plan *floor = new Plan(Vector(0, -255, -165), Vector(0, 1, 0), "utils/grama.jpg", 10);
    scene.add_object(floor);

    scene.add_light(new PointLight(Color(1, 1, 0.7), Vector(300, 1000, -665))); 
    scene.add_light(new AmbientLight(Color(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Color(0.3, 0.3, 0.3), Vector(0, 0, -40))); 
    scene.add_light(new SpotLight(Color(1, 1, 0.7), Vector(0, 380, -665), Vector(0, -1, 0), 0.4)); 

    scene.lookAt(Vector(600, 0, -665), Vector(0, 0, -665), Vector(600, 500, -665)); // FRENTE
    // scene.lookAt(Vector(0, 800, -665), Vector(0, 0, -665), Vector(0, 800, -800)); // CIMA
    // scene.lookAt(Vector(-1000, 250, -500), Vector(0, 250, -500), Vector(0, 500, -500)); // FRENTE
    // scene.lookAt(Vector(665, 0, -665), Vector(0, 0, -165), Vector(665, 90, -665)); // DIREITA
    scene.draw_scenario(); 

    scene.save_scenario("out.png");

    SDLEngine sdlEngine{ "IMAGEM", 
                        LARGURA_TELA, ALTURA_TELA, 
                        LARGURA_CANVAS, ALTURA_CANVAS
    };
    
    SDL_Event e;
    bool quit = false;
    bool teste = true;
    int testeNum = 0; 

    std::set<Object*> objs_selected;

    int i, j;
    
    sdlEngine.atualizarCanvas( scene, nullptr, objs_selected );
    sdlEngine.atualizarJanela();

    Object* obj_selected;

    while (!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) quit = true;
            if(SDL_MOUSEBUTTONDOWN == e.type) {
                if(SDL_BUTTON_LEFT == e.button.button){
                    SDL_GetMouseState(&j, &i);
                    obj_selected = scene.picking(i, j); 

                    if(obj_selected == nullptr){
                        std::cout << "NENHUM OBJETO SELECIONADO\n";  
                        continue;
                    }

                    sdlEngine.atualizarCanvas( scene, obj_selected, objs_selected );
                    sdlEngine.atualizarJanela();

                    int op;
                    std::cout << " --- MENU DE OPCOES ---\n";
                    std::cout << "(1) - Translação\n";
                    std::cout << "(2) - Rotação\n";
                    std::cout << "(3) - Espelhamento\n";
                    std::cout << "(4) - Escalonamento\n";
                    std::cout << "(5) - Cisalhamento\n";
                    std::cout << "(6) - Mudar Coloração\n";
                    std::cout << "(7) - Deletar\n";
                    std::cout << "(8) - Selecionar/Deselecionar Objetos\n";
                    cout << "Digite a sua opção: "; cin >> op;

                    if(op == 1) {
                        int i, j, k;
                        std::cout << "Digite o local de translação: "; cin >> i >> j >> k;
                        for(Object *o : objs_selected) o->translate(Vector(i, j, k));
                    }
                    else if(op == 2) {
                        std::cout << " --- MENU DE ROTAÇÕES ---\n";
                        std::cout << "(1) - Rotação no Eixo X\n";
                        std::cout << "(2) - Rotação no Eixo Y\n";
                        std::cout << "(3) - Rotação no Eixo Z\n";

                        cout << "Digite a sua opção: "; cin >> op;

                        double angle;
                        std::cout << "Digite o ângulo da rotação (em radianos): "; cin >> angle;

                        if(op == 1) for(Object *o : objs_selected) o->rotation_x(angle);
                        else if(op == 2) for(Object *o : objs_selected) o->rotation_y(angle);
                        else if(op == 3) for(Object *o : objs_selected) o->rotation_z(angle);

                    }
                    else if(op == 3) {
                        std::cout << " --- MENU DE ESPELHAMENTO ---\n";
                        std::cout << "(1) - Espelhamento no plano XY\n";
                        std::cout << "(2) - Espelhamento no plano XZ\n";
                        std::cout << "(3) - Espelhamento no plano YZ\n";
                        std::cout << "(4) - Espelhamento no plano arbitrário\n";
                        cout << "Digite a sua opção: "; cin >> op;

                        if(op == 1) for(Object *o : objs_selected) o->reflection_xy();
                        else if(op == 2) for(Object *o : objs_selected) o->reflection_xz();
                        else if(op == 3) for(Object *o : objs_selected) o->reflection_yz();
                        else {
                            double i, j, k;
                            std::cout << "Digite o vetor normal ao plano: "; cin >> i >> j >> k; Vector n(i, j, k);
                            std::cout << "Digite o ponto que pertencem ao plano: "; cin >> i >> j >> k; Vector p(i, j, k);
                            for(Object *o : objs_selected) o->reflection_at(n, p);
                        }
                    }
                    else if(op == 4) {
                        double i, j, k;
                        std::cout << "Digite o tamanho do objeto: "; cin >> i >> j >> k; 
                        for(Object *o : objs_selected) o->scaling(i, j, k);
                    }
                    else if(op == 5) {
                        std::cout << " --- MENU DE CISALHAMENTO ---\n";
                        std::cout << "(1) - Cisalhamento XY\n";
                        std::cout << "(2) - Cisalhamento YX\n";
                        std::cout << "(3) - Cisalhamento XZ\n";
                        std::cout << "(4) - Cisalhamento ZX\n";
                        std::cout << "(5) - Cisalhamento YZ\n";
                        std::cout << "(6) - Cisalhamento ZY\n";
                        cout << "Digite a sua opção: "; cin >> op;

                        double angle;

                        std::cout << "Digite o ângulo do cisalhamento(em radianos): "; cin >> angle;
                        if(op == 1) for(Object* o : objs_selected) o->shearing_xy(angle);                             
                        else if(op == 2) for(Object* o : objs_selected) o->shearing_yx(angle);                             
                        else if(op == 3) for(Object* o : objs_selected) o->shearing_xz(angle);                             
                        else if(op == 4) for(Object* o : objs_selected) o->shearing_zx(angle);                             
                        else if(op == 5) for(Object* o : objs_selected) o->shearing_yz(angle);                             
                        else for(Object* o : objs_selected) o->shearing_zy(angle);                             
                    }
                    else if(op == 6) {
                        double i, j, k;
                        std::cout << "Digite as intensidades do ka: "; cin >> i >> j >> k; Color ka(i, j, k);
                        std::cout << "Digite as intensidades do kd: "; cin >> i >> j >> k; Color kd(i, j, k);
                        std::cout << "Digite as intensidades do ks: "; cin >> i >> j >> k; Color ke(i, j, k);
                        for(Object* o : objs_selected){
                            o->set_ka(ka); 
                            o->set_kd(kd);
                            o->set_ke(ke);
                        }
                    }
                    else if(op == 7) for(Object* o : objs_selected) scene.erase_object(o); 
                    else continue;    
                    
                    scene.draw_scenario();
                    sdlEngine.atualizarCanvas(scene, obj_selected, objs_selected);
                    sdlEngine.atualizarJanela();
                
                }
            }
        }
    } 
    return 0;
}
