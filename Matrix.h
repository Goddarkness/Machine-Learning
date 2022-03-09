#ifndef MATRIX
#define MATRIX
#include<vector>
#include <iostream>


class Matrix {
public:
    Matrix(void); // ������
    ~Matrix();
    std::vector <double> ma;  // ����
    int m = 0, n = 0; // �� ����

    double To_double(); // ��һά������double����ʵ��
    void setsize( int m, int n); //��ƾ����ģ
    void changerow(int a, int b ); // ����(����Ϊ����ʵ���У���1��ʼ��

    Matrix transpose();  // ����ת��
    Matrix operator*(Matrix A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(double a);
    Matrix operator/(double a);
    bool operator==(Matrix B);// �ж��������Ƿ����

    Matrix subMatrrix(int row, int column); // �Ҵμ��������ڷ���det����(����Ϊ����ʵ�����У���1��ʼ��
    double det(); //������ʽ 

    double cofactor(int row, int column);//��row��column�еĴ�������ʽ����Ӧ��ʵ��������У����Ǵ�0��ʼ)
    Matrix AdjointMatrix(); // ��þ���������
    Matrix together(); // �ϲ������������ڷ���inverse����
    Matrix SeperateLeft();//�ֿ���������õ���ߵľ������ڷ���inverse����
    Matrix SeperateRight(); // �ֿ���������õ��ұߵľ������ڷ���inverse����
    Matrix mutiply(double a, int row); // �Ծ���column��a������Ϊ����ʵ���У���1��ʼ��
    Matrix mutiply(double a, int row_1, int row_2);//�Ծ����row_2�м��ϵ�row_1�г�a������Ϊ����ʵ���С���1��ʼ��
    bool IsIdentifyMatrix();// �ж��Ƿ�Ϊ��λ����
    Matrix inverse();//�������

    Matrix combine();//
    void SetAllElements(double element);// ������Ԫ��ȫ������Ϊelement
    void print(); // �������
    int findMaxelememtline(); // �ҵ�ӵ�����Ԫ�����ڵ��У�����ֵΪ����ʵ�����������Ǵ�0��ʼ)
    bool closeenough(Matrix B); // ���ڷ��� == �� ����������Χ���򷵻�true
};
#endif // !MATRIX
