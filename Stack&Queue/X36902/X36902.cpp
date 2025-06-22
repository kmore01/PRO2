// Programa que dice si una sequencia de parentesis es correcta o incorrecta,
// en el caso de que sea incorrecta tambien dice la ultima posicion que hace
// falta visitar

#include <iostream>
#include <stack>

using namespace std;

// Funcion que devuelve 0 si la expresion es correcta y en caso contrario, la
// ultima posicion que hace falta mirar para saber que una expresion es
// incorrecta
int evaluar() {
    stack<char> CPila; // contiene los caracteres de entrada
    char input;
    cin >> input;
    int pos = 1;

    while (input != '.') {
        if (input == '(' or input == '[') CPila.push(input);
        else {
            if (input == ')') {
                if (CPila.empty() or CPila.top() == '[') return pos; // incorrecta
                else CPila.pop();
            }
            else { // ']'
                if (CPila.empty() or CPila.top() == '(') return pos; // incorrecta
                else CPila.pop();
            }
        }
        ++pos;
        cin >> input;
    }

    if (not CPila.empty()) return pos - 1;
    else return 0;
}

int main() {
    int veredicto = evaluar();
    if (veredicto == 0) cout << "Correcte" << endl;
    else cout << "Incorrecte " << veredicto << endl;
}