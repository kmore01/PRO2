#include "evaluatePrefix.hh"

string wordReverse(string s) {
    string m;
    for (int i = 0; i < s.size() / 2; ++i) {
        swap(s[i], s[s.size() - i - 1]);
    }
    return s;
}

static string evaluatePrefix_aux(BinTree<string> t, int n, bool reverse) {
    // Caso base
    if (t.empty()) return "";
    // Caso general
    if (t.value() == "Reverse") {
        return evaluatePrefix_aux(t.left(), n, not reverse).substr(0, n);
    }
    else if (t.value() == "Concat") {
        if (not reverse) {
            string izq = evaluatePrefix_aux(t.left(), n, reverse);
            string der = "";
            if (izq.length() < n) {
                der = evaluatePrefix_aux(t.right(), n - izq.length(), reverse);
            }
            return (izq + der).substr(0, n);
        }
        else { // lo miramos en orden invertido
            string der = evaluatePrefix_aux(t.right(), n, reverse);
            string izq = "";
            if (der.length() < n) {
                izq = evaluatePrefix_aux(t.left(), n - der.length(), reverse);
            }
            return (der + izq).substr(0, n);
        }
    }
    else { // es una hoja
        if (reverse) return wordReverse(t.value()).substr(0, n);
        else return t.value().substr(0, n);
    }
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
//       n>=0
// Post: Retorna el prefix de longitut n de l'avaluació de l'expressió representada per t.
//       En cas que n sigui més gran que la longitut d'aquesta avaluació,
//       llavors retorna només l'avaluació, cap caràcter més.
string evaluatePrefix(BinTree<string> t, int n) {
    if (n > 0) return evaluatePrefix_aux(t, n, false);
    return "";
}