/** @file Rio.hh
    @brief Especificación de la clase Rio
*/

#ifndef _RIO_HH_
#define _RIO_HH_

#include "Producto.hh"
#include "Ciudad.hh"
#include "Barco.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <list>
#endif

/** @class Rio
    @brief Representa el rio de la cuenca fluvial. 

    
*/

class Rio
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un río.
        \pre <em>cierto</em>
        \post El resultado es un rio sin inicializar
    */  
    Rio();

    /** @brief Creadora con valores concretos. 
        \pre <em>cierto</em>
        \post El resultado es un rio con estructura "cuenca", catalogo "lista_prod" y embarcacion embarc
    */   
    Rio(const map<int, Producto> &cat, const BinTree<string> &estruct, const Barco &embarc);

    // Modificadoras

    /** @brief Añade nuevos productos al catalogo del rio.
        \pre El enterno nprod > 0
        \post El parámetro implícito contiene su carga original más nprod productos nuevos
    */
    void agregar_productos(int nprod);

    /** @brief Modificadora de Barco de Rio.
        \pre Los dos productos existen, diferentes, las unidades no son negativas y al menos una de ellas es estrictamente positiva
        \post El barco del parámetro implícito ha sido modificado
    */
    void modificar_barco(int id1, int nid1, int id2, int nid2);

    /** @brief Modificadora de Ciudad de Rio.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga más p y se ha escrito por el canal standard de salida el peso y volumen total de la ciudad
    */
    void poner_producto(string id, int pid, const Producto &p);

    /** @brief Elimina un Producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga menos p y se ha escrito por el canal standard de salida el peso y volumen total de la ciudad
    */
    void quitar_producto(string id, int pid);

    /** @brief Modifica un Producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados y se ha escrito por el canal standard de salida el peso y volumen total de la ciudad
    */
    void modificar_producto(string id, int pid, const Producto &p);

    /** @brief Modifica un Producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados
    */
    void modificar_producto2(string id, int pid, const Producto &p);

    /** @brief Comercia entre dos ciudades con identificadores id1 y id2.
        \pre Las dos ciudades existen y son diferentes
        \post Los productos de las dos ciudades han sido modificados
    */
    void comerciar(string id1, string id2);

    /** @brief La ciudad de la desembocadura comercia con su ciudad río arriba a mano derecha hay luego con la ciudad río arriba a mano izquierda, y así sucesivamente
        \pre <em>cierto</em>
        \post Los inventarios de las ciudades del Rio han sido modificados
    */
    void redistribuir();

    /** @brief El Barco compra y vende productos por la ruta que le permita mas esto, en caso de empate, se queda con la más corta, y en caso de que tengan la misma longitud, se queda con la que viene río arriba a mano derecha
        \pre <em>cierto</em>
        \post Los inventarios de las ciudades del cio han sido modificados y se ha escrito por el canal de salida los productos vendidos y comprados por el barco en su ruta
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
        \post El resultado es true si la ciudad existe, de otra manera es falso
    */
    bool existe_ciudad(string id) const;

    /** @brief Consultora de la existencia de un producto.
        \pre <em>cierto</em>
        \post El resultado es true si el producto existe, de otra manera es falso
    */
    bool existe_prod(int id) const;

    /** @brief Consultora de la mejor ruta posible que permita al barco comprar y vender la mayor cantidad de productos.
        \pre <em>cierto</em>
        \post El resultado es camino más conveniente
    */
    list<string> camino();

    // Lectura y escritura de rio

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

    /** @brief Operación de escriuta del producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Se escribe el producto de la ciudad "identificador" con id "id"
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
    map<int, Producto> catalogo;
    BinTree<string> estructura;
    // id->Ciudad
    map<string, Ciudad> infoCiudades;
    Barco embarcacion;

    BinTree<string> leer_rio2();
    void redistribuir2(BinTree<string> t);
    static list<string> camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco &b, int &compradas, int &vendidas);
};
#endif
