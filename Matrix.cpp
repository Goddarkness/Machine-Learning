#include "Matrix.h"
void Matrix::setsize( int m, int n) {
    ma.resize(m*n);
    this->m = m;
    this->n = n;
}

Matrix Matrix::operator*(Matrix A)
{   
    if (n != A.m)
    {
        std::cout << "请检查矩阵规模，不能相乘" << std::endl;
        return Matrix();
    }
    Matrix C;
    C.setsize( m, A.n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A.n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum = sum + ma[i * n + k] * A.ma[k * A.n + j];
            C.ma[i * A.n + j] = sum;
        }

    }
    return  C;
}

Matrix Matrix::transpose() {
    Matrix A;
    A.setsize( n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            A.ma[i * m + j] = ma[j * n + i];
    }
    return A;
}

Matrix Matrix::operator+(Matrix A) {
    Matrix B;
    B.setsize( m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            B.ma[i * n + j] = ma[i * n + j] + A.ma[i * n + j];
    }
    return B;
}

Matrix Matrix::operator-(Matrix A) {
    Matrix B;
    B.setsize( m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            B.ma[i * n + j] = ma[i * n + j] - A.ma[i * n + j];
    }
    return B;
}

Matrix  Matrix::operator*(int a) {
    Matrix B;
    for (int i = 0; i < m * n; i++) {
        B.ma[i] = ma[i] * a;
    }
    return B;
}

Matrix Matrix::operator/(int a) {
    Matrix B;
    for (int i = 0; i < m * n; i++) {
        B.ma[i] = ma[i] / a;
    }
    return B;
}


double Matrix::To_double() {
    if (m != 1 || n != 1)
    {
        std::cout << "wrong to change to double" << std::endl;
        return NULL;
    }
    return ma[0, 0];
}

Matrix Matrix::subMatrrix(int row, int column) {
    Matrix B;
    B.setsize(m - 1, n - 1);
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i != row && j != column) {
                B.ma[count] = ma[i * n + j];
                count++;
            }
        }
    }
    return B;
}

double Matrix::det() {
    if (m != n) {
        std::cout << "row colmun dont't match";
        return 0;
    }
    if (m == 1)
        return ma[0];
    else if (m == 2)
        return ma[3] * ma[0] - ma[1] * ma[2];
    else {
        double value = 0;
        int sign = 1;
        for (int i = 0; i < n; i++) {
            value = value + sign * ma[i] * subMatrrix(0, i).det();
            sign = -sign;
        }
        return value;
    }

}