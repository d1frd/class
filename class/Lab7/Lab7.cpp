
#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    Pair p1(2, 2.5);            // Создание пары
    List<Pair> a(3, p1);        // Список из 3 одинаковых пар
    cout << "Список a (инициализированный):\n" << a << endl;

    cout << "Введите элементы списка a:\n";
    cin >> a;
    cout << "Список a после ввода:\n" << a << endl;

    List<Pair> b(a);            // Копирование списка
    cout << "Список b (копия a):\n" << b << endl;

    List<Pair> c = a + b;       // Поэлементное сложение списков
    cout << "Список c = a + b:\n" << c << endl;
    cout << "Итерация по списку b:\n";
    for (Iterator<Pair> iter = b.first(); iter != b.last(); ++iter)
        cout << *iter << '\n';

    return 0;
}
/*    // Пример использования
    List<int> list1(3, 5);
    cout << "List 1: " << list1 << endl;  // Output: 5 5 5

    List<int> list2(2, 10);
    cout << "List 2: " << list2 << endl;  // Output: 10 10

    List<int> list3 = list1 + list2;
    cout << "List 1 + List 2: " << list3 << endl;  // Output: 5 5 5 10 10

    List<int> list4 = list1 + 2;
    cout << "List 1 + 2: " << list4 << endl;  // Output: 7 7 7

    cout << "List 1[0]: " << list1[0] << endl;  // Output: 5
    list1[1] = 20;
    cout << "List 1[1] after assignment: " << list1 << endl;  // Output: 5 20 5

    List<int> list5;
    cout << "Enter some integers for list5 (separated by spaces): ";
    cin >> list5;
    cout << "List 5: " << list5 << endl;

    return 0;
}

*/
