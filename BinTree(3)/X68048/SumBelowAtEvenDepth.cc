#include <iostream>
#include "BinTree.hh"

using namespace std;
typedef BinTree<int> BT;

BinTree<int> SumBelowAtEvenDepth_(BinTree<int> t, int altura) {
    // Caso base
    if (t.empty()) return BT();
    // Caso general
    else {
        BT left = SumBelowAtEvenDepth_(t.left(), altura + 1);
        BT right = SumBelowAtEvenDepth_(t.right(), altura + 1);
        int raiz = t.value();

        // Si es par
        if (altura % 2 == 0) {
            if (not left.empty()) {
                raiz += left.value();
                if (not left.left().empty()) raiz += left.left().value();
                if (not left.right().empty()) raiz += left.right().value();
            }
            if (not right.empty()) {
                raiz += right.value();
                if (not right.left().empty()) raiz += right.left().value();
                if (not right.right().empty()) raiz += right.right().value();
            }
        }
        return BT(raiz, left, right);
    }
}

BinTree<int> SumBelowAtEvenDepth(BinTree<int> t) {
    return SumBelowAtEvenDepth_(t, 0);
}
