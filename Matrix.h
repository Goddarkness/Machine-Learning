#ifndef MATRIX
#define MATRIX
#include<vector>
#include <iostream>

class Matrix {
public:
    void setsize( int m, int n); //��ƾ����ģ
    Matrix transpose();  // ����ת��
    Matrix operator*(Matrix A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(int a);
    Matrix operator/(int a);
    Matrix subMatrrix(int row, int column); // �Ҵμ�����
    double To_double();
    double det(); //������ʽ
    std::vector <double> ma;  // ����
    int m = 0, n = 0; // �� ����
};
#endif // !MATRIX
