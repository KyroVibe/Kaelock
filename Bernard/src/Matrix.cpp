#include "Matrix.hpp"

Matrix::Matrix(unsigned int rows, unsigned int columns): rows(rows), columns(columns) {
    mat = new double[rows * columns];
}

Matrix::~Matrix() {
    delete[] mat;
}
