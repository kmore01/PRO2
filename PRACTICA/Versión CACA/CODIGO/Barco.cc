#include "Barco.hh"

Barco::Barco()
{
}

Barco::Barco(int id1, int nid1, int id2, int nid2)
{
    idProductoComprar = id1;
    nProductoComprar = nid1;
    idProductoVender = id2;
    nProductoVender = nid2;
}

void Barco::modificar_barco(int id1, int nid1, int id2, int nid2)
{
    idProductoComprar = id1;
    nProductoComprar = nid1;
    idProductoVender = id2;
    nProductoVender = nid2;
}

void Barco::leer()
{
    int id1, id2, nid1, nid2;
    cin >> id1 >> nid1 >> id2 >> nid2;
    idProductoComprar = id1;
    nProductoComprar = nid1;
    idProductoVender = id2;
    nProductoVender = nid2;
}

void Barco::escribir_barco() const 
{
    cout << idProductoComprar << ' ' << nProductoComprar << ' ';
    cout << idProductoVender << ' ' << nProductoVender << endl;
    bool primer = true;
    for (int i = 0; i < viajes.size(); ++i) {
        if (primer) cout << ' ';
        primer = false;
        cout << viajes[i] << endl;
    }
}