/** @file Ciudad.cc
    @brief Codigo de la clase Ciudad
*/

#include "Ciudad.hh"

Ciudad::Ciudad() 
{
    inventario = map<int, pair<int, int>>();
    peso_total = 0;
    volumen_total = 0;
}

Ciudad::Ciudad(const map<int, pair<int, int>> &inv, int pes_tot, int vol_tot)
{
    inventario = inv;
    peso_total = pes_tot;
    volumen_total = vol_tot;
}

void Ciudad::poner_producto(int peso, int volumen,
const pair<int, int> &p, int id_producto)
{
    if (inventario.find(id_producto) == inventario.end()) {
        inventario[id_producto] = p;
        peso_total += (peso * p.first);
        volumen_total += (volumen * p.first);
        cout << peso_total << ' ' << volumen_total << endl;
    }
    else cout << "error: la ciudad ya tiene el producto" << endl;
}

void Ciudad::poner_producto2(int peso, int volumen,
const pair<int, int> &p, int id_producto)
{
    inventario[id_producto] = p;
    peso_total += peso * p.first;
    volumen_total += volumen * p.first;
}

void Ciudad::modificar_producto(int peso, int volumen,
const pair<int, int> &p, int id_producto) 
{
    auto it = inventario.find(id_producto);
    // Si it != inventario.end() significa que el producto esta en la ciudad
    if (it != inventario.end()) {
        // Los productos que tenia la ciudad antes
        int tiene = it->second.first;
        // Los productos que tiene la ciudad ahora
        int tiene2 = p.first;
        peso_total = peso_total - (peso * tiene) + (peso * tiene2);
        volumen_total = volumen_total - (volumen * tiene) + (volumen * tiene2);
        inventario[id_producto] = p;
        cout << peso_total << ' ' << volumen_total << endl;
    }
    else cout << "error: la ciudad no tiene el producto" << endl;
}

void Ciudad::modificar_producto2(int peso, int volumen,
const pair<int, int> &p, int id_producto) 
{
    auto it = inventario.find(id_producto);
    // Los productos que tenia la ciudad antes
    int tiene = it->second.first;
    // Los productos que tiene la ciudad ahora
    int tiene2 = p.first;
    peso_total = peso_total - (peso * tiene) + (peso * tiene2);
    volumen_total = volumen_total - (volumen * tiene) + (volumen * tiene2);
    inventario[id_producto] = p;
}


void Ciudad::quitar_producto(int peso, int volumen, int id_producto)
{
    auto it = inventario.find(id_producto);
    // Si it != inventario.end() significa que el producto esta en la ciudad
    if (it != inventario.end()) {
        peso_total -= peso * it->second.first;
        volumen_total -= volumen * it->second.first;
        inventario.erase(it); 
        cout << peso_total << ' ' << volumen_total << endl;
    }
    else cout << "error: la ciudad no tiene el producto" << endl;
}

// Pre: Las dos ciudades existen, son diferentes y tienes por lo menos un
// producto
// Post: Se han intercambiado los productos que le sobraban a una ciudad y 
// necesitaba la otra
void Ciudad::comerciar_inventario(Ciudad &c,
const map<int, pair<int, int>> &catalogo)
{
    auto it = inventario.begin();
    auto it2 = c.inventario.begin();
    while (it != inventario.end() and it2 != c.inventario.end()) {
        // Si el identificador del producto de la primera ciudad es mas
        // pequeño, signfica que la segunda ciudad no tiene ese producto, asi
        // que tenemos que pasar al siguiente producto de la primera ciudad
        // para comprobar si coincide con el de la segunda
        if (it->first < it2->first) ++it;
        // Si el identificador del producto de la segunda ciudad es mas
        // pequeño, signfica que la primera ciudad no tiene ese producto, asi
        // que tenemos que pasar al siguiente producto de la segunda ciudad
        // para comprobar si coincide con el de la primera
        else if (it->first > it2->first) ++it2;
        // En el caso que los dos identificadores sean iguales, hemos
        // encontrado un producto en comun de las dos ciudades
        else {
            auto it3 = catalogo.find(it->first);
            int peso1 = it3->second.first;
            int vol1 = it3->second.second;

            auto it4 = catalogo.find(it2->first);
            int peso2 = it4->second.first;
            int vol2 = it4->second.second;

            // La primera ciudad quiere comprar (tiene1 < quiere1) y la segunda
            // quiere vender (tiene2 > quiere2)
            if (it->second.first < it->second.second and
            it2->second.first > it2->second.second) {
                // La cantidad intercambiada sera la minima que
                // quieran comprar/vender las ciudades
                int intercambio = min(it->second.second - it->second.first,
                it2->second.first - it2->second.second);
                // Cambios que sufre la primera ciudad
                it->second.first += intercambio;
                peso_total += (peso1 * intercambio);
                volumen_total += (vol1 * intercambio);
                // Cambios que sufre la segunda ciudad
                it2->second.first -= intercambio;
                c.peso_total -= (peso2 * intercambio);
                c.volumen_total -= (vol2 * intercambio);
            }
            // La segunda ciudad quiere comprar (tiene2 < quiere2) y la primera
            // quiere vender (tiene1 > quiere1)
            else if (it2->second.first < it2->second.second and
            it->second.first > it->second.second) {
                // La cantidad intercambiada sera la minima que
                // quieran comprar/vender las ciudades
                int intercambio = min(it2->second.second - it2->second.first,
                it->second.first - it->second.second);
                // Cambios que sufre la segunda ciudad
                it2->second.first += intercambio;
                c.peso_total += (peso2 * intercambio);
                c.volumen_total += (vol2 * intercambio);
                // Cambios que sufre la primera ciudad
                it->second.first -= intercambio;
                peso_total -= (peso1 * intercambio);
                volumen_total -= (vol1 * intercambio);
            }
            // Como ya hemos visto el producto que tienen en comun las dos
            // ciudades, pasamos al siguiente
            ++it;
            ++it2;
        }
    }
}

void Ciudad::inicializar()
{
    peso_total = volumen_total = 0;
    inventario = map<int, pair<int, int>>();
}

void Ciudad::consultar_producto(int id_producto) const
{
    auto it = inventario.find(id_producto);
    // Si it != inventario.end() significa que el producto esta en la ciudad
    if (it != inventario.end()) {
        cout << it->second.first << ' ' << it->second.second << endl;
    }
    else cout << "error: la ciudad no tiene el producto" << endl;
}

int Ciudad::consultar_size() const
{
    return inventario.size();
}

int Ciudad::consultar_tiene(int id) const
{
    if (not inventario.count(id)) return 0;
    else {
        auto it = inventario.find(id);
        return it->second.first;
    }
}

int Ciudad::consultar_quiere(int id) const
{
    if (not inventario.count(id)) return 0;
    else {
        auto it = inventario.find(id);
        return it->second.second;
    }
}

bool Ciudad::existe(int id) const
{
    return inventario.count(id);
}

void Ciudad::escribir_ciudad() const
{
    // Escritura del inventario
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        cout << it->first << ' ' << it->second.first << ' '
             << it->second.second << endl;
    }
    // Escriutra peso y volumen total
    cout << peso_total << ' ' << volumen_total << endl; 
}