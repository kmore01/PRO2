#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

// Procedimiento que actualiza la lista 1 con la mejor nota de los estudiantes
void actualizar (Cjt_estudiants &Cjt1, const Cjt_estudiants &Cjt2) {
    for (int i = 0; i < Cjt1.mida(); ++i) {
        // El resultat es l'estudiant i-essim del parametre implicit en ordre
        // creixent per DNI, es decir, devuelve el estudiante i-esimo en orden
        // creciente, teniendo en cuenta que empieza desde 1
        Estudiant conj1 = Cjt1.consultar_iessim(i + 1);
        Estudiant conj2 = Cjt2.consultar_iessim(i + 1);

        if (conj1.te_nota()) {
            if (conj2.te_nota() and conj2.consultar_nota() > conj1.consultar_nota()) Cjt1.modificar_iessim(i + 1, conj2);
        }
        // Si conj1 no tiene nota pero conj2 si la tiene
        else if (conj2.te_nota()) Cjt1.modificar_iessim(i + 1, conj2);
    }
}

int main () {
    Cjt_estudiants Cjt1;
    Cjt_estudiants Cjt2;
    Cjt1.llegir();
    Cjt2.llegir();
    actualizar(Cjt1, Cjt2);
    Cjt1.escriure();
}