// Programa que dado un arbol binario y un numero, devuelve el mismoa arbol pero
// con todos los segundos elementos que ya havia mas el numero

#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"

using namespace std;
typedef BinTree<ParInt> BT;

int main () {
    string format;
    getline(cin, format);
    BinTree<ParInt> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        int num;
        cin >> num;
    	sumak(t, num);
        cout << t << endl;
  	}
}