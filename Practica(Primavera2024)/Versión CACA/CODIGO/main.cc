/** @mainpage
    El programa principal se encuentra en el módulo main.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Rio en el que se desarrollarán las diferentes acciones previamente estipuladas, otro para el tipo Ciudad, otro para el tipo Producto y otro para el tipo Barco.
*/

/** @file main.cc

    @brief Programa principal
    
    Estamos suponiendo que los datos leídos siempre son correctos, ya que
    no incluímos comprobaciones al respecto. Utilizaremos strings como opciones como el enunciado estipula.
*/

#include "Rio.hh"
#include "Ciudad.hh" 
#include "Barco.hh"
#include "Producto.hh"

typedef BinTree<Ciudad> BT;

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

    /* BUCLE */
    string accion;
    getline(cin, accion);
    getline(cin, accion); // Consumir // bucle

    cin >> accion;
    while (accion != "fin") {
        cout << '#' << accion;
        if (accion == "leer_rio" or accion == "lr") {
            cout << endl;
            cuenca.leer_rio();
        }

        else if (accion == "leer_inventario" or accion == "li") {
            string identificador;
            cin >> identificador;
            cout << ' ' << identificador << endl;
            if (cuenca.existe_ciudad(identificador)) {
                cuenca.leer_inventario(identificador);
            }
            else {
                cout << "error: no existe la ciudad" << endl;
                int n;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    int x;
                    cin >> x >> x >> x;
                }
            }
        }

        else if (accion == "leer_inventarios" or accion == "ls") {
            cout << endl;
            cuenca.leer_inventarios();
        }

        else if (accion == "modificar_barco" or accion == "mb") {
            cout << endl;
            int id1, nid1, id2, nid2;
            cin >> id1 >> nid1 >> id2 >> nid2;
            if (id1 == id2) 
            cout << "error: no se puede comprar y vender el mismo producto" << endl;
            else if (cuenca.existe_prod(id1) and cuenca.existe_prod(id2)) {
                cuenca.modificar_barco(id1, nid1, id2, nid2);
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "escribir_barco" or accion == "eb") {
            cout << endl;
            cuenca.escribir_barco();
        }

        else if (accion == "consultar_num" or accion == "cn") {
            cout << endl;
            cout << cuenca.consultar_num() << endl;
        }

        else if (accion == "agregar_productos" or accion == "ap") {
            int n;
            cin >> n;
            cout << ' ' << n << endl;
            if (n > 0) cuenca.agregar_productos(n);
            else cout << "FALLO N <= 0" << endl;
        }

        else if (accion == "escribir_producto" or accion == "ep") {
            int identificiador;
            cin >> identificiador;
            cout << ' ' << identificiador << endl;
            if (cuenca.existe_prod(identificiador)) {
                cuenca.escribir_prod(identificiador);
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "escribir_ciudad" or accion == "ec") {
            string identificador;
            cin >> identificador;
            cout << ' ' << identificador << endl;
            if (cuenca.existe_ciudad(identificador)) {
                cuenca.escribir_ciudad(identificador);
            }
            else cout << "error: no existe la ciudad" << endl;
        }

        else if (accion == "poner_prod" or accion == "pp") {
            string idCiudad;
            int idProducto, tiene, quiere;
            cin >> idCiudad >> idProducto >> tiene >> quiere;
            cout << ' ' << idCiudad << ' ' << idProducto << endl;
            if (cuenca.existe_prod(idProducto)) {
                if (cuenca.existe_ciudad(idCiudad)) {
                    Producto aux (cuenca.consultar_peso(idProducto), cuenca.consultar_volumen(idProducto),tiene, quiere);
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
            cout << ' ' << idCiudad << ' ' << idProducto << endl;
            if (cuenca.existe_prod(idProducto)) {
                if (cuenca.existe_ciudad(idCiudad)) {
                    Producto aux (cuenca.consultar_peso(idProducto), cuenca.consultar_volumen(idProducto),tiene, quiere);
                    cuenca.modificar_producto(idCiudad, idProducto, aux);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "quitar_prod" or accion == "qp") {
            string identificador;
            int id;
            cin >> identificador >> id;
            cout << ' ' << identificador << ' ' << id << endl;
            if (cuenca.existe_prod(id)) {
                if (cuenca.existe_ciudad(identificador)) {
                    cuenca.quitar_producto(identificador, id);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "consultar_prod" or accion == "cp") {
            string identificador;
            int id;
            cin >> identificador >> id;
            cout << ' ' << identificador << ' ' << id << endl;
            if (cuenca.existe_prod(id)) {
                if (cuenca.existe_ciudad(identificador)) {
                    cuenca.consultar_prod(identificador, id);
                }
                else cout << "error: no existe la ciudad" << endl;
            }
            else cout << "error: no existe el producto" << endl;
        }

        else if (accion == "comerciar" or accion == "co") {
            string identificador1, identificador2;
            cin >> identificador1 >> identificador2;
            cout << ' ' << identificador1 << ' ' << identificador2 << endl;
            if (identificador1 == identificador2) cout << "error: ciudad repetida" << endl;
            else if (cuenca.existe_ciudad(identificador1) and cuenca.existe_ciudad(identificador2)) {
                cuenca.comerciar(identificador1, identificador2);
            }
            else cout << "error: no existe la ciudad" << endl;
        }

        else if (accion == "redistribuir" or accion == "re") {
            cout << endl;
            cuenca.redistribuir();
        }

        else if (accion == "hacer_viaje" or accion == "hv"){ // "hacer_viaje" o "hv"
            cout << "EN PROCESO" << endl;
        }
        cin >> accion;
    }
}