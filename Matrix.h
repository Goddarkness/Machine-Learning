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
    double getMoudule();//����ȡģ
    void print();//�������
};


class Matrix {
public:
    Matrix(void); // ������
    ~Matrix();// 
    std::vector <double> ma;  // ����
    int m = 0, n = 0; // �� ����

    int factorial( int n); //��n�Ľ׳�

    double To_double(); // ��һά������double����ʵ��
    void setsize( int m, int n); //��ƾ����ģ
 
    Matrix transpose();  // ����ת��
    Matrix operator*(Matrix A);
    Vector operator*(Vector A);
    Matrix operator+(Matrix A);
    Matrix operator-(Matrix A);
    Matrix operator*(double a);
    Matrix operator/(double a);
    bool operator==(Matrix B);// �ж��������Ƿ����

    bool IsColumnZero(int column);// �жϵ�column���Ƿ�Ϊ0����
    void changeColumn(int column_1, int column2); //�ı�����column_1,column_2��
    bool IsAllColumnZero( int column); //�ж��ӵ�column�п�ʼ������Ƿ�Ϊ0���������ҽ�Ϊ0�������ƶ������
    bool IsRowZero(int row);   //�жϵ�row���Ƿ�Ϊ0
    void changeRow(int row_1, int row_2);
    bool IsAllRowZero(int row); 
    Matrix SpecialMatrix();//�������

    Matrix subMatrix(int row, int column); // �Ҵμ��������ڷ���det����(����Ϊ����ʵ�����У���1��ʼ��
    double det(); //������ʽ 

   
    int rank(); //��������

    Matrix GetEigenvector();
    double GetEigenvalue();

    double cofactor(int row, int column);//��row��column�еĴ�������ʽ����Ӧ��ʵ��������У����Ǵ�0��ʼ)
    Matrix AdjointMatrix(); // ��þ���������
    Matrix together(); // �ϲ������������ڷ���inverse����
    Matrix SeperateLeft();//�ֿ���������õ���ߵľ������ڷ���inverse����
    Matrix SeperateRight(); // �ֿ���������õ��ұߵľ������ڷ���inverse����
    Matrix mutiply(double a, int row); // �Ծ���column��a������Ϊ����ʵ���У���1��ʼ��
    Matrix mutiply(double a, int row_1, int row_2);//�Ծ����row_2�м��ϵ�row_1�г�a������Ϊ����ʵ���С���1��ʼ��
    bool IsIdentifyMatrix();// �ж��Ƿ�Ϊ��λ����
    Matrix inverse();//�������

    void SetAllElements(double element);// ������Ԫ��ȫ������Ϊelement
    void print(); // �������
    int findMaxelememtline( int line,int column); //�ӵ�column �п�ʼ �ҵ�ӵ�����Ԫ�����ڵ��У�����ֵΪ����ʵ�����������Ǵ�0��ʼ)
    bool closeenough(Matrix B); // ���ڷ��� == �� ����������Χ���򷵻�true
};


#endif // !MATRIX
