#include "Pairr.h"

Pair::Pair(int a, double b) : a(a), b(b) {}

int Pair::get_a() const { return a; }
double Pair::get_b() const { return b; }
void Pair::set_a(int a_) { a = a_; }
void Pair::set_b(double b_) { b = b_; }

Pair Pair::operator+(const Pair& other) const {
    return Pair(a + other.a, b + other.b);
}

bool Pair::operator>(const Pair& other) const {
    if (a != other.a)
        return a > other.a;
    return b > other.b;
}

std::ostream& operator<<(std::ostream& out, const Pair& p) {
    out << "(" << p.a << ", " << p.b << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Pair& p) {
    in >> p.a >> p.b;
    return in;
}
