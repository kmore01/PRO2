/** @file Rio.hh
    @brief Especificación de la clase Rio
*/

#ifndef _RIO_HH_
#define _RIO_HH_

#include "Ciudad.hh"
#include "Barco.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <list>
#endif

/** @class Rio
    @brief Representa el río de la cuenca fluvial. 

    Sus operaciones son las modificadoras de barco, añadir productos al 
    catalogo, añadir, quitar y modificar productos de inventario, comerciar 
    entre ciudad, redistribuir la cuenca y hacer viaje en la cuenca, las 
    consultoras de los productos de la cuenca, peso y volumen y existencia de 
    una ciudad y producto, la de lectura del río, inventarios, productos de la 
    cuenca, barco y la de escritura de ciudad, producto de una ciudad, producto 
    de la cuenca y barco.
*/

class Rio
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un río.
        \pre <em>cierto</em>
        \post El resultado es un río sin ningún tipo de atributo
    */
    Rio();

    /** @brief Creadora con valores concretos. 
        \pre <em>cierto</em>
        \post El resultado es un río con catalogo "cat", estructura "estruct" y barco "embarc"
    */   
    Rio(const map<int, pair<int, int>> &cat,
    const BinTree<string> &estruct, const Barco &embarc);

    // Modificadoras

    /** @brief Añade nuevos productos al catalogo del río.
        \pre El enterno nprod > 0
        \post El parámetro implícito contiene su carga original más nprod productos nuevos
    */
    void agregar_productos(int nprod);

    /** @brief Modificadora del barco del río.
        \pre Los dos productos existen, diferentes, las unidades no son negativas y al menos una de ellas es estrictamente positiva
        \post El barco del parámetro implícito ha sido modificado
    */
    void modificar_barco(int id1, int nid1, int id2, int nid2);

    /** @brief Modificadora de ciudad del río.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga más p y se ha escrito por el canal standard de salida el peso y volumen total de la ciudad
    */
    void poner_producto(string id, int pid, const pair<int, int> &p);

    /** @brief Elimina un producto de una ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga menos p y se ha escrito por el canal standard de salida el peso y volumen total de la ciudad
    */
    void quitar_producto(string id, int pid);

    /** @brief Modifica un producto de una ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados y se ha escrito por el canal standard de salida el peso y volumen total de la ciudad
    */
    void modificar_producto(string id, int pid, const pair<int, int> &p);

    /** @brief Modifica un producto de una ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados
    */
    void modificar_producto2(string id, int pid, const pair<int, int> &p);

    /** @brief Se intercambian los productos que le sobren a una ciudad y necesite la otra ciudad.
        \pre Las dos ciudades existen y son diferentes
        \post Los productos de las dos ciudades han sido modificados
    */
    void comerciar(string id1, string id2);

    /** @brief La ciudad de la desembocadura comercia con su ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda, y así sucesivamente
        \pre <em>cierto</em>
        \post Los inventarios de las ciudades del río han sido modificados
    */
    void redistribuir();

    /** @brief El Barco compra y vende productos por la ruta que le permita mas esto, en caso de empate, se queda con la más corta, y en caso de que tengan la misma longitud, se queda con la que viene río arriba a mano derecha.
        \pre <em>cierto</em>
        \post Los inventarios de las ciudades del río han sido modificados y se ha escrito por el canal standard de salida los productos vendidos y comprados por el barco
    */
    void hacer_viaje();

    // Consultoras

    /** @brief Consultora del número de productos diferentes en la cuenca.
        \pre <em>cierto</em>
        \post El resultado es el tamaño del catalogo del parámetro implícito
    */
    int consultar_num() const;

    /** @brief Consultora del peso de un producto.
        \pre El producto existe
        \post El resultado es el peso del producto
    */
    int consultar_peso(int id) const;

    /** @brief Consultora del volumen de un producto.
        \pre El producto existe
        \post El resultado es el volumen del producto
    */
    int consultar_volumen(int id) const;

    /** @brief Consultora de la existencia de una ciudad.
        \pre <em>cierto</em>
        \post El resultado es cierto si la ciudad existe y falso en caso contrario
    */
    bool existe_ciudad(string id) const;

    /** @brief Consultora de la existencia de un producto.
        \pre <em>cierto</em>
        \post El resultado es cierto si el producto existe y falso en caso contrario
    */
    bool existe_prod(int id) const;

    // Lectura y escritura

    /** @brief Operación de lectura de la estructura de la cuenca.
        \pre <em>cierto</em>
        \post Se ha leído la estructura del rio
    */
    void leer_rio();

    /** @brief Operación de lectura de el inventario de una ciudad.
        \pre La ciudad existe
        \post Se ha leído el inventario de una ciudad
    */
    void leer_inventario(string id);

    /** @brief Operación de lectura de los inventarios de las ciudades.
        \pre <em>cierto</em>
        \post Se ha leído el inventario de varias ciudades
    */
    void leer_inventarios();

    /** @brief Operación de lectura de los productos de toda la cuenca.
        \pre <em>cierto</em>
        \post Se ha leído todos los productos de la cuenca
    */
    void leer_productos_dif();

    /** @brief Operación de lectura de barco.
        \pre <em>cierto</em>
        \post Se ha leído el barco de la cuenca
    */
    void leer_barco();

    /** @brief Operación de escritura de una ciudad.
        \pre La ciudad con identificador "id" existe
        \post Se han escrito los atributos de la ciudad en el canal
        standard de salida  
    */
    void escribir_ciudad(string id) const;

    /** @brief Operación de escriuta del producto de una ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Se escribe el producto de la ciudad "identificador" con identificador "id"
    */
    void consultar_prod(string identificador, int id) const;

    /** @brief Operación de escritura de un producto de la cuenca.
        \pre El producto con identificador "id" existe
        \post Se han escrito los atributos del producto en el canal
        standard de salida  
    */
    void escribir_prod(int id) const;

    /** @brief Operación de escritura del barco de la cuenca.
        \pre <em>cierto</em>
        \post Se han escrito los atributos del barco en el canal
        standard de salida  
    */
    void escribir_barco() const;

private:
    // id->producto(peso, volumen)
    map<int, pair<int, int>> catalogo;
    BinTree<string> estructura;
    // id->Ciudad
    map<string, Ciudad> infoCiudades;
    Barco embarcacion;

    /** @brief Operación de lectura recursiva de la estructura de la cuenca.
        \pre <em>cierto</em>
        \post Se ha leído la estructura recursivamente del rio
    */
    BinTree<string> leer_rio2();

    /** @brief La ciudad de la desembocadura comercia con su ciudad río arriba a mano derecha y luego con la ciudad río arriba a mano izquierda, y así sucesivamente
        \pre <em>cierto</em>
        \post Los inventarios de las ciudades han sido modificados usando un algoritmo recursivo
    */
    void redistribuir2(const BinTree<string> &t);

    /** @brief Consultora de la mejor ruta posible que permita al barco comprar y vender la mayor cantidad de productos.
        \pre <em>cierto</em>
        \post El resultado es el camino más conveniente posible
    */
    static list<string> camino(const BinTree<string> &t,
    const map<string, Ciudad> &info, int &nidc, int &nidv, int idc, int idv);
};
#endif
