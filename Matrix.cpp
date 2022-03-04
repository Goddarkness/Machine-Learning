#include "Matrix.h"
#include <cmath>

Matrix::Matrix(void) {

}

Matrix::~Matrix() {
    
}
void Matrix::print() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ma[i * n + j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Matrix::setsize( int m, int n) {
    ma.resize(m*n);
    this->m = m;
    this->n = n;
}

void Matrix::changerow(int a, int b) {
    std::vector<double>temp;
    a = a - 1;
    b = b - 1;
    temp.resize(n);
    for (int i = 0; i < n; i++) {
        temp[i] = ma[a * n + i];
    }
    for (int i = 0; i < n; i++) {
        ma[a*n+i] = ma[b * n + i];
    }
    for (int i = 0; i < n; i++) {
        ma[b * n + i] = temp[i];
    }

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
    for (int i = 0; i < m*n; i++) {
        B.ma[i] = ma[i] + A.ma[i];
    }

       
    return B;
}      //  +只是对应位置的相加，不需要用二维方式表示

Matrix Matrix::operator-(Matrix A) {
    Matrix B;
    B.setsize( m, n);
    for (int i = 0; i < m * n; i++) {
        B.ma[i] = ma[i] + A.ma[i];
    }
    return B;
}  
// -只是对应位置的相减，不需要二维方式的表示

Matrix  Matrix::operator*(double a) {
    Matrix B;
    B.setsize(m,n);
    for (int i = 0; i < m * n; i++) {
        B.ma[i] = ma[i] * a;
    }
    return B;
}

Matrix Matrix::operator/(double a) {
    Matrix B;
    B.setsize(m, n);
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
    row = row - 1;
    column = column - 1;
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
            value = value + sign * ma[i] * subMatrrix(1, 1+i).det();
            sign = -sign;
        }
        return value;
    }

}

double Matrix::cofactor(int row, int column) {
    row = row - 1;
    column = column - 1;
    Matrix B;
    B.setsize(m - 1, n - 1);
    int count = 0;
    for (int i = 0; i < m ; i++) {
        for (int j = 0; j < m; j++) {
            if (i != row && j != column) {
                B.ma[count] = ma[i * n + j];
                count++;
            }
         }
    }
    return pow(-1,row+column+2)*B.det();
}

Matrix Matrix::AdjointMatrix() {
    Matrix B;
    B.setsize(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B.ma[i * n + j] = cofactor(j+1, i+1);
        }
    }
    return B;
}

int Matrix::findMaxelememtline() {
    std::vector <double> Max;
    Max.resize(m);
    for (int i = 0; i < m; i++) {
        double max = ma[i * n];
        for (int j = 1; j < n; j++) {
            if (ma[i * n + j] > max)
                max = ma[i * n + j];
        }
        Max[i] = max;
    }
    double max = Max[0];
    int locate = 0;
    for (int i = 1; i < m; i++) {
        if (max < Max[i]) {
            max = Max[i];
            locate = i;
        }
           
    }
    return locate+1;
}



bool Matrix::closeenough( Matrix B) {
    if (m != B.m  || n != B.n)
        return false;
    for (int i = 0; i < m * n; i++) {
        if (abs(ma[i] - B.ma[i]) > 1.e-12) {
            return false;
            break;
        }
    }
    return true;
 }

bool Matrix::operator==(Matrix B) {
    if (closeenough(B))
        return true;
    else
        return false;
}

Matrix Matrix::together() {
    if (m != n) {
        std::cout << " fail to combine Matrix" << std::endl;
        return Matrix();
    }
    Matrix B;
    B.setsize(m, 2 * n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B.ma[i * 2 * n + j] = ma[i * n + j];
        }
    }
    for (int i = 0; i < m; i++) {
        B.ma[i * 2 * n + m + i] = 1;
    }
    return B;
}

Matrix Matrix::SeperateLeft() {
    if (n != 2 * m) {
        std::cout << "fail to seperate this Matrix" << std::endl;
        return Matrix();
    }
    Matrix B;
    B.setsize(m, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            B.ma[i * m + j] = ma[i * n + j];
        }
    }
    return B;
}


Matrix Matrix::SeperateRight() {
    if (n != 2 * m) {
        std::cout << "fail to separate this Matrix" << std::endl;
        return Matrix();
    }
    Matrix B;
    B.setsize(m, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            B.ma[i * m + j] = ma[i *  n + j+m];
        }
    }
    return B;
}

Matrix Matrix::mutiply(double a, int row) {
    Matrix B;
    B.setsize(m, n);
    for (int i = 0; i < m * n; i++) {
        B.ma[i] = ma[i];
    }
    for (int i = 0; i < n; i++) {
        B.ma[(row - 1) * n + i] = ma[(row - 1) * n + i] * a;
    }
    return B;
}

Matrix Matrix::mutiply(double a, int row_1, int row_2) {
    Matrix B;
    B.setsize(m, n);
    for (int i = 0; i < m * n; i++) {
        B.ma[i] = ma[i];
    }
    for (int i = 0; i < n; i++) {
        B.ma[(row_2 - 1) * n + i] = B.ma[(row_2 - 1) * n + i] + ma[(row_1 - 1) * n + i] * a;
    }
    return B;
}

bool Matrix::IsIdentifyMatrix() {
    if (m != n) {
        return false;
    }
    Matrix B;
    B.setsize(m, n);
    for (int i = 0; i < m; i++) {
        B.ma[i * n + i] = 1;
    }
    for (int i = 0; i < m * n; i++) {
        if (ma[i] != B.ma[i]) {
            return false;
            break;
        }
    }
    return true;
}

Matrix Matrix::inverse() {
    if (m != n) {
        std::cout << "矩阵不是方阵，无法求逆矩阵" << std::endl;
        return Matrix();
    }
    if (det() == 0) {
        std::cout << "该矩阵为退化矩阵，不存在逆矩阵" << std::endl;
    }
    Matrix B;
    B = AdjointMatrix()/det();
    return B;
}