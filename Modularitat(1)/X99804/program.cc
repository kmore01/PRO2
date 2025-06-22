#include <iostream>
#include "Estudiant.hh"
#include <vector>
#include <algorithm>

using namespace std;

bool ordenar(const Estudiant &a, const Estudiant &b) {
    if (a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
    else return a.consultar_DNI() < b.consultar_DNI();
}


int main () {
    int num_students, num_subjects, subjects_assigned;
    cin >> num_students >> num_subjects >> subjects_assigned;

    // Vector que contendra las asignaturas validas
    vector<bool> indetificator_subject(num_subjects);
    for (int i = 0; i < subjects_assigned; ++i) {
        int num;
        cin >> num;
        indetificator_subject[num - 1] = true;
    }

    vector<Estudiant> seq(num_students);
    for (int i = 0; i < num_students; ++i) {
        int DNI;
        cin >> DNI;
        seq[i] = Estudiant(DNI);
        double ans = 0;
        
        for (int k = 0; k < num_subjects; ++k) {    
            double mark;
            cin >> mark;
            if (indetificator_subject[k]) { // cuenta
                ans += mark;
            }
        }

        if (seq[i].te_nota()) seq[i].modificar_nota(ans / subjects_assigned);
        else seq[i].afegir_nota(ans / subjects_assigned);
    }

    sort(seq.begin(), seq.end(), ordenar);

    // Imprimir en orden el vector
    for (int i = 0; i < num_students; ++i) {
        seq[i].escriure();
    }
}
