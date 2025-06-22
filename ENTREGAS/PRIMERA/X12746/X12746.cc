// Programa que simula una estructura de datos similar a un vector

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Idea: La primera posicion sirve para acceso indexado y la segunda es lo
    // que se encuentra en esa posicion
    // Tambien no añadiremos todos los zeros, sino que tendremos un indice que
    // no sera siguiente al anterior que nos indicara cuantos zeros hay
    map<int,int> v;
    string command;
    while (cin >> command) {
        if (command == "v.push_back(") {
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ");"
            if (v.size() == 0) v[0] = val; // Si no hay elementos en el map
            else { // Si hay un elemento o mas en el map
                map<int,int>::iterator it = v.end(); // _,_,_,()
                --it; // Ahora el it apunta al ultimo elemento del map
                v[(it->first) + 1] = val; // Añadir elemento al final
            }
        }
        
        else if (command == "v.push_front(") {
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ");"
            if (v.size() == 0) v[0] = val; // Si no hay ningun elemento en el map
            else {
                map<int,int>::iterator it = v.begin(); // (_),_,_,
                v[(it-> first) - 1] = val; // Añadir elemento al principio
            }
        }
        
        else if (command == "v.pop_front();") {
            if (v.size() != 0) { // Si la size es 0 no hay que eliminar ningun
            // elemento (no se si el Jutge contempla este caso)
                map<int,int>::iterator it = v.begin(); // (_),_,_,
                int elem = it->first;
                // En el caso que tengamos un numero y luego una sequencia de
                // zero's-> Miramos siempre si existe un elemento en la
                // siguiente posicion con indice + 1, si no es asi, esto 
                //significa que estamos 
                // en el caso previamente mencionado, asi que tenemos que crear 
                // que el siguiente elemento al actual sea zero y asi 
                // empezaremos en el indice + 1 y todo estara alineado de nuevo 
                // una vez eliminado el elemento ya que la v.size() -= 1
                if (not v.count(elem + 1)) v[elem + 1] = 0;
                it = v.erase(it); // Eliminar primer elemento
            }
        }
        
        else if (command == "v.pop_back();") {
            if (v.size() != 0) {
                map<int,int>::iterator it = v.end(); // _,_,_,()
                --it; 
                int elem = it->first;
                // En el caso que tengamos un numero y antes una sequencia de
                // zero's-> Miramos siempre si existe un elemento en la
                // anterior posicion con indice 1-, si no es asi, esto
                // significa que estamos 
                // en el caso previamente mencionado, asi que tenemos que crear 
                // que el anterior elemento al actual sea zero y asi 
                // empezaremos en el indice - 1 y todo estara alineado de nuevo 
                // una vez eliminado el elemento ya que la v.size() -= 1
                if (not v.count(elem - 1)) v[elem - 1] = 0;
                it = v.erase(it); // Eliminar ultimo elemento
            }
        }

        else if (command == "v.resize(") {
            int newsize;
            cin >> newsize;
            string ending;
            cin >> ending; // Això consumeix el ");"

            if (v.size() != 0) {
                auto it = v.begin(); // (_),_,_,_
                int primer_elem = it->first;
                it = v.end(); // _,_,_,()
                --it; // _,_,_,(_)
                int comp = it->first - primer_elem + 1;
                if (newsize < comp) { // Si el resize es menor que la v.size()
                    it = v.begin(); // (_),_,_,_
                    // Si no existe el indice maximo el cual tendra nuestro map
                    // lo añadimos
                    if (v.count(it->first + newsize) == 0) 
                    v[it->first + newsize] = 0;
                    // Si no existe el indice penultimo el cual tendra nuestro
                    // map lo añadimos
                    if (v.count(it->first + newsize - 1) == 0)
                    v[it->first + newsize - 1] = 0;
                    // Buscamos el ultimo elemento que es accesible del map
                    it = v.find(it->first + newsize); 
                    // Borramos todos los numeros que haya en el map a partir de ese
                    v.erase(it, v.end());                    
                }
                else { // Si el resize es mayor que la v.size() 
                    if (newsize > comp) {
                        it = v.begin(); // (_),_,_,_
                        v[it->first + newsize - 1] = 0; // Añadimos la cadena de zeros
                    }
                }
            }
            else { // Si v.size() == 0
                v[0] = 0;
                v[newsize - 1] = 0; // ultima posicion del 0
            }

        }

        else if (command == "cout<<v[") {
            int index;
            cin >> index;
            string ending;
            cin >> ending; // Això consumeix el "];"
            map<int,int>::iterator it = v.begin(); // (_),_,_,_
            cout << v[it->first + index] << endl; // v[index] porque no tiene porque empezar en 0
        }
    
        else if (command == "cout<<v;") {
            map<int,int>::iterator it = v.end(); // _,_,_,_()
            --it; // _,_,_,(_)
            int salir = it->first + 1; // centinela

            it = v.begin(); // (_),_,_,_
            bool printcomma = false; // Para printar la primera coma
            for (int i = it-> first; i != salir; ++i) {
                if (printcomma) cout << ',';
                printcomma = true;
                // Si existe hacemos el cout del numero al cual apunta
                if (i == it->first) {
                    cout << it->second; 
                    ++it; // Siguiente elemento
                }
                // Si no coinciden que no hay un numero, asi que es una cadena de zero's
                else {
                    cout << 0;
                }
            }
            cout << endl;
        }
    
        else if (command == "v[") {
            int index;
            cin >> index;
            string mid;
            cin >> mid; // Això consumeix el "]="
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ";"
            map<int,int>::iterator it = v.begin();
            int i = it -> first + index; // Los elementos no tienes porque empezar en zero
            v[i] = val; // Cambiamos el valor
        }
    
        else if (command == "//") {
            string comment;
            getline(cin, comment);
            cout << "//" << comment << endl;
        }
        
        else {
            cout << "Wrong command '" << command << "'" << endl;
            string discard;
            getline(cin, discard);
        }
    }
}