/* programa que calcula el nombre de l’equip, el nombre total de punts, 
els gols marcats i els rebuts */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct partit {
    int gols_casa, gols_visitant;
};

struct resultats {
    int num_equip, punts, gols_marcats, gols_rebuts;
};

/* funcio que llegeix els resultats dels partits i els guarda a una matriu */
vector<vector<partit> > leer_matriz(int mida) {
    vector<vector<partit> > VPartits(mida, vector<partit>(mida));
    for (int i = 0; i < mida; ++i) {
        for (int j = 0; j < mida; ++j) {
            cin >> VPartits[i][j].gols_casa >> VPartits[i][j].gols_visitant;
        }
    }

    return VPartits;
}

/* funcio que conta els punts, gols marcats i rebuts de cada equip */
vector<resultats> contar(vector<vector<partit> > input, int n) {
    vector<resultats> VRes(n); // (x1-y1-z1-k1)____(x2-y2-z2-k2)___...
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[0].size(); ++j) {
            if (i != j) { // les diagonals no son valides
                /* Gols marcats */
                VRes[i].gols_marcats += input[i][j].gols_casa;
                VRes[j].gols_marcats += input[i][j].gols_visitant;

                /* Gols rebuts */
                VRes[i].gols_rebuts += input[i][j].gols_visitant;
                VRes[j].gols_rebuts += input[i][j].gols_casa;

                /* Punts */
                if (input[i][j].gols_casa > input[i][j].gols_visitant) VRes[i].punts += 3;
                else if (input[i][j].gols_casa < input[i][j].gols_visitant) VRes[j].punts += 3;
                else {
                    VRes[i].punts += 1;
                    VRes[j].punts += 1;
                }
            }
        }
    }

    return VRes;
}

/* funcio que ordena dos equips segons diferents criteris establerts */
bool ordenar (const resultats &v1, const resultats &v2) {
    if (v1.punts != v2.punts) return v1.punts > v2.punts;
    else if (v1.gols_marcats - v1.gols_rebuts != v2.gols_marcats - v2.gols_rebuts) {
        return v1.gols_marcats - v1.gols_rebuts > v2.gols_marcats - v2.gols_rebuts;
    }
    else return v1.num_equip < v2.num_equip;
}

int main () {
    int n;
    cin >> n;
    vector<vector<partit> > VInput = leer_matriz(n);
    vector<resultats> VOutput = contar(VInput, n);

    /* Numero d'equip */
    for (int i = 0; i < n; ++i) {
        VOutput[i].num_equip = i + 1;
    }

    sort(VOutput.begin(), VOutput.end(), ordenar);
    for (int i = 0; i < n; ++i) {
        cout << VOutput[i].num_equip << ' ' << VOutput[i].punts << ' '
             << VOutput[i].gols_marcats << ' ' << VOutput[i].gols_rebuts
             << endl;
    }
}