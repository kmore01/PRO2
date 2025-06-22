#include <iostream>
#include "BinTree.hh"
#include "searchInBST.hh"

using namespace std;
typedef BinTree<int> BT;

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t
bool searchInBST(BinTree<int> t, int x) {
    if (t.empty()) return false;
    else if (t.value() == x) return true;
    else if (x < t.value()) return searchInBST(t.left(), x);
    else return searchInBST(t.right(), x);
}
/*
int main() {
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
	cin >> t;
    int x;
    while (cin >> x) {
		if (searchInBST(t, x)) cout << "Exists" << endl;
        else cout << "Does not exist" << endl;
    }
}
*/
// c.erase(it); si no quieres que siga associado
// it = c.erase(it) si que sigue associado al map y lo puedes seguir usando
// borrar con it
// lower_bound