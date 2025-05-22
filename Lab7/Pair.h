#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
    int a;
    double b;

public:
    Pair();                                 // ����������� �� ���������
    Pair(int A, double B);                  // ����������� � �����������
    Pair(const Pair& p);                    // ����������� �����������
    ~Pair();                                // ����������

    int get_a();                            // ������ ��� a
    void set_a(int A);                      // ������ ��� a

    double get_b();                         // ������ ��� b
    void set_b(double B);                   // ������ ��� b

    Pair& operator++();                     // ���������� ���������
    Pair& operator++(int);                  // ����������� ���������
    Pair& operator=(const Pair& Link);      // �������� ������������
    Pair operator+(const Pair& p) const;    // �������� ��������

    friend bool operator<(Pair& p, Pair& q);                  // �������� ��������� <
    friend bool operator>(Pair& p, Pair& q);                  // �������� ��������� >
    friend istream& operator>>(istream& in, Pair& Pointer);   // �������� �����
    friend ostream& operator<<(ostream& out, const Pair& Pointer); // �������� ������
};
