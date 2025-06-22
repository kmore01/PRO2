// Programa que dice si una sequencia es palindrome utilizando pilas

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// Funcion que devuelve una pila con la mitad del input
stack<int> leer_pila(int numseq) {
    stack<int> valores;
    for (int i = 0; i < numseq / 2; ++i) {
        int numero;
        cin >> numero;
        valores.push(numero);
    }

    return valores;
}

// Procedimiento que evalua si una pila junto a enteros es palindrome
void evalua(stack<int> input, int numseq) {
    bool palindrom = true;
    int numero;

    if (numseq > 1) {
        if (numseq % 2 != 0) cin >> numero; // pasamos el elemento central
        while (palindrom and cin >> numero) {
            if (input.top() != numero) palindrom = false;
            input.pop(); // eliminamos el elemento ya revisado
        }
    }
    else if (numseq == 1) {
        cin >> numero;
    }
    if (palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main () {
    int num_valores; // entero
    cin >> num_valores;
    stack<int> valores = leer_pila(num_valores);
    evalua(valores, num_valores);
}