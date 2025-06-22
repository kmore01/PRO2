#include "evaluate.hh"
#include "utils.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre naturals i variables enteres, i els operadors +,-,*.
//       Totes les variables que apareixen a t estan definides a variable2value.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(map<string,int> &variable2value, BinTree<string> t) {
    // Caso base
    if (t.empty()) return 0;
    // Caso general
    int izq = evaluate(variable2value, t.left());
    int der = evaluate(variable2value, t.right());
    if (t.value() == "+") return izq + der;
    else if (t.value() == "-") return izq - der;
    else if (t.value() == "*") return izq * der;
    // t.value() es un numero
    else if (isNumber(t.value())) return mystoi(t.value());
    // t.value() es una variable    
    else return variable2value[t.value()];
}