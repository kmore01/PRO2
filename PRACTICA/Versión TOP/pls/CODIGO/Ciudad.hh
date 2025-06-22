/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad
*/

#ifndef _CIUDAD_HH_
#define _CIUDAD_HH_

#include "Producto.hh"
#include "Barco.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Ciudad
    @brief Representa una ciudad perteneciente a la cuenca fluvial. 

    
*/

class Ciudad
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar una ciudad.
        \pre <em>cierto</em>
        \post El resultado es una ciudad sin inicializar
    */  
    Ciudad();

    /** @brief Creadora con valores concretos. 
        \pre <em>cierto</em>
        \post El resultado es una ciudad con identificador "id"
    */   
    Ciudad(string id);

    // Modificadoras

    /** @brief Añade un producto al inventario de la ciudad.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga original más p y se ha escrito el peso y volumen total por el canal de salida
    */
    void poner_producto(const Producto &p, int id_producto);

    /** @brief Añade un producto al inventario de la ciudad.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga original más p
    */
    void poner_producto2(const Producto &p, int id_producto);

    /** @brief Modifica un producto de la ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El inventario del parámetro implícito se ha visto modificado y se ha escrito el peso y volumen total por el canal de salida 
    */
    void modificar_producto(const Producto &p, int id_producto);

    /** @brief Modifica un producto de la ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El inventario del parámetro implícito se ha visto modificado
    */
    void modificar_producto2(const Producto &p, int id_producto);

    /** @brief Elimina un producto de la ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post El parámetro implícito contiene su carga original menos p
    */
    void quitar_producto(int id_producto);

    /** @brief Dos ciudades comercian entre ellas.
        \pre Las dos ciudades existen y son diferentes
        \post Los inventarios de las dos ciudades han sido modificados
    */
    void comerciar_inventario(Ciudad &c);

    /** @brief Inicializa el peso y volumen total del parametro implicito.
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
        \post El resultado es la cantidad del producto con identificador "id"
    */
    int consultar_tiene(int id) const;

    /** @brief Devuelve cuántas unidades quiere la ciudad de un producto.
        \pre El producto existe y se encuentra en el inventario
        \post El resultado es la cantidad que quiere la ciudad del producto con identificador "id"
    */
    int consultar_quiere(int id) const;

    bool existe(int id) const;
    
    // Escritura de ciudad

    /** @brief Escribe cuantas unidades tiene y quiere la ciudad de un producto.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Se han escrito cuantas unidades tiene y quiere la ciudad en el canal standard de salida
    */
    void consultar_producto(int id_producto) const;

    /** @brief Operación de escritura.
        \pre La ciudad existe
        \post Se han escrito los atributos del parámetro implícito en el canal
        standard de salida  
    */
    void escribir_ciudad() const;

private:
    string identificador;
    // identificador->Prodcuto
    map<int, Producto> inventario;
    int peso_total;
    int volumen_total;
};
#endif