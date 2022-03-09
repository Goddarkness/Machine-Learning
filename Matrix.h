#ifndef MATRIX
#define MATRIX
#include<vector>
#include <iostream>


class Matrix {
public:
    Matrix(void); // 构造器
    ~Matrix();
    std::vector <double> ma;  // 矩阵
    int m = 0, n = 0; // 行 ，列

    double To_double(); // 将一维矩阵变成double类型实数
    void setsize( int m, int n); //设计矩阵规模
    void changerow(int a, int b ); // 换行(参数为矩阵实际行，从1开始）

    Matrix transpose();  // 矩阵转置
    Matrix operator*(Matrix A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(double a);
    Matrix operator/(double a);
    bool operator==(Matrix B);// 判断两矩阵是否相等

    Matrix subMatrrix(int row, int column); // 找次级矩阵，用于服务det函数(参数为矩阵实际行列，从1开始）
    double det(); //求行列式 

    double cofactor(int row, int column);//求row行column列的代数余子式（对应现实矩阵的行列，不是从0开始)
    Matrix AdjointMatrix(); // 求该矩阵伴随矩阵
    Matrix together(); // 合并两个矩阵，用于服务inverse函数
    Matrix SeperateLeft();//分开两个矩阵得到左边的矩阵，用于服务inverse函数
    Matrix SeperateRight(); // 分开两个矩阵得到右边的矩阵，用于服务inverse函数
    Matrix mutiply(double a, int row); // 对矩阵column乘a（参数为矩阵实际行，从1开始）
    Matrix mutiply(double a, int row_1, int row_2);//对矩阵第row_2行加上第row_1行乘a（参数为矩阵实际行。从1开始）
    bool IsIdentifyMatrix();// 判断是否为单位矩阵
    Matrix inverse();//求逆矩阵

    Matrix combine();//
    void SetAllElements(double element);// 将矩阵元素全部设置为element
    void print(); // 输出矩阵
    int findMaxelememtline(); // 找到拥有最大元素所在的行（返回值为矩阵实际行数，不是从0开始)
    bool closeenough(Matrix B); // 用于服务 == ， 两矩阵在误差范围内则返回true
};
#endif // !MATRIX
