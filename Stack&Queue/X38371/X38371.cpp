// Programa que calcula el maximo, minimo y media a medida
// que van entrando y saliendo numeros

#include <iostream>
#include <queue>

using namespace std;

// Procedimiento que recorre toda la cola y recalcula el valor minimo y maximo
void recalcular_min_max(queue<int> a, int& min, int& max) {
	max = -1000, min = 1000;
	while (not a.empty()) {
		if (max < a.front()) max = a.front();
		if (min > a.front()) min = a.front();
		a.pop();
	}
}

// Procedimiento que calcula el maximo, minimo y medio
void evaluar() {
    queue<int> sequencia;
    int num, min = 1000, max = -1000; // Ponemos estos valores para que se modifiquen siempre
    double total = 0; 
    while (cin >> num and num >= -1001 and num <= 1000) {
        if (num != -1001) {
            sequencia.push(num);
            if (num > max) max = num;
            if (num < min) min = num;
            total += num;
        }
        else if (not sequencia.empty()) { // -1001
            int num_elim = sequencia.front();
            sequencia.pop();
            total -= num_elim;
            // Si num a elim era un maximo o minimo hay que calcularlo de nuevo
            if (num_elim == max or num_elim == min) {
                recalcular_min_max(sequencia, min, max);
            }  
        }

        // Imprimir el resultado
        if (sequencia.empty()) {
            cout << 0 << endl;
            max = -1000;
            min = 1000;
        }
        else cout << "min " << min << "; " << "max " << max << "; " << "media "
                  << (total/sequencia.size()) << endl;
    }       
}

int main () {
    evaluar();
}