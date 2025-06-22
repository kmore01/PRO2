#include "ArbGIOint.hh"

int main () {
    ArbreGen<int> a;
    llegir_arbre_int(a, 0);
    ArbreGen<int> res;
    cout << a.buscar(4) << endl;
}