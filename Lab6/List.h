#pragma once
#include <iostream>

class List {
private:
    int* data;
    int size;

public:
    class Iterator {
    private:
        List* list;
        int current_index;

    public:
        Iterator(List* list_ptr, int start_index = 0);
        Iterator operator-(int n);          // Возврат нового итератора
        int& operator*();                   // Разыменование
        bool isValid() const;
        friend class List;
    };

    List(int size);
    List(const List& other);
    ~List();

    int& operator[](int index);            // Доступ по индексу
    int operator()() const;                // Размер
    List operator+(const List& other) const; // Сложение
    Iterator getIterator();

    friend std::ostream& operator<<(std::ostream& out, const List& list);
};
