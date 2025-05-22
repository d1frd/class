#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
private:
    int first;
    double second;

public:
    Pair();
    Pair(int f, double s);
    Pair(const Pair& p);
    ~Pair();

    int get_first() const;
    double get_second() const;
    void set_first(int f);
    void set_second(double s);

    // Перегруженные операции
    Pair& operator=(const Pair& p);
    Pair& operator--();
    Pair operator--(int); // постфиксная операция
    friend bool operator<(const Pair& p, const Pair& q);
    friend bool operator>(const Pair& p, const Pair& q);
    friend std::istream& operator>>(std::istream& in, Pair& p);
    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
};

#endif // PAIR_H
