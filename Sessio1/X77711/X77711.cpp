/* Programa que calcula la classificacio de N equips despres de M jornades */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct resultats {
    int num_equip, punts, gols_marcats, gols_rebuts;
};

/* funcio que llegeix els resultats dels partits i els guarda a una matriu */
vector<vector<int> > leer_matriz(int mida) {
    vector<vector<int> > VPartits(mida / 2, vector<int>(4));
    for (int i = 0; i < mida / 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> VPartits[i][j];
        }
    }

    return VPartits;
}

/* funcio que conta els punts, gols marcats i rebuts de cada equip */
void contar(vector<vector<int>>& input, vector<resultats>& VRes) {
    for (int i = 0; i < input.size(); ++i) {
        int equipo_local = input[i][0];
        int equipo_visitante = input[i][1];
        int goles_local = input[i][2];
        int goles_visitante = input[i][3];

        /* Actualitzem els gols*/
        // Restem 1 perque el vector comença a la posició 0 (0 --> equip 1...)
        VRes[equipo_local - 1].gols_marcats += goles_local;
        VRes[equipo_local - 1].gols_rebuts += goles_visitante;
        VRes[equipo_visitante - 1].gols_marcats += goles_visitante;
        VRes[equipo_visitante - 1].gols_rebuts += goles_local;

        /* Actualitzem els punts */
        if (goles_local > goles_visitante) {
            VRes[equipo_local - 1].punts += 3;
        } else if (goles_local < goles_visitante) {
            VRes[equipo_visitante - 1].punts += 3;
        } else {
            VRes[equipo_local - 1].punts += 1;
            VRes[equipo_visitante - 1].punts += 1;
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

    /* Numero d'equip */
    for (int i = 0; i < num_equips; ++i) {
        VRespostes[i].num_equip = i + 1;
    }

    /* Actualitzem cada parametre a cada jornada */
    for (int i = 0; i < num_jornades; ++i) {
        vector<vector<int> > VInput = leer_matriz(num_equips);
        contar(VInput, VRespostes);
    }

    sort(VRespostes.begin(), VRespostes.end(), ordenar);
    for (int i = 0; i < num_equips; ++i) {
        cout << VRespostes[i].num_equip << ' ' << VRespostes[i].punts << ' '
             << VRespostes[i].gols_marcats << ' ' << VRespostes[i].gols_rebuts
             << endl;
    }
}