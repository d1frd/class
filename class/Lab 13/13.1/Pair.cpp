#include "pair.h"

Pair::Pair() : first(0), second(0.0) {}

Pair::Pair(int f, double s) : first(f), second(s) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

Pair::~Pair() {}

int Pair::get_first() const { return first; }

double Pair::get_second() const { return second; }

void Pair::set_first(int f) { first = f; }

void Pair::set_second(double s) { second = s; }

Pair& Pair::operator=(const Pair& p) {
    if (this != &p) {
        first = p.first;
        second = p.second;
    }
    return *this;
}

Pair& Pair::operator--() {
    --first;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp = *this;
    --first;
    return temp;
}

bool operator<(const Pair& p, const Pair& q) {
    return (p.first < q.first) || (p.first == q.first && p.second < q.second);
}

bool operator>(const Pair& p, const Pair& q) {
    return (p.first > q.first) || (p.first == q.first && p.second > q.second);
}

std::istream& operator>>(std::istream& in, Pair& p) {
    std::cout << "¬ведите first: "; in >> p.first;
    std::cout << "¬ведите second: "; in >> p.second;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& p) {
    return out << p.first << ":" << p.second;
}
