#include "sumAtDepthEven.hh"

int sumAtDepthEven_aux(BinTree<int> t, bool par) {
    // Caso base
    if (t.empty()) return 0;
    // Caso general
    int izq = sumAtDepthEven_aux(t.left(), not par);
    int der = sumAtDepthEven_aux(t.right(), not par);
    if (par) return t.value() + izq + der;
    else return izq + der;
}

// Pre:
// Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinTree<int> t) {
    return sumAtDepthEven_aux(t, true);
}