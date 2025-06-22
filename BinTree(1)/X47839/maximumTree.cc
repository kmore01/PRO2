// Programa que dados dos arboles binarios crea un nuevo arbol con los maximos
// de cada posicion 

#include <iostream>
#include "BinTree.hh"
#include "maximumTree.hh"

using namespace std;
typedef BinTree<int> BT;

// Pre: Rep dos arbres binaris d'enters positius t1 i t2.
// Post: Retorna un arbre, on a la seva arrel hi ha el màxim de les arrels de t1,t2,
// en l'arrel del fill esquerre hi ha el màxim de les arrels dels fills esquerre de t1,t2,
// en l'arrel del fill dret hi ha el màxim de les arrels dels fills drets de t1,t2,
// i així successivament.
// Quan un dels arbres no té valors definits en alguna posició, l'arbre resultant hi té
// el valor de l'altre arbre en aquella posició.
BinTree<int> maximumTree(BinTree<int> t1,BinTree<int> t2) {
    // Caso base
    if (t1.empty() and t2.empty()) return BT();
    // Caso general
    else {
        BT t3;
        if (t1.empty()) {
            int nodo = t2.value();
            t3 = BT(nodo, maximumTree(BT(), t2.left()), 
                  maximumTree(BT(), t2.right()));
        }
        else if (t2.empty()) {
            int nodo = t1.value();
            t3 = BT(nodo, maximumTree(t1.left(), BT()), 
                  maximumTree(t1.right(), BT()));
        }
        else { // ningun arbol esta vacio
            int nodo = max(t1.value(), t2.value());
            t3 = BT(nodo, maximumTree(t1.left(), t2.left()), 
                  maximumTree(t1.right(), t2.right()));
        }
        return t3;
    }
}

/*
int main() {
    string format;
    getline(cin, format);
    BT t1, t2;
    t1.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    t2.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t1 and not t1.empty() and cin >> t2 and not t2.empty()) {
    	BT t=maximumTree(t1, t2);
        t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << t << endl;
  	}
}
*/