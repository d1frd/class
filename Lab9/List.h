#pragma once
#include <iostream>
using namespace std;

#define MAX_SIZE 10

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class List
{
private:
    int size;
    Node* head;
    Node* tail;

public:
    List();                              // конструктор по умолчанию
    List(int n, int k = 0);              // конструктор с параметрами
    List(const List&);                   // конструктор копирования
    ~List();                             // деструктор

    friend ostream& operator <<(ostream&, const List&);
    friend istream& operator >>(istream&, const List&);

    List& operator=(const List&);

    int& operator[](int index);          // доступ по индексу
    int& operator()();                   // возвращает размер списка

    List operator+(int value);           // добавление элемента в НАЧАЛО списка
    List operator+(const List& other);   // объединение двух списков
    List& operator++(int elem);           // добавить элемент в конец списка

    void pushback(int);                  // добавление в конец списка
};
