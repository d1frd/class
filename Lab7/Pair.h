#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
    int a;
    double b;

public:
    Pair();                                 // Конструктор по умолчанию
    Pair(int A, double B);                  // Конструктор с параметрами
    Pair(const Pair& p);                    // Конструктор копирования
    ~Pair();                                // Деструктор

    int get_a();                            // Геттер для a
    void set_a(int A);                      // Сеттер для a

    double get_b();                         // Геттер для b
    void set_b(double B);                   // Сеттер для b

    Pair& operator++();                     // Префиксный инкремент
    Pair& operator++(int);                  // Постфиксный инкремент
    Pair& operator=(const Pair& Link);      // Оператор присваивания
    Pair operator+(const Pair& p) const;    // Оператор сложения

    friend bool operator<(Pair& p, Pair& q);                  // Оператор сравнения <
    friend bool operator>(Pair& p, Pair& q);                  // Оператор сравнения >
    friend istream& operator>>(istream& in, Pair& Pointer);   // Оператор ввода
    friend ostream& operator<<(ostream& out, const Pair& Pointer); // Оператор вывода
};
