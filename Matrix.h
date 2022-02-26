#ifndef MATRIX
#define MATRIX
#include<vector>
#include <iostream>

class Matrix {
public:
    void setsize( int m, int n); //设计矩阵规模
    Matrix transpose();  // 矩阵转置
    Matrix operator*(Matrix A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(int a);
    Matrix operator/(int a);
    Matrix subMatrrix(int row, int column); // 找次级矩阵
    double To_double();
    double det(); //求行列式
    std::vector <double> ma;  // 矩阵
    int m = 0, n = 0; // 行 ，列
};
#endif // !MATRIX
