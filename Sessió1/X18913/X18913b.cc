/* programa que devuelve la posicion de un entero en un vector */

#include <iostream>
#include <vector>

using namespace std;
 
/* Pre: cierto */
/* Post: si el resultado es v.size(), x no esta en v;
en caso contrario, indica la posicion de la primera aparicion de x en v */
int busqueda_lin(const vector<int>& v, int x) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == x) return i;
    }

    return v.size();
}