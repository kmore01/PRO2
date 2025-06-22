/** @file Producto.hh
    @brief Especificación de la clase Producto
*/

#ifndef _PRODUCTO_HH_
#define _PRODUCTO_HH_

#ifndef NO_DIAGRAM
#include "PRO2Excepcio.hh"
#include <iostream>
using namespace std;
#endif

/** @class Producto
    @brief Representa una producto. 
*/

class Producto
{
public:
    // Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un producto.
        \pre <em>cierto</em>
        \post El resultado es una producto sin inicializar
    */  
    Producto();

    /** @brief Creadora con todos los valores concretos. 
        \pre pes > 0 y vol > 0
        \post El resultado es un producto con identificador "id", peso "pes", volumen "vol", en_posesion "en_pos" y deseados "des" 
    */   
    Producto(int pes, int vol, int en_pos, int des);

    // Modificadoras

    /** @brief Modificadora de los atributos.
        \pre pes > 0 y vol > 0
        \post El parámetro implícito pasa a tener identificador "id", peso "pes", volumen "vol", en_posesion "en_pos" y deseados "des"  
    */
    void modificar(int pes, int vol, int en_pos, int des);

    /** @brief Modificadora de los atributos.
        \pre <em>cierto</em>
        \post El parámetro implícito pasa a tener ++en_posesion 
    */
    void mas_tiene();

    /** @brief Modificadora de los atributos.
        \pre <em>cierto</em>
        \post El parámetro implícito pasa a tener ++deseados 
    */
    void menos_tiene();

    // Consultoras

    /** @brief Consultora del peso.
        \pre <em>cierto</em>
        \post El resultado es el peso del parámetro implícito
    */
    int consul_peso() const;

    /** @brief Consultora del volumen.
        \pre <em>cierto</em>
        \post El resultado es el volumen del parámetro implícito
    */
    int consul_volumen() const;

    /** @brief Consultora de en_posesion.
        \pre <em>cierto</em>
        \post El resultado es el en_posesion del parámetro implícito
    */
    int consul_enpos() const;

    /** @brief Consultora de deseado.
        \pre <em>cierto</em>
        \post El resultado es el deseados del parámetro implícito
    */
    int consul_des() const;
    
    // Lectura y escritura de producto

    /** @brief Operación de lectura.
        \pre <em>cierto</em>
        \post Se ha leído un producto desde el canal de entrada
    */
    void leer();

    /** @brief Segunda peración de escritura.
        \pre El producto existe
        \post Se ha escrito el peso y volumen del parámetro implícito
    */
    void escribir_producto() const;

private:
    int peso;
    int volumen;
    int en_posesion;
    int deseados;
};
#endif