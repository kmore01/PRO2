#include <iostream>
#include "BinTreeIOint.hh"
#include "BinTree.hh"

using namespace std;
typedef BinTree<int> BT;

int altura (const BT &t) {
    // Caso base
    if (t.empty()) return 0;
    // Caso general
    else {
        if (t.left().empty() and t.right().empty()) return 1;
        else return 1 + max(altura(t.left()), altura(t.right()));
    }
}

/* Pre: a=A */
/* Post: agd es un arbre amb la mateixa estructura que A on cada
node conte el grau de desequilibri del subarbre d'A corresponent */
void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    // Caso base
    if (a.empty()) return;
    // Caso general
    else {
        BT left;
        BT right;
        int dif = altura(a.left()) - altura(a.right());
        arbre_graus_desequilibri(a.left(), left);
        arbre_graus_desequilibri(a.right(), right);
        agd = BT(dif, left, right);
    }
}