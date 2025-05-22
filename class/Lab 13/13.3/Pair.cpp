#include "Pair.h"

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

Pair& Pair::operator--() {
    --first;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp = *this;
    second--;
    return temp;
}

bool operator<(const Pair& p, const Pair& q) {
    if (p.first < q.first) {
        return true;
    }
    else if (p.first > q.first) {
        return false;
    }
    else {
        return p.second < q.second;
    }
}

bool operator>(const Pair& p, const Pair& q) {
    if (p.first > q.first) {
        return true;
    }
    else if (p.first < q.first) {
        return false;
    }
    else {
        return p.second > q.second;
    }
}

istream& operator>>(istream& in, Pair& p) {
    cout << "first? "; in >> p.first;
    cout << "second? "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    return out << p.first << ":" << p.second;
}
