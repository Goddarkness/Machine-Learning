#ifndef MATRIX
#define MATRIX
#include<vector>
#include <iostream>

class Vector {
public:
    Vector(void);
    ~Vector();
    int m = 0;
    int n = 1;
    std::vector <double> va;
    void setsize(int m);
    double getMoudule();//向量取模
    void print();//输出向量
};


class Matrix {
public:
    Matrix(void); // 构造器
    ~Matrix();// 
    std::vector <double> ma;  // 矩阵
    int m = 0, n = 0; // 行 ，列

    int factorial( int n); //求n的阶乘

    double To_double(); // 将一维矩阵变成double类型实数
    void setsize( int m, int n); //设计矩阵规模
 
    Matrix transpose();  // 矩阵转置
    Matrix operator*(Matrix A);
    Vector operator*(Vector A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(double a);
    Matrix operator/(double a);
    bool operator==(Matrix B);// 判断两矩阵是否相等

    bool IsColumnZero(int column);// 判断第column列是否为0向量
    void changeColumn(int column_1, int column2); //改变矩阵第column_1,column_2列
    bool IsAllColumnZero( int column); //判读从第column列开始后面的是否都为0向量，并且将为0的向量移动至最后
    bool IsRowZero(int row);   //判断第row行是否为0
    void changeRow(int row_1, int row_2);
    bool IsAllRowZero(int row); 
    Matrix SpecialMatrix();//求阶梯型

    Matrix subMatrix(int row, int column); // 找次级矩阵，用于服务det函数(参数为矩阵实际行列，从1开始）
    double det(); //求行列式 

   
    int rank(); //求矩阵的秩

    Matrix GetEigenvector();
    double GetEigenvalue();

    double cofactor(int row, int column);//求row行column列的代数余子式（对应现实矩阵的行列，不是从0开始)
    Matrix AdjointMatrix(); // 求该矩阵伴随矩阵
    Matrix together(); // 合并两个矩阵，用于服务inverse函数
    Matrix SeperateLeft();//分开两个矩阵得到左边的矩阵，用于服务inverse函数
    Matrix SeperateRight(); // 分开两个矩阵得到右边的矩阵，用于服务inverse函数
    Matrix mutiply(double a, int row); // 对矩阵column乘a（参数为矩阵实际行，从1开始）
    Matrix mutiply(double a, int row_1, int row_2);//对矩阵第row_2行加上第row_1行乘a（参数为矩阵实际行。从1开始）
    bool IsIdentifyMatrix();// 判断是否为单位矩阵
    Matrix inverse();//求逆矩阵

    void SetAllElements(double element);// 将矩阵元素全部设置为element
    void print(); // 输出矩阵
    int findMaxelememtline( int line,int column); //从第column 行开始 找到拥有最大元素所在的行（返回值为矩阵实际行数，不是从0开始)
    bool closeenough(Matrix B); // 用于服务 == ， 两矩阵在误差范围内则返回true
};


#endif // !MATRIX
