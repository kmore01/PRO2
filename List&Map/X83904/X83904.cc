// Programa que dice las personas que han participado en todas las actividades
// y las que no han participado en ninguna

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

// Procedimiento que imprime la respuesta en el formato esperado
void imprimir(const set<string> &toda_actividad, const set<string> &ninguna_actividad) {
    cout << "Totes les activitats:";
    if (not toda_actividad.empty()) {
        cout << ' ';
        set<string>::iterator it1 = toda_actividad.begin();
        cout << *it1;
        ++it1;
        for (; it1 != toda_actividad.end(); it1++) {
            cout << ' ' << *it1;
        }
    }
    cout << endl << "Cap activitat:";
    if (not ninguna_actividad.empty()) {
        cout << ' ';
        set<string>::iterator it = ninguna_actividad.begin();
        cout << *it;
        ++it;
        for (; it != ninguna_actividad.end(); it++) {
            cout << ' ' << *it;
        }
    }
    cout << endl;
}

int main () {
    set<string> personas = leer_set();
    set<string> toda_actividad = personas;
    set<string> ninguna_actividad = personas;
    // Eliminaremos de toda_actividad las personas que no aparezcan en la
    // actividad y viceversa para ninguna_actividad
    int num_actividades;
    cin >> num_actividades;
    for (int i = 0; i < num_actividades; ++i) {
        set<string> actividad = leer_set();
        for (set<string>::iterator itr = personas.begin(); itr != personas.end(); itr++) {
        string nombre = *itr;
        if (not actividad.count(nombre)) toda_actividad.erase(nombre);
        else ninguna_actividad.erase(nombre);
        }
    }
    imprimir(toda_actividad, ninguna_actividad);
}