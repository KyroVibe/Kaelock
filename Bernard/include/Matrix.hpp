#ifndef BERNARD_QUICK_MATHS
#define BERNARD_QUICK_MATHS

class Matrix {
private:
    double* mat;
    unsigned int rows, columns;
public:
    Matrix(unsigned int rows, unsigned int columns);
    ~Matrix();
};

#endif
