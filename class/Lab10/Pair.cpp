#include "Pair.h"
Pair::Pair() : a(0), b(0.0) {}
Pair::Pair(int A, double B) : a(A), b(B) {}
Pair::Pair(const Pair& p) : a(p.a), b(p.b) {}
Pair::~Pair() {}
int Pair::get_a() const { return a; }
void Pair::set_a(int A) { a = A; }
double Pair::get_b() const { return b; }
void Pair::set_b(double B) { b = B; }
Pair& Pair::operator--() { // префикс: уменьшаем a
    --a;
    return *this;
}

Pair Pair::operator--(int) { // постфикс: уменьшаем b
    Pair temp(*this);
    b--;
    return temp;
}

Pair& Pair::operator=(const Pair& p) {
    if (this != &p) {
        a = p.a;
        b = p.b;
    }
    return *this;
}

bool operator<(const Pair& p1, const Pair& p2) {
    return (p1.a < p2.a) || (p1.a == p2.a && p1.b < p2.b);
}

bool operator>(const Pair& p1, const Pair& p2) {
    return (p1.a > p2.a) || (p1.a == p2.a && p1.b > p2.b);
}

bool operator==(const Pair& p1, const Pair& p2) {
    return p1.a == p2.a && p1.b == p2.b;
}

istream& operator >> (istream& in, Pair& p) {
    cout << "Enter int (a): ";
    in >> p.a;
    cout << "Enter double (b): ";
    in >> p.b;
    return in;
}

fstream& operator >> (fstream& fin, Pair& p) {
    fin >> p.a >> p.b;
    return fin;
}


ostream& operator << (ostream& out, const Pair& p) {
    return out << p.a << " : " << p.b << endl;
}

fstream& operator << (fstream& fout, const Pair& p) {
    fout << p.a << " " << p.b << endl;
    return fout;
}


void Pair::decrease_by(double l) {
    a -= static_cast<int>(l);
    b -= l - static_cast<int>(l);
}
