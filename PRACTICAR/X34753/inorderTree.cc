#include "inorderTree.hh"
#include "BinTree.hh"

typedef BinTree<int> BT;

BinTree<int> inorderTree(BinTree<int> t, int &count) {
    if (t.empty()) return BT();
    else {
        BT left = inorderTree(t.left(), count);
        ++count;
        int ans = count;
        BT right = inorderTree(t.right(), count);
        return BT(ans, left, right);
    }
}

BinTree<int> inorderTree(BinTree<int> t) {
    int count = 0;
    return inorderTree(t, count);
}