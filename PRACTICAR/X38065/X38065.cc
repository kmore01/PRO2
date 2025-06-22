// Programa que maneja una lista de personas y sus monedas

#include <iostream>
#include <map>

using namespace std;

int main () {
    map<string, int> personas;
    map<int,int> contador;
    string instruccion;
    while (cin >> instruccion) {
        if (instruccion == "ADD") {
            string name;
            int numcoins;
            cin >> name >> numcoins;
            personas[name] = numcoins; // Lo añadimos
            contador[numcoins] += 1; // Le sumamos 1 al contador de monedas
        }
        else if (instruccion == "DELETE") {
            string name;
            cin >> name;
            map<string,int>::iterator it = personas.find(name);
            contador[it->second] -= 1; // Eliminamos a la persona del contador
            personas.erase(name); // Lo eliminamos
        }
        else { // "NUMPEOPLE"
            int numcoins;
            cin >> numcoins;
            if (contador.count(numcoins)) {
                map<int,int>::iterator it = contador.find(numcoins);
                cout << it->second << endl;
            }
            else cout << 0 << endl;
        }
    }
}