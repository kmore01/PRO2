/** @file Rio.cc
    @brief Codigo de la clase Rio
*/

#include "Rio.hh"

Rio::Rio()
{
    catalogo = map<int, pair<int, int>>();
    estructura = BinTree<string>();
    infoCiudades = map<string, Ciudad>();
    embarcacion = Barco();
}

Rio::Rio(const map<int, pair<int, int>> &cat, const BinTree<string> &estruct,
const Barco &embarc)
{
    catalogo = cat;
    estructura = estruct;
    embarcacion = embarc;
}

void Rio::agregar_productos(int nprod)
{
    auto it = catalogo.end();
    --it;
    // Posicion contiene el identificador del siguiente producto a añadir
    int posicion = it->first + 1;
    for (int i = 0; i < nprod; ++i) {
        pair<int, int> aux;
        cin >> aux.first >> aux.second;
        catalogo[posicion] = aux;
        ++posicion;
    }
}

void Rio::modificar_barco(int id1, int nid1, int id2, int nid2)
{
    embarcacion.modificar_barco(id1, nid1, id2, nid2);
}

void Rio::poner_producto(string id, int pid, const pair<int, int> &p) 
{
    auto it = infoCiudades.find(id);
    it->second.poner_producto(consultar_peso(pid), consultar_volumen(pid), p,
    pid);
}

void Rio::quitar_producto(string id, int pid)
{
    auto it = infoCiudades.find(id);
    it->second.quitar_producto(consultar_peso(pid), consultar_volumen(pid),
    pid);
}

void Rio::modificar_producto(string id, int pid, const pair<int, int> &p)
{
    auto it = infoCiudades.find(id);
    it->second.modificar_producto(consultar_peso(pid), consultar_volumen(pid),
    p, pid);
}

void Rio::modificar_producto2(string id, int pid, const pair<int, int> &p)
{
    auto it = infoCiudades.find(id);
    it->second.modificar_producto2(consultar_peso(pid), consultar_volumen(pid),
    p, pid);
}

void Rio::comerciar(string id1, string id2)
{
    if (infoCiudades[id1].consultar_size() != 0
    and infoCiudades[id2].consultar_size() != 0) {
        auto it = infoCiudades.find(id2);
        infoCiudades[id1].comerciar_inventario(it->second, catalogo);
    }
}

void Rio::redistribuir()
{
    redistribuir2(estructura);
}

void Rio::hacer_viaje()
{
    int comprados = embarcacion.consultar_nidcompra();
    int vendidos = embarcacion.consultar_nidventa();
    // Ruta contiene el mejor camino posible para el barco
    list<string> ruta = camino(estructura, infoCiudades, comprados, vendidos,
    embarcacion.consultar_idcompra(), embarcacion.consultar_idventa());
    
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

        // Venta de ciudad y compra de barco
        if (tiene1 > quiere1 and nidc > 0) {
            // venta contiene la cantidad que puede vender la ciudad sin
            // dejar al barco en numeros negativos ni a ella misma
            int venta = min(tiene1 - quiere1, nidc);
            pair<int, int> aux(tiene1 - venta, quiere1);
            modificar_producto2(*it, idc, aux);
            productosVendidosComprados += venta;
            // Modificamos los productos que ofrece el barco (solo en esta ruta)
            nidc -= venta;
        }
        // Compra de ciudad y venta de barco
        if (tiene2 < quiere2 and nidv > 0) {
            // compra contiene la cantidad que puede comprar la ciudad sin
            // dejar al barco en numeros negativos ni a ella misma
            int compra = min(quiere2 - tiene2, nidv);
            pair<int, int> aux(tiene2 + compra, quiere2);
            modificar_producto2(*it, idv, aux);
            productosVendidosComprados += compra;
            // Modificamos los productos que ofrece el barco (solo en esta ruta)
            nidv -= compra;
        }
    }

    cout << productosVendidosComprados << endl;
    // Si hay alguna ciudad que comercia anadimos el viaje
    if (ruta.size() > 0) {
        auto it = ruta.end();
        --it;
        embarcacion.anadir_viaje(*it);
    }
}

int Rio::consultar_num() const 
{
    return catalogo.size();
}

int Rio::consultar_peso(int id) const {
    auto it = catalogo.find(id);
    return it->second.first;
}

int Rio::consultar_volumen(int id) const
{
    auto it = catalogo.find(id);
    return it->second.second;
}

bool Rio::existe_ciudad(string id) const
{
    return infoCiudades.count(id);
}

bool Rio::existe_prod(int id) const
{
    return catalogo.count(id);
}

void Rio::leer_rio() 
{
    // Limpiamos los atributos de todas las ciudades
    infoCiudades.clear();
    estructura = leer_rio2();
    // Cuando se lee un nuevo rio, los viajes se restablecen
    embarcacion = Barco(embarcacion.consultar_idcompra(),
    embarcacion.consultar_nidcompra(), embarcacion.consultar_idventa(),
    embarcacion.consultar_nidventa(), list<string>());
}

void Rio::leer_inventario(string id) 
{
    // Eliminamos el inventario de la ciudad en caso de que ya lo tuviera
    infoCiudades[id].inicializar();
    int productos;
    cin >> productos;
    for (int i = 0; i < productos; ++i) {
        int pid;
        pair<int, int> p;
        cin >> pid >> p.first >> p.second;
        int peso = catalogo[pid].first;
        int volumen = catalogo[pid].second;
        infoCiudades[id].poner_producto2(peso, volumen, p, pid);
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
    // Los identificadores de los productos empiezan desde 1
    for (int i = 1; i <= numProd; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
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
    cout << id << ' ' << it->second.first << ' ' << it->second.second << endl;
}

void Rio::escribir_barco() const
{
    embarcacion.escribir_barco();
}

BinTree<string> Rio::leer_rio2() 
{
    string identificador;
    cin >> identificador;
    // Caso base
    if (identificador == "#") return BinTree<string>();
    // Caso general
    // Hacemos que la ciudad exista aunque no hayamos leido aun sus atributos
    infoCiudades[identificador] = Ciudad();
    BinTree<string> left = leer_rio2();
    BinTree<string> right = leer_rio2();
    return BinTree<string>(identificador, left, right);
}

void Rio::redistribuir2(const BinTree<string> &t)
{
    // Caso base
    if (t.empty()) return;
    // Caso general
    if (not t.left().empty()) comerciar(t.value(), t.left().value());
    if (not t.right().empty()) comerciar(t.value(), t.right().value());
    redistribuir2(t.left());
    redistribuir2(t.right());
}

// Pre: Cierto
// Post: El resultado es el camino más conveniente posible
list<string> Rio::camino(const BinTree<string> &t,
const map<string, Ciudad> &info, int &nidc, int &nidv, int idc, int idv)
{
    list<string> ret;
    // Caso base
    if (t.empty()) ret = list<string>();
    else {
        // Caso general
        int comprados = nidc;
        int vendidos = nidv;

        /* EVALUACION DE PRODUCTOS */ 
        auto it = info.find(t.value());
        if (it->second.existe(idc)) {
            int tiene1 = it->second.consultar_tiene(idc);
            int quiere1 = it->second.consultar_quiere(idc);
            // El barco compra productos
            if (tiene1 > quiere1 and nidc != 0) {
                int compra = min(tiene1 - quiere1, nidc);
                nidc -= compra;
            }
        }
        if (it->second.existe(idv)) {
            int tiene2 = it->second.consultar_tiene(idv);
            int quiere2 = it->second.consultar_quiere(idv);
            // El barco vende productos
            if (tiene2 < quiere2 and nidv != 0) {
                int venta = min(quiere2 - tiene2, nidv);
                nidv -= venta;
            }
        }

        // Caso 1: El barco ya no tiene mas productos (paramos la ejecucion)
        if (nidc == 0 and nidv == 0) {
            ret = list<string>(1, t.value());
        }
        else {
            /* LLAMADAS RECURSIVAS */
            int comp_izq = nidc;
            int vend_izq = nidv;
            list<string> izq = camino(t.left(), info, comp_izq, vend_izq, idc,
            idv);
            int comp_der = nidc;
            int vend_der = nidv;
            list<string> der = camino(t.right(), info, comp_der, vend_der, idc,
            idv);
            /* HI: izq es el camino mas provechoso del subarbol izquierdo y
            der el camino mas provechoso del subarbol derecho 
            */

            // Caso 2: El nodo es una hoja y no se ha comprado y vendido ningun
            // producto
            if (comp_izq == nidc and vend_izq == nidv and comp_der == nidc
            and vend_der == nidv) {
                if (comprados == nidc and vendidos == nidv)
                ret = list<string>();
                else ret = list<string>(1, t.value());
            }
            else {
                // Caso 3: Ruta izquierda
                if ((comp_izq + vend_izq) < (comp_der + vend_der)) {
                    izq.push_front(t.value());
                    nidc = comp_izq;
                    nidv = vend_izq;
                    ret = izq;
                }
                // Caso 4: Ruta derecha
                else if (comp_izq + vend_izq > comp_der + vend_der) {
                    der.push_front(t.value());
                    nidc = comp_der;
                    nidv = vend_der;
                    ret = der;
                }
                // Caso 5: Depende
                else {
                    if (izq.size() <= der.size()) {
                        izq.push_front(t.value());
                        nidc = comp_izq;
                        nidv = vend_izq;
                        ret = izq;
                    }
                    else {
                        der.push_front(t.value());
                        nidc = comp_der;
                        nidv = vend_der;
                        ret = der;
                    }
                }
            }
        }
    }
    return ret;
}
