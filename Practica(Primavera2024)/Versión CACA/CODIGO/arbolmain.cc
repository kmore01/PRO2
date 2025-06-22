#include <iostream>
#include "BinTree.hh"

using namespace std;
typedef BinTree<string> BT;

BT leer_rio() {
    string identificador;
    cin >> identificador;

    if (identificador == "#") return BT();
    else {
        BT left = leer_rio();
        BT right = leer_rio();
        return BT(identificador, left, right);
    }
}

int main () {
    BT t;
    string nombre;
    string format;
    cin >> format;
    BT pri = leer_rio();
    pri.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    cout << pri << endl;
}

