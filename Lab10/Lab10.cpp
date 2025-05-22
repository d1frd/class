#include "Pair.h"
#include "fileWork.h"

int main() {
    char filename[30];
    int choice;

    do {
        cout << "\nMenu:\n"
            << "1. Create file\n"
            << "2. Print file\n"
            << "3. Delete all entries equal to a value\n"
            << "4. Decrease all equal entries by L\n"
            << "5. Insert K records after value\n"
            << "0. Exit\n"
            << "Your choice: ";
        cin >> choice;

        if (choice == 0) break;

        Pair p;
        double L;
        int K;

        cout << "Enter filename: ";
        cin >> filename;

        switch (choice) {
        case 1:
            make_file(filename); break;
        case 2:
            if (print_file(filename) == 0) cout << "File is empty or not found.\n";
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> p;
            delete_equal(filename, p);
            break;
        case 4:
            cout << "Enter value to decrease: ";
            cin >> p;
            cout << "Enter L: ";
            cin >> L;
            decrease_equal(filename, p, L);
            break;
        case 5:
            cout << "Enter value to insert after: ";
            cin >> p;
            cout << "Enter K (number of elements to insert): ";
            cin >> K;
            insert_after(filename, p, K);
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (true);

    return 0;
}
