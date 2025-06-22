#include "evaluatePrefix.hh"

string reverseWord(string s) {
    string m;
    for (int i = 0; i < s.size() / 2; ++i) {
        swap(s[i], s[s.size() - i - 1]);
    }
    return s;
}

string evaluatePrefix_aux(BinTree<string> t, int n, bool reverse) {
    // Caso base
    if (t.empty()) return "";
    // Caso general
    if (t.value() == "Reverse") {
        return evaluatePrefix_aux(t.left(), n, not reverse);
    }
    else if (t.value() == "Concat") {
        string resultado;
        if (reverse) {
            // llamada recursiva al subarbol derecho primero (reverse)
            resultado = evaluatePrefix_aux(t.right(), n, reverse); 
            // Caso: aun no hemos llegado a la longitud
            if (resultado.length() < n) {
                resultado += evaluatePrefix_aux(t.left(), n - resultado.length(), reverse);
            }
        }
        else { // not reverse
            // llamada recursiva al subarbol izquierdo (not reverse), lo hacemos normal
            resultado = evaluatePrefix_aux(t.left(), n, reverse); 
            // Caso: aun no hemos llegado a la longitud
            if (resultado.length() < n) {
                resultado += evaluatePrefix_aux(t.right(), n - resultado.length(), reverse);
            }
        }
        return resultado;
    }
    else { // es una hoja
        if (reverse) {
            return reverseWord(t.value()).substr(0, n);
        }
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
    else return "";
}