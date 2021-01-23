#include "Matrix.h"
#include <iostream>
#include <time.h>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;

template <class T>
Matrix<T>::Matrix()
{
    setRow(10);
    setCol(10);
    setValue(0.0);
    CreateMatrix();
}

template <class T>
Matrix<T>::Matrix(int row, int col, T value)
{
    setRow(row);
    setCol(col);
    setValue(value);
    CreateMatrix();
}

template <class T>
Matrix<T>::Matrix(int row, int col, char cvalue)
{
    setRow(row);
    setCol(col);
    if (cvalue == 'e')
    {
        CreateUnitMatrix();
    }
    else if (cvalue == 'r')
    {
        CreateRandomMatrix();
    }
    else
        cout << "Hatalı istek!" << endl;
}

template <class T>
Matrix<T>::~Matrix()
{
}

template <class T>
void Matrix<T>::setRow(int row)
{
    this->row = row;
}

template <class T>
void Matrix<T>::setCol(int col)
{
    this->col = col;
}

template <class T>
void Matrix<T>::setValue(T value)
{
    this->value = value;
}

template <class T>
T Matrix<T>::getRow()
{
    return row;
}

template <class T>
T Matrix<T>::getCol()
{
    return col;
}

template <class T>
T Matrix<T>::getValue()
{
    return value;
}

template <class T>
void Matrix<T>::CreateMatrix()
{
    int _row = getRow();
    int _col = getCol();
    T _value = getValue();
    AllocateMatrix(_row, _col);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            this->matrix[i][j] = _value;
        }
    }
}

template <class T>
void Matrix<T>::CreateUnitMatrix()
{
    int _row = getRow();
    int _col = getCol();

    if (_row == _col)
    {
        AllocateMatrix(_row, _col);
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                if (i == j)
                    this->matrix[i][j] = 1.0;
                else
                    this->matrix[i][j] = 0.0;
            }
        }
    }
    else
        cout << "Satir Sutun Esit Degil!" << endl;
}

template <class T>
void Matrix<T>::CreateRandomMatrix()
{
    int _row = getRow();
    int _col = getCol();
    AllocateMatrix(_row, _col);
    srand(time(NULL));
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            this->matrix[i][j] = rand() % 255;
        }
    }
}

template <class T>
void Matrix<T>::AllocateMatrix(int _row, int _col)
{
    this->matrix = new int *[_row];
    for (int i = 0; i < _row; i++)
    {
        this->matrix[i] = new int[_col];
    }
}

template <class T>
void Matrix<T>::MatrixPrint()
{
    int _row = getRow();
    int _col = getCol();
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            cout << this->matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

template <class T>
void Matrix<T>::MatrixResize(int _newRow, int _newCol)
{
    int _row = getRow();
    int _col = getCol();

    if (_row > _newRow)
    {
        setRow(_newRow);
    }
    if (_col > _newCol)
    {
        setCol(_newCol);
    }

    _row = getRow();
    _col = getCol();
    Matrix<int> *temp = new Matrix<int>(_newRow, _newCol, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j];
        }
    }

    setRow(_newRow);
    setCol(_newCol);
    AllocateMatrix(_newRow, _newCol);
    for (int i = 0; i < _newRow; i++)
    {
        for (int j = 0; j < _newCol; j++)
        {
            this->matrix[i][j] = temp->matrix[i][j];
        }
    }
}

template <class T>
Matrix<T> &Matrix<T>::operator+(const Matrix<T> &other)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<int> *temp = new Matrix<int>(_row, _col, 0);
    if (_col != other.col || _row != other.row)
        exit(0);

    else
    {
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                temp->matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator-(const Matrix<T> &other)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    if (_col != other.col || _row != other.row)
        exit(0);

    else
    {
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                temp->matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator*(const Matrix<T> &other)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);
    if (_col != other.col || _row != other.row)
        exit(0);

    else
    {
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < other.col; j++)
            {
                for (int k = 0; k < _col; k++)
                {
                    temp->matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator+(const T &val)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j] + val;
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator-(const T &val)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j] - val;
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator*(const T &val)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j] * val;
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator/(const T &val)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j] / val;
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator%(const T &val)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j] % val;
        }
    }

    return *temp;
}

template <class T>
Matrix<T> &Matrix<T>::operator^(const T &val)
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = pow(this->matrix[i][j], val);
        }
    }

    return *temp;
}

template <class T>
void Matrix<T>::MatrixTranspose()
{
    int _col = getCol();
    int _row = getRow();

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            temp->matrix[i][j] = this->matrix[i][j];
        }
    }

    setRow(_col);
    setCol(_row);
    _col = getCol();
    _row = getRow();
    AllocateMatrix(_row, _col);

    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            this->matrix[i][j] = temp->matrix[j][i];
        }
    }
}

template <class T>
void Matrix<T>::MatrixEmul(const Matrix<T> &other)
{
    int _col = getCol();
    int _row = getRow();

    if (_col != other.col || _row != other.row)
        exit(0);
    else
    {
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                this->matrix[i][j] *= other.matrix[i][j];
            }
        }
    }
}

template <class T>
double Matrix<T>::MatrixDeterminant()
{
    double det = 1.0;
    int _col = getCol();
    int _row = getRow();
    int d1, d2, c, total = 1;
    int t_array[_row + 1];

    Matrix<T> *temp = new Matrix<T>(_row, _col, 0);

    if (_col != _row)
        det = 0;
    else if (_col == 1 && _row == 1)
        det = matrix[0][0];
    else if (!CheckMatrix())
        det = 0;
    else if (_col == 2 && _row == 2)
    {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    else
    {
        for (int k = 0; k < _row; k++)
        {
            for (int m = 0; m < _col; m++)
            {
                temp->matrix[k][m] = this->matrix[k][m];
            }
        }

        for (int i = 0; i < _row; i++)
        {
            c = i;
            while (temp->matrix[c][i] == 0 && c < _row)
            {
                c++;
            }
            if (c == _row)
            {
                continue;
            }
            if (c != i)
            {
                for (int j = 0; j < _row; j++)
                {
                    swap(temp->matrix[c][j], temp->matrix[i][j]);
                }

                det = det * pow(-1, c - i);
            }
            for (int j = 0; j < _row; j++)
            {
                t_array[j] = temp->matrix[i][j];
            }

            for (int j = i + 1; j < _row; j++)
            {
                d1 = t_array[i];
                d2 = temp->matrix[j][i];
                for (int k = 0; k < _row; k++)
                {
                    temp->matrix[j][k] = (d1 * temp->matrix[j][k]) - (d2 * t_array[k]);
                }
                total = total * d1;
            }
        }

        for (int i = 0; i < _row; i++)
        {
            det = det * temp->matrix[i][i];
        }
        if (total == 0)
        {
            det = 0;
        }
        else
        {
            det = det / total;
        }
    }
    return det;
}

template <class T>
bool Matrix<T>::CheckMatrix()
{
    int _col = getCol();
    int _row = getRow();
    int counter = 0;
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            if (this->matrix[i][j] != this->matrix[0][0])
            {
                counter++;
                break;
            }
        }
    }
    return (counter != 0) ? true : false;
}
template <class T>
void Matrix<T>::MatrixInverse(){
   // Matrix res;
    int _col = getCol();
    int _row = getRow();
    float t;
    double det= MatrixDeterminant();
 

    if(_row== _col && det != 0) { 
       for (int i = 0; i < _row; i++) {

        for (int j = 0; j < 2 * _col; j++) {
            if (j == (i + _row))
                this->matrix[i][j] = 1;

    }

}
       for (int i = _row - 1; i > 0; i--) {
           if (this->matrix[i - 1][0] < this->matrix[i][0]) {
            int *t = this->matrix[i];
            this->matrix[i] = this->matrix[i - 1];
            this->matrix[i - 1] = t;

       }
       }
        for (int i = 0; i < _row; i++) {

        for (int j = 0; j < _col; j++) {

            if (j != i) {

                t = this->matrix[j][i] / this->matrix[i][i];
                for (int k = 0; k < 2 * _col; k++) {

                    this->matrix[j][k] -= this->matrix[i][k] * t;
                }
            }
        }
    }
        for (int i = 0; i < _row; i++) {

        t = this->matrix[i][i];
        for (int j = 0; j < 2 * _col; j++) {

            this->matrix[i][j] = this->matrix[i][j] / t;
        }
    }


     for (int i = 0; i < _row; i++) {
        for (int j = _row; j < 2* _col; j++) {
           cout<<this->matrix[i][j];
        }
        cout<<endl;
    }

    }
    else{
        cout<<"\nInverse of Entered Matrix is not possible\n";

    }
}
template <class T>
void Matrix<T>::MatrixPrint(string file){
   // Matrix res;
    int _col = getCol();
    int _row = getRow();


    if(file=="file.txt",ios::app){
    ofstream file("file.txt" );
        for(int i = 0; i<_col;i++){
            for(int j = 0; j<_row;j++){
                    file<<this->matrix[i][j]<<"\t";
            }
            file<<endl;
        }
    }

     else{
        cout<<"Dosya bulunamadi"<<endl;
     }




}

