// Funcion que calcula cuantas subexpresiones negativas hay en un arbol binario

#include <iostream>
#include "BinTree.hh"
#include "numNegative.hh"
#include "utils.hh"

using namespace std;

int evaluate(BinTree<string> t, int &neg) {
    if (t.empty()) return 0;
    else {
        string value = t.value();
        int result;
        if (value == "+" or value == "-" or value == "*") {
            int l = evaluate(t.left(), neg);
            int r = evaluate(t.right(), neg);
            if (value == "+") {
                result = l + r;
                if (result < 0) neg += 1;
            }
            else if (value == "-") {
                result = l - r;
                if (result < 0) neg += 1;
            }
            else {
                result = l * r;
                if (result < 0) neg += 1;
            }
        }
        else {
            result = atoi(value.c_str());
            if (result < 0) neg += 1;
        }
        return result;
    } 
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna el nombre de subexpressions de l'expressió representada per t
//       amb avaluació estrictament menor que 0.
int numNegative(BinTree<string> t) {
    int neg = 0;
    evaluate(t, neg);
    return neg;
}