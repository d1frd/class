#include "List.h"

#define SIZE_ERROR 1
#define MIN_INDEX_ERROR 2
#define MAX_INDEX_ERROR 3
#define FULL_SIZE_ERROR 4

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::List(int n, int k)
{
    if (n > MAX_SIZE || n < 1) throw SIZE_ERROR;
    size = n;
    head = nullptr;
    tail = nullptr;

    Node* node = new Node;
    node->data = k;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;

    for (int i = 1; i < n; i++)
    {
        Node* newNode = new Node;
        Node* prevNode = node;
        node->next = newNode;
        node = node->next;
        node->data = k;
        node->next = nullptr;
        node->prev = prevNode;
    }

    tail = node;
}

List::List(const List& p)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node* node = p.head;
    while (node != nullptr)
    {
        pushback(node->data);
        node = node->next;
    }
}

void List::pushback(int k)
{
    Node* newNode = new Node;
    newNode->data = k;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

List::~List()
{
    Node* tmp = head;
    while (tmp != nullptr)
    {
        Node* next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head = nullptr;
    tail = nullptr;
}

ostream& operator<<(ostream& out, const List& p)
{
    Node* tmp = p.head;
    while (tmp != nullptr)
    {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, const List& p)
{
    Node* tmp = p.head;
    while (tmp != nullptr)
    {
        in >> tmp->data;
        tmp = tmp->next;
    }
    return in;
}

List List::operator+(int value)
{
    List newList(*this); // Копируем текущий список

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = newList.head;
    newNode->prev = nullptr;

    if (newList.head != nullptr)
        newList.head->prev = newNode;

    newList.head = newNode;
    newList.size++;

    return newList;
}

List List::operator+(const List& other)
{
    List result(*this); // Копируем текущий список

    Node* tmp = other.head;
    while (tmp != nullptr)
    {
        result.pushback(tmp->data);
        tmp = tmp->next;
    }

    return result;
}

List& List::operator++(int elem)
{
    if (size >= MAX_SIZE) throw FULL_SIZE_ERROR;
    pushback(elem);
    return *this;
}

int& List::operator[](int index)
{
    if (index < size && index >= 0)
    {
        Node* tmp = head;
        for (int i = 0; i < index; i++) tmp = tmp->next;
        return tmp->data;
    }
    else
    {
        if (index >= size)
        {
            throw MAX_INDEX_ERROR;
        }
        if (index < 0)
        {
            throw MIN_INDEX_ERROR;
        }
    }
}

int& List::operator()()
{
    return size;
}

List& List::operator=(const List& p)
{
    if (this == &p) return *this;

    Node* tmp = head;
    while (tmp != nullptr)
    {
        Node* next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* curr = p.head;
    while (curr != nullptr)
    {
        pushback(curr->data);
        curr = curr->next;
    }

    return *this;
}
