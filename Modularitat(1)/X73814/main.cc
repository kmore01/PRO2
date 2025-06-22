#include <iostream>
#include "Estudiant.hh"
#include <vector>

using namespace std;

// Procedimiento que guarda las notas de los alumnos en un vector
vector<Estudiant> leer_vector() {
    int n;
    cin >> n;
    vector<Estudiant> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].llegir();
    }

    return v;
}

void simplifica_vector (const vector<Estudiant> &v, vector<Estudiant> &r, int &j) {
    r = vector<Estudiant> (v.size());
    r[0] = v[0];
    j = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].consultar_DNI() != r[j].consultar_DNI()) {
            ++j;
            r[j] = v[i];
        }
        else { // Mismo DNI que el ultimo que he puesto
            if (v[i].te_nota()) {
                if (r[j].te_nota()) {
                    if (v[i].consultar_nota() > r[j].consultar_nota()) r[j] = v[i];
                }
                else r[j] = v[i];
            }
        }
    }
    r.resize(j+1);
}

void escribir_vector(const vector<Estudiant> &def) {
    int size = def.size();
    for (int i = 0; i < size; ++i) {
        def[i].escriure();
    }
}

int main () {
    vector<Estudiant> valors_inicials = leer_vector();
    vector<Estudiant> def;
    int j;
    simplifica_vector(valors_inicials, def, j);
    escribir_vector(def);
}