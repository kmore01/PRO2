/** @file Barco.hh
    @brief Especificación de la clase Barco
*/

#ifndef _BARCO_HH_
#define _BARCO_HH_

#include "Producto.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Barco
    @brief Representa el barco comerciante de la cuenca fluvial. 

    
*/

class Barco
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar el barco.
        \pre <em>cierto</em>
        \post El resultado es el barco sin ningun tipo de producto
    */  
    Barco();

    /** @brief Creadora con valores concretos. 
        \pre <em>cierto</em>
        \post El resultado es el barco con comprar "comp" y vender "vend"
    */   
    Barco(int id1, int nid1, int id2, int nid2);

    // Modificadoras

    /** @brief Modifica la carga del barco.
        \pre Los dos productos existen, diferentes, las unidades no son negativas y al menos una de ellas es estrictamente positiva
        \post La carga del parámetro implícito se ha visto modificado
    */  
    void modificar_barco(int id1, int nid1, int id2, int nid2);

    // Consultoras

    // Lectura y escritura de barco

    /** @brief Operación de lectura.
        \pre <em>cierto</em>
        \post Se ha leído un barco desde el canal de entrada
    */
    void leer();

    /** @brief Operación de escritura.
        \pre <em>cierto</em>
        \post Se ha escrito el producto a comprar y el producto a vender
    */
    void escribir_barco() const;

private:
    int idProductoComprar;
    int nProductoComprar;
    int idProductoVender;
    int nProductoVender;
    // VECTOR O LIST
    vector<string> viajes;
};
#endif