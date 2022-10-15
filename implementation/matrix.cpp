#include "../header/matrix.hpp"

Matrix::Matrix() {}
Matrix::Matrix(int row, int col): row(row), col(col) { this->values.resize(row, std::vector<double>(col)); }

void Matrix::print(){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            std::cout << this->values[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::operator * (Matrix M) {  
    if(this->col != M.row) return Matrix(1, 1);

    Matrix B(this->row, M.col);    

    for(int i = 0; i < this->row; i++)
        for(int j = 0; j < M.col; j++)
            for(int k = 0; k < M.row; k++)
                B.values[i][j] += this->values[i][k]*M.values[k][j];
    return B;
}

Vector Matrix::matrix_to_vector() {
    Vector v;
    v.set_x(this->values[0][0]);
    v.set_y(this->values[1][0]);
    v.set_z(this->values[2][0]);
    v.set_a(this->values[3][0]);
    return v;
}

Matrix Matrix::vector_to_matrix(Vector v) {
    Matrix M(4, 1);
    M.values[0][0] = v.get_x();
    M.values[1][0] = v.get_y();
    M.values[2][0] = v.get_z();
    M.values[3][0] = 1;
    return M;
}

Matrix Matrix::identity(int size) {
    Matrix M(size, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == j) M.values[i][j] = 1.;
            else M.values[i][j] = 0.;
        }
    }
    return M;
}

Matrix Matrix::rotation_x_matrix(double angle) {
    Matrix M(4, 4);
    M.values[0] = {1., 0., 0. , 0.};
    M.values[1] = {0., std::cos(angle), -std::sin(angle), 0.};
    M.values[2] = {0., std::sin(angle),  std::cos(angle), 0.};
    M.values[3] = {0., 0., 0. , 1.};
    return M;
}

Matrix Matrix::rotation_y_matrix(double angle) {
    Matrix M(4, 4);
    M.values[0] = { std::cos(angle), 0., std::sin(angle), 0.};
    M.values[1] = {0., 1., 0., 0.};
    M.values[2] = {-std::sin(angle), 0., std::cos(angle), 0.};
    M.values[3] = {0., 0., 0. , 1.};
    return M;
}

Matrix Matrix::rotation_z_matrix(double angle) {
    Matrix M(4, 4);
    M.values[0] = {std::cos(angle), -std::sin(angle), 0.};
    M.values[1] = {std::sin(angle),  std::cos(angle), 0.};
    M.values[2] = {0., 0., 1., 0.};
    M.values[3] = {0., 0., 0., 1.};
    return M;
}

Matrix Matrix::translation_matrix(Vector v) {
    Matrix M(4, 4);
    M.values[0] = {1., 0., 0., v.get_x()};
    M.values[1] = {0., 1., 0., v.get_y()};
    M.values[2] = {0., 0., 1., v.get_z()};
    M.values[3] = {0., 0., 0., 1.};
    return M;
}

Matrix Matrix::scaling_matrix(double x, double y, double z) {
    Matrix M(4, 4);
    M.values[0] = {x , 0., 0., 0.};
    M.values[1] = {0., y , 0., 0.};
    M.values[2] = {0., 0., z , 0.};
    M.values[3] = {0., 0., 0., 1.};
    return M;
}

std::vector<std::vector<double>> Matrix::get_values() { return this->values; }
void Matrix::set_values(std::vector<std::vector<double>> v) { values =  v; }

int Matrix::get_row() { return this->row; }
void Matrix::set_row(int row) { this->row = row; }

int Matrix::get_col() { return this->col; }
void Matrix::set_col(int col) { this->col = col; }