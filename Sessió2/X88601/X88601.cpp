/* Programa que intercanvia dues lletres d'una paraula */

#include <iostream>
#include <string>

using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j) {
    if (i >= j) { // cas base
    }
    else { // cas general
        char temporal = s[i];
        s[i] = s[j];
        s[j] = temporal;
        reverseSubstring(s, i + 1, j - 1);
    }
}

int main () {
    string paraula;
    while (cin >> paraula) {
        int i, j;
        cin >> i >> j;
        reverseSubstring(paraula, i, j);
        cout << paraula << endl;
    }
}