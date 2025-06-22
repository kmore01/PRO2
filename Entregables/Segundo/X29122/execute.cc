// Funcion que evalua un arbol binario

#include <iostream>
#include "BinTree.hh"
#include <map>

using namespace std;
BinTree<string> BT;

bool isDigit(char c) {
    return '0' <= c and c <= '9';
}

bool isNumber(string s) {
    if (int(s.size()) == 0) return false;
	for (int i = 0; i < int(s.size()); ++i)
        if (not isDigit(s[i]))
            return false;
    return true;
}

// Los numeros son en modulo 10
// Quan una expressió conté una variable que no ha estat assignada abans, suposem que té valor per defecte 0.

// Pre: t és un arbre no buit d'strings que representa una expressió correcta
// sobre dígits i variables que guarden dígits, i els operadors +,* mòdul 10.
// En particular, l'arrel de t és o bé +, o bé *, o bé un dígit, o bé una variable.
// var2val és un mapeig de variables a dígits.
// Post: Retorna l'avaluació de l'expressió representada per t reemplaçant les variables
// pels seus corresponents valors definits a var2val, o per 0 si no estan definides.
int evaluate(map<string,int> &var2val, BinTree<string> t) {
    // CASO BASE
    if (t.empty()) return 0;
    // CASO GENERAL
    else {
        string value = t.value();
        int result;
        /* SI ES UNA VARIABLE */
        if (not isNumber(value) and value != "+" and value != "-" and value != "*") {
            if (var2val.count(value)) {
                map<string,int>::iterator it = var2val.find(value);
                result = it->second % 10;
            }
            else result = 0;
        }

        /* SI ES UN NUMERO */
        else if (isNumber(value) and t.left().empty() and t.right().empty()) result = atoi(value.c_str()) % 10;

        else {
            int l = evaluate(var2val, t.left());
            int r = evaluate(var2val, t.right());
            if (value == "+") result = (l + r) % 10;
            else if (value == "-") result = (l - r) % 10;
            else result = (l * r) % 10;
        }
        return result;
    }
}

// Pre: t és un arbre no buit d'strings que representa una instrucció correcta
// del llenguatge de programació descrit a l'enunciat.
// En particular, o bé és l'arbre buit,
// o bé la seva arrel és, o bé =, o bé print, o bé if, o bé while,
// o bé list, cas en el cual, representa una subllista d'instruccions.
// Post: S'ha simulat l'execució d'aquesta instrucció, modificant var2val
// i escrivint el que calgui per la sortida estandar, d'acord a aquesta simulació.
void execute(map<string,int> &var2val, BinTree<string> t) {
    // CASO BASE
    if (t.empty());
    // CASO GENERAL
    else {
        string value = t.value();
        if (value == "=") {
            var2val[t.left().value()] = evaluate(var2val, t.right());
        }
        else if (value == "print") {
            int answer = evaluate(var2val, t.left());
            cout << answer << endl;
        }
        /* Per a les expressions de la condició de if i while, es considera que
        es cumpleixen si s’avaluen a diferent de 0 */
        else if (value == "if" or value == "while") {
            if (value == "if") {
                if (evaluate(var2val, t.left()) != 0) execute(var2val, t.right());
            }
            else { // "while"
                while (evaluate(var2val, t.left()) != 0) {
                    execute(var2val, t.right());
                }
            }
        }
        else { // "list"
            execute(var2val, t.left());
            execute(var2val, t.right());
        }
    }
}