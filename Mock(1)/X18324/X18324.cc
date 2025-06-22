#include <iostream>
#include <stack>

using namespace std;

/* Per a cada cas d’string s d’entrada, escriviu en una línia la longitut del prefix més llarg de s que és ben-parentitzat */

using namespace std;

int main() {
    string s;
    while(cin >> s) {
        stack<char> seq;
        int contador = 0, max_contador = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' or s[i] == '[') seq.push(s[i]);
            else if(not seq.empty() and s[i] == ')' and (seq.size() > 0 and seq.top() == '(')) {
                seq.pop();
                contador += 2;
            }
            else if (not seq.empty() and s[i] == ']' and (seq.size() > 0 and seq.top() == '[')) {
                seq.pop();
                contador += 2;
            }
            else {
                contador = 0;
                seq.push(s[i]);
            }

            // Si la sequencia esta vacia significa que esta bien parentizada
            if (max_contador < contador and seq.empty()) max_contador = contador;
        }
        
        cout << max_contador << endl;
    }
}