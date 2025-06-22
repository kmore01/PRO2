#include <iostream>
#include <stack>

using namespace std;

int reduce(string w) {
    stack<char> s;
    int canvios = 0;
    for (int i = 0; i < int(w.size()); i++) {
        char c = w[i];
        if (c == '(' or c == '[') {
            s.push(c);
        } 
        else if ((s.top() == '(' and c == ')') or (s.top() == '[' and c == ']')) {
            s.pop();
        }
        else {
            ++canvios;
            s.pop();
        }
    }

    return canvios;
}


int main() {
  string w;
  while (cin >> w)
    cout << reduce(w) << endl;
}
