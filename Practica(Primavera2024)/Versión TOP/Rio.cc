#include "Rio.hh"
#include "Producto.hh"
#include "Ciudad.hh"
#include "Barco.hh"

Rio::Rio()
{
    catalogo = map<int, Producto>();
    estructura = BinTree<string>();
    infoCiudades = map<string, Ciudad>();
    embarcacion = Barco();
}

Rio::Rio(const map<int, Producto> &cat, const BinTree<string> &estruct, const Barco &embarc)
{
    catalogo = cat;
    estructura = estruct;
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

void Rio::poner_producto(string id, int pid, const Producto &p) 
{
    auto it = infoCiudades.find(id);
    it->second.poner_producto(p, pid);
}

void Rio::quitar_producto(string id, int pid)
{
    auto it = infoCiudades.find(id);
    it->second.quitar_producto(pid);
}

void Rio::modificar_producto(string id, int pid, const Producto &p)
{
    auto it = infoCiudades.find(id);
    it->second.modificar_producto(p, pid);
}

void Rio::modificar_producto2(string id, int pid, const Producto &p)
{
    auto it = infoCiudades.find(id);
    it->second.modificar_producto2(p, pid);
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

void Rio::hacer_viaje()
{
    list<string> ruta = camino();
    // Añadimos la ultima ciudad con la que se ha intercambiado productos
    if (ruta.size() > 0) {
        auto it = ruta.end();
        --it;
        embarcacion.anadir_viaje(*it);
    }
    /*
    for (auto it = ruta.begin(); it != ruta.end(); ++it) cout << *it << endl;
    cout << endl;
    */
    
    int idc = embarcacion.consultar_idcompra();
    int idv = embarcacion.consultar_idventa();
    int nidc = embarcacion.consultar_nidcompra();
    int nidv = embarcacion.consultar_nidventa();

    int productosVendidosComprados = 0;
    for (auto it = ruta.begin(); it != ruta.end(); ++it) {
        int tiene1 = infoCiudades[*it].consultar_tiene(idc);
        int quiere1 = infoCiudades[*it].consultar_quiere(idc);
        int tiene2 = infoCiudades[*it].consultar_tiene(idv);
        int quiere2 = infoCiudades[*it].consultar_quiere(idv);

        // VENTA DE CIUDAD
        if (tiene1 > quiere1 and nidc > 0) {
            int venta = min(tiene1 - quiere1, nidc);
            Producto aux(consultar_peso(idc), consultar_volumen(idc), tiene1 - venta, quiere1);
            modificar_producto2(*it, idc, aux);
            productosVendidosComprados += venta;
            nidc -= venta;
        }
        // COMPRA DE CIUDAD
        if (tiene2 < quiere2 and nidv > 0) {
            int compra = min(quiere2 - tiene2, nidv);
            Producto aux(consultar_peso(idv), consultar_volumen(idv), tiene2 + compra, quiere2);
            modificar_producto2(*it, idv, aux);
            productosVendidosComprados += compra;
            nidv -= compra;
        }
    }
    cout << productosVendidosComprados << endl;
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

bool Rio::existe_ciudad(string id) const
{
    return infoCiudades.count(id);
}

bool Rio::existe_prod(int id) const
{
    return catalogo.count(id);
}

list<string> Rio::camino()
{
    int comprados, vendidos;
    comprados = vendidos = 0;
    Barco a = embarcacion;
    return camino2(estructura, infoCiudades, a, comprados, vendidos);
}

void Rio::leer_rio() 
{
    infoCiudades.clear();
    estructura = leer_rio2();
    embarcacion = Barco(embarcacion.consultar_idcompra(), embarcacion.consultar_nidcompra(), embarcacion.consultar_idventa(), embarcacion.consultar_nidventa(), list<string>());
}

void Rio::leer_inventario(string id) 
{
    // infoCiudad[id] = Ciudad();
    infoCiudades[id].inicializar();
    int productos;
    cin >> productos;
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

void Rio::consultar_prod(string identificador, int id) const
{
    infoCiudades.at(identificador).consultar_producto(id);
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

BinTree<string> Rio::leer_rio2() 
{
    string identificador;
    cin >> identificador;

    if (identificador == "#") return BinTree<string>();
    else {
        infoCiudades[identificador];
        BinTree<string> left = leer_rio2();
        BinTree<string> right = leer_rio2();
        return BinTree<string>(identificador, left, right);
    }
}

void Rio::redistribuir2(BinTree<string> t)
{
    if (t.empty()) return;
    if (not t.left().empty()) comerciar(t.value(), t.left().value());
    if (not t.right().empty()) comerciar(t.value(), t.right().value());
    redistribuir2(t.left());
    redistribuir2(t.right());
}

list<string> Rio::camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco &b, int &compradas, int&vendidas)
{
    // Caso base
    if (t.empty()) return list<string>();
    // Caso general

    /* EVALUACION DE PRODUCTOS */
    int idc = b.consultar_idcompra();
    int nidc = b.consultar_nidcompra();
    int idv = b.consultar_idventa();
    int nidv = b.consultar_nidventa();

    auto it = info.find(t.value());
    bool comercioRealizado = false;  // Variable para rastrear si se ha realizado algún comercio
    if (it->second.existe(idc)) {
        int tiene1 = it->second.consultar_tiene(idc);
        int quiere1 = it->second.consultar_quiere(idc);
        // El barco compra productos
        if (tiene1 > quiere1 and nidc != 0) {
            int compra = min(tiene1 - quiere1, nidc);
            compradas += compra;
            b.modificar_ncomprar(nidc - compra);
            comercioRealizado = true;
        }
    }
    if (it->second.existe(idv)) {
        int tiene2 = it->second.consultar_tiene(idv);
        int quiere2 = it->second.consultar_quiere(idv);
        // El barco vende productos
        if (tiene2 < quiere2 and nidv != 0) {
            int venta = min(quiere2 - tiene2, nidv);
            vendidas += venta;
            b.modificar_nvender(nidv - venta);
            comercioRealizado = true;
        }
    }

    // Caso1: El barco ya no tiene más productos
    if (b.consultar_nidcompra() == 0 and b.consultar_nidventa() == 0) {
        if (comercioRealizado) return list<string>(1, t.value());
        else return list<string>();
    }

    /* LLAMADAS RECURSIVAS */ 
    int ci = compradas;
    int vi = vendidas;
    list<string> izq = camino2(t.left(), info, b, compradas, vendidas);
    ci = compradas - ci;  // Productos comprados en el subárbol izquierdo
    vi = vendidas - vi;  // Productos vendidos en el subárbol izquierdo
    
    int cd = compradas;
    int vd = vendidas;
    list<string> der = camino2(t.right(), info, b, compradas, vendidas);
    cd = compradas - cd;  // Productos comprados en el subárbol derecho
    vd = vendidas - vd;  // Productos vendidos en el subárbol derecho

    /* FINALIZACIÓN */
    // Caso2: No se ha comerciado
    if ((ci == 0 and vi == 0) and (cd == 0 and vd == 0)) {
        if (comercioRealizado) return list<string>(1, t.value());
        else return list<string>();
    }
    else if (ci + vi > cd + vd) {
        if (comercioRealizado) izq.push_front(t.value());
        compradas = ci;
        vendidas = vi;
        return izq;
    }
    else if (ci + vi < cd + vd) {
        if (comercioRealizado) der.push_front(t.value());
        compradas = cd;
        vendidas = vd;
        return der;
    }
    else {
        if (izq.size() <= der.size()) {
            if (comercioRealizado) izq.push_front(t.value());
            compradas = ci;
            vendidas = vi;
            return izq;
        }
        else {
            if (comercioRealizado) der.push_front(t.value());
            compradas = cd;
            vendidas = vd;
            return der;
        }
    }
}