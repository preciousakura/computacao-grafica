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
    
    scene.add_object(new Sphere(Vector(0, 95, -200), 5, Color(0.854, 0.647, 0.125), Color(0.854, 0.647, 0.125), Color(0.854, 0.647, 0.125), 10)); 
    Cube *cb = new Cube(Color(1., 0.078, 0.576), Color(1., 0.078, 0.576), Color(1., 0.078, 0.576), 10);
    cb->scaling(40, 40, 40);
    cb->transform();
    cb->translate(Vector(0, -150, -165));
    scene.add_object(cb);
    scene.add_object(new Cone(Vector(0, -60, -200), Vector(0., 1., 0), 90, 150, Color(0., 1., 0.498), Color(0., 1., 0.498), Color(0., 1., 0.498), 10, false));
    scene.add_object(new Cylinder(Vector(0, -150, -200), Vector(0., 1., 0), 5, 90, Color(0.824, 0.706, 0.549), Color(0.824, 0.706, 0.549), Color(0.824, 0.706, 0.549), 10, true, true)); 

    scene.add_object(new Plan(Vector(0, -150, 0), Vector(0, 1, 0), Color(0.5, 0.5, 0.5), Color(0.5, 0.5, 0.5), Color(0.5, 0.5, 0.5), 1));
    scene.add_object(new Plan(Vector(200, -150, 0), Vector(-1., 0., 0), Color(0.686, 0.933, 0.933), Color(0.686, 0.933, 0.933), Color(0.686, 0.933, 0.933), 1));
    scene.add_object(new Plan(Vector(200, -150, -400), Vector(0., 0., 1), Color(0.686, 0.933, 0.933), Color(0.686, 0.933, 0.933), Color(0.686, 0.933, 0.933), 1));
    scene.add_object(new Plan(Vector(-200, -150, 0), Vector(1., 0., 0.), Color(0.933, 0.933, 0.933), Color(0.933, 0.933, 0.933), Color(00.933, 0.933, 0.933), 1));
    scene.add_object(new Plan(Vector(0, 150, 0), Vector(0., -1., 0.), Color(0.933, 0.933, 0.933), Color(0.933, 0.933, 0.933), Color(0.933, 0.933, 0.933), 1));

    scene.add_light(new AmbientLight(Color(0.3, 0.3, 0.3))); 
    scene.add_light(new PointLight(Color(0.7, 0.7, 0.7), Vector(-100, 140, -20))); 
    scene.add_light(new DirectionLight(Color(0.0, 0.0, 0.0), Vector(0, 0, 0))); 

    // scene.lookAt(Vector(0, 800, -665), Vector(0, 0, -665), Vector(0, 800, -800)); // CIMA
    // scene.lookAt(Vector(0, 0, 0), Vector(0, 0, -165), Vector(0, 90, -165)); // FRENTE
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
