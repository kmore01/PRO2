#include "Ciudad.hh"

Ciudad::Ciudad() 
{
    inventario = map<int, Producto>();
    peso_total = volumen_total = 0;
}

Ciudad::Ciudad(string id) 
{
    identificador = id;
}

void Ciudad::poner_producto(const Producto &p, int id_producto)
{
    if (inventario.find(id_producto) == inventario.end()) {
        inventario[id_producto] = p;
        peso_total += p.consul_peso() * p.consul_enpos();
        volumen_total += p.consul_volumen() * p.consul_enpos();
        cout << peso_total << ' ' << volumen_total << endl;
    }
    else cout << "error: la ciudad ya tiene el producto" << endl;
}

void Ciudad::poner_producto2(const Producto &p, int id_producto)
{
    inventario[id_producto] = p;
    peso_total += p.consul_peso() * p.consul_enpos();
    volumen_total += p.consul_volumen() * p.consul_enpos();
}

void Ciudad::modificar_producto(const Producto &p, int id_producto) 
{
    auto it = inventario.find(id_producto);
    if (it != inventario.end()) {
        int tiene = it->second.consul_enpos();
        int tiene2 = p.consul_enpos();
        peso_total = peso_total - (it->second.consul_peso() * tiene) + (p.consul_peso() * tiene2);
        volumen_total = volumen_total - (it->second.consul_volumen() * tiene) + (p.consul_volumen() * tiene2);
        inventario[id_producto] = p;
        cout << peso_total << ' ' << volumen_total << endl;
    }
    else cout << "error: la ciudad no tiene el producto" << endl;
}

void Ciudad::modificar_producto2(const Producto &p, int id_producto) 
{
    auto it = inventario.find(id_producto);
    int tiene = it->second.consul_enpos();
    int tiene2 = p.consul_enpos();
    peso_total = peso_total - (it->second.consul_peso() * tiene) + (p.consul_peso() * tiene2);
    volumen_total = volumen_total - (it->second.consul_volumen() * tiene) + (p.consul_volumen() * tiene2);
    inventario[id_producto] = p;
}


void Ciudad::quitar_producto(int id_producto)
{
    auto it = inventario.find(id_producto);
    if (it != inventario.end()) {
        peso_total -= it->second.consul_peso() * it->second.consul_enpos();
        volumen_total -= it->second.consul_volumen() * it->second.consul_enpos();
        inventario.erase(it); 
        cout << peso_total << ' ' << volumen_total << endl;
    }
    else cout << "error: la ciudad no tiene el producto" << endl;
}

void Ciudad::comerciar_inventario(Ciudad &c)
{
    auto it = inventario.begin();
    auto it2 = c.inventario.begin();
    while (it != inventario.end() and it2 != c.inventario.end()) {
        if (it->first < it2->first) ++it;
        else if (it->first > it2->first) ++it2;
        else {
            int peso1 = it->second.consul_peso();
            int vol1 = it->second.consul_volumen();
            int peso2 = it2->second.consul_peso();
            int vol2 = it2->second.consul_volumen();
            if (it->second.consul_enpos() < it->second.consul_des() and   it2->second.consul_enpos() > it2->second.consul_des()) {
                int intercambio = min(it->second.consul_des() - it->second.consul_enpos(), it2->second.consul_enpos() - it2->second.consul_des());
                it->second.mas_tiene(intercambio);
                peso_total += peso1 * intercambio;
                volumen_total += vol1 * intercambio;
                it2->second.menos_tiene(intercambio);
                c.peso_total -= peso2 * intercambio;
                c.volumen_total -= vol2 * intercambio;
            }
            else if (it2->second.consul_enpos() < it2->second.consul_des() and it->second.consul_enpos() > it->second.consul_des()) {
                int intercambio = min(it2->second.consul_des() - it2->second.consul_enpos(), it->second.consul_enpos() - it->second.consul_des());
                it2->second.mas_tiene(intercambio);
                c.peso_total += peso2 * intercambio;
                c.volumen_total += vol2 * intercambio;
                it->second.menos_tiene(intercambio);
                peso_total -= peso1 * intercambio;
                volumen_total -= vol1 * intercambio;
            }
            ++it;
            ++it2;
        }
    }
}

/*
void Ciudad::comerciar_inventario(Ciudad &c)
{
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        auto it2 = c.inventario.find(it->first);
        if (it2 != c.inventario.end()) {
            int peso1 = it->second.consul_peso();
            int vol1 = it->second.consul_volumen();
            int peso2 = it2->second.consul_peso();
            int vol2 = it2->second.consul_volumen();
        
            if (it->second.consul_enpos() < it->second.consul_des() and   it2->second.consul_enpos() > it2->second.consul_des()) {
                int intercambio = min(it->second.consul_des() - it->second.consul_enpos(), it2->second.consul_enpos() - it2->second.consul_des());
                it->second.mas_tiene(intercambio);
                peso_total += peso1 * intercambio;
                volumen_total += vol1 * intercambio;
                it2->second.menos_tiene(intercambio);
                c.peso_total -= peso2 * intercambio;
                c.volumen_total -= vol2 * intercambio;
            }
            else if (it2->second.consul_enpos() < it2->second.consul_des() and it->second.consul_enpos() > it->second.consul_des()) {
                int intercambio = min(it2->second.consul_des() - it2->second.consul_enpos(), it->second.consul_enpos() - it->second.consul_des());
                it2->second.mas_tiene(intercambio);
                c.peso_total += peso2 * intercambio;
                c.volumen_total += vol2 * intercambio;
                it->second.menos_tiene(intercambio);
                peso_total -= peso1 * intercambio;
                volumen_total -= vol1 * intercambio;
            }
        }
    }
}
*/

void Ciudad::inicializar()
{
    peso_total = volumen_total = 0;
    inventario = map<int, Producto>();
}

void Ciudad::consultar_producto(int id_producto) const
{
    auto it = inventario.find(id_producto);
    if (it != inventario.end()) {
        cout << it->second.consul_enpos() << ' ' << it->second.consul_des() << endl;
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
        return it->second.consul_enpos();
    }
}

int Ciudad::consultar_quiere(int id) const
{
    if (not inventario.count(id)) return 0;
    else {
        auto it = inventario.find(id);
        return it->second.consul_des();
    }
}

bool Ciudad::existe(int id) const
{
    if (inventario.count(id)) return true;
    return false;
}

void Ciudad::escribir_ciudad() const
{
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        cout << it->first << ' ' << it->second.consul_enpos() << ' '
             << it->second.consul_des() << endl;
    }
    cout << peso_total << ' ' << volumen_total << endl; 
}