// Programa que cuenta la frequencia de palabras en un diccionario con borrado

#include <iostream>
#include <map>

using namespace std;


int main () {
    map<string,int> freq;
    char codigo; // 'a' o 'f'
    string palabra;
    while (cin >> codigo >> palabra) {
        if (not freq.count(palabra))freq[palabra] = 0;

        if (codigo == 'a') {
            map<string,int>::iterator it = freq.find(palabra);
            freq[palabra] = it->second + 1;
        }
        else if (codigo == 'f' ){
            map<string,int>::iterator it = freq.find(palabra);
            cout << it->second << endl;
        }
        else { // 'e'
            map<string,int>::iterator it = freq.find(palabra); // Si find no encuentra el elemento deja el it en freq.end()
            if (it->second != 0) freq[palabra] = it->second - 1;
        }
    }
}