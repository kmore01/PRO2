/* programa que devuelve el valor maximo y minimo de un vector */

#include <iostream>
#include <vector>

using namespace std;
 
struct parint {int prim, seg;};

/* Pre: v.size() > 0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
parint max_min1(const vector<int>& v) {
    parint solucion;
    solucion.prim = solucion.seg = v[0];
    /* Miramos el primer elemento */
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > solucion.prim) solucion.prim = v[i];
        else if (v[i] < solucion.seg) solucion.seg = v[i];
    }

    return solucion;
}

/* Pre: v.size() > 0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
pair<int,int> max_min2(const vector<int>& v) {
    pair <int, int> solucion;
    solucion.first = solucion.second = v[0];

    /* Miramos el primer elemento */
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > solucion.first) solucion.first = v[i];
        else if (v[i] < solucion.second) solucion.second = v[i];
    }

    return solucion;
}
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
void max_min3(const vector<int>& v, int& x, int& y) {
    x = y = v[0];
    /* Miramos el primer elemento */
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    }
}