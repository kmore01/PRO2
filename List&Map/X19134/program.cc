#include <iostream>
#include <list>
#include "LlistaIOParInt.hh"

using namespace std;

void BuscarNum(const list<ParInt> &a, int nbuscado) {
    int repeticiones = 0, suma = 0;
    for (list<ParInt>::const_iterator it = a.begin(); it != a.end(); ++it) {
        ParInt aux = *it;
        if (aux.primer() == nbuscado) {
            ++repeticiones;
            suma += aux.segon();
        }
    }

    cout << repeticiones << ' ' << suma << endl;
}

int main () {
    list<ParInt> input;
    LlegirLlistaParInt(input);
    int num_buscado;
    cin >> num_buscado;
    cout << num_buscado << ' ';
    BuscarNum(input, num_buscado);
}