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
    Rio(map<int, Producto> cat, BinTree<string> estruct, map<string, bool> ciud, Barco embarc);

    // Modificadoras

    /** @brief Añade nuevos productos al catalogo del Rio.
        \pre nprod > 0
        \post El parámetro implícito contiene su carga original más nprod nuevos
    */
    void agregar_productos(int nprod);

    /** @brief Modificadora de Barco de Rio.
        \pre Los dos productos existen, diferentes, las unidades no son negativas y al menos una de ellas es estrictamente positiva
        \post El barco del parámetro implícito ha sido modificado
    */
    void modificar_barco(int id1, int nid1, int id2, int nid2);

    /** @brief Modificadora de Ciudad de Rio.
        \pre El producto existe, la ciudad existe y el producto no está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados
    */
    void poner_producto(string id, int pid, Producto &p);

    /** @brief Elimina un Producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados
    */
    void quitar_producto(string id, int pid);

    /** @brief Modifica un Producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Los productos del parámetro implícito han sido modificados
    */
    void modificar_producto(string id, int pid, Producto &p);

    /** @brief Comercia entre dos ciudades con id1 y id2.
        \pre Las dos ciudades existen
        \post Los productos de las ciudades del parámetro implícito han sido modificados
    */
    void comerciar(string id1, string id2);

    /** @brief La ciudad de la desembocadura comercia con su ciudad río arriba a mano derec hay luego con la ciudad río arriba a mano izquierda, y así sucesivamente
        \pre <em>cierto</em>
        \post Los inventarios de las Ciudades del Rio han sido modificados
    */
    void redistribuir();

    // Consultoras

    /** @brief Consultora del número de productos diferentes.
        \pre <em>cierto</em>
        \post El resultado es el tamaño del diccionario del parámetro implícito
    */
    int consultar_num() const;

    /** @brief Consultora del peso de un Producto.
        \pre <em>cierto</em>
        \post El resultado es el peso del Producto
    */
    int consultar_peso(int id) const;

    /** @brief Consultora del volumen de un Producto.
        \pre <em>cierto</em>
        \post El resultado es el volumen del Producto
    */
    int consultar_volumen(int id) const;

    /** @brief Consultora del Producto de una Ciudad.
        \pre El producto existe, la ciudad existe y el producto está en el inventario de la ciudad
        \post Se escribe el producto de la Ciudad "identificador" con id id
    */
    void consultar_prod(string identificador, int id) const;

    /** @brief Consultora de la existencia de una ciudad.
        \pre <em>cierto</em>
        \post El resultado es true si la ciudad existe, de otra manera falso
    */
    bool existe_ciudad(string id) const;

    /** @brief Consultora de la existencia de un producto.
        \pre <em>cierto</em>
        \post El resultado es true si el producto existe, de otra manera falso
    */
    bool existe_prod(int id) const;

    // Lectura y escritura de rio

    /** @brief Primera operación de lectura.
        \pre <em>cierto</em>
        \post Se ha leído la estructura del rio
    */
    BinTree<string> leer_rio();

    /** @brief Segunda operación de lectura.
        \pre La ciudad existe
        \post Se ha leído el inventario de una ciudad
    */
    void leer_inventario(string id);

    /** @brief Tercera operación de lectura.
        \pre <em>cierto</em>
        \post Se ha leído el inventario de varias ciudades
    */
    void leer_inventarios();

    /** @brief Cuarta operación de lectura.
        \pre <em>cierto</em>
        \post Se ha leído todos los productos de río
    */
    void leer_productos_dif();

    /** @brief Operación de lectura del atributo Barco.
        \pre <em>cierto</em>
        \post Se ha leído el barco de río
    */
    void leer_barco();

    /** @brief Primera operación de escritura.
        \pre La ciudad con identificador "id" existe
        \post Se han escrito los atributos del parámetro implícito en el canal
        standard de salida  
    */
    void escribir_ciudad(string id) const;

    /** @brief Segunda operación de escritura.
        \pre El producto con identificador id existe
        \post Se han escrito los atributos del parámetro implícito en el canal
        standard de salida  
    */
    void escribir_prod(int id) const;

    /** @brief Tercera operación de escritura.
        \pre <em>cierto</em>
        \post Se han escrito los atributos del parámetro implícito en el canal
        standard de salida  
    */
    void escribir_barco() const;



private:
    map<int, Producto> catalogo;
    BinTree<string> estructura;
    // id->Ciudad
    map<string, Ciudad> infoCiudades;
    // string->Ciudad
    map<string, bool> ciudades;
    Barco embarcacion;
    void redistribuir2(BinTree<string> t);
};
#endif
