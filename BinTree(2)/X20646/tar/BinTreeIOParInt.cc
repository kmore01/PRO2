#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"

using namespace std;
typedef BinTree<ParInt> BT;

// Pre: a és buit; el canal estandar d’entrada conté un nombre
// parell d’enters, que representa un arbre binari en preordre,
// on el parell 0 0 representa un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada
void read_bintree_parint(BinTree<ParInt> &a) {
    ParInt x;
    if (x.llegir()) {
        BT left;
        BT right;
        read_bintree_parint(left);
        read_bintree_parint(right);

        a = BT(x, left, right);
    }
}

// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorrreguts en inordre, a = A
void write_bintree_parint(const BinTree<ParInt>& a) {
    if (not a.empty()) {
        // Inorden significa recorrer el arbol en orden inverso, es decir de derecha a izquierda
        write_bintree_parint(a.right());
        a.value().escriure();
        write_bintree_parint(a.left());
    }
}