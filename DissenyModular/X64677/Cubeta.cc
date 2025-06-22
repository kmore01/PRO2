#include "Cubeta.hh"
#include "Prenda.hh"
#include "Lavadora.hh"

using namespace std;

Cubeta::Cubeta()
{
}

Cubeta::Cubeta(const Cubeta& c)
{
    ropacolor = c.ropacolor;
    ropablanca = c.ropablanca;
}
void Cubeta::anadir_prenda(const Prenda& p)
{
    if (p.consul_color()) ropacolor.push(p);
    else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav)
{
    if (lav.consultar_color()) completar_lavadora_pila_rec(ropacolor, lav);
    else completar_lavadora_pila_rec(ropablanca, lav);
}

void Cubeta::escribir() const
{
    cout << "   Cubeta: " << endl;
    cout << "Ropa de color de la cubeta: " << endl;
    escribir_pila_prenda(ropacolor);
    cout << "Ropa blanca de la cubeta: " << endl;
    escribir_pila_prenda(ropablanca);
    cout << endl;
}

void Cubeta::completar_lavadora_pila_rec(stack<Prenda>& p, Lavadora& l)
{
    // Si hay ropa en la pila
    if (not p.empty()) {
        Prenda aux = p.top();
        // Si la prenda cabe 
        if (aux.consul_peso() <= l.consultar_peso_maximo() - l.consultar_peso()) {
            l.anadir_prenda(aux);
            p.pop();
            completar_lavadora_pila_rec(p, l);
        }
    }
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p) 
{
    stack<Prenda> aux = p;
    while (not aux.empty()) {
        aux.top().escribir();
        aux.pop();
    }
}
