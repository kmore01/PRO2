/* Programa que calcula la classificacio de N equips despres de M jornades */

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
    vector<vector<partit> > VPartits(mida / 2, vector<partit>(mida / 2));
    for (int i = 0; i < mida / 2; ++i) {
        for (int j = 0; j < mida / 2; ++j) {
            cin >> VPartits[i][j].gols_casa >> VPartits[i][j].gols_visitant;
        }
    }

    return VPartits;
}

/* funcio que conta els punts, gols marcats i rebuts de cada equip */
void contar(vector<vector<partit> > input, vector<resultats> VRes) {
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[0].size(); ++j) {
             // les diagonals no son valides
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

/* funcio que ordena dos equips segons diferents criteris establerts */
bool ordenar (const resultats &v1, const resultats &v2) {
    if (v1.punts != v2.punts) return v1.punts > v2.punts;
    else if (v1.gols_marcats - v1.gols_rebuts != v2.gols_marcats - v2.gols_rebuts) {
        return v1.gols_marcats - v1.gols_rebuts > v2.gols_marcats - v2.gols_rebuts;
    }
    else return v1.num_equip < v2.num_equip;
}

int main () {
    int num_equips, num_jornades;
    cin >> num_equips >> num_jornades;
    vector<resultats> VRespostes(num_equips);
    vector<vector<partit> > VInput(num_equips / 2, vector<partit>(num_equips / 2));

    /*VRespostes[0].punts = VRespostes[0].gols_marcats = VRespostes[0].gols_rebuts = 0;*/

    for (int i = 0; i < num_jornades; ++i) {
        VInput = leer_matriz(num_equips);
        contar(VInput, VRespostes);
    }

    sort(VRespostes.begin(), VRespostes.end(), ordenar);
    for (int i = 0; i < num_equips / 2; ++i) {
        for (int j = 0; j < num_equips / 2; ++j) {
            cout << VInput[i][j].gols_casa << ' ' << VInput[i][j].gols_visitant << ' ';
        }
        cout << endl;
    }

}