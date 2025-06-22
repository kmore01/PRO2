// Programa que imprimie arboles de fibonacci

#include <iostream>
#include <vector>

using namespace std;

vector<string> printtree (vector<string> &v1, vector<string> &v2, int size) {
    vector<string> copy(size);
    int size1 = v1.size();
    int size2 = v2.size();
    bool check1 = false, check2 = false;

    string criteri = "-|";
    string branch = " |";
    for (int i = 0; i < size; ++i) {
        if (i < size1) {
            if (size1 == 1) copy[i] = branch + v1[i];
            else {
                if (v1[i] == criteri) check1 = true;
                if (not check1) copy[i] = string(2, ' ') + v1[i];
                else copy[i] = branch + v1[i];
            }
        }
        else if (i == size1) copy[i] = criteri;
        else {
            if (size2 == 1) copy[i] = branch + v2[i - size1 - 1];
            if (size2 > 1) {
                if (not check2) copy[i] = branch + v2[i - size1 - 1];
                else copy[i] = string(2, ' ') + v2[i - size1 - 1];
                if (v2[i - size1 - 1] == criteri) check2 = true;
            }
        }
    }
    return copy;
}

vector<string> arbre(int num) {
    // Caso especial
    if (num == 0 or num == 1) return vector<string> (1, "*");
    else {
        vector<string> first = arbre(num - 2);
        vector<string> second = arbre(num - 1);
        int size = first.size() + second.size() + 1;
        vector<string> v(size);
        v = printtree(first, second, size);
        return v;
    }
}

void print(const vector<string> &arbre) {
    int size = arbre.size();
    for (int i = 0; i < size; ++i) {
        cout << arbre[i] << endl; 
    }
}

int main () {
    int num;
    while (cin >> num) {
        print(arbre(num));
        cout << endl;
    }
}