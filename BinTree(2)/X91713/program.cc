#include "longestLeftmostPath.hh"

// Pre:
// Post: Retorna la llista d'elements que es troben a t, baixant des de l'arrel i
//       seguint el camí més llarg. En cas de varis camins màxims,
//       escull el de més a l'esquerra.
list<int> longestLeftmostPath(BinTree<int> t) {
    // Caso base
    if (t.empty()) return list<int>();
    // Caso general
    list<int> izq = longestLeftmostPath(t.left());
    list<int> der = longestLeftmostPath(t.right());
    if (izq.size() >= der.size()) {
        izq.push_front(t.value());
        return izq;
    }
    else {
        der.push_front(t.value());
        return der;
    }
}