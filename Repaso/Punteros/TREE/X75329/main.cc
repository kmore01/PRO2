#include "ArbIOint.hh"

int main () {
    Arbre<int> a;
    llegir_arbre_int(a, 0);
    Arbre<int> res;
    cout << a.freq(1) << endl;
}