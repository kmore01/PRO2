#include "ArbIOint.hh"

int main () {
    Arbre<int> a;
    llegir_arbre_int(a, 0);
    cout << a.max_suma_cami() << endl;
}