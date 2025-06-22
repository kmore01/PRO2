#include <iostream>
#include <map>

using namespace std;

int main () {
    map<string, int> dinero_total;
    map<string, bool> en_rojo; // se podria utilizar cualquier otro tipo de estructura
    string opcion;
    while (cin >> opcion) {
        if (opcion == "TRANSACTION") {
            string nombre;
            int dinero;
            cin >> nombre >> dinero;
            dinero_total[nombre] += dinero;
            if (dinero_total[nombre] < 0) en_rojo[nombre] = true;
            else if (dinero_total[nombre] >= 0 and en_rojo.count(nombre)) en_rojo.erase(nombre);

        }
        else if (opcion == "NUMBERINRED") {
            cout << en_rojo.size() << endl;
        }
        else { // opcion == "PEOPLEINRED"
            bool blanco = false;
            for (auto it = en_rojo.begin(); it != en_rojo.end(); ++it) {
                if (blanco) cout << ' ';
                blanco = true;
                cout << it->first;
            }
            cout << endl;
        }
    }
}