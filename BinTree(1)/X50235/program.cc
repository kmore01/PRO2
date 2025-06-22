#include <iostream>
#include "BinTree.hh"

using namespace std;
typedef BinTree<int> BT;

bool poda_subarbre(BinTree<int> &a, int x) {
    // Caso base
    if (a.empty()) return false;
    // Caso general
    else {
        // Si lo encontramos eliminamos todo el arbol hacia abajo
        if (a.value() == x) {
            a = BT();
            return true;
        }
        // Si no lo encontramos
        else {
            BT left = a.left();
            BT right = a.right();

            bool encontrado = poda_subarbre(left, x);
            // Si no esta en el arbol izquierdo buscamos en el arbol derecho
            if (not encontrado) encontrado = poda_subarbre(right, x);
            a = BinTree<int>(a.value(),left,right);
            return encontrado;
        }
    }
}