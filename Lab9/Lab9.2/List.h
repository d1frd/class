#pragma once
#include "error.h"
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;
    int size;

public:
    List();                       // Конструктор
    List(const List& other);       // Конструктор копирования
    ~List();                      // Деструктор

    int& operator[](int index);    // Доступ по индексу
    List operator+(const List& other) const;  // Сложение списков
    List operator+(int value) const;          // Добавление числа в начало списка

    void push_back(int value);     // Добавить элемент в конец
    void push_front(int value);    // Добавить элемент в начало
    void print() const;            // Вывести список
};
