#include <iostream>
#include "Estudiant.hh"
#include <vector>

using namespace std;

/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
resultat es la posicio de l'estudiant de nota maxima de v i la segona
component es la posicio de l'estudiant de nota minima de v (si hi ha
empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
hi ha cap estudiant amb nota, totes dues components valen -1 */
pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
    int size = v.size();
    pair<int, int> alumno_perm;
    alumno_perm.first = -1;
    alumno_perm.second = -1;
    bool hay = false;
    for (int i = 0; i < size; ++i) {
        // Es posible que l'alumne no tingui nota
        if (v[i].te_nota()) {
            if (not hay) {
                alumno_perm.first = alumno_perm.second = i;
                hay = true;
            }
            else {
                hay = true;
                /* Nota maxima */
                double nota_alumno = v[i].consultar_nota();
                double nota_alumno2 = v[alumno_perm.first].consultar_nota();
                if (nota_alumno > nota_alumno2) alumno_perm.first = i;
                // si hi ha empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI
                else if (nota_alumno == nota_alumno2) {
                    if (v[i].consultar_DNI() < v[alumno_perm.first].consultar_DNI()) alumno_perm.first = i;
                    // En cas contrari, ja es correcte
                }

                /* Nota minima */
                double nota_alumno3 = v[alumno_perm.second].consultar_nota();
                if (nota_alumno < nota_alumno3) alumno_perm.second = i;
                else if (nota_alumno == nota_alumno3) {
                    if (v[i].consultar_DNI() < v[alumno_perm.second].consultar_DNI()) alumno_perm.second = i;
                    // En cas contrari, ja es correcte
                }
            }
        }
    }
    // si no hi ha cap estudiant amb nota, totes dues components valen -1
    return alumno_perm;
}