#include "list.h"
List::List() : head(nullptr), size(0) {}
List::List(const List& other) : head(nullptr), size(0) {
    Node* temp = other.head;
    while (temp) {
        push_back(temp->data);
        temp = temp->next;
    }
}

List::~List() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void List::push_back(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    size++;
}

void List::push_front(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

int& List::operator[](int index) {
    if (index < 0 || index >= size) {
        throw error();
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

List List::operator+(const List& other) const {
    List result(*this); // копируем текущий список
    Node* temp = other.head;
    while (temp) {
        result.push_back(temp->data);
        temp = temp->next;
    }
    return result;
}

List List::operator+(int value) const {
    List result(*this);
    result.push_front(value);
    return result;
}

void List::print() const {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
