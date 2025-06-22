#include <iostream>
#include <stack>

using namespace std;

int reduce(string w) {
    stack<char> s;
    int max_len = 0;
    int last_invalid_pos = -1;
    for (int i = 0; i < w.length(); ++i) {
        if (w[i] == '(' || w[i] == '[') {
            s.push(w[i]);
        } else {
            if (!s.empty() && ((w[i] == ')' && s.top() == '(') || (w[i] == ']' && s.top() == '['))) {
                s.pop();
                if (s.empty()) {
                    max_len = i - last_invalid_pos;
                } else {
                    max_len = max(max_len, i - (int)s.size());
                }
            } else {
                last_invalid_pos = i;
                while (!s.empty()) s.pop();
            }
        }
    }
    return max_len;
}

int main() {
  string w;
  while (cin >> w)
    cout << reduce(w) << endl;
}