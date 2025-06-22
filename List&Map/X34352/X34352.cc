// Programa que cuenta la frequencia de palabras en un diccionario

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
        else { // 'f'
            map<string,int>::iterator it = freq.find(palabra);
            cout << it->second << endl;
        }
    }
}