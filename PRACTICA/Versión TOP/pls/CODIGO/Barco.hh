/** @file Barco.hh
    @brief Especificación de la clase Barco
*/

#ifndef _BARCO_HH_
#define _BARCO_HH_

#include "Producto.hh"

#ifndef NO_DIAGRAM
#include <list>
#endif

/** @class Barco
    @brief Representa el barco comerciante de la cuenca fluvial. 

    Sus operaciones son las modificadoras de todos los atributos, las unidades a comprar y vender y añadir un nuevo viaje, las consultoras de el identificador del producto a comprar y vender y sus respectivas cantidades, la de lectura y la de escritura.
*/

class Barco
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar el barco.
        \pre <em>cierto</em>
        \post El resultado es el barco sin ningun tipo de atributo
    */  
    Barco();

    /** @brief Creadora con valores concretos. 
        \pre <em>cierto</em>
        \post El resultado es el barco con idProductoComprar "id1", nproductoComprar "nid1", idProductoVender "id2", nProductoVender "nid2" y viajes "l"
    */   
    Barco(int id1, int nid1, int id2, int nid2, list<string> l);

    // Modificadoras

    /** @brief Modificadora de la carga del barco.
        \pre Los dos productos existen, son diferentes, las unidades no son negativas y al menos una de ellas es estrictamente positiva
        \post La carga del parámetro implícito se ha visto modificada
    */  
    void modificar_barco(int id1, int nid1, int id2, int nid2);

    /** @brief Modificadora de las unidades de producto a comprar.
        \pre El entero nid1 >= 0
        \post El atributo nproductoComprar del parámetro implícito se ha visto modificada
    */ 
    void modificar_ncomprar(int nid1);

    /** @brief Modificadora de las unidades de producto a vender.
        \pre El entero nid2 >= 0
        \post El atributo nProductoVender del parámetro implícito se ha visto modificada
    */ 
    void modificar_nvender(int nid2);

    /** @brief Añade un nuevo viaje.
        \pre <em>cierto</em>
        \post La carga del parámetro implícito se ha visto modificada
    */ 
    void anadir_viaje(string ciudad);

    // Consultoras

    /** @brief Consultora de el id del producto a comprar.
        \pre <em>cierto</em>
        \post El resultado es el id del producto que el barco busca comprar
    */ 
    int consultar_idcompra() const;

    /** @brief Consultora de las unidades de producto a comprar.
        \pre <em>cierto</em>
        \post El resultado es el numero de productos que el barco busca comprar
    */ 
    int consultar_nidcompra() const;

    /** @brief Consultora de el id del producto a vender.
        \pre <em>cierto</em>
        \post El resultado es el id del producto que el barco busca vender
    */ 
    int consultar_idventa() const;

    /** @brief Consultora de las unidades de producto a vender.
        \pre <em>cierto</em>
        \post El resultado es el numero de productos que el barco busca vender
    */ 
    int consultar_nidventa() const;

    // Lectura y escritura de barco

    /** @brief Operación de lectura.
        \pre <em>cierto</em>
        \post Se ha leído un barco desde el canal de entrada
    */
    void leer();

    /** @brief Operación de escritura.
        \pre <em>cierto</em>
        \post Se han escrito los atributos del parámetro implícito por el canal de salida
    */
    void escribir_barco() const;

private:
    int idProductoComprar;
    int nProductoComprar;
    int idProductoVender;
    int nProductoVender;
    list<string> viajes;
};
#endif