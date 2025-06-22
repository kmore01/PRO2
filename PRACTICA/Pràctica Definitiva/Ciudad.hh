/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad 
*/

#ifndef _CIUDAD_HH_
#define _CIUDAD_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Ciudad
    @brief Representa una ciudad perteneciente a la cuenca fluvial. 

    Sus operaciones son las modificadoras del inventario para poner, modificar 
    y quitar productos, comerciar e inicializar los atributos, las consultoras 
    de los productos del inventario, la cantidad que tiene y quiere de un 
    producto y si el producto está en el inventario, la de escritura de un producto y una ciudad.
*/

class Ciudad
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar una ciudad.
        \pre <em>cierto</em>
        \post El resultado es una ciudad sin ningún tipo de atributo
    */  
    Ciudad();

    /** @brief Creadora con valores concretos. 
        \pre <em>cierto</em>
        \post El resultado es la ciudad con inventario "inv", peso_total "pes_tot" y volumen_total "vol_tot"
    */   
    Ciudad(const map<int, pair<int, int>> &inv, int pes_tot, int vol_tot);

    // Modificadoras

    /** @brief Añade un producto al inventario de la ciudad.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga original más p y se ha escrito el peso y volumen total por el canal standard de salida
    */
    void poner_producto(int peso, int volumen, const pair<int, int> &p,
    int id_producto);

    /** @brief Añade un producto al inventario de la ciudad.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga original más p
    */
    void poner_producto2(int peso, int volumen, const pair<int, int> &p,
    int id_producto);

    /** @brief Modifica un producto de la ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El inventario del parámetro implícito se ha visto modificado y se ha escrito el peso y volumen total por el canal standard de salida 
    */
    void modificar_producto(int peso, int volumen, const pair<int, int> &p,
    int id_producto);

    /** @brief Modifica un producto de la ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El inventario del parámetro implícito se ha visto modificado
    */
    void modificar_producto2(int peso, int volumen, const pair<int, int> &p,
    int id_producto);

    /** @brief Elimina un producto de la ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga original menos p y se ha escrito el peso y volumen total por el canal standard de salida 
    */
    void quitar_producto(int peso, int volumen, int id_producto);

    /** @brief Dos ciudades comercian entre ellas.
        \pre Las dos ciudades existen y son diferentes
        \post Se han intercambiado los productos que le sobraban a una ciudad y necesitaba la otra
    */
    void comerciar_inventario(Ciudad &c, 
    const map<int, pair<int, int>> &catalogo);

    /** @brief Inicializa el inventario y el peso y volumen total del parametro implicito.
        \pre <em>cierto</em>
        \post Los atributos mencionados anteriormente han sido inicializados
    */
    void inicializar();

    // Consultoras

    /** @brief Devuelve cuántos productos tiene la ciudad.
        \pre La ciudad existe
        \post El resultado es el tamaño del inventario de la ciudad
    */
    int consultar_size() const;

    /** @brief Devuelve cuántas unidades tiene la ciudad de un producto.
        \pre El producto existe y se encuentra en el inventario
        \post El resultado es la cantidad que tiene la ciudad del producto con identificador "id"
    */
    int consultar_tiene(int id) const;

    /** @brief Devuelve cuántas unidades quiere la ciudad de un producto.
        \pre El producto existe y se encuentra en el inventario
        \post El resultado es la cantidad que quiere la ciudad del producto con identificador "id"
    */
    int consultar_quiere(int id) const;

    /** @brief Consultora de la existencia de un producto.
        \pre <em>cierto</em>
        \post El resultado es cierto si el parametro implícito contiene el producto con identificador "id" y falso en caso contrario
    */
    bool existe(int id) const;
    
    // Escritura

    /** @brief Escribe cuantas unidades tiene y quiere la ciudad de un producto.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Se han escrito cuantas unidades tiene y quiere la ciudad en el canal standard de salida
    */
    void consultar_producto(int id_producto) const;

    /** @brief Operación de escritura.
        \pre La ciudad existe
        \post Se ha escrito el inventario, el peso total y volumen total del parámetro implícito por el canal standard de salida  
    */
    void escribir_ciudad() const;

private:
    // identificador->producto(tiene, quiere)
    map<int, pair<int, int>> inventario;
    int peso_total;
    int volumen_total;
};
#endif