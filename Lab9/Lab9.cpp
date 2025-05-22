#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    List A(3, 1); // Список из 3 элементов со значением 1
    List B(2, 2); // Список из 2 элементов со значением 2

    cout << "List A: " << A;
    cout << "List B: " << B;

    List C = A + B; // Складываем два списка
    cout << "List C (A+B): " << C;

    List D = C + 99; // Добавляем число 99 в начало
    cout << "List D (C+99): " << D;

    cout << "Элемент с индексом 2 в D: " << D[2] << endl;

    return 0;
}
