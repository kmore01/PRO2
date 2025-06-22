#include "numLeftRight.hh"

BinTree<int> numLeftRight_aux(BinTree<int> t, int izq, int der) {
    // Caso base
    if (t.empty()) return BinTree<int>();
    // Caso general
    BinTree<int> arbol_izq = numLeftRight_aux(t.left(), izq + 1, der);
    BinTree<int> arbol_der = numLeftRight_aux(t.right(), izq, der + 1);
    if (t.value() == -1) {
        return BinTree<int>(izq, arbol_izq, arbol_der);
    }
    else return BinTree<int>(der, arbol_izq, arbol_der);
}

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
//       Els valors guardats a T son tots -1 o -2.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui p una posició qualsevol de T'.
//       Si T té un valor -1 a posició p, llavors T' té el nombre de cops que
//       s'escull fill-esquerra en el camí des de l'arrel fins a posició p.
//       Si T té un valor -2 a posició p, llavors T' té el nombre de cops que
//       s'escull fill-dret en el camí des de l'arrel fins a posició p.
BinTree<int> numLeftRight(BinTree<int> t) {
    return numLeftRight_aux(t, 0, 0);
}
