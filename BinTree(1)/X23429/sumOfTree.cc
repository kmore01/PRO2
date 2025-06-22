// Funcion que devuelve la suma de todos los nodos de un arbol binario

#include <iostream>
#include "BinTree.hh"

using namespace std;
typedef BinTree<int> BT;

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinTree<int> t) {
    // Caso base
    if (t.empty()) return 0; 
    // Caso general
    else return t.value() + sumOfTree(t.right()) + sumOfTree(t.left());
}

/*
int main() {
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << sumOfTree(t) << endl;
  	}
}
*/