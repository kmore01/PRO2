#include <iostream>
#include "BinTree.hh"
#include "evaluate.hh"
#include "utils.hh"

using namespace std;

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(BinTree<string> t) {
    string value = t.value();
    int answer;
    if (value == "+" or value == "-" or value == "*") {
        int l = evaluate(t.left());
        int r = evaluate(t.right());
        if (value == "+") answer = l + r;
        else if (value == "-") answer = l - r;
        else answer = l * r;
    }
    else answer = atoi(value.c_str()); // si hay un unico numero lo pasamos a tipos int

    return answer;
}
/*
int main() {
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << evaluate(t) << endl;
  	}
}
*/