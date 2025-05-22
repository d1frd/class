#include <iostream>

class CustomType {
private:
    int value;

public:
    // Конструктор по умолчанию
    CustomType() : value(0) {}

    // Конструктор с параметром
    CustomType(int v) : value(v) {}

    // Метод для получения значения
    int getValue() const {
        return value;
    }

    // Перегрузка операторов
    bool operator<(const CustomType& other) const {
        return value < other.value;
    }

    bool operator>(const CustomType& other) const {
        return value > other.value;
    }

    CustomType operator+(double avg) const {
        return CustomType(value + static_cast<int>(avg));
    }

    friend std::ostream& operator<<(std::ostream& os, const CustomType& obj) {
        os << obj.value;
        return os;
    }
};

class ContainerAdapter {
private:
    CustomType* data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity) {
        CustomType* newData = new CustomType[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ContainerAdapter() : data(nullptr), capacity(0), size(0) {}

    ~ContainerAdapter() {
        delete[] data;
    }

    void add(const CustomType& item) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = item;
    }

    void remove(const CustomType& item) {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] < item || !(data[i] < item) && !(item < data[i])) { // Проверка на равенство
                for (size_t j = i; j < size - 1; ++j) {
                    data[j] = data[j + 1];
                }
                --size;
                break;
            }
        }
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Найти максимальный элемент и добавить его в конец контейнера
    void addMaxToEnd() {
        if (size == 0) return;
        CustomType maxElement = data[0];
        for (size_t i = 1; i < size; ++i) {
            if (data[i] > maxElement) {
                maxElement = data[i];
            }
        }
        add(maxElement);
    }

    // Удалить элементы в диапазоне
    void removeInRange(int minKey, int maxKey) {
        size_t newSize = 0;
        for (size_t i = 0; i < size; ++i) {
            if (!(data[i] < CustomType(minKey) || data[i] > CustomType(maxKey))) {
                data[newSize++] = data[i];
            }
        }
        size = newSize;
    }

    // Добавить среднее арифметическое к каждому элементу
    void addAverageToElements() {
        if (size == 0) return;

        double sum = 0;
        for (size_t i = 0; i < size; ++i) {
            sum += static_cast<double>(data[i].getValue());
        }
        double avg = sum / size;

        for (size_t i = 0; i < size; ++i) {
            data[i] = data[i] + avg;
        }
    }
};

// Глобальные функции для выполнения заданий
void executeTasks(ContainerAdapter& container) {
    // Найти максимальный элемент и добавить его в конец
    container.addMaxToEnd();
    std::cout << "After adding max to end: ";
    container.print();

    // Удалить элементы в диапазоне [2, 4]
    container.removeInRange(2, 4);
    std::cout << "After removing elements in range [2, 4]: ";
    container.print();

    // Добавить среднее арифметическое к каждому элементу
    container.addAverageToElements();
    std::cout << "After adding average to each element: ";
    container.print();
}

int main() {
    ContainerAdapter container;
    // Заполнение контейнера элементами пользовательского типа
    container.add(CustomType(1));
    container.add(CustomType(3));
    container.add(CustomType(5));
    container.add(CustomType(2));

    std::cout << "Initial container elements: ";
    container.print();

    // Выполнение всех заданий
    executeTasks(container);

    return 0;
}
