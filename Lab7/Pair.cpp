#include "Pair.h"
#include <iostream>
using namespace std;
Pair::Pair() : a(0), b(0.0) {}
Pair::Pair(int A, double B) : a(A), b(B) {}
Pair::Pair(const Pair& p) : a(p.a), b(p.b) {}
Pair::~Pair() {}
// ������� � �������
int Pair::get_a() { return a; }
void Pair::set_a(int A) { a = A; }

double Pair::get_b() { return b; }
void Pair::set_b(double B) { b = B; }
// ��������� ����������
Pair& Pair::operator++() {
    ++a;
    return *this;
}
Pair& Pair::operator++(int) {
    b++;
    return *this;
}

// �������� ������������
Pair& Pair::operator=(const Pair& Link) {
    if (this != &Link) {
        a = Link.a;
        b = Link.b;
    }
    return *this;
}

// �������� ��������
Pair Pair::operator+(const Pair& p) const {
    return Pair(a + p.a, b + p.b);
}

// �������� ��������� <
bool operator<(Pair& p, Pair& q) {
    if (p.a < q.a) return true;
    if (p.a > q.a) return false;
    return p.b < q.b;
}

// �������� ��������� >
bool operator>(Pair& p, Pair& q) {
    if (p.a > q.a) return true;
    if (p.a < q.a) return false;
    return p.b > q.b;
}

// ����
istream& operator>>(istream& in, Pair& Pointer) {
    cout << "������� a: ";
    in >> Pointer.a;
    cout << "������� b: ";
    in >> Pointer.b;
    return in;
}

// �����
ostream& operator<<(ostream& out, const Pair& Pointer) {
    out << Pointer.a << " : " << Pointer.b;
    return out;
}

