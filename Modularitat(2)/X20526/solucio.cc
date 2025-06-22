#include "Cjt_estudiants.hh"

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int pos = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
    b = pos < nest and vest[pos].consultar_DNI() == est.consultar_DNI();
    // El estudiante ya esta en el conjunto o la posicion es invalida
    if (b) return;
    if(est.te_nota()) {
      ++nest_amb_nota;
      suma_notes += est.consultar_nota();
      mitjana_estudiants_amb_nota();
    }
    // Bucle para mover los estudiantes desde pos una posicion a la derecha
    for (int i = nest; i > pos; --i) vest[i] = vest[i - 1];
    vest[pos] = est;
    ++nest;
}

/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
amb el dni dni; si b, aquest estudiant ha quedat eliminat
del paràmetre implícit */
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    b = pos < nest and vest[pos].consultar_DNI() == dni;
    // El estudiante no esta en el conjunto o la posicion es invalida
    if (not b) return;
    if(vest[pos].te_nota()) {
      --nest_amb_nota;
      suma_notes -= vest[pos].consultar_nota();
      mitjana_estudiants_amb_nota();
    }
    // Movemos todos los estudiantes una posicion a la izquierda desde pos
    for (int i = pos; i < nest - 1; ++i) vest[i] = vest[i + 1];
    --nest;
}