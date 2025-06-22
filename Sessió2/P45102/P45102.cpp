// Programa que calcula expresiones matematicas

#include <iostream>

using namespace std;

// Funcion que devuelve la expresion matematica de entrada
int recursiveCalcule() {
    char input;
    int resultado = 0;

    if (cin >> input) {
        // Caso base
        if (input >= '0' and input <= '9') return input - '0';
        // Caso general
        else {
            int operando1 = recursiveCalcule();
            char operador; // '+' '-' '*'
            cin >> operador;
            int operando2 = recursiveCalcule();
            cin >> input; // ')'

            if (operador == '+') resultado = operando1 + operando2;
            else if (operador == '-') resultado = operando1 - operando2;
            else resultado = operando1 * operando2;
        }
    }

    return resultado;
}

int main () {
    cout << recursiveCalcule() <<endl;
}