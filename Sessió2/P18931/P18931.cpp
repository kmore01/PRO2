//  Programa que dibuja cuadrados usando un patron recursivo

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Funcion que devuelve un vector de strings con el cuadrado deseado
vector<string> calcula(int n) {
    // Caso base
    if (n == 1) return vector<string> (1, "#");
    // Caso general
    else {
        vector<string> w = calcula(n - 1);
        vector<string> v;

        v.push_back(w[0] + "#" + w[0]);
        for (int i = 1; i < w.size(); ++i) {
            v.push_back(w[i] + "." + w[i]);
        }

        v.push_back("#" + string(pow(2, n) - 3, '.') + "#");
        for (int i = 0; i < w.size() - 1; ++i) {
            v.push_back(w[i] + "." + w[i]);
        }

        v.push_back(w[w.size() - 1] + "#" + w[w.size() - 1]);
        
        return v;
    }
}

// Procedimiento que imprime el cuadrado
void imprimir (const vector<string> &cuadrado) {
    int size = cuadrado.size();
    for (int i = 0; i < size; ++i) {
        cout << cuadrado[i] << endl;
    }
}

int main () {
    int n; // 1 <= natural <= 11
    cin >> n;
    vector<string> v = calcula(n);
    imprimir(v);
}