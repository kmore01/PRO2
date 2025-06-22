// Programa que deriva expresiones de codigo usando diferentes reglas

#include <iostream>
#include <vector>

using namespace std;

void aplicarReglas(vector<char> &a, string &b, int pos_string) {
    bool cambio = false;
    
    while (not cambio) {
        int pos_ult = a.size() - 1;
        cambio = true;
        /* n → E */
        if (a[pos_ult] == 'n') {
            a[pos_ult] = 'E';
            cambio = false;
        }
        /* v → E (no es pot aplicar si ve seguida de '=') */
        else if (a[pos_ult] == 'v' and b[pos_string + 1] != '=') {
            a[pos_ult] = 'E';
            cambio = false;
        }
        /* E*E → E */
        else if (a.size() >= 3 and a[pos_ult] == 'E' and a[pos_ult - 1] == '*'
        and a[pos_ult - 2] == 'E') {
            a.pop_back(); // Eliminar 'E'
            a.pop_back(); // Eliminar '*'
            cambio = false;
        }
        /* E+E → E (no es pot aplicar si ve seguida de '*') */
        else if (a.size() >= 3 and a[pos_ult] == 'E' and a[pos_ult - 1] == '+'
        and a[pos_ult - 2] == 'E' and b[pos_string + 1] != '*') {
            a.pop_back(); // Eliminar 'E'
            a.pop_back(); // Eliminar '+'
            cambio = false;
        }
        /* E<E → E (no es pot aplicar si ve seguida de '*' o '+') */
        else if (a.size() >= 3 and a[pos_ult] == 'E' and a[pos_ult - 1] == '<'
        and a[pos_ult - 2] == 'E' and b[pos_string + 1] != '*'
        and b[pos_string + 1] != '+') {
            a.pop_back(); // Eliminar 'E'
            a.pop_back(); // Eliminar '<'
            cambio = false;
        }
        /* v=E; → I */
        else if (a.size() >= 3 and a[pos_ult] == ';' and a[pos_ult - 1] == 'E'
        and a[pos_ult - 2] == '=' and a[pos_ult - 3] == 'v') {
            a.pop_back();  // Eliminar ';'
            a.pop_back();  // Eliminar 'E'
            a.pop_back();  // Eliminar '='
            a.pop_back();  // Eliminar 'v'
            a.push_back('I');
            cambio = false;
        }
        /* (E) → E (no es pot aplicar si ve precedida de 'i' o 'w') */
        else if ((a.size() == 3 and a[pos_ult] == ')' and a[pos_ult - 1] == 'E'
        and a[pos_ult - 2 == '(']) or (a.size() > 3 and a[pos_ult] == ')'
        and a[pos_ult - 1] == 'E' and a[pos_ult - 2] == '('
        and a[pos_ult - 3] != 'i' and a[pos_ult - 3] != 'w')) {
            a.pop_back();  // Eliminar ')'
            a.pop_back();  // Eliminar 'E'
            pos_ult = a.size() - 1;
            a[pos_ult] = 'E';
            cambio = false;
        }
        /* i(E)I → I (no es pot aplicar si ve seguida de 'e') */
        else if (a.size() >= 5 and a[pos_ult] == 'I' and a[pos_ult - 1] == ')'
        and a[pos_ult - 2] == 'E' and a[pos_ult - 3] == '('
        and a[pos_ult - 4] == 'i' and b[pos_string + 1] != 'e') {
            a.pop_back();  // Eliminar 'I'
            a.pop_back();  // Eliminar ')'
            a.pop_back();  // Eliminar 'E'
            a.pop_back();  // Eliminar '('
            a.pop_back(); // Eliminar 'i'
            a.push_back('I');
            cambio = false;
        }
        /* i(E)IeI → I */
        else if (a.size() >= 7 and a[pos_ult] == 'I' and a[pos_ult - 1] == 'e'
        and a[pos_ult - 2] == 'I' and a[pos_ult - 3] == ')'
        and a[pos_ult - 4] == 'E' and a[pos_ult - 5] == '('
        and a[pos_ult - 6] == 'i') {
            a.pop_back();  // Eliminar 'I'
            a.pop_back();  // Eliminar 'e'
            a.pop_back();  // Eliminar 'I'
            a.pop_back();  // Eliminar ')'
            a.pop_back(); // Eliminar 'E'
            a.pop_back(); // Eliminar '('
            a.pop_back(); // Eliminar 'i'
            a.push_back('I');
            cambio = false;
        }
        /* w(E)I → I */
        else if (a.size() >= 5 and a[pos_ult] == 'I' and a[pos_ult - 1] == ')'
        and a[pos_ult - 2] == 'E' and a[pos_ult - 3] == '('
        and a[pos_ult - 4] == 'w') {
            a.pop_back();  // Eliminar 'I'
            a.pop_back();  // Eliminar ')'
            a.pop_back();  // Eliminar 'E'
            a.pop_back();  // Eliminar '('
            a.pop_back(); // Eliminar 'w'
            a.push_back('I');
            cambio = false;
        }
        /* LI → L */
        else if (a.size() > 1 and a[pos_ult] == 'I' and a[pos_ult - 1] == 'L') {
            a.pop_back(); // Eliminamos 'I'
            pos_ult = a.size() - 1;
            a[pos_ult] = 'L';
            cambio = false;
        }
        /* I → L (no es pot aplicar si ve precedida de ')' o 'L') */
        else if ((a[pos_ult] == 'I' and a.size() == 1) or (a.size() > 1
        and a[pos_ult] == 'I' and a[pos_ult - 1] != ')'
        and a[pos_ult - 1] != 'L')) {
            a[pos_ult] = 'L';
            cambio = false;
        }
        /* {L} → I */
        else if (a.size() >= 3 and a[pos_ult] == '}' and a[pos_ult - 1] == 'L'
        and a[pos_ult - 2] == '{') {
            a.pop_back(); // Eliminar '}'
            a.pop_back(); // Eliminar 'L'
            a.pop_back(); // Eliminar '{'
            a.push_back('I');
            cambio = false;
        }
        /* L → P (només es pot aplicar si aquest L és l’únic caràcter que queda,
        és a dir, si tot l’string inicial ha estat reduït a exactament L) */
        else if (a.size() == 1 and a[pos_ult] == 'L'
        and pos_string == b.size() - 1) {
            a[pos_ult] = 'P';
            cambio = false;
        }
    }
}

int main () {
    string entrada; // {+, *, =, <, {, }, (, ), ;, v, n, i, e, w}
    while (cin >> entrada) {
        int longitud = entrada.length();
        vector<char> VChar;
        for (int i = 0; i < longitud; ++i) {
            VChar.push_back(entrada[i]);
            aplicarReglas(VChar, entrada, i);
        }
        for (int i = 0; i < VChar.size(); ++i) cout << VChar[i];
        cout << endl;
    }
}