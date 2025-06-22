/* Programa que dibuixa 2^n - 1 barres seguint un patró */

#include <iostream>

using namespace std;

// funcio que dibuixa els asteriscs del dibuix
void bars (int size) {
    if (size != 0) {
        cout << '*';
        bars(size - 1);
    }
}

// funcio que dibuixa
void romb (int size) {
    if (size != 0) {
        /* Part descendet */
        bars(size);
        cout << endl;
        romb(size - 1);
        /* Part creixent - decreixent */
        romb(size - 1);
    }
}

int main () {
    int mida;
    cin >> mida;
    romb(mida);
}