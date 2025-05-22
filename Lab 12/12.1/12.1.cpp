#include <iostream>
#include <set>

using namespace std;

void fillSet(set<double>& mySet) {
    int n;
    cout << "Введите количество элементов для добавления в контейнер: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double value;
        cout << "Введите элемент " << (i + 1) << ": ";
        cin >> value;
        mySet.insert(value); // Добавляем элемент в set
    }
}

void addMaxToEnd(set<double>& mySet) {
    if (mySet.empty()) return;

    double maxElement = *mySet.rbegin(); // Получаем максимальный элемент
    mySet.insert(maxElement); // Добавляем максимальный элемент в контейнер
}

void removeInRange(set<double>& mySet, double minKey, double maxKey) {
    for (auto it = mySet.lower_bound(minKey); it != mySet.end() && *it <= maxKey; ) {
        it = mySet.erase(it); // Удаляем элемент и получаем следующий итератор
    }
}

void addAverageToElements(set<double>& mySet) {
    if (mySet.empty()) return;

    double sum = 0.0;
    int count = 0;

    // Подсчитываем сумму и количество элементов
    for (const auto& item : mySet) {
        sum += item;
        count++;
    }

    double average = sum / count; // Вычисляем среднее арифметическое

    set<double> updatedSet; // Новый набор для обновленных значений
    for (const auto& item : mySet) {
        updatedSet.insert(item + average); // Добавляем среднее арифметическое к каждому элементу
    }
    mySet.swap(updatedSet); // Обновляем оригинальный набор
}

void printSet(const set<double>& mySet) {
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
    set<double> mySet;

    // Заполнение контейнера
    fillSet(mySet);
    cout << "Изначальные элементы контейнера: ";
    printSet(mySet);

    // Задание 3: Найти максимальный элемент и добавить его в конец контейнера
    addMaxToEnd(mySet);
    cout << "После добавления максимального элемента в конец: ";
    printSet(mySet);

    // Задание 4: Удалить элементы в диапазоне [minKey, maxKey]
    double minKey, maxKey;
    cout << "Введите минимальное значение диапазона для удаления: ";
    cin >> minKey;
    cout << "Введите максимальное значение диапазона для удаления: ";
    cin >> maxKey;

    removeInRange(mySet, minKey, maxKey);
    cout << "После удаления элементов в диапазоне [" << minKey << ", " << maxKey << "]: ";
    printSet(mySet);

    // Задание 5: Добавить среднее арифметическое к каждому элементу
    addAverageToElements(mySet);
    cout << "После добавления среднего арифметического к каждому элементу: ";
    printSet(mySet);

    return 0;
}
