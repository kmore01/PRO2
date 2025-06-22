#include "ArbIOint.hh"

int main () {
    Arbre<int> a;
    llegir_arbre_int(a, 0);
    Arbre<int> res;
    a.sub_arrel(res, -2);
    escriure_arbre_int(res);
}