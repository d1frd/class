#include "List.h"
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    try {
        int size;
        cout << "Введите размер списков: ";
        cin >> size;

        List list1(size);
        cout << "Введите значения для List 1: ";
        for (int i = 0; i < size; ++i) {
            cin >> list1[i];
        }

        List list2(size);
        cout << "Введите значения для List 2: ";
        for (int i = 0; i < size; ++i) {
            cin >> list2[i];
        }

        cout << "List 1: " << list1 <<endl;
        cout << "List 2: " << list2 << endl;

        List sum = list1 + list2;
        cout << "Sum: " << sum << endl;

        List::Iterator it = list1.getIterator();
        cout << "Original Iterator Value: " << *it <<endl;

        int shift;
        cout << "Введите величину сдвига итератора влево: ";
        cin >> shift;

        try {
            List::Iterator new_it = it - shift;
            cout << "Iterator Value After Moving Left " << shift << ": " << *new_it << endl;
        }
        catch (const exception& e) {
            cout << "Исключение при работе с итератором: " << e.what() << endl;
        }

    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
