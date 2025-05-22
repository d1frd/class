#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include "pair.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    deque<Pair> myDeque;

    // Заполнение контейнера
    int n;
    cout << "Введите количество элементов для добавления в контейнер: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Pair p;
        cin >> p; // Используем перегруженный оператор ввода
        myDeque.push_back(p);
    }

    // Найти максимальный элемент и добавить его в конец контейнера
    if (!myDeque.empty()) {
        Pair maxElement = myDeque[0];
        for (size_t i = 1; i < myDeque.size(); ++i) {
            if (myDeque[i] > maxElement) {
                maxElement = myDeque[i];
            }
        }
        myDeque.push_back(maxElement);
        cout << "Максимальный элемент добавлен в конец контейнера: " << maxElement << endl;
    }

    // Удалить элементы с ключами из заданного диапазона
    int lowerBound, upperBound;
    cout << "Введите диапазон для удаления (нижний и верхний пределы): ";
    cin >> lowerBound >> upperBound;

    for (size_t i = 0; i < myDeque.size();) {
        if (myDeque[i].get_first() >= lowerBound && myDeque[i].get_first() <= upperBound) {
            myDeque.erase(myDeque.begin() + i); // Удаляем элемент
        }
        else {
            ++i; // Переходим к следующему элементу
        }
    }

    cout << "Контейнер после удаления элементов в заданном диапазоне:\n";
    for (size_t i = 0; i < myDeque.size(); ++i) {
        cout << myDeque[i] << endl;
    }

    // К каждому элементу добавить среднее арифметическое контейнера
    double sum = 0.0;
    for (size_t i = 0; i < myDeque.size(); ++i) {
        sum += myDeque[i].get_second();
    }

    double average = sum / myDeque.size();

    for (size_t i = 0; i < myDeque.size(); ++i) {
        myDeque[i].set_second(myDeque[i].get_second() + average);
    }
    cout << "Контейнер после добавления среднего арифметического:\n";
    for (size_t i = 0; i < myDeque.size(); ++i) {
        cout << myDeque[i] << endl;
    }

    // Сортировка по возрастанию и убыванию
    sort(myDeque.begin(), myDeque.end());

    cout << "Контейнер после сортировки по возрастанию:\n";
    for (size_t i = 0; i < myDeque.size(); ++i) {
        cout << myDeque[i] << endl;
    }

    sort(myDeque.rbegin(), myDeque.rend());

    cout << "Контейнер после сортировки по убыванию:\n";
    for (size_t i = 0; i < myDeque.size(); ++i) {
        cout << myDeque[i] << endl;
    }

    // Поиск заданного элемента
    int keyToFind;
    cout << "Введите ключ для поиска: ";
    cin >> keyToFind;

    bool found = false;
    for (size_t i = 0; i < myDeque.size(); ++i) {
        if (myDeque[i].get_first() == keyToFind) {
            cout << "Элемент найден: " << myDeque[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Элемент с ключом " << keyToFind << " не найден." << endl;
    }

    // Подсчет элементов с заданным условием
    int count = 0;

    for (size_t i = 0; i < myDeque.size(); ++i) {
        if (myDeque[i].get_first() == keyToFind) {
            count++;
        }
    }

    cout << "Количество элементов с ключом " << keyToFind << ": " << count << endl;

    // Дополнительная обработка элементов
    for (size_t i = 0; i < myDeque.size(); ++i) {
        cout << "Обрабатываем элемент: " << myDeque[i] << endl;
        // Здесь можно добавить любую дополнительную обработку
    }

    return 0;
}
