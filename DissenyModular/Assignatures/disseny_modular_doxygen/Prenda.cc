#include "Prenda.hh"

using namespace std;

Prenda::Prenda() 
{
}

Prenda::Prenda(int pes, bool col) {
    peso = pes;
    color = col;
}

void Prenda::modificar(int pes, bool col) {
    peso = pes;
    color = col;
}

int Prenda::consul_peso() const {
    return peso;
}

bool Prenda::consul_color() const {
    return color;
}

// OJO!!!!
void Prenda::escribir() const {
    cout << peso << ' ';
    if (color) cout << "true";
    else cout << "false";
    cout << endl;
}