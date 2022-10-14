#ifndef VECTOR_HPP
#define VECTOR_HPP

#define EPS 0.0000001
#define INF 1e18

class Vector {
    private:
        double x, y, z, a;
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(double x, double y, double z, double a);

        Vector operator * (double n);
        Vector operator % (Vector n);
        double operator * (Vector v); 
        Vector operator / (double n);
        Vector operator - (Vector v);
        Vector operator - (); 
        Vector operator + (Vector v);
        double operator ~ (); 

        double get_x();
        void set_x(double x);
        double get_y();
        void set_y(double y);
        double get_z();
        void set_z(double z);
        double get_a();
        void set_a(double a);
};

#endif