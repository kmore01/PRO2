// Funcion que devuelve un arbol binario con la suma de
// los ancestros para cada nodo

#include <iostream>
#include "BinTree.hh"

using namespace std;
typedef BinTree<int> BT;

// Pre:
// Post: Retorna un arbre d'enters t' amb la mateixa estructura que t.
// Per a cada posició p, el valor guardat a t' a posició p és igual a la suma
// dels valors guardats a t a posició p i a posicions ancestres de p.
BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
    // Caso base
    if (t.empty()) return BinTree<int>();
    // Caso general
    else {
        BT left, right;
        int leftValue = 0, rightValue = 0;
        // Miramos si el arbol izquierdo no esta vacio y si es asi, sumamos el
        // valor del actual nodo mas el suyo y creamos el subarbol utilizando
        // la funcion recursiva
        if (not t.left().empty()) {
            leftValue = t.left().value();
            BT t1(leftValue + t.value(), t.left().left(), t.left().right());
            left = treeOfSumsOfAncestors(t1);
        }
        // Miramos si el arbol derecho no esta vacio y si es asi, sumamos el
        // valor del actual nodo mas el suyo y creamos el subarbol utilizando
        // la funcion recursiva
        if (not t.right().empty()) {
            rightValue = t.right().value();
            BT t2(rightValue + t.value(), t.right().left(), t.right().right());
            right = treeOfSumsOfAncestors(t2);
        }
        return BT(t.value(), left, right);
    }
}