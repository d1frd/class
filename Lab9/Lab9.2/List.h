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
    List();                       // �����������
    List(const List& other);       // ����������� �����������
    ~List();                      // ����������

    int& operator[](int index);    // ������ �� �������
    List operator+(const List& other) const;  // �������� �������
    List operator+(int value) const;          // ���������� ����� � ������ ������

    void push_back(int value);     // �������� ������� � �����
    void push_front(int value);    // �������� ������� � ������
    void print() const;            // ������� ������
};
