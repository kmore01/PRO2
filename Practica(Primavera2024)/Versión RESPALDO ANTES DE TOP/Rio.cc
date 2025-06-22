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
    if (ruta.empty()) return;
    /*
    for (auto it = ruta.begin(); it != ruta.end(); ++it) cout << *it << endl;
    cout << endl;
    */
    
    int idc = embarcacion.consultar_idcompra();
    int idv = embarcacion.consultar_idventa();
    int nidc = embarcacion.consultar_nidcompra();
    int nidv = embarcacion.consultar_nidventa();
    
    //cout << "nidv" << ' ' << nidv << endl;
    string ultimaCiudad;

    int productosVendidosComprados = 0;
    for (auto it = ruta.begin(); it != ruta.end(); ++it) {
        //cout << "nidv" << ' ' << nidv << endl;
        int tiene1 = infoCiudades[*it].consultar_tiene(idc);
        int quiere1 = infoCiudades[*it].consultar_quiere(idc);
        int tiene2 = infoCiudades[*it].consultar_tiene(idv);
        int quiere2 = infoCiudades[*it].consultar_quiere(idv);

        //cout << *it << ": " << endl;
        // cout << ' ' << tiene2 << ' ' << quiere2 << endl;
        // VENTA DE CIUDAD
        if (tiene1 > quiere1 and nidc > 0) {
            int venta = min(tiene1 - quiere1, nidc);
            Producto aux(consultar_peso(idc), consultar_volumen(idc), tiene1 - venta, quiere1);
            modificar_producto2(*it, idc, aux);
            productosVendidosComprados += venta;
            nidc -= venta;
            ultimaCiudad = *it;
        }
        // COMPRA DE CIUDAD
        if (tiene2 < quiere2 and nidv > 0) {
            int compra = min(quiere2 - tiene2, nidv);
            Producto aux(consultar_peso(idv), consultar_volumen(idv), tiene2 + compra, quiere2);
            modificar_producto2(*it, idv, aux);
            productosVendidosComprados += compra;
            nidv -= compra;
            ultimaCiudad = *it;
        }
    }
    cout << productosVendidosComprados << endl;
    if (productosVendidosComprados > 0) embarcacion.anadir_viaje(ultimaCiudad);
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

/*
list<string> Rio::camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco &b, int &compradas, int &vendidas) {
    bool comerciado = false;
    auto it = info.find(t.value());
    int id_comp = b.consultar_idcompra();
    int cant_comp = b.consultar_nidcompra();
    if(it->second.existe(id_comp)) {
        int tiene1 = it->second.consultar_tiene(id_comp);
        int quiere1 = it->second.consultar_quiere(id_comp);
        if(quiere1 < tiene1) {
            int vender_ciudad = tiene1 - quiere1;
            if(b.consultar_nidcompra() != cant_comp) {
                comerciado = true;
                if(b.consultar_nidcompra() + vender_ciudad > cant_comp) b.modificar_ncomprar(cant_comp);
                else b.modificar_ncomprar(b.consultar_nidcompra() + vender_ciudad);
            }
        }
    }

    int id_ven = b.consultar_idventa();
    int cant_ven = b.consultar_nidventa();
    if (it->second.existe(id_ven)) {
        int tiene2 = it->second.consultar_tiene(id_ven);
        int quiere2 = it->second.consultar_quiere(id_ven);
        if(tiene2 < quiere2) {
            int dif = quiere2 - tiene2;
            if(b.consultar_nidventa() != cant_ven) {
                comerciado = true;
                if(b.consultar_nidventa() + dif > cant_ven) b.modificar_nvender(cant_ven);
                else b.modificar_nvender(b.consultar_nidventa() + dif);
            } 
        }
    }
    
    if(t.left().empty() and t.right().empty()) {
        if(comerciado) {
            return list<string>(1, t.value());
        }
        else{
            return list<string>();
        }
    }
    else {
        if(comerciado) {
            list<string> izq = camino2(t.left(), info, b, compradas, vendidas);
            list<string> der = camino2(t.right(), info, b, compradas, vendidas);
        }
        else {
            list<string> izq = camino2(t.left(), info, b, compradas, vendidas);
            list<string> der = camino2(t.right(), info, b, compradas, vendidas);
        }hacer
    }
}
*/

list<string> Rio::camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco &b, int &compradas, int&vendidas)
{
    // Caso base
    if (t.empty()) return list<string>();
    // Caso general

    // EVALUACION DE PRODUCTOS 
    int idc = b.consultar_idcompra();
    int nidc = b.consultar_nidcompra();
    int idv = b.consultar_idventa();
    int nidv = b.consultar_nidventa();

    auto it = info.find(t.value());
    if (it->second.existe(idc)) {
        int tiene1 = it->second.consultar_tiene(idc);
        int quiere1 = it->second.consultar_quiere(idc);
        // El barco compra productos
        if (tiene1 > quiere1 and nidc != 0) {
            int compra = min(tiene1 - quiere1, nidc);
            compradas += compra;
            b.modificar_ncomprar(nidc - compra);
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
        }
    }

    // Caso1: El barco ya no tiene más productos
    if (b.consultar_nidcompra() == 0 && b.consultar_nidventa() == 0) {
        // El barco ya no tiene productos, devolver ruta hasta este punto
        return list<string>(1, t.value());
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
        return list<string>(1, t.value());
    }
    else if (ci + vi > cd + vd) {
        izq.push_front(t.value());
        compradas = ci;
        vendidas = vi;
        return izq;
    }
    else if (ci + vi < cd + vd) {
        der.push_front(t.value());
        compradas = cd;
        vendidas = vd;
        return der;
    }
    else {
        if (izq.size() <= der.size()) {
            izq.push_front(t.value());
            compradas = ci;
            vendidas = vi;
            return izq;
        }
        else {
            der.push_front(t.value());
            compradas = cd;
            vendidas = vd;
            return der;
        }
    }
}


/*
list<string> Rio::camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco b, int &compradas, int&vendidas)
{
    // Caso base 
    if (t.empty()) return list<string>();

    // Caso general
    list<string> izq = camino2(t.left(), info, b, compradas, vendidas);
    list<string> der = camino2(t.right(), info, b, compradas, vendidas);
    int izq_compr, izq_vend, der_compr, der_vend;
    izq_compr = izq_vend = der_compr = der_vend = 0;

    auto it = izq.end();
    for (int i = izq.size() - 1; i >= 0; --i) {
        --it;  
        string ciudad = *it;
        auto it2 = info.find(ciudad);
        if (it2->second.consultar_size() != 0) {
            int idc = b.consultar_idcompra();
            int nidc = b.consultar_nidcompra();
            int idv = b.consultar_idventa();
            int nidv = b.consultar_nidventa();
            // La ciudad quiere vender
            if (it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc) > 0) {
                izq_compr += it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc);
            }
            // La ciudad quiere comprar
            if (it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv) > 0) {
                izq_vend += it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv);
            }

            if (izq_compr >= nidc) izq_compr = nidc;
            if (izq_vend >= nidv) izq_vend = nidv;
        }
    }
    auto it0 = der.end();
    for (int i = der.size() - 1; i >= 0; --i) {
        --it0;  
        string ciudad = *it0;
        auto it2 = info.find(ciudad);
        if (it2->second.consultar_size() != 0) {
            int idc = b.consultar_idcompra();
            int nidc = b.consultar_nidcompra();
            int idv = b.consultar_idventa();
            int nidv = b.consultar_nidventa();
            // La ciudad quiere vender
            if (it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc) > 0) {
                der_compr += it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc);
            }
            // La ciudad quiere comprar
            if (it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv) > 0) {
                der_vend += it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv);
            }

            if (der_compr >= nidc) der_compr = nidc;
            if (der_vend >= nidv) der_vend = nidv;
        }
    }

    if (izq_compr >= b.consultar_nidcompra() and izq_vend >= b.consultar_nidventa() and der_compr >= b.consultar_nidcompra() and der_vend >= b.consultar_nidventa()) {
        // AQUI        >=
        if (der.size() < izq.size()) {
            der.push_front(t.value());
            return der;
        }
        else {
            izq.push_front(t.value());
            return izq;
        }
    }
    else if (izq_compr + izq_vend > der_compr + der_vend) {
        compradas = izq_compr;
        vendidas = izq_vend;
        izq.push_front(t.value());
        return izq;
    }
    else if (izq_compr + izq_vend < der_compr + der_vend) {
        compradas = der_compr;
        vendidas = der_vend;
        der.push_front(t.value());
        return der;
    }
    else {
        if (der.size() < izq.size()) {
            compradas = der_compr;
            vendidas = der_vend;
            der.push_front(t.value());
            return der;
        }
        else {
            compradas = izq_compr;
            vendidas = izq_vend;
            izq.push_front(t.value());
            return izq;
        }
    }
}
*/

/*
list<string> Rio::camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco b, int &compradas, int&vendidas)
{
    // Caso base 
    if (t.empty()) return list<string>();

    // Caso general
    list<string> izq = camino2(t.left(), info, b, compradas, vendidas);
    list<string> der = camino2(t.right(), info, b, compradas, vendidas);
    int izq_compr, izq_vend, der_compr, der_vend;
    izq_compr = izq_vend = der_compr = der_vend = 0;

    auto it = izq.end();
    for (int i = izq.size() - 1; i >= 0; --i) {
        --it;  
        string ciudad = *it;
        auto it2 = info.find(ciudad);
        if (it2->second.consultar_size() != 0) {
            int idc = b.consultar_idcompra();
            int nidc = b.consultar_nidcompra();
            int idv = b.consultar_idventa();
            int nidv = b.consultar_nidventa();
            // La ciudad quiere vender
            if (it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc) > 0) {
                izq_compr += it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc);
            }
            // La ciudad quiere comprar
            if (it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv) > 0) {
                izq_vend += it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv);
            }

            if (izq_compr >= nidc) izq_compr = nidc;
            if (izq_vend >= nidv) izq_vend = nidv;
        }
    }
    auto it0 = der.end();
    for (int i = der.size() - 1; i >= 0; --i) {
        --it0;  
        string ciudad = *it0;
        auto it2 = info.find(ciudad);
        if (it2->second.consultar_size() != 0) {
            int idc = b.consultar_idcompra();
            int nidc = b.consultar_nidcompra();
            int idv = b.consultar_idventa();
            int nidv = b.consultar_nidventa();
            // La ciudad quiere vender
            if (it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc) > 0) {
                der_compr += it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc);
            }
            // La ciudad quiere comprar
            if (it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv) > 0) {
                der_vend += it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv);
            }

            if (der_compr >= nidc) der_compr = nidc;
            if (der_vend >= nidv) der_vend = nidv;
        }
    }

    if (izq_compr >= b.consultar_nidcompra() and izq_vend >= b.consultar_nidventa() and der_compr >= b.consultar_nidcompra() and der_vend >= b.consultar_nidventa()) {
        // AQUI        >=
        if (der.size() < izq.size()) {
            der.push_front(t.value());
            return der;
        }
        else {
            izq.push_front(t.value());
            return izq;
        }
    }
    
    else if (izq_compr + izq_vend > der_compr + der_vend) {
        compradas = izq_compr;
        vendidas = izq_vend;
        izq.push_front(t.value());
        return izq;
    }
    else if (izq_compr + izq_vend < der_compr + der_vend) {
        compradas = der_compr;
        vendidas = der_vend;
        der.push_front(t.value());
        return der;
    }
    else {
        if (der.size() < izq.size()) {
            compradas = der_compr;
            vendidas = der_vend;
            der.push_front(t.value());
            return der;
        }
        else {
            compradas = izq_compr;
            vendidas = izq_vend;
            izq.push_front(t.value());
            return izq;
        }
    }
}
*/

/*
list<string> Rio::camino2(BinTree<string> t, const map<string, Ciudad> &info, Barco b, int &compradas, int&vendidas)
{
    // Caso base 
    if (t.empty()) return list<string>();

    // Caso general
    list<string> izq = camino2(t.left(), info, b, compradas, vendidas);
    list<string> der = camino2(t.right(), info, b, compradas, vendidas);
    int izq_compr, izq_vend, der_compr, der_vend;
    izq_compr = izq_vend = der_compr = der_vend = 0;

    auto it = izq.end();
    for (int i = izq.size() - 1; i >= 0; --i) {
        --it;  
        string ciudad = *it;
        auto it2 = info.find(ciudad);
        if (it2->second.consultar_size() != 0) {
            int idc = b.consultar_idcompra();
            int nidc = b.consultar_nidcompra();
            int idv = b.consultar_idventa();
            int nidv = b.consultar_nidventa();
            // La ciudad quiere vender
            if (it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc) > 0) {
                izq_compr += it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc);
            }
            // La ciudad quiere comprar
            if (it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv) > 0) {
                izq_vend += it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv);
            }

            if (izq_compr >= nidc) izq_compr = nidc;
            if (izq_vend >= nidv) izq_vend = nidv;
        }
    }
    auto it0 = der.end();
    for (int i = der.size() - 1; i >= 0; --i) {
        --it0;  
        string ciudad = *it0;
        auto it2 = info.find(ciudad);
        if (it2->second.consultar_size() != 0) {
            int idc = b.consultar_idcompra();
            int nidc = b.consultar_nidcompra();
            int idv = b.consultar_idventa();
            int nidv = b.consultar_nidventa();
            // La ciudad quiere vender
            if (it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc) > 0) {
                der_compr += it2->second.consultar_tiene(idc) - it2->second.consultar_quiere(idc);
            }
            // La ciudad quiere comprar
            if (it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv) > 0) {
                der_vend += it2->second.consultar_quiere(idv) - it2->second.consultar_tiene(idv);
            }

            if (der_compr >= nidc) der_compr = nidc;
            if (der_vend >= nidv) der_vend = nidv;
        }
    }

    if (izq_compr >= b.consultar_nidcompra() and izq_vend >= b.consultar_nidventa() and der_compr >= b.consultar_nidcompra() and der_vend >= b.consultar_nidventa()) {
        // AQUI        >=
        if (der.size() < izq.size()) {
            der.push_front(t.value());
            return der;
        }
        else {
            izq.push_front(t.value());
            return izq;
        }
    }
    if (der_compr >= b.consultar_nidcompra() and der_vend >= b.consultar_nidventa()) {
        der.push_front(t.value());
        compradas = der_compr;
        vendidas = der_vend;
        return der;
    }
    if (izq_compr >= b.consultar_nidcompra() and izq_vend >= b.consultar_nidventa()) {
        izq.push_front(t.value());
        compradas = izq_compr;
        vendidas = izq_vend;
        return izq;
    }
    if (der_compr + der_vend > izq_compr + izq_vend) {
        der.push_front(t.value());
        compradas = der_compr;
        vendidas = der_vend;
        return der;
    }
    izq.push_front(t.value());
    compradas = izq_compr;
    vendidas = izq_vend;
    return izq;
*/