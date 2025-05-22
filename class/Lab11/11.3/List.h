#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
};

template <class T>
class List {
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List();

    void pushback(const T& value);
    int get_size() const { return size; }
    T& operator[](int index);

    void print() const;

    // Задание 3
    void add_max_to_end();

    // Задание 4
    void delete_by_key_range(int low, int high);

    // Задание 5
    void add_average_to_all();
};

template <class T>
List<T>::~List() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void List<T>::pushback(const T& value) {
    Node<T>* node = new Node<T>(value);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
}

template <class T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    Node<T>* current = head;
    for (int i = 0; i < index; ++i)
        current = current->next;
    return current->data;
}

template <class T>
void List<T>::print() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template <class T>
void List<T>::add_max_to_end() {
    if (!head) return;
    T max_elem = head->data;
    Node<T>* current = head->next;
    while (current) {
        if (current->data > max_elem)
            max_elem = current->data;
        current = current->next;
    }
    pushback(max_elem);
}

template <class T>
void List<T>::delete_by_key_range(int low, int high) {
    Node<T>* current = head;
    while (current) {
        Node<T>* next_node = current->next;
        int key = current->data.get_a();
        if (key >= low && key <= high) {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            size--;
        }
        current = next_node;
    }
}

template <class T>
void List<T>::add_average_to_all() {
    if (!head) return;

    T sum;
    Node<T>* current = head;
    while (current) {
        sum = sum + current->data;
        current = current->next;
    }

    T average;
    average.set_a(sum.get_a() / size);
    average.set_b(sum.get_b() / size);

    current = head;
    while (current) {
        current->data = current->data + average;
        current = current->next;
    }
}

#endif // LIST_H
