#include "ArbIOint.hh"

int main () {
    ArbreNari<int> a;
    llegir_arbre_int(a, 0);
    Arbre<int> res;
    a.arb_sumes(res);
    escriure_arbre_int(res);
}