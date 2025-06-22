#include "removeAll.hh"

typedef BinTree<string> BT;

string find(const string &ext) {
    int i = ext.size() - 1;
    bool found = false;
    while (i >= 0 and not found) {
        if (ext[i] == '.') found = true;
        else --i;
    }
    if (found) return ext.substr(i + 1);
    else return "";

}

// Pre:  Els nodes de 't' o bé son strings no buits de lletres minuscules, o bé
//       son de la forma "s.e", on s i e son strings no buits de lletres minúscules.
//       En l'últim cas, el node ha de ser una fulla, i e s'anomena la extensió de la fulla.
// Post: Retorna l'arbre resultant d'esborrar de t tots els nodes amb strings de
//       la forma "s.e" a on 'e' és igual a 'extension'.
BinTree<string> removeAll(const string &extension, const BinTree<string> &t) {
    // CASO BASE
    if (t.empty()) return BT();
    // CASO GENERAL
    else {
        // SI ES UNA HOJA
        if (t.left().empty() and t.right().empty()) {
            // SI TIENE PUNTO...
            string st = find(t.value());
            // SI ES LA EXTENSION QUE QUIERO BORRAR
            if (st == extension) return BT();
            // NO ES LA MISMA EXTENSION QUE QUIERO BORRAR
            else return t;
            // SI NO TIENE PUNTO, ES UNA CARPETA
        }
        // SI NO ES UNA HOJA, ES UNA CARPETA
        else {
            return BT(t.value(), removeAll(extension, t.left()), removeAll(extension, t.right()));
        }
    }
}