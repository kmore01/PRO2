// Programa que dice las personas que han participado en todas las actividades
// y las que no han participado en ninguna

#include <iostream>
#include <set>

using namespace std;

void leer_lista(set<string> &lista) {
    string nombre;
    cin >> nombre;
    while (nombre != ".") {
        lista.insert(lista.end(), nombre);
        cin >> nombre;
    }
}

void primera_partida(set<string> &lista, set<string> &partida) {
    set<string>::iterator it = lista.begin();
    string nombre;
    cin >> nombre;
    while (nombre != ".") {
        partida.insert(partida.end(), nombre);
        while (it != lista.end() and *it <= nombre) {
            if (*it < nombre) ++it;
            else it = lista.erase(it);
        }
        cin >> nombre;
    }
}

void comprobar_lista(set<string> &lista, set<string> &partida) {
    set<string>::iterator it1 = lista.begin();
    set<string>::iterator itp = partida.begin();
    string nombre;
    cin >> nombre;
    while (nombre != ".") {
        while (it1 != lista.end() and *it1 <= nombre) {
            if (*it1 < nombre) ++it1;
            else it1 = lista.erase(it1);
        }
        while (itp != partida.end() and *itp <= nombre) {
            if (*itp < nombre) itp = partida.erase(itp);
            else ++itp;
        }
        cin >> nombre;
    }
    while (itp != partida.end()) itp = partida.erase(itp);
}

void imprimir(set<string> &a) {
    for (set<string>::iterator it = a.begin(); it != a.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}

int main () {
    set<string> lista;
    leer_lista(lista);
    set<string> partida;
    int actividades;
    cin >> actividades;
    primera_partida(lista, partida);
    for (int i = 1; i < actividades; ++i) {
        comprobar_lista(lista, partida);
    }
    
    // Imprimir
    cout << "Totes les activitats:";
    imprimir(partida);
    cout << "Cap activitat:";
    imprimir(lista);
}   