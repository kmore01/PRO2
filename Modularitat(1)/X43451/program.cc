#include <iostream>
#include "Estudiant.hh"
#include "PRO2Excepcio.hh"
#include <vector>

using namespace std;

/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
void redondear_e_a(Estudiant& est) {
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

/* Pre: cert */
/* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
a la decima mes propera */
void arrodonir_vector(vector<Estudiant>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) redondear_e_a(v[i]);
    }
}