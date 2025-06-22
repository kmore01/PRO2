#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOParInt.hh"

using namespace std;
typedef BinTree<ParInt> BT;

int buscar (const BT &t, int n, int &seg) {
    // Caso base
    if (t.empty()) return -1;
    // Caso general
    else {
        if (t.value().primer() == n) { // Lo hemos encontrado
            seg = t.value().segon();
            return 0;
        }
        int left = buscar(t.left(), n, seg);
        if (left != -1) return 1 + left;
        int right = buscar(t.right(), n, seg);
        if (right != -1) return 1 + right;
    }
    return -1;
}

int main () {
    BT input;
    read_bintree_parint(input);

    int num_buscado, seg;
    while (cin >> num_buscado) {
        int encontrado = buscar(input, num_buscado, seg);
        // Encontrado
        if (encontrado != -1) cout << num_buscado << ' ' << seg << ' ' << encontrado << endl;
        // No encontrado
        else cout << -1 << endl;
    }
}