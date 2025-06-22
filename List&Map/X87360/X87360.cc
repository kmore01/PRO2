//

#include <iostream>
#include <list>

using namespace std;

// Funcion que lee listas de enteros
list<int> LeerLista() {
    list<int> a;
    int num;
    while (cin >> num and num != -0) {
        a.push_back(num);
    }

    return a;
}

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int> &uno, const list<int> &dos) {
    // Utilizaremos dos iteradores para ir comprobando hacia donde avanzar
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();
    int cota_inferior = 0, cota_superior;
    while (it1 != uno.end() and it2 != dos.end()) {
        if (*it1 < *it2) ++it1;
        else if (cota_inferior != 0 and *it2 <= *it1) {
            cota_superior = *it1;
            ++it2;
        }
        else if (*it1 >= *it2) {
            cota_inferior = *it2;
            ++it1;
            ++it2;
        }
    }

    while (not uno.empty()) {
        uno.erase(uno.begin());
    }

    uno.push_back(cota_inferior);
    uno.push_back(cota_superior);

    cout << '[' << cota_inferior << ' ' << cota_superior << ']' << endl;
}

int main () {
    list<int> l1 = LeerLista();
    list<int> l2 = LeerLista();
    inter(l1, l2);
}
