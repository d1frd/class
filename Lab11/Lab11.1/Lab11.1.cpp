#include <iostream>
#include <deque>

using namespace std;

// Функция для создания и заполнения контейнера
deque<double> createAndFillContainer() {
    deque<double> container;
    double value;

    cout << "Введите элементы контейнера (введите 'q' для завершения ввода):" << endl;
    while (cin >> value) {
        container.push_back(value);
    }
    cin.clear(); // Очистка состояния потока
    cin.ignore(10000, '\n'); // Игнорирование оставшегося ввода

    return container;
}

// Задание 3: Найти максимальный элемент и добавить его в конец контейнера
void addMaxElementToEnd(deque<double>& container) {
    if (!container.empty()) {
        double maxElement = container[0];
        for (size_t i = 1; i < container.size(); ++i) {
            if (container[i] > maxElement) {
                maxElement = container[i];
            }
        }
        container.push_back(maxElement);
        cout << "Максимальный элемент " << maxElement << " добавлен в конец контейнера." << endl;
    }
}

// Задание 4: Найти элементы с ключами из заданного диапазона и удалить их из контейнера
void removeElementsInRange(deque<double>& container, double minValue, double maxValue) {
    for (size_t i = 0; i < container.size(); ) {
        if (container[i] >= minValue && container[i] <= maxValue) {
            container.erase(container.begin() + i); // Удаляем элемент
        }
        else {
            ++i; // Переходим к следующему элементу
        }
    }
    cout << "Элементы в диапазоне [" << minValue << ", " << maxValue << "] удалены." << endl;
}

// Задание 5: К каждому элементу добавить среднее арифметическое контейнера
void addAverageToElements(deque<double>& container) {
    if (!container.empty()) {
        double sum = 0.0;
        for (size_t i = 0; i < container.size(); ++i) {
            sum += container[i];
        }
        double average = sum / container.size();

        for (size_t i = 0; i < container.size(); ++i) {
            container[i] += average;
        }
        cout << "К каждому элементу добавлено среднее арифметическое: " << average << endl;
    }
}

// Функция для вывода элементов контейнера
void printContainer(const deque<double>& container) {
    cout << "Элементы контейнера: ";
    for (size_t i = 0; i < container.size(); ++i) {
        cout << container[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Создание и заполнение контейнера
    deque<double> container = createAndFillContainer();

    // Вывод элементов контейнера
    printContainer(container);

    // Задание 3
    addMaxElementToEnd(container);

    // Вывод элементов после добавления максимального элемента
    printContainer(container);

    // Задание 4
    double minValue, maxValue;
    cout << "Введите диапазон для удаления элементов (min max): ";
    cin >> minValue >> maxValue;
    removeElementsInRange(container, minValue, maxValue);

    // Вывод элементов после удаления
    printContainer(container);

    // Задание 5
    addAverageToElements(container);

    // Вывод окончательных элементов контейнера
    printContainer(container);

    return 0;
}
