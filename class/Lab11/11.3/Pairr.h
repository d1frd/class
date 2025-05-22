#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
    int a;
    double b;

public:
    Pair(int a = 0, double b = 0.0);

    int get_a() const;
    double get_b() const;
    void set_a(int a);
    void set_b(double b);

    Pair operator+(const Pair& other) const;
    bool operator>(const Pair& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
    friend std::istream& operator>>(std::istream& in, Pair& p);
};

#endif // PAIR_H

