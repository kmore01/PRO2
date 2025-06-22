/** @mainpage
    El programa principal se encuentra en el módulo program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Rio en el que se desarrollarán las diferentes acciones previamente estipuladas, otro para el tipo Ciudad y otro para el tipo Barco.
*/

/** @file program.cc
    @brief Programa principal
*/

#include "Rio.hh"

int main() 
{
    /* LECTURA INICIAL */
    Rio cuenca;
    // Leemos todos los productos que hay en el rio
    cuenca.leer_productos_dif();
    // Leemos la estructura de la cuenca fluvial
    cuenca.leer_rio();
    // Leemos los datos del barco
    cuenca.leer_barco();

    /* BUCLE ACCIONES */
    string accion;
    cin >> accion;
    while (accion != "fin") {
        if (accion == "leer_rio" or accion == "lr") {
            cout << '#' << accion << endl;
            cuenca.leer_rio();
        }

        else if (accion == "leer_inventario" or accion == "li") {
            string identificador;
            cin >> identificador;
            cout << '#' << accion << ' ' << identificador << endl;
            if (cuenca.existe_ciudad(identificador)) {
                cuenca.leer_inventario(identificador);
            }
            else {
                cout << "error: no existe la ciudad" << endl;
                // Tenemos que leer los datos aunque la ciudad sea erronea
                int numProd;
                cin >> numProd;
                for (int i = 0; i < numProd; ++i) {
                    int basura;
                    cin >> basura >> basura >> basura;
                }
            }
        }

        else if (accion == "leer_inventarios" or accion == "ls") {
            cout << '#' << accion << endl;
            cuenca.leer_inventarios();
        }

        else if (accion == "modificar_barco" or accion == "mb") {
            cout << '#' << accion << endl;
            int id1, nid1, id2, nid2;
            cin >> id1 >> nid1 >> id2 >> nid2;
            if (cuenca.existe_prod(id1) and cuenca.existe_prod(id2)) {
                if (id1 == id2)  {
                    cout << "error: no se puede comprar y vender el mismo producto" << endl;
                }
                else cuenca.modificar_barco(id1, nid1, id2, nid2);
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "escribir_barco" or accion == "eb") {
            cout << '#' << accion << endl;
            cuenca.escribir_barco();
        }

        else if (accion == "consultar_num" or accion == "cn") {
            cout << '#' << accion << endl;
            cout << cuenca.consultar_num() << endl;
        }

        else if (accion == "agregar_productos" or accion == "ap") {
            int numProd;
            cin >> numProd;
            cout << '#' << accion << ' ' << numProd << endl;
            cuenca.agregar_productos(numProd);
        }

        else if (accion == "escribir_producto" or accion == "ep") {
            int identificiador;
            cin >> identificiador;
            cout << '#' << accion << ' ' << identificiador << endl;
            if (cuenca.existe_prod(identificiador)) {
                cuenca.escribir_prod(identificiador);
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "escribir_ciudad" or accion == "ec") {
            string identificador;
            cin >> identificador;
            cout << '#' << accion << ' ' << identificador << endl;
            if (cuenca.existe_ciudad(identificador)) {
                cuenca.escribir_ciudad(identificador);
            }
            else cout << "error: no existe la ciudad" << endl;
        }

        else if (accion == "poner_prod" or accion == "pp") {
            string idCiudad;
            int idProducto, tiene, quiere;
            cin >> idCiudad >> idProducto >> tiene >> quiere;
            cout << '#' << accion << ' ' << idCiudad << ' ' 
                 << idProducto << endl;
            if (cuenca.existe_prod(idProducto)) {
                if (cuenca.existe_ciudad(idCiudad)) {
                    pair<int, int> aux(tiene, quiere);
                    cuenca.poner_producto(idCiudad, idProducto, aux);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "modificar_prod" or accion == "mp") {
            string idCiudad;
            int idProducto, tiene, quiere;
            cin >> idCiudad >> idProducto >> tiene >> quiere;
            cout << '#' << accion << ' ' << idCiudad << ' ' 
                 << idProducto << endl;
            if (cuenca.existe_prod(idProducto)) {
                if (cuenca.existe_ciudad(idCiudad)) {
                    pair<int, int> aux(tiene, quiere);
                    cuenca.modificar_producto(idCiudad, idProducto, aux);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "quitar_prod" or accion == "qp") {
            string identificador;
            int idProducto;
            cin >> identificador >> idProducto;
            cout << '#' << accion << ' ' << identificador << ' ' 
                 << idProducto << endl;
            if (cuenca.existe_prod(idProducto)) {
                if (cuenca.existe_ciudad(identificador)) {
                    cuenca.quitar_producto(identificador, idProducto);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "consultar_prod" or accion == "cp") {
            string identificador;
            int idProducto;
            cin >> identificador >> idProducto;
            cout << '#' << accion << ' ' << identificador 
                 << ' ' << idProducto << endl;
            if (cuenca.existe_prod(idProducto)) {
                if (cuenca.existe_ciudad(identificador)) {
                    cuenca.consultar_prod(identificador, idProducto);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "comerciar" or accion == "co") {
            string identificador1, identificador2;
            cin >> identificador1 >> identificador2;
            cout << '#' << accion << ' ' << identificador1 
                 << ' ' << identificador2 << endl;
            if (identificador1 == identificador2) {
                cout << "error: ciudad repetida" << endl;
            }
            else if (cuenca.existe_ciudad(identificador1) and cuenca.existe_ciudad(identificador2)) {
                cuenca.comerciar(identificador1, identificador2);
            }
            else cout << "error: no existe la ciudad" << endl;
        }

        else if (accion == "redistribuir" or accion == "re") {
            cout << '#' << accion << endl;
            cuenca.redistribuir();
        }

        else if (accion == "hacer_viaje" or accion == "hv"){
            cout << '#' << accion << endl;
            cuenca.hacer_viaje();
        }

        else { // Es un comentario empezado por "//"
            string basura;
            getline(cin, basura);
        }
        cin >> accion;
    }
}