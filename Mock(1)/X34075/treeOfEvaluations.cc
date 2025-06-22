#include <iostream>
#include "BinTree.hh"
#include "treeOfEvaluations.hh"

using namespace std;
typedef BinTree<bool> BT;

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    if (t.empty()) return BT();
    else {
        BT left = treeOfEvaluations(t.left());
        BT right = treeOfEvaluations(t.right());
        string val = t.value();
        if (val == "and") {
            return BT(left.value() and right.value(), left, right);
        }
        else if (val == "or"){
            return BT(left.value() or right.value(), left, right);
        }
        else if (val == "not") {
            return BT(not left.value(), left, right);
        }
        else { // true, false
            return BT(val == "true", left, right);
        }
    }
}