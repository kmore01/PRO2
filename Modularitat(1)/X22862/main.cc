#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

// Funcion que devuelve el valor redondeado al valor mas proximo
double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

int main () {
    Cjt_estudiants Cjt1;
    Cjt1.llegir();
    int operacion;
    cin >> operacion;
    
    while (operacion != -6) {
        if (operacion == -1) {
            Estudiant prov;
            int DNI;
            double nota;
            cin >> DNI >> nota;
            if (not Cjt1.existeix_estudiant(DNI)) {
                if (nota >= 0 and nota <= 10) {
                    prov = Estudiant(DNI);
                    prov.afegir_nota(nota);
                    Cjt1.afegir_estudiant(prov);
                }
                else {
                    prov = Estudiant(DNI);
                    Cjt1.afegir_estudiant(prov);
                }
            }
            else cout << "el estudiante " << DNI << " ya estaba" << endl << endl;
        }

        else if (operacion == -2) {
            int DNI;
            cin >> DNI;
            if (not Cjt1.existeix_estudiant(DNI)) cout << "el estudiante " << DNI << " no esta" << endl << endl;
            else {
                Estudiant prov = Cjt1.consultar_estudiant(DNI);
                if (not prov.te_nota()) cout << "el estudiante " << DNI << " no tiene nota" << endl << endl;
                else cout << "el estudiante " << DNI << " tiene nota " << prov.consultar_nota() << endl << endl;
            }

        }
        else if (operacion == -3) {
            int DNI;
            double nota;
            cin >> DNI >> nota;
            if (not Cjt1.existeix_estudiant(DNI)) cout << "el estudiante " << DNI << " no esta" << endl << endl;
            else {
                Estudiant prov = Cjt1.consultar_estudiant(DNI);
                if (not prov.te_nota()) prov.afegir_nota(nota);
                else prov.modificar_nota(nota);
                Cjt1.modificar_estudiant(prov);
            }

        }
        else if (operacion == -4) {
            int size = Cjt1.mida();
            for (int i = 1; i <= size; ++i) {
                Estudiant prov = Cjt1.consultar_iessim(i);
                if (prov.te_nota()) {
                    prov.modificar_nota(redondear(prov.consultar_nota()));
                    Cjt1.modificar_iessim(i, prov);
                }
            }
        }

        else {
            Cjt1.escriure();
            cout << endl;
        }

        cin >> operacion;
    }
}