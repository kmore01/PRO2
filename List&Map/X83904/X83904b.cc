#include <iostream>
#include <set>

using namespace std;

// Funcion que guarda las personas en un set
set<string> leer_set() {
    set<string> lectura_nom;
    string nombre;
    while (cin >> nombre and nombre != ".") {
        lectura_nom.insert(nombre);
    }

    return lectura_nom;
}


int main () {
    set<string> personas = leer_set();
    set<string> toda_actividad = personas;
    set<string> ninguna_actividad = personas;

    // Leer el número de actividades
    int num_actividades;
    cin >> num_actividades;

    for (int i = 0; i < num_actividades; ++i) {
        set<string> actividad = leer_set();
        
        // Actualizar los conjuntos de personas
        for (auto it = personas.begin(); it != personas.end(); ++it) {
            const string& nombre = *it;
            if (!actividad.count(nombre)) {
                toda_actividad.erase(nombre);
            } else {
                ninguna_actividad.erase(nombre);
            }
        }
    }

    // IMPRIMIR
    cout << "Totes les activitats: ";
    set<string>::iterator it1 = toda_actividad.begin();
    cout << *it1;
    ++it1;
    for (; it1 != toda_actividad.end(); it1++) {
        cout << ' ' << *it1;
    }
    cout << endl << "Cap activitat: ";
    set<string>::iterator it = ninguna_actividad.begin();
    cout << *it;
    ++it;
    for (; it != ninguna_actividad.end(); it++) {
        cout << ' ' << *it;
    }
    cout << endl;
}
