// Funcion que devuelve dado un arbol binario, su mismo girado

#include <iostream>
#include "BinTree.hh"

using namespace std;
typedef BinTree<int> BT;

// Pre:  
// Post: retorna el revessat de t.
BinTree<int> reverseTree(BinTree<int> t) {
    if (t.empty()) return t;
    else return BT(t.value(), reverseTree(t.right()), reverseTree(t.left()));
}

/*
int main() {
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        t = reverseTree(t);
        t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << t << endl;
  	}
}
*/