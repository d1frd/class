#include "List.h"
#include <stdexcept>

// �����������
List::List(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

// ����������� �����������
List::List(const List& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// ����������
List::~List() {
    delete[] data;
}

// ������ �� �������
int& List::operator[](int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    throw std::out_of_range("Index out of range");
}

// ������
int List::operator()() const {
    return size;
}

// �������� ���� �������
List List::operator+(const List& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Lists must be of same size");
    }

    List result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// �������� ��������
List::Iterator List::getIterator() {
    return Iterator(this);
}

// �������� - �����������
List::Iterator::Iterator(List* list_ptr, int start_index) : list(list_ptr), current_index(start_index) {}

// �������� - �������� �����
List::Iterator List::Iterator::operator-(int n) {
    int new_index = current_index - n;
    if (new_index < 0 || new_index >= list->size) {
        throw std::out_of_range("Iterator out of range after shifting left");
    }
    return Iterator(list, new_index);
}

// �������� - �������������
int& List::Iterator::operator*() {
    if (!isValid()) {
        throw std::out_of_range("Iterator is out of bounds");
    }
    return list->data[current_index];
}

// �������� �� ����������
bool List::Iterator::isValid() const {
    return current_index >= 0 && current_index < list->size;
}

// ���������� ������
std::ostream& operator<<(std::ostream& out, const List& list) {
    for (int i = 0; i < list(); ++i) {
        out << list.data[i] << " ";
    }
    return out;
}
