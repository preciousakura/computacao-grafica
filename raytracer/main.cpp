#include "utils.cpp"

int main() {
    std::vector<Sphere> spheres;
    
    Sphere red(Vector(0, -1, 3), 1, Color(255, 0, 0));
    Sphere blue(Vector(2, 0, 4), 1, Color(0, 0, 255));
    Sphere green(Vector(-2, 0, 4), 1, Color(0, 255, 0));

    spheres.push_back(red);
    spheres.push_back(blue);
    spheres.push_back(green);

    Viewport vp(1.0, 1.0, 1.0);
    Canvas canva(500.0, 500.0, vp, Color(0, 0, 0));
    Scene scene(spheres, Vector(0, 0, 0), canva);

    std::ofstream out("out.ppm");
    
    out << "P3";
    out << std::endl;
    out << canva.w << std::endl;
    out << canva.h << std::endl;
    out << 255 << std::endl;


    for(int x = 0; x < canva.w; x++){
        for(int y = 0; y < canva.h; y++) {
            Vector d = canva.canvasToViewport(x, y);
            Color color = scene.traceRay(d, 1.0, INFINITY);

            out << color.r << std::endl;
            out << color.g << std::endl;
            out << color.b << std::endl;
        }
    }

    out.close();
    return 0;
}