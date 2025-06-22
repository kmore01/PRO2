// Programa que dibuja figuras con recursividad alterna
// Si es impar el primero va a la izquierda(arriba) del todo y el segundo a la derecha y a la inversa

#include <iostream>
#include <vector>

using namespace std;

// Procedimiento que dibuja una parte de la figura deseada
void calcula(int n, vector<int> &v) {
    // Caso base
    if (n == 0) v = vector<int> (1, 0); // hay 1 * en la posicion 0
    // Caso general
    else {
        calcula(n - 1, v);
        int m = v.size();

        /* CASO N PAR */
        if (n % 2 == 0) { 
            // el push_back lo puedes quitar pq el tamaño = 2^n
            for (int i = 0; i < m; ++i) {
                v.push_back(v[i] + m); // añadimos los elem que nos faltan (ultimos)
            }
        }
        /* CASO N IMPAR */
        else {
            // Los pones todos y les sumas la longitud a los del final
            // PAPEL Y SE VE
            for (int i = 0; i < m; ++i) {
                v.push_back(v[i]);
                v[i] += m; // le sumas la longitud de par a impar
            }
        }
    }
}

void imprimir(const vector<int> &posicion) {
    for (int i = 0; i < posicion.size(); ++i) {
        for (int j = 0; j < posicion[i]; ++j) {
            cout << ' '; // espacios hasta el *
        }
        cout << '*' << endl; // unico * de la linea
    }
    cout << string(10, '-') << endl; // "----------" es menos efectivo
}

int main () {
    int n; // natural >= 0  
    while (cin >> n) {
        vector<int> v;
        calcula(n, v);
        imprimir(v);
    }
}