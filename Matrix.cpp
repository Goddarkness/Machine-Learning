#include "Matrix.h"
#include <cmath>


// Class Vector:

Vector::Vector(void) {

}

Vector::~Vector() {
    va.~vector();
}

void Vector::setsize(int m) {
    va.resize(m);
    this->m = m;
}
double Vector::getMoudule() {
    double sum = 0;
    for (int i = 0; i < m; i++)
        sum = sum + va[i] * va[i];
    return sqrt(sum);
}

void Vector::print() {
    for (int i = 0; i < m; i++)
        std::cout << va[i] << std::endl;
}



// Class Matrix:
Matrix::Matrix(void) {

}

Matrix::~Matrix() {
    m = 0;
    n = 0;
    ma.~vector();
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

int Matrix::factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
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
            double sum = 0;
            for (int k = 0; k < n; k++)
                sum = sum + ma[i * n + k] * A.ma[k * A.n + j];
            C.ma[i * A.n + j] = sum;
        }

    }
    return  C;
}

Vector Matrix::operator*(Vector A) {
    if (n!=A.m) {
        std::cout << "请检查矩阵规模，不能相乘" << std::endl;
        return Vector();
    }
    Vector B;
    B.setsize(m);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            B.va[i] = B.va[i] + ma[i * n + k] * A.va[k];
        }
    }
    return B;

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

bool Matrix::IsColumnZero(int column) {

    column = column - 1;
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (ma[i * n + column] == 0)
            count++;
    }
    if (count == m)
        return true;
    else
        return false;
}

void Matrix::changeColumn(int column_1, int column_2) {
    column_1 = column_1 - 1;
    column_2 = column_2 - 1;
    double *temp;
    temp = new double [m];
    for (int i = 0; i < m; i++) {
        temp[i] = ma[i * n + column_1];
    }
    for (int i = 0; i < m; i++) {
        ma[i * n + column_1] = ma[i * n + column_2];
    }
    for (int i = 0; i < m; i++) {
        ma[i * n + column_2] = temp[i];
    }
    delete []temp;
}



bool Matrix::IsAllColumnZero(int column) {
    column = column - 1;
    int count = 0;
    for (int i = column; i < n; i++) {
        if (IsColumnZero(i + 1)) {    
            count++;
        }
       
    }
    int i_count = 0;
    for (int i = column; i_count<n-column-count; ) {
        if (IsColumnZero(i + 1)) {
            for (int k = i; k < n - 1; k++) {
                changeColumn(k + 1, k + 2);
            }
        }
        else
        {
            i++;
            i_count++;
        }

    }
    
    if (count == n  - column)
        return true;
    else
        return false;
}

bool Matrix::IsRowZero(int row) {
    row = row - 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ma[row * n + i]==0) {
           
            count++;
        }
    }
    
    if (count == n)
        return true;
    else
        return false;
}

void Matrix::changeRow(int row_1, int row_2) {
    row_1 = row_1 - 1;
    row_2 = row_2 - 1;
    double* temp;
    temp = new double[n];
    for (int i = 0; i < n; i++) {
        temp[i] = ma[row_1 * n + i];
    }
    for (int i = 0; i < n; i++) {
        ma[row_1 * n + i] = ma[row_2 * n + i];
    }
    for (int i = 0; i < n; i++) {
        ma[row_2 * n + i] = temp[i];
    }
    delete []temp;
}

bool Matrix::IsAllRowZero(int row) {
    row = row - 1;
    int count = 0;
    for (int i = row; i < m; i++) {
        if (IsRowZero(i + 1)) {
            count++;
        }
    }
  
    int i_count = 0;

    for (int i = row; i_count < m - row - count; ) {
        if (IsRowZero(i + 1)) {
     
            for (int k = i; k < m-1 ; k++) {
                changeRow(k + 1, k + 2);
               
            }
            
        }
        else
        {

            i++;
            i_count++;
         
        }

    }

    if (count == m-row)
        return true;
    else
        return false;
}

Matrix Matrix::SpecialMatrix() {

    Matrix B;
    B.setsize(m, n);
    B.ma = ma;
  
    int j = 0;
   
    for (int i = 0; i < m-1; i++) {
        if (i <= n) {
            if (IsAllColumnZero(i + 1)) {
                return B;
                break;
            }
            if (IsAllRowZero(i + 1)) {
                return B;
                break;

            }
        }

            int MaxRow = B.findMaxelememtline(i + 1, j + 1);
            if (i != MaxRow - 1)
                B.changeRow(i + 1, MaxRow);
            for (int k = i + 1; k < m; k++) {
                double temp = B.ma[k * n + j];
                for (int p = j; p < n; p++) {
                    B.ma[k * n + p] = B.ma[k * n + p] - B.ma[i * n + p] / B.ma[i * n + j] * temp;
                }
            }
            j++;
        }
           
       
       
        return B;

    }


Matrix Matrix::subMatrix(int row, int column) {
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
            value = value + sign * ma[i] * subMatrix(1, 1+i).det();
            sign = -sign;
        }
        return value;
    }

}

int Matrix::rank() {
    Matrix B = SpecialMatrix();
    int count = 0;
    for (int i = 0; i < B.m; i++) {
        int count_zero = 0;
        for (int j = 0; j < n; j++) {
            if (B.ma[i * B.n + j] == 0)
                count_zero++;
        }
        if (count_zero == n)
            count++;
    }
   
    return m-count;
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

int Matrix::findMaxelememtline(  int row,int column) {
    std::vector <double> Max;
    row = row - 1;
    column = column - 1;
    Max.resize(m);
    for (int i = 0; i < m; i++) {
        Max[i] =abs(ma[i * n + column]);
    }
    double max = Max[row];
    int locate = row;
    for (int i =  row+1; i < m; i++) {
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

void Matrix::SetAllElements(double element) {
    for (int i = 0; i < m * n; i++) {
        ma[i] = element;
    }
}


