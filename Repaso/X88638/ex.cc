#include "BinTree.hh"

int numTwins(BinTree<int> t) {
    int twins = 0;
    if (not t.empty()) {
        if (t.left().empty()) return numTwins(t.right());
        else if (t.right().empty()) return numTwins(t.left());
        else {
            // Comprovamos si el hijo izquierdo y derecho son nodos hermanos
            if (t.left().value() == t.right().value()) twins = 1;
            // Sumamos todos los nodos hermanos llamando recursivamente a la funcion
            return twins + numTwins(t.left()) + numTwins(t.right());
        }
    }
    else return twins;
}