#include <iostream>
#include <deque>
#include "Pair.h"

using namespace std;

// Функция для заполнения контейнера
void fillDeque(deque<Pair>& myDeque) {
    int n;
    cout << "Введите количество элементов для добавления в контейнер: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Pair value;
        cin >> value; // Используем перегруженный оператор ввода
        myDeque.push_back(value); // Добавляем элемент в deque
    }
}

// Задание 3: Найти максимальный элемент и добавить его в конец контейнера
void addMaxToEnd(deque<Pair>& myDeque) {
    if (myDeque.empty()) {
        cout << "Контейнер пуст, нельзя найти максимальный элемент." << endl;
        return;
    }

    Pair maxElement = myDeque[0];
    for (const auto& item : myDeque) {
        if (item > maxElement) {
            maxElement = item;
        }
    }

    myDeque.push_back(maxElement);
}

// Задание 4: Удалить элементы из заданного диапазона
void removeInRange(deque<Pair>& myDeque, int minFirst, int maxFirst) {
    myDeque.erase(remove_if(myDeque.begin(), myDeque.end(),
        [minFirst, maxFirst](const Pair& p) {
            return p.get_first() >= minFirst && p.get_first() <= maxFirst;
        }), myDeque.end());
}

// Задание 5: К каждому элементу добавить среднее арифметическое контейнера
void addAverageToElements(deque<Pair>& myDeque) {
    if (myDeque.empty()) {
        cout << "Контейнер пуст." << endl;
        return;
    }

    double sum = 0.0;
    for (const auto& item : myDeque) {
        sum += item.get_second();
    }

    double average = sum / myDeque.size();

    for (auto& item : myDeque) {
        item.set_second(item.get_second() + average);
    }
}

// Функция для вывода элементов контейнера
void printDeque(const deque<Pair>& myDeque) {
    if (myDeque.empty()) {
        cout << "Контейнер пуст." << endl;
        return;
    }

    for (const auto& item : myDeque) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    deque<Pair> myDeque;

    // Заполнение контейнера
    fillDeque(myDeque);

    cout << "Изначальные элементы контейнера: ";
    printDeque(myDeque);

    // Задание 3: Найти максимальный элемент и добавить его в конец контейнера
    addMaxToEnd(myDeque);

    cout << "После добавления максимального элемента: ";
    printDeque(myDeque);

    // Задание 4: Удалить элементы в диапазоне [minKey, maxKey]
    int minKey, maxKey;
    cout << "Введите минимальное значение диапазона для удаления (по первому элементу): ";
    cin >> minKey;
    cout << "Введите максимальное значение диапазона для удаления (по первому элементу): ";
    cin >> maxKey;

    removeInRange(myDeque, minKey, maxKey);

    cout << "После удаления элементов в диапазоне [" << minKey << ", " << maxKey << "]: ";
    printDeque(myDeque);

    // Задание 5: К каждому элементу добавить среднее арифметическое контейнера
    addAverageToElements(myDeque);

    cout << "После добавления среднего арифметического к каждому элементу: ";
    printDeque(myDeque);

    return 0;
}
