#include "treeOfSums.hh"

typedef BinTree<int> BT;

int getValue(BT t)
{
  if (t.empty()) return 0;
  return t.value();
}

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a arrel la suma dels nodes del corresponent subarbre a t.
BinTree<int> treeOfSums(BinTree<int> t) {
    // Caso base
    if (t.empty()) return BT();
    // Caso general
    BT izq = treeOfSums(t.left());
    BT der = treeOfSums(t.right());
    return BT(t.value() + getValue(izq) + getValue(der), izq, der);
}