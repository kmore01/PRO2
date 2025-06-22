#include "treeOfHeights.hh"

typedef BinTree<int> BT;

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a arrel la seva alçada.
BinTree<int> treeOfHeights(BinTree<int> t) {
    // Caso base
    if (t.empty()) return BinTree<int>();
    // Caso general
    BT left = treeOfHeights(t.left());
    BT right = treeOfHeights(t.right());
    
    int nodo = 0;
    if (not left.empty() and not right.empty()) {
        nodo = max(left.value(), right.value());
    }
    else if (not left.empty()) {
        nodo = left.value();
    }
    else if (not t.right().empty()){
        nodo = right.value();
    }
    // else nodo = 0;
    
    return BT(nodo + 1, left, right);
}
