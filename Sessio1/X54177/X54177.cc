/* programa que obtiene las sumas de varias secuencias de enteros */

#include <iostream>

using namespace std;

int main () {
    int numseq, x;
    cin >> numseq >> x;
    for (int i = 1; i <= numseq; ++i) {
        int num, res = 0;
        cin >> num;
        while (num != x) {
            res += num;
            cin >> num;
        }
        /* Utilizaremos getline para saltar a la siguiente linea despues de encontrar un 0 */
        string basura;
        getline(cin, basura);
        cout << "La suma de la secuencia " << i << " es " << res << endl;
    }
}