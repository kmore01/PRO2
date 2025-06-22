/** @file Barco.cc
    @brief Codigo de la clase Barco
*/

#include "Barco.hh"

Barco::Barco()
{
    idProductoComprar = 0;
    nProductoComprar = 0;
    idProductoVender = 0;
    nProductoVender = 0;
    viajes = list<string>();
}

Barco::Barco(int id1, int nid1, int id2, int nid2, list<string> l)
{
    idProductoComprar = id1;
    nProductoComprar = nid1;
    idProductoVender = id2;
    nProductoVender = nid2;
    viajes = l;
}

void Barco::modificar_barco(int id1, int nid1, int id2, int nid2)
{
    idProductoComprar = id1;
    nProductoComprar = nid1;
    idProductoVender = id2;
    nProductoVender = nid2;
}

void Barco::modificar_ncomprar(int nid1)
{
    nProductoComprar = nid1;
}

void Barco::modificar_nvender(int nid2)
{
    nProductoVender = nid2;
}

void Barco::anadir_viaje(string ciudad)
{
    viajes.push_back(ciudad);
}

int Barco::consultar_idcompra() const
{
    return idProductoComprar;
}

int Barco::consultar_nidcompra() const
{
    return nProductoComprar;
}

int Barco::consultar_idventa() const
{
    return idProductoVender;
}

int Barco::consultar_nidventa() const
{
    return nProductoVender;
}

void Barco::leer()
{
    int id1, nid1, id2, nid2;
    cin >> id1 >> nid1 >> id2 >> nid2;
    idProductoComprar = id1;
    nProductoComprar = nid1;
    idProductoVender = id2;
    nProductoVender = nid2;
}

void Barco::escribir_barco() const 
{
    // Escritura de los productos que contiene el barco
    cout << idProductoComprar << ' ' << nProductoComprar << ' ';
    cout << idProductoVender << ' ' << nProductoVender << endl;
    // Escritura de los viajes realizados
    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        cout << *it << endl;
    }
}