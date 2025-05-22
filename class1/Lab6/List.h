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
        Iterator operator-(int n);          // ������� ������ ���������
        int& operator*();                   // �������������
        bool isValid() const;
        friend class List;
    };

    List(int size);
    List(const List& other);
    ~List();

    int& operator[](int index);            // ������ �� �������
    int operator()() const;                // ������
    List operator+(const List& other) const; // ��������
    Iterator getIterator();

    friend std::ostream& operator<<(std::ostream& out, const List& list);
};
