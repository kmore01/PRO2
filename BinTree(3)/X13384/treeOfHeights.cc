#include <iostream>
#include "BinTree.hh"
#include "treeOfHeights.hh"

using namespace std;
typedef BinTree<int> BT;

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a arrel la seva alçada.
BinTree<int> treeOfHeights(BinTree<int> t) {
    // Caso Base
    if (t.empty()) return BT();
    // Caso general
    else {
        BT t2;
        if (not t.left().empty() and not t.right().empty()) t2 = BT(-1, treeOfHeights(t.left()), treeOfHeights(t.right()));
        else if (t.left().empty() and not t.right().empty()) t2 = BT(-1, BT(), treeOfHeights(t.right()));
        else if (not t.left().empty() and t.right().empty()) t2 = BT(-1, treeOfHeights(t.left()), BT());

        else if (t.left().empty() and t.right().empty()) return BT(1,BT(),BT());

        if (not t2.left().empty() and not t2.right().empty()) return BT(max(t2.left().value(),t2.right().value()) + 1, t2.left(), t2.right());
        else if (t2.right().empty()) return BT(t2.left().value() + 1, t2.left(), t2.right());
        else return BT(t2.right().value() + 1, t2.left(), t2.right());
    }
}