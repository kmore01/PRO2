#include <iostream>
#include "BinTree.hh"
#include "evaluate.hh"

using namespace std;

string reverseString(const string &a) {
    string reversedA = a; // Creamos una copia del string original
    
    // Intercambiamos los caracteres desde los extremos hacia el centro
    for (int i = 0; i < reversedA.length() / 2; ++i) {
        char temp = reversedA[i];
        reversedA[i] = reversedA[reversedA.length() - 1 - i];
        reversedA[reversedA.length() - 1 - i] = temp;
    }
    
    return reversedA;
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
// Post: Retorna l'avaluació de l'expressió representada per t.
string evaluate(BinTree<string> t) {
    // Caso base
    if (t.empty()) return "";
    // Caso general
    else {
        // devuelve el string izquierdo al reves
        if (t.value() == "Reverse") {
            string left = evaluate(t.left());
            return reverseString(left);
        }
        // une en un solo string arbol izquierdo y arbol derecho
        else if (t.value() == "Concat") { 
            string left = evaluate(t.left());
            string right = evaluate(t.right());
            return left + right;
        }
        else { // "acbabcaba..."
            return t.value();
        }
    }
}