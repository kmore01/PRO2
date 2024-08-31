// Funcion que dado un arbol binario y un numero, devuelve el mismoa arbol pero
// con todos los segundos elementos que ya havia mas el numero

#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"

using namespace std;
typedef BinTree<ParInt> BT;
// Pre: a = A 
// Post: a es com a A amb k sumat al segon component de cada node
BinTree<ParInt> sumak2(const BT &a, int k) {
    // Caso base
    if (a.empty()) return BT(); 
    // Caso general
    else {
        ParInt new_value(a.value().primer(), a.value().segon() + k); // Crear un nuevo ParInt con el segundo componente modificado
        BT new_left = sumak2(a.left(), k); // Recorrer el subárbol izquierdo
        BT new_right = sumak2(a.right(), k); // Recorrer el subárbol derecho
        return BT(new_value, new_left, new_right); // Construir un nuevo árbol con los cambios
    }
}


// Pre: a = A 
// Post: a es com a A amb k sumat al segon component de cada node
void sumak(BinTree<ParInt> &a, int k) {
  a = sumak2(a, k);
}