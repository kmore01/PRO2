//

#include "CuaIOParInt.hh"

using namespace std;

void llegirCuaParInt(queue<ParInt>& c) {
    ParInt aux;
    while(aux.llegir()) {
        c.push(aux);
    }
}

void escriureCuaParInt(queue<ParInt> c) {
    queue<ParInt> aux = c; // no queremos modificar la cola
	while (not aux.empty()) {
		aux.front().escriure(); // escribimos el primer elem
		aux.pop(); // lo eliminamos
    }
}
