#ifndef MATRIX
#define MATRIX
#include<vector>
#include <iostream>

class Matrix {
public:
    std::vector <double> ma;  // ����
    int m = 0, n = 0; // �� ����

    double To_double(); // ��һά������double����ʵ��
    void setsize( int m, int n); //��ƾ����ģ
    void changerow(int a, int b ); // ����

    Matrix transpose();  // ����ת��
    Matrix operator*(Matrix A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(double a);
    Matrix operator/(double a);
    bool operator==(Matrix B);// �ж��������Ƿ����

    Matrix subMatrrix(int row, int column); // �Ҵμ��������ڷ���det����
    double det(); //������ʽ 

    
    Matrix together(); // �ϲ������������ڷ���inverse����
    Matrix seperate(); // �ֿ������������ڷ���inverse����
    Matrix mutiply(double a, int row); // �Ծ���column��a
    Matrix mutiply(double a, int row_1, int row_2);
    bool IsIdentifyMatrix();// �ж��Ƿ�Ϊ��λ����
    Matrix inverse();//�������


    void print(); // �������
    int findMaxelememtline(); // �ҵ�ӵ�����Ԫ�����ڵ���
    bool closeenough(Matrix B); // ���ڷ��� == �� ����������Χ���򷵻�true
};
#endif // !MATRIX
