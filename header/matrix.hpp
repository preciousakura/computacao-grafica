#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include <vector>

#include <cmath>
#include <iostream>

class Matrix {
    private:
        int row, col;
        std::vector<std::vector<double>> values;
    public:
        Matrix();
        Matrix(int row, int col);

        Matrix operator * (Matrix m);
        Matrix operator * (double e);
        Matrix operator - (Matrix m);
        Matrix operator - ();
        Matrix operator ~ ();

        void print();

        Vector matrix_to_vector();
        static Matrix vector_to_matrix(Vector v, bool ponto = true);

        static Matrix identity(int size);

        static Matrix rotation_x_matrix(double angle);
        static Matrix rotation_y_matrix(double angle);
        static Matrix rotation_z_matrix(double angle);
        static Matrix translation_matrix(Vector v);
        static Matrix scaling_matrix(double x, double y, double z);
        static Matrix shearing_xy_matrix(double angle);
        static Matrix shearing_xz_matrix(double angle);
        static Matrix shearing_yx_matrix(double angle);
        static Matrix shearing_yz_matrix(double angle);
        static Matrix shearing_zx_matrix(double angle);
        static Matrix shearing_zy_matrix(double angle);

        static Matrix reflection_xy_matrix();
        static Matrix reflection_yz_matrix();
        static Matrix reflection_xz_matrix();

        static Matrix householder_matrix(Vector n);
        static Matrix reflection_at_matrix(Vector p, Vector n);

        static Matrix world_to_camera_matrix(Vector e, Vector at, Vector up);
        static Matrix camera_to_world_matrix(Vector e, Vector at, Vector up);

        std::vector<std::vector<double>> get_values();
        void set_values(std::vector<std::vector<double>> v);


        int get_row();
        void set_row(int row);

        int get_col();
        void set_col(int col);

        static Matrix rotation_x_matrix();
};

#endif