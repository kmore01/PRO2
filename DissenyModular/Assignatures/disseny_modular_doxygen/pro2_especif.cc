/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main () {
    Lavadora lav;
    Cubeta cub;
    int opcion;
    cin >> opcion;
    while (opcion != -8) {    
        // inicializar lavadora (datos: peso máximo y color)
        if (opcion == -1) {
            int pmaxim;
            bool color;
            cin >> pmaxim;
            color = readbool();
            lav.inicializar(pmaxim, color);
        }
        // añadir una prenda a la lavadora (datos: peso  y color de la prenda)
        else if (opcion == -2) {
            int peso;
            bool color;
            cin >> peso;
            color = readbool();
            Prenda pren(peso, color);
            lav.anadir_prenda(pren);
        }
        // añadir una prenda a la cubeta (datos: peso  y color de la prenda)
        else if (opcion == -3) {
            int peso;
            bool color;
            cin >> peso;
            color = readbool();
            Prenda pren(peso, color);
            cub.anadir_prenda(pren);
        }
        // completar la lavadora
        else if (opcion == -4) {
            cub.completar_lavadora(lav);
        }
        // realizar un lavado
        else if (opcion == -5) {
            lav.lavado();
        }
        // escribir el contenido de la cubeta
        else if (opcion == -6) {
            cub.escribir();
        }
        // escribir el contenido de la lavadora
        else if (opcion == -7) {
            lav.escribir();
        }
        cin >> opcion;
    }
}
