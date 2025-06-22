// Programa que lee colas y imprime los clientes que salen de dichas
// colas y como quedan despues de las entradas y salidas de estos clientes

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// Procedimiento que guarda las colas en un vector de estas
void leer_colas(vector<queue<string>> &a, int n) {
    for (int i = 0; i < n; ++i) {
        string linea;
        getline(cin, linea);
        
        istringstream iss(linea); // Crear un stringstream desde la linea
        string palabra;
        while (iss >> palabra) { // Leer cada palabra de la línea
            a[i].push(palabra);
        }
    }
}

// Procedimiento que imprime las colas siguiendo el formato adequado
void imprimir_colas(vector<queue<string>>& a) {
    cout << endl << "CONTINGUTS FINALS" << endl
        << "-----------------" << endl;
    int size = a.size();
    for (int i = 0; i < size; ++i) {
        cout << "cua " << i + 1 << ":";
        if (not a[i].empty()) { // Primer elemento
            cout << ' ' << a[i].front();
            a[i].pop();
        }

        while (not a[i].empty()) {
            cout << ' ' << a[i].front();
            a[i].pop();
        }
        cout << endl;
    }
}

int main() {
    int num_colas; // natural > 0
    cin >> num_colas;
    cin.ignore(); // Limpiamos el buffer de entrada antes de leer las lineas
    vector<queue<string>> colas(num_colas);
    leer_colas(colas, num_colas);
    cout << "SORTIDES" << endl << "--------" << endl;

    string accion;
    while (cin >> accion) {
        if (accion == "ENTRA") {
            string cliente;
            int cola_a_entrar;
            cin >> cliente >> cola_a_entrar;
            if (1 <= cola_a_entrar and cola_a_entrar <= num_colas) {
                colas[cola_a_entrar - 1].push(cliente);
            }
        }
        else { // "SURT"
            int cola_a_salir;
            cin >> cola_a_salir;
            if (1 <= cola_a_salir and cola_a_salir <= num_colas 
                and not colas[cola_a_salir - 1].empty()) {
                cout << colas[cola_a_salir - 1].front() << endl;
                colas[cola_a_salir - 1].pop();
            }
        }
    }
    imprimir_colas(colas);
}
