#include "Lavadora.hh"
#include "Prenda.hh"
#include <stack>

using namespace std;

Lavadora::Lavadora()
{
}

void Lavadora::inicializar(int pmax, bool col)
{
    pesmax = pmax;
    this->col = col;
    ini = true;
}

void Lavadora::anadir_prenda(const Prenda& p)
{
    // Si la prenda cabe
    if (p.consul_peso() + pes <= pesmax) {
        prendas.push_back(p);
        pes += p.consul_peso();
    }
}

void Lavadora::lavado ()
{
    prendas = list<Prenda>(); 
    pes = 0;
    ini = false;
}
bool Lavadora::esta_inicializada() const
{
    return ini;
}

bool Lavadora::consultar_color() const 
{
    return col;
}
int Lavadora::consultar_peso() const 
{
    return pes;
}

int Lavadora::consultar_peso_maximo() const 
{
    return pesmax;
}

// Usar un const iterator
void Lavadora::escribir() const 
{
    cout << "   Lavadora: " << endl;
    if (not ini) cout << "Lavadora no inicializada" << endl << endl;
    else {
        if (col) cout << "Lavadora de color, con peso actual ";
        else cout << "Lavadora de blanco, con peso actual ";
        cout << pes << " y peso maximo " << pesmax << "; sus prendas son" << endl;

        list<Prenda> aux = prendas;
        for (auto it = aux.begin(); it != aux.end(); ++it) {
            (*it).escribir();
        }
        cout << endl;
    }
}