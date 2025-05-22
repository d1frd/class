#include <iostream>
#include <list>

template<typename T>
class CustomList {
private:
    std::list<T> elements;

public:
    void add(const T& item) {
        elements.push_back(item);
    }

    void remove(const T& item) {
        elements.remove(item);
    }

    void addMaxToEnd() {
        if (elements.empty()) return;

        T maxElement = elements.front(); // Начнем с первого элемента
        for (const auto& item : elements) {
            if (item > maxElement) {
                maxElement = item; // Находим максимальный элемент
            }
        }
        add(maxElement); // Добавляем максимальный элемент в конец
    }

    void removeInRange(const T& minKey, const T& maxKey) {
        auto it = elements.begin();
        while (it != elements.end()) {
            if (*it >= minKey && *it <= maxKey) {
                it = elements.erase(it); // Удаляем элемент и получаем следующий итератор
            }
            else {
                ++it; // Переходим к следующему элементу
            }
        }
    }

    void addAverageToElements() {
        if (elements.empty()) return;

        double sum = 0;
        size_t count = 0;

        for (const auto& item : elements) {
            sum += static_cast<double>(item);
            ++count; // Считаем количество элементов
        }

        double avg = sum / count;

        // Обновляем элементы
        for (auto& item : elements) {
            item += static_cast<T>(avg); // Добавляем среднее арифметическое к каждому элементу
        }
    }

    void print() const {
        if (elements.empty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        for (const auto& item : elements) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    CustomList<int> list;
    int n;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Введите элемент " << (i + 1) << ": ";
        std::cin >> value;
        list.add(value);
    }

    std::cout << "Изначальные элементы списка: ";
    list.print();

    // Задание 3: Найти максимальный элемент и добавить его в конец контейнера
    list.addMaxToEnd();
    std::cout << "После добавления максимального элемента в конец: ";
    list.print();

    // Задание 4: Удалить элементы в диапазоне [2, 4]
    int minKey, maxKey;
    std::cout << "Введите минимальное значение диапазона для удаления: ";
    std::cin >> minKey;
    std::cout << "Введите максимальное значение диапазона для удаления: ";
    std::cin >> maxKey;

    list.removeInRange(minKey, maxKey);
    std::cout << "После удаления элементов в диапазоне [" << minKey << ", " << maxKey << "]: ";
    list.print();

    // Задание 5: Добавить среднее арифметическое к каждому элементу
    list.addAverageToElements();
    std::cout << "После добавления среднего арифметического к каждому элементу: ";
    list.print();

    return 0;
}

