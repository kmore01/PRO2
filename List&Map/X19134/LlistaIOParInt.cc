// Programa que contiene la codificacion de las funciones de LlistaIOParInt.hh

#include "LlistaIOParInt.hh"

using namespace std;

void LlegirLlistaParInt(list<ParInt> &l) {
    ParInt auxiliar;
    while(auxiliar.llegir()) {
        l.push_back(auxiliar);
    }
}

void EscriureLlistaParInt(const list<ParInt> &l) {
    ParInt aux;
    for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) {
        aux = *it;
        aux.escriure();
    }
}