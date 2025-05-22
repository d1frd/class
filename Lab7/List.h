#pragma once
#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : next(nullptr), prev(nullptr) {}
};

template <class T>
class Iterator {
private:
    template <class U> friend class List;
    Node<T>* elem;

public:
    Iterator() : elem(nullptr) {}
    Iterator(const Iterator<T>& it) : elem(it.elem) {}

    Iterator<T>& operator=(const Iterator<T>& p) {
        elem = p.elem;
        return *this;
    }

    bool operator==(const Iterator<T>& it) const { return elem == it.elem; }
    bool operator!=(const Iterator<T>& it) const { return elem != it.elem; }

    Iterator<T>& operator++() {
        if (elem) elem = elem->next;
        return *this;
    }

    Iterator<T>& operator--() {
        if (elem) elem = elem->prev;
        return *this;
    }

    Iterator<T>& operator+(int p) {
        for (int i = 0; i < p && elem; ++i) elem = elem->next;
        return *this;
    }

    Iterator<T>& operator-(int p) {
        for (int i = 0; i < p && elem; ++i) elem = elem->prev;
        return *this;
    }

    T& operator*() const { return elem->data; }
};

template <class T>
class List {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
    Iterator<T> beg;
    Iterator<T> end;

public:
    List();                         // Пустой список
    List(int n);                    // n элементов со значением по умолчанию
    List(int n, T k);               // n элементов со значением k
    List(const List<T>&);           // Конструктор копирования
    ~List();                        // Деструктор

    void pushback(T);              // Добавление в конец
    T& operator[](int index);      // Доступ по индексу
    int& operator()();             // Размер списка
    List<T> operator+(List<T>&);   // Сложение списков
    List<T> operator+(T);          // Сложение с числом
    List<T>& operator=(const List<T>&); // Присваивание

    List<T>& operator++();         // Префиксный ++ (итератор вперёд)

    Iterator<T> first() { return beg; }
    Iterator<T> last() { return end; }

    template <class U>
    friend ostream& operator<<(ostream&, const List<U>&);

    template <class U>
    friend istream& operator>>(istream&, List<U>&);
};

// Реализация методов

template <class T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
List<T>::List(int n) : size(n), head(nullptr), tail(nullptr) {
    if (n <= 0) return;

    Node<T>* node = new Node<T>;
    node->data = T();
    head = tail = node;

    for (int i = 1; i < n; i++) {
        Node<T>* newNode = new Node<T>;
        newNode->data = T();
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    beg.elem = head;
    end.elem = tail->next;
}

template <class T>
List<T>::List(int n, T k) : size(n), head(nullptr), tail(nullptr) {
    if (n <= 0) return;

    Node<T>* node = new Node<T>;
    node->data = k;
    head = tail = node;

    for (int i = 1; i < n; i++) {
        Node<T>* newNode = new Node<T>;
        newNode->data = k;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    beg.elem = head;
    end.elem = tail->next;
}

template <class T>
List<T>::List(const List<T>& p) : head(nullptr), tail(nullptr), size(0) {
    Node<T>* node = p.head;
    while (node) {
        pushback(node->data);
        node = node->next;
    }
    beg.elem = head;
    end.elem = tail->next;
}

template <class T>
void List<T>::pushback(T k) {
    Node<T>* newNode = new Node<T>;
    newNode->data = k;

    if (!head)
        head = tail = newNode;
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    end.elem = tail->next;
    size++;
}

template <class T>
List<T>::~List() {
    Node<T>* tmp = head;
    while (tmp) {
        Node<T>* toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
}

template <class T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Index outside!" << endl;
        exit(1);
    }
    Node<T>* tmp = head;
    for (int i = 0; i < index; ++i)
        tmp = tmp->next;
    return tmp->data;
}

template <class T>
int& List<T>::operator()() {
    return size;
}

template <class T>
List<T> List<T>::operator+(List<T>& p) {
    int minSize = (size < p.size) ? size : p.size;
    List<T> result(minSize);
    for (int i = 0; i < minSize; i++)
        result[i] = (*this)[i] + p[i];
    return result;
}

template <class T>
List<T> List<T>::operator+(T value) {
    List<T> result;
    Node<T>* tmp = head;
    while (tmp) {
        result.pushback(tmp->data + value);
        tmp = tmp->next;
    }
    return result;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& p) {
    if (this == &p) return *this;

    Node<T>* node = head;
    while (node) {
        Node<T>* next = node->next;
        delete node;
        node = next;
    }

    head = tail = nullptr;
    size = 0;

    Node<T>* curr = p.head;
    while (curr) {
        pushback(curr->data);
        curr = curr->next;
    }

    beg.elem = head;
    end.elem = tail->next;
    return *this;
}

template <class T>
List<T>& List<T>::operator++() {
    ++beg;
    return *this;
}

template <class T>
ostream& operator<<(ostream& out, const List<T>& p) {
    Node<T>* tmp = p.head;
    while (tmp) {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}

template <class T>
istream& operator>>(istream& in, List<T>& p) {
    Node<T>* tmp = p.head;
    while (tmp) {
        in >> tmp->data;
        tmp = tmp->next;
    }
    return in;
}

#endif // LIST_H
