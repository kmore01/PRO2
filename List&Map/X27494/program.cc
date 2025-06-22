#include <iostream>
#include <list>
using namespace std;

// Procedimiento que calcula el maximo y minimo de una lista
void calcular(list<int>& l, int& min, int& max) {
    if (not l.empty()) {
        max = min = *l.begin();
        for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
            if (*it > max) max = *it;
            if (*it < min) min = *it;
        }
    }
}

// Procedimiento que elimina un elemento de una lista
void eliminar(list<int>& l, int& n, double& total) {
    if (not l.empty()) {
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            if (*it == n) {
                it = l.erase(it);
                total -= n;
                return;
            }
            else ++it;
        }
    }
}

int main() {
    int codi, num, min, max;
    double total = 0;
    list<int> l;
    while (cin >> codi >> num and not (codi == 0 and num == 0)) {
        if (codi == -1) {
            if (l.empty()) {
                min = max = num;
            }
            else {
                if (max < num) max = num;
                if (min > num) min = num;
            }
            l.push_back(num);
            total += num;
        }
        else if (codi == -2) {
            eliminar(l, num, total);
            if (max == num or min == num) calcular(l, min, max);
        }

        if (not l.empty()) cout << min << ' ' << max << ' ' << total / l.size() << endl;
        else cout << 0 << endl;
    }
}
