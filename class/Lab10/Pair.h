#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair {
private:
    int a;
    double b;

public:
    Pair();
    Pair(int A, double B);
    Pair(const Pair& p);
    ~Pair();

    int get_a() const;
    void set_a(int A);

    double get_b() const;
    void set_b(double B);

    Pair& operator--();        // Префиксный: уменьшает a
    Pair operator--(int);      // Постфиксный: уменьшает b

    Pair& operator=(const Pair& p);

    friend bool operator<(const Pair& p1, const Pair& p2);
    friend bool operator>(const Pair& p1, const Pair& p2);
    friend bool operator==(const Pair& p1, const Pair& p2);

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
    friend fstream& operator>>(fstream& fin, Pair& p);
    friend fstream& operator<<(fstream& fout, const Pair& p);

    void decrease_by(double l);
};






