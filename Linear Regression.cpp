// Linear Regression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include <algorithm>
#include <initializer_list>
#include<cmath>
using namespace std;

class liner {
public:
    Matrix X;
    Matrix Y;
    Matrix theta;
    double alpha; // learining rate
    void settrainningsettings();  // 初始化训练样本及变量
    double cost();   // 计算代价函数
    void gradience( int steps);  // 梯度下降法
    Matrix normalequation(); //正规方程法
    Matrix FeatureNormalixe();
    
};

void liner::settrainningsettings() {
    cout << "Input the number of traingseamples" << endl;
    int m, n;
    cin >> m;
    cout << "Input the number of each settings" << endl;
    cin >> n;
    X.setsize(m, n);
    Y.setsize(1, n);
    theta.setsize(n, 1);
    
}

double liner::cost() {
    Matrix J;
    J = (X.transpose()*theta-Y).transpose()* (X.transpose() * theta - Y)/(2*Y.m);
    return J.To_double();
}

void liner::gradience( int steps) {
    for (int i = 0; i < steps; i++) {
        Matrix pridection = (X.transpose()) * theta;
        Matrix sum = pridection.transpose() - Y;
        Matrix one;
        one.setsize(X.n, 1);
        one.SetAllElements(1);
        Matrix Sum = sum.transpose() * one;
        theta = theta - X * (alpha / (double)(X.n) * Sum.To_double());
    }
}

Matrix liner::FeatureNormalixe() {
    Matrix B;
    Matrix mu;
    Matrix sigma;
    B.setsize(X.m, X.n);
    mu.setsize(1, X.n);
    sigma.setsize(1, X.n);
    for (int i = 0; i < X.n; i++) {
        double sum = 0;
        for (int j = 0; j < X.m; j++) {
            sum = sum + X.ma[j * X.n + i];
        }
        mu.ma[i] = sum / X.m;
    }
    for (int i = 0; i < X.n; i++) {
        double sum = 0;
        for (int j = 0; j < X.m; j++) {
            sum = sum + (X.ma[j * X.n + i] - mu.ma[i]) * (X.ma[j * X.n + i] - mu.ma[i]);
        }
        sigma.ma[i] = sum / (X.m - 1);
    }
    for (int i = 0; i < X.n; i++) {
        for (int j = 0; j < X.m; j++) {
            B.ma[j * X.n + i] = (X.ma[j * X.m + i] - mu.ma[i]) / sigma.ma[i];
        }
     }
    return B;
}

Matrix liner::normalequation() {
    Matrix B = X.transpose();
    theta = (B.transpose() * X).inverse() * B.inverse() * Y;
    return theta;
}

int main()
{
    Matrix matrix;
    matrix.setsize(4, 4);
    matrix.ma[0] = 6;
    matrix.ma[1] = 7;
    matrix.ma[2] = 10;
    matrix.ma[3] = 1;
    matrix.ma[4] = 5;
    matrix.ma[5] = 4;
    matrix.ma[6] = 3;
    matrix.ma[7] = 2;
    matrix.ma[8] = 7;
    matrix.ma[9] = 7;
    matrix.ma[10] = 1;
    matrix.ma[11] = 3;
    matrix.ma[12] = 1;
    matrix.ma[13] = 4;
    matrix.ma[14] = 0;
    matrix.ma[15] = 8;
    
    matrix.print();
    Matrix B;
    B = matrix.inverse();
    B.print();
   // cout << matrix.cofactor(1, 2) << endl;



     

   


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
