#include <iostream>
#include "BinTree.hh"
#include "treeOfSizes.hh"

using namespace std;
typedef BinTree<int> BT;

int getValue(BT t) {
    if (t.empty()) return 0;
    return t.value();
}

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a valor a l'arrel el nombre de nodes
//       del corresponent subarbre a t.
BinTree<int> treeOfSizes(BinTree<int> t) {
    // Caso base
    if (t.empty()) return BT();
    // Caso general
    else {
        BT left = treeOfSizes(t.left());
        BT right = treeOfSizes(t.right());

        if (t.left().empty() and t.right().empty()) return BT(1, BT(), BT());
        else return BT(1 + getValue(left) + getValue(right), left, right);
    }
}