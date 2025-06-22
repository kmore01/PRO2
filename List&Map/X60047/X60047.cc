// Programa que busca el numero del medio de una lista

#include <iostream>
#include <list>

using namespace std;

int main() {
    string accion;
    list<int> L;
    list<int>::iterator it = L.end();

    while (cin >> accion) {
        int num;
        
        if (accion == "push_front") {
            cin >> num;
            L.push_front(num);
            if (L.size() == 1) --it;
            else if (L.size() % 2 == 0) --it;
        }

        else if (accion == "push_back") {
            cin >> num;
            L.push_back(num);
            if (L.size() % 2 != 0) ++it;
        }

        else if (accion == "pop_front") {
            if (not L.empty()) {
                if (L.size() == 1) it = L.end();
                else if (L.size() % 2 == 0) ++it;
                L.pop_front();
            }
            else cout << "error" << endl;
        }

        else if (accion == "pop_back") {
            if (not L.empty()) {
                if (L.size() == 1) it = L.end();
                else if (L.size() % 2 != 0) --it;
                L.pop_back();
            }
            else cout << "error" << endl;
        }

        else {
            if (not L.empty() and L.size() % 2 != 0) cout << *it << endl;
            else cout << "error" << endl;
        }
    }
}