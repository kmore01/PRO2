#include <iostream>
#include "BinTree.hh"
#include "evaluate.hh"

using namespace std;

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna l'avaluació de l'expressió representada per t.
bool evaluate(BinTree<string> t) {
    if (t.empty()) return false;
    else {
        // bool left = evaluate(t.left());
        // bool right = evaluate(t.right());
        if (t.value() == "and") {
            bool left = evaluate(t.left());
            if (not left) return false;
            else {
                bool right = evaluate(t.right());
                if (not right) return false;
                else return true;
            }
        }
        else if (t.value() == "or"){
            bool left = evaluate(t.left());
            if (left == true) return true;
            else {
                bool right = evaluate(t.right());
                if (right == true) return true;
                else return false;
            }
        }
        else if (t.value() == "not") {
            bool n = evaluate(t.left());
            if (n) return false;
            else return true;
        }
        else { // true, false
            if (t.value() == "true") return true;
            else return false;
        }
    }
}