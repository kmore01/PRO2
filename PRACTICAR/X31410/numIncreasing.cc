#include "numIncreasing.hh"
#include "BinTree.hh"

int numIncreasingAux(BinTree<int> t, int valor_padre, bool tiene_padre) {
    // Caso base
    if (t.empty()) return 0;
    // Caso general
    // Nodo actual
    int contador = 0;
    if (tiene_padre and t.value() > valor_padre) ++contador;

    // Sumamos las veces que un nodo es mayor que su padre en el subarbol 
    // izquierdo y derecho
    contador += numIncreasingAux(t.left(), t.value(), true);
    contador += numIncreasingAux(t.right(), t.value(), true);

    return contador;
}

// Pre:
// Post: Retorna el nombre de nodes de t que no son l'arrel de t i que guarden un valor
//       estríctament major que el valor guardat al seu node pare.
int numIncreasing(BinTree<int> t) {
    return numIncreasingAux(t, 0, false);
}
