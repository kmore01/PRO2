#include <iostream>
#include <queue>
#include "CuaIOParInt.hh"

using namespace std;

void ordenacioDeCua(queue<ParInt> a, queue<ParInt> &b, queue<ParInt> &c) {
    int tiempob = 0, tiempoc = 0; 
    while (not a.empty()) {
        if (tiempob <= tiempoc) {
            b.push(a.front());
            tiempob += a.front().segon();
            a.pop();
        }
        else {
            c.push(a.front());
            tiempoc += a.front().segon();
            a.pop();
        }
    }
}

int main () {
    queue<ParInt> a;
    llegirCuaParInt(a);
    queue<ParInt> b; // cola 1
    queue<ParInt> c; // cola 2
    ordenacioDeCua(a, b, c);
    escriureCuaParInt(b);
    cout << endl;
    escriureCuaParInt(c);
}