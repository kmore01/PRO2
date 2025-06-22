// Programa que dado un string escribe despues de cada caracter (parentesis) el
// numero correspodiente dependiendo la posicion de este

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Procedimiento que imprime cada numero despues de cada parentesis
void evaluar(string s) {
    stack <int> nums; // pila que contiene los valores despues de los ')'
    int parentesis_abierto = 1; 
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            cout << s[i] << parentesis_abierto;
            nums.push(parentesis_abierto);
            ++parentesis_abierto;
        }
        else {
            cout << s[i] << nums.top();
            nums.pop();
        }
    }

    cout << endl;
}

int main() {
    string sequencia;
    while (cin >> sequencia) {
        evaluar(sequencia);
    }
}