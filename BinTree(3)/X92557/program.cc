#include "sortTree.hh"

typedef BinTree<int> BT;

BinTree<int> sortTree_aux(BinTree<int> t, int &suma) {
    // CASO BASE
    if (t.empty()) {
        suma = 0;
        return BT();
    }
    // CASO GENERAL
    else {
        BT tl, tr;
        int sl, sr;
        tl = sortTree_aux(t.left(), sl);
        tr = sortTree_aux(t.right(), sr);
        suma = t.value() + sl + sr;
        if (sr < sl) return BT(t.value(), tr, tl);
        else return BT(t.value(), tl, tr);
    }
}



// Pre: sigui T el valor inicial de t.
// Post: el valor retornat s'obté a partir de T a base de
// swapejar els fills esquerra i dret dels nodes de T
// que cumpleixen que la suma dels valors que penjen del seu fill esquerra és més gran
// estricte que la suma dels valors que penjen del seu fill dret.
BinTree<int> sortTree(BinTree<int> t) {
    int s;
    return sortTree_aux(t, s);
}