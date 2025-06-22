#include "postorderTree.hh"
#include "BinTree.hh"

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui n1,n2,...,nk els nodes de T' en el recorregut en postordre de T'.
//       Llavors, n1 guarda el valor 1, n2 guarda el valor 2, ..., nk guarda el valor k.
BinTree<int> rec(BinTree<int> t, int &valor) {
    // Caso base
    if (t.empty()) return BinTree<int>();
    // Caso general
    BinTree<int> izq = rec(t.left(), valor);
    BinTree<int> der = rec(t.right(), valor);
    ++valor;
    return BinTree<int>(valor, izq, der);
}

BinTree<int> postorderTree(BinTree<int> t) {
    int valor = 0;
    return rec(t, valor);
}
