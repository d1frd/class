#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

class Pair {
private:
    int first;
    double second;

public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair(const Pair& p) : first(p.first), second(p.second) {}
    ~Pair() {}

    int get_first() const { return first; }
    double get_second() const { return second; }
    void set_first(int f) { first = f; }
    void set_second(double s) { second = s; }

    // Перегруженные операции
    Pair& operator=(const Pair&);
    Pair& operator--();
    Pair operator--(int); // Постфиксная операция

    friend bool operator<(const Pair& p, const Pair& q); // Оператор сравнения
    friend bool operator>(const Pair& p, const Pair& q);
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};

#endif // PAIR_H
