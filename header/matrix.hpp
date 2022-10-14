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

        void print();

        Vector matrix_to_vector();
        static Matrix vector_to_matrix(Vector v);

        static Matrix identity(int size);

        static Matrix rotation_x_matrix(double angle);
        static Matrix rotation_y_matrix(double angle);
        static Matrix rotation_z_matrix(double angle);
        static Matrix translation_matrix(double x, double y, double z);
        static Matrix scaling_matrix(double x, double y, double z);

        std::vector<std::vector<double>> get_values();
        void set_values(std::vector<std::vector<double>> v);


        int get_row();
        void set_row(int row);

        int get_col();
        void set_col(int col);

        static Matrix rotation_x_matrix();
};

#endif