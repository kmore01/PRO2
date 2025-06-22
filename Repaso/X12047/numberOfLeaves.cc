// Funcion que cuenta el numero de hojas que tiene un arbol binario

#include <iostream>
#include "BinTree.hh"

using namespace std;

// Pre:
// Post: Retorna el nombre de fulles de t
int numberOfLeaves(BinTree<int> t) {
    // CASO BASE
    if (t.empty()) return 0;
    // CASO GENERAL
    else {
        // Si es una hoja
        if (t.left().empty() and t.right().empty()) return 1;
        // Si aun no hemos llegado a la hoja
        else return numberOfLeaves(t.left()) + numberOfLeaves(t.right());
    }
}