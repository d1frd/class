#include <iostream>
#include "List.h"
#include "Pairr.h"

int main() {
    setlocale(LC_ALL, "RU");
    List<Pair> lst;
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::cout << "Введите пары (int, double):\n";
    for (int i = 0; i < n; ++i) {
        Pair p;
        std::cin >> p;
        lst.pushback(p);
    }

    std::cout << "Список: ";
    lst.print();

    // Задание 3:
    lst.add_max_to_end();
    std::cout << "После добавления максимума: ";
    lst.print();

    // Задание 4:
    int low, high;
    std::cout << "Введите диапазон ключей для удаления (low high): ";
    std::cin >> low >> high;
    lst.delete_by_key_range(low, high);
    std::cout << "После удаления: ";
    lst.print();

    // Задание 5: 
    lst.add_average_to_all();
    std::cout << "После добавления среднего: ";
    lst.print();

    return 0;
}
