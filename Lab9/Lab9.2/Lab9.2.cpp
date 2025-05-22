// Lab9
#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List A;
    A.push_back(10);
    A.push_back(20);
    A.push_back(30);

    cout << "List A: ";
    A.print();

    try {
        cout << "Element at index 1: " << A[1] << endl;
        cout << "Element at index 5: " << A[5] << endl; // ошибка
    }
    catch (const error& e) {
        cout << e.what() << endl;
    }

    List B;
    B.push_back(40);
    B.push_back(50);

    cout << "List B: ";
    B.print();

    List C = A + B;
    cout << "List C (A+B): ";
    C.print();

    List D = A + 5;
    cout << "List D (5 + A): ";
    D.print();

    return 0;
}
