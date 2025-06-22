#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> s;
    string entrada;
    while (cin >> entrada) {
        for (int i = 0; i < entrada.length(); i++) {
            if ((not s.empty()) and (((entrada[i]-'a'+'A')==s.top()) or (((entrada[i]+'a'-'A')==s.top())))) {
                s.pop();
            }
            else s.push(entrada[i]);
        }
        stack<char> s2;
        while (not s.empty()) {
            s2.push(s.top());
            s.pop();
        }
        while (not s2.empty()) {
            cout << s2.top();
            s2.pop();
        }
        cout << endl;
    }
}