// Programa que hace diversas acciones en una libreria

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Procedimiento que almacena los libros
void modificar_en_categoria(vector<stack<string> > &v1) {
    string nombre;
    int categoria;
    cin >> nombre >> categoria;
    v1[categoria - 1].push(nombre);
}

// Procedimiento que elimina los libros
void eliminar_en_categoria(vector<stack<string> > &v1) {
    int libros_a_eliminar, categoria;
    cin >> libros_a_eliminar >> categoria;
    for (int i = 0; i < libros_a_eliminar; ++i) {
        v1[categoria - 1].pop();
    }
}

// Procedimiento que imprime una categoria
void imprimir_categoria(stack<string>  s) {
    while (not s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main () {
    int categorias, opcion; // -4 < opcion < -1
    cin >> categorias;
    vector<stack<string> > v1(categorias);

    cin >> opcion;
    while (opcion != -4) {
        if (opcion == -1) { // devolucion de libro
            modificar_en_categoria(v1);
        }
        else if (opcion == -2) { // retirada de libros de una categoria
            eliminar_en_categoria(v1);
        }
        else { // escribir contenido de una categoria  
            int categoria;
            cin >> categoria;
            cout << "Pila de la categoria " << categoria << endl;
            imprimir_categoria(v1[categoria - 1]);
        }
       cin >> opcion; // siguiente comando
    }
}