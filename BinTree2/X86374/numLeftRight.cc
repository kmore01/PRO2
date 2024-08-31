#include <iostream>
#include "BinTree.hh"
#include "numLeftRight.hh"

using namespace std;
typedef BinTree<int> BT;

BT camino(BT t, int izq, int der) {
    // Caso base
    if (t.empty()) return BT();
    // Caso general
    else {
        BT left = camino(t.left(), izq + 1, der);
        BT right = camino(t.right(), izq, der + 1);
        // Tenemos que deolver las veces de izquierda
        if (t.value() == -1) {
            return BT(izq, left, right);
        }
        // Tenemos que deolver las veces de derecha
        else {
            return BT(der, left, right);
        }
    }
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
    int izq = 0, der = 0;
    return camino(t, izq, der);
}