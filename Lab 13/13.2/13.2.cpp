#include <iostream>
#include <stack>

using namespace std;

// Определение класса Pair
class Pair {
private:
    int first;
    double second;

public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair(const Pair& p) : first(p.first), second(p.second) {}
    ~Pair() {}

    int get_first() const { return first; }
    double get_second() const { return second; }
    void set_first(int f) { first = f; }
    void set_second(double s) { second = s; }

    // Перегруженные операции
    Pair& operator=(const Pair&);

    friend bool operator<(const Pair& p, const Pair& q);
    friend bool operator>(const Pair& p, const Pair& q);
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

bool operator<(const Pair& p, const Pair& q) {
    return p.first < q.first;
}

bool operator>(const Pair& p, const Pair& q) {
    return p.first > q.first;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "first? "; in >> p.first;
    cout << "second? "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    return out << p.first << ":" << p.second;
}

// Функция для заполнения стека
void fillStack(stack<Pair>& myStack) {
    int n;
    cout << "Введите количество элементов для добавления в стек: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Pair value;
        cin >> value; // Используем перегруженный оператор ввода
        myStack.push(value); // Добавляем элемент в стек
    }
}

// Функция для замены элементов
void replaceInStack(stack<Pair>& myStack, int oldFirst, int newFirst) {
    stack<Pair> tempStack;

    while (!myStack.empty()) {
        Pair current = myStack.top();
        myStack.pop();

        if (current.get_first() == oldFirst) {
            current.set_first(newFirst);
        }

        tempStack.push(current);
    }

    // Возвращаем элементы обратно в оригинальный стек
    while (!tempStack.empty()) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }
}

// Функция для удаления элементов
void removeFromStack(stack<Pair>& myStack, int minKey, int maxKey) {
    stack<Pair> tempStack;

    while (!myStack.empty()) {
        Pair current = myStack.top();
        myStack.pop();

        if (current.get_first() < minKey || current.get_first() > maxKey) {
            tempStack.push(current);
        }
    }

    // Возвращаем элементы обратно в оригинальный стек
    while (!tempStack.empty()) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }
}

// Функция для поиска максимального элемента и добавления его в конец
void addMaxToEnd(stack<Pair>& myStack) {
    if (myStack.empty()) return;

    Pair maxElement = myStack.top();
    stack<Pair> tempStack;

    while (!myStack.empty()) {
        Pair current = myStack.top();
        myStack.pop();

        if (current > maxElement) {
            maxElement = current;
        }

        tempStack.push(current);
    }

    // Возвращаем элементы обратно в оригинальный стек
    while (!tempStack.empty()) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }

    // Добавляем максимальный элемент в стек
    myStack.push(maxElement);
}

// Функция для добавления среднего арифметического к элементам стека
void addAverageToElements(stack<Pair>& myStack) {
    if (myStack.empty()) return;

    double sum = 0.0;
    int count = 0;

    stack<Pair> tempStack;

    // Считаем сумму и количество элементов
    while (!myStack.empty()) {
        Pair current = myStack.top();
        myStack.pop();

        sum += current.get_second();
        count++;
        tempStack.push(current);
    }
    double average = sum / count;

    // Добавляем среднее арифметическое к каждому элементу
    while (!tempStack.empty()) {
        Pair current = tempStack.top();
        tempStack.pop();

        current.set_second(current.get_second() + average);
        myStack.push(current);
    }
}

// Функция для сортировки стека по возрастанию ключевого поля
void sortStack(stack<Pair>& myStack) {
    stack<Pair> sortedStack;

    while (!myStack.empty()) {
        Pair current = myStack.top();
        myStack.pop();

        // Вставляем элемент в отсортированный стек
        while (!sortedStack.empty() && sortedStack.top() > current) {
            myStack.push(sortedStack.top());
            sortedStack.pop();
        }

        sortedStack.push(current);

        // Возвращаем элементы обратно в оригинальный стек
        while (!myStack.empty()) {
            sortedStack.push(myStack.top());
            myStack.pop();
        }

        // Переносим отсортированный стек обратно в оригинальный стек
        while (!sortedStack.empty()) {
            myStack.push(sortedStack.top());
            sortedStack.pop();
        }
    }
}

// Функция для поиска элемента по ключевому полю
void findInStack(stack<Pair>& myStack, int key) {
    stack<Pair> tempStack;
    bool found = false;

    while (!myStack.empty()) {
        Pair current = myStack.top();
        myStack.pop();

        if (current.get_first() == key) {
            cout << "Элемент найден: " << current << endl;
            found = true;
        }

        tempStack.push(current);
    }

    if (!found) {
        cout << "Элемент с ключом " << key << " не найден." << endl;
    }

    // Возвращаем элементы обратно в оригинальный стек
    while (!tempStack.empty()) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }
}

// Функция для вывода элементов стека
void printStack(stack<Pair>& myStack) {
    stack<Pair> tempStack;

    while (!myStack.empty()) {
        tempStack.push(myStack.top());
        myStack.pop();
    }

    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        myStack.push(tempStack.top()); // Возвращаем элементы обратно в стек
        tempStack.pop();
    }

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    stack<Pair> myStack;

    // Заполнение стека
    fillStack(myStack);

    cout << "Изначальные элементы стека: ";
    printStack(myStack);

    // Задание 3: Найти максимальный элемент и добавить его в конец контейнера
    addMaxToEnd(myStack);

    cout << "После добавления максимального элемента: ";
    printStack(myStack);

    // Задание 4: Удалить элементы в диапазоне [minKey, maxKey]
    int minKey, maxKey;

    cout << "Введите минимальное значение диапазона для удаления (по первому элементу): ";
    cin >> minKey;

    cout << "Введите максимальное значение диапазона для удаления (по первому элементу): ";
    cin >> maxKey;

    removeFromStack(myStack, minKey, maxKey);

    cout << "После удаления элементов в диапазоне [" << minKey << ", " << maxKey << "]: ";
    printStack(myStack);

    // Задание 5: К каждому элементу добавить среднее арифметическое контейнера
    addAverageToElements(myStack);

    cout << "После добавления среднего арифметического к каждому элементу: ";
    printStack(myStack);

    // Сортировка по возрастанию ключевого поля
    sortStack(myStack);
    cout << "Стек после сортировки по возрастанию ключевого поля: ";
    printStack(myStack);

    // Поиск элемента по ключевому полю
    int keyToFind;
    cout << "Введите ключ для поиска: ";
    cin >> keyToFind;
    findInStack(myStack, keyToFind);

    return 0;
}
