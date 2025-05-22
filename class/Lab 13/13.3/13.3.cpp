#include <iostream>
#include <set>
#include "Pair.h"

using namespace std;

void fillSet(set<Pair>& mySet) {
    int n;
    cout << "Введите количество элементов для добавления в контейнер: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Pair value;
        cin >> value; // Используем перегруженный оператор ввода
        mySet.insert(value); // Добавляем элемент в set
    }
}

void removeInRange(set<Pair>& mySet, int minFirst, int maxFirst) {
    for (auto it = mySet.lower_bound(Pair(minFirst, 0)); it != mySet.end() && it->get_first() <= maxFirst; ) {
        it = mySet.erase(it); // Удаляем элемент и получаем следующий итератор
    }
}

void printSet(const set<Pair>& mySet) {
    if (mySet.empty()) {
        cout << "Контейнер пуст." << endl;
        return;
    }

    for (const auto& item : mySet) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    set<Pair> mySet;

    // Заполнение контейнера
    fillSet(mySet);
    cout << "Изначальные элементы контейнера: ";
    printSet(mySet);

    // Задание 4: Удалить элементы в диапазоне [minKey, maxKey]
    int minKey, maxKey;
    cout << "Введите минимальное значение диапазона для удаления (по первому элементу): ";
    cin >> minKey;
    cout << "Введите максимальное значение диапазона для удаления (по первому элементу): ";
    cin >> maxKey;

    removeInRange(mySet, minKey, maxKey);
    cout << "После удаления элементов в диапазоне [" << minKey << ", " << maxKey << "]: ";
    printSet(mySet);

    return 0;
}
