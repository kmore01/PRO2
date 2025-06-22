#include <iostream>
#include "BinTree.hh"
#include "sumAtDepthEven.hh"

using namespace std;

int sumAtDepthEven2(BinTree<int> t, int altura) {
    // Caso base
    if (t.empty()) return 0;
    // Caso general
    else {
        int left = sumAtDepthEven2(t.left(), altura + 1);
        int right = sumAtDepthEven2(t.right(), altura + 1);

        // Si estamos en altura par
        if (altura % 2 == 0) return t.value() + left + right;
        // Si estamos en altura impar
        else return left + right;
    }
}

// Pre:
// Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinTree<int> t) {
    return sumAtDepthEven2(t, 0);
}