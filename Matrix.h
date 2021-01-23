#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <time.h>

using namespace std;

template <class T>
class Matrix
{

private:
    int col;
    int row;
    T value;
    T **matrix;
    void setCol(int col);
    void setRow(int row);
    void setValue(T value);
    void CreateMatrix();
    void CreateRandomMatrix();
    void CreateUnitMatrix();
    bool CheckMatrix();


public:

    Matrix();
    Matrix(int row, int col, T dvalue);
    Matrix(int row, int col, char cvalue);
    ~Matrix();

    void MatrixResize(int,int);
    void MatrixPrint();
    void AllocateMatrix(int,int);
    void MatrixTranspose();
    void MatrixEmul(const Matrix<T>& other);
    double MatrixDeterminant();
    void MatrixPrint(string);
    void MatrixInverse();

    T getCol();
    T getRow();
    T getValue();

    Matrix<T>& operator+(const Matrix<T>& other);
    Matrix<T>& operator-(const Matrix<T>& other);
    Matrix<T>& operator*(const Matrix<T>& other);
    Matrix<T>& operator+(const T& val);
    Matrix<T>& operator-(const T& val);
    Matrix<T>& operator*(const T& val);
    Matrix<T>& operator/(const T& val);
    Matrix<T>& operator%(const T& val);
    Matrix<T>& operator^(const T& val);
};


#endif // MATRIX_H
