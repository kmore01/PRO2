#include "Rio.hh"
#include "Producto.hh"
#include "Ciudad.hh"
#include "Barco.hh"

Rio::Rio()
{
}

Rio::Rio(map<int, Producto> cat, BinTree<string> estruct, map<string, bool> ciud, Barco embarc)
{
    catalogo = cat;
    estructura = estruct;
    ciudades = ciud;
    embarcacion = embarc;
}

void Rio::agregar_productos(int nprod)
{
    auto it = catalogo.end();
    --it;
    int posicion = it->first + 1;
    for (int i = 0; i < nprod; ++i) {
        Producto aux;
        aux.leer();
        catalogo[posicion] = aux;
        ++posicion;
    }
}

void Rio::modificar_barco(int id1, int nid1, int id2, int nid2)
{
    embarcacion.modificar_barco(id1, nid1, id2, nid2);
}

void Rio::poner_producto(string id, int pid, Producto &p) 
{
    auto it = infoCiudades.find(id);
    it->second.poner_producto(p, pid);
}

void Rio::quitar_producto(string id, int pid)
{
    auto it = infoCiudades.find(id);
    it->second.quitar_producto(pid);
}

void Rio::modificar_producto(string id, int pid, Producto &p)
{
    auto it = infoCiudades.find(id);
    it->second.modificar_producto(p, pid);
}

void Rio::comerciar(string id1, string id2)
{
    int size1 = infoCiudades[id1].consultar_size();
    int size2 = infoCiudades[id2].consultar_size();
    if (size1 < size2) {
        auto it = infoCiudades.find(id2);
        infoCiudades[id1].comerciar_inventario(it->second);
    }
    else {
        auto it = infoCiudades.find(id1);
        infoCiudades[id2].comerciar_inventario(it->second);
    }
}

void Rio::redistribuir()
{
    redistribuir2(estructura);
}

int Rio::consultar_num() const 
{
    return catalogo.size();
}

int Rio::consultar_peso(int id) const {
    auto it = catalogo.find(id);
    return it->second.consul_peso();
}

int Rio::consultar_volumen(int id) const
{
    auto it = catalogo.find(id);
    return it->second.consul_volumen();
}

void Rio::consultar_prod(string identificador, int id) const
{
    infoCiudades.at(identificador).consultar_producto(id);
}

bool Rio::existe_ciudad(string id) const
{
    return ciudades.count(id);
}

bool Rio::existe_prod(int id) const
{
    return catalogo.count(id);
}

BinTree<string> Rio::leer_rio() 
{
    string identificador;
    cin >> identificador;

    if (identificador == "#") return BinTree<string>();
    else {
        ciudades[identificador] = true;
        BinTree<string> left = leer_rio();
        BinTree<string> right = leer_rio();
        return BinTree<string>(identificador, left, right);
    }
}

void Rio::leer_inventario(string id) 
{
    int productos;
    cin >> productos;
    if (productos == 0) infoCiudades[id].inicializar();
    for (int i = 0; i < productos; ++i) {
        int pid, tiene, quiere;
        cin >> pid >> tiene >> quiere;
        int peso = catalogo[pid].consul_peso();
        int volumen = catalogo[pid].consul_volumen();
        Producto aux(peso, volumen, tiene, quiere);
        infoCiudades[id].poner_producto2(aux, pid);
    }
}

void Rio::leer_inventarios() 
{
    string id;
    cin >> id;
    while (id != "#") {
        leer_inventario(id);
        cin >> id;
    }
}

void Rio::leer_productos_dif() 
{
    int numProd;
    cin >> numProd;
    for (int i = 1; i <= numProd; ++i) {
        Producto p;
        p.leer();
        catalogo[i] = p;
    }
}
void Rio::leer_barco()
{
    embarcacion.leer();
}

void Rio::escribir_ciudad(string id) const
{
    auto it = infoCiudades.find(id);
    it->second.escribir_ciudad();
}

void Rio::escribir_prod(int id) const
{
    auto it = catalogo.find(id);
    cout << id << ' ';
    it->second.escribir_producto();
}

void Rio::escribir_barco() const
{
    embarcacion.escribir_barco();
}

void Rio::redistribuir2(BinTree<string> t)
{
    if (t.empty()) return;
    redistribuir2(t.left());
    redistribuir2(t.right());
    if (not t.left().empty()) comerciar(t.value(), t.left().value());
    if (not t.right().empty()) comerciar(t.value(), t.right().value());
}