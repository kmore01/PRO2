#include "Producto.hh"

Producto::Producto()
{
    peso = volumen = en_posesion = deseados = 0;
}

Producto::Producto(int pes, int vol, int en_pos, int des)
{
    peso = pes;
    volumen = vol;
    en_posesion = en_pos;
    deseados = des;
}

void Producto::modificar(int pes, int vol, int en_pos, int des)
{
    peso = pes;
    volumen = vol;
    en_posesion = en_pos;
    deseados = des;
}

void Producto::mas_tiene(int n)
{
    en_posesion += n;
}

void Producto::menos_tiene(int n)
{
    en_posesion -= n;
}

int Producto::consul_peso() const
{
    return peso;
}

int Producto::consul_volumen() const
{
    return volumen;
}

int Producto::consul_enpos() const
{
    return en_posesion;
}

int Producto::consul_des() const
{
    return deseados;
}

void Producto::leer()
{
    int pes, vol;
    cin >> pes >> vol;
    peso = pes;
    volumen = vol;
}

void Producto::escribir_producto() const 
{
    cout << peso << ' ' << volumen << endl;
}