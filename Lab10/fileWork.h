#pragma once
#include "Pair.h"
#include <fstream>
#include <iostream>
using namespace std;

int make_file(const char* fname) {
    fstream file(fname, ios::out | ios::trunc);
    if (!file) return -1;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Pair p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        file << p;
    }
    file.close();
    return n;
}

int print_file(const char* fname) {
    fstream file(fname, ios::in);
    if (!file) return -1;

    Pair p;
    int count = 0;
    while (file >> p) {
        cout << p;
        count++;
    }
    file.close();
    return count;
}

int delete_equal(const char* fname, const Pair& target) {
    fstream in(fname, ios::in);
    fstream out("temp", ios::out | ios::trunc);
    if (!in || !out) return -1;

    Pair p;
    int count = 0;
    while (in >> p) {
        if (!(p == target)) {
            out << p;
            count++;
        }
    }
    in.close();
    out.close();
    remove(fname);
    rename("temp", fname);
    return count;
}

int decrease_equal(const char* fname, const Pair& target, double L) {
    fstream in(fname, ios::in);
    fstream out("temp", ios::out | ios::trunc);
    if (!in || !out) return -1;

    Pair p;
    int modified = 0;
    while (in >> p) {
        if (p == target) {
            p.decrease_by(L);
            modified++;
        }
        out << p;
    }
    in.close();
    out.close();
    remove(fname);
    rename("temp", fname);
    return modified;
}

int insert_after(const char* fname, const Pair& target, int K) {
    fstream in(fname, ios::in);
    fstream out("temp", ios::out | ios::trunc);
    if (!in || !out) return -1;

    Pair p;
    int inserted = 0;
    while (in >> p) {
        out << p;
        if (p == target) {
            for (int i = 0; i < K; ++i) {
                Pair newP;
                cin >> newP;
                out << newP;
                inserted++;
            }
        }
    }
    in.close();
    out.close();
    remove(fname);
    rename("temp", fname);
    return inserted;
}
