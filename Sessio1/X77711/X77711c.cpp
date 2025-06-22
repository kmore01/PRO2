#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct resultats {
    int num_equip, punts, gols_marcats, gols_rebuts;
};

// Función para leer los resultados de los partidos
vector<vector<int>> leer_matriz(int mida) {
    vector<vector<int>> VPartits(mida / 2, vector<int>(4)); // Cada partido tiene 4 valores: equipo local, goles local, equipo visitante, goles visitante
    for (int i = 0; i < mida / 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> VPartits[i][j];
        }
    }
    return VPartits;
}

// Función para contar los goles marcados y recibidos de cada equipo
void contar(vector<vector<int>> input, vector<resultats>& VRes, int n) {
    for (int i = 0; i < n / 2; ++i) {
        // Para cada partido
        int local = input[i][0];
        int goles_local = input[i][1];
        int visitante = input[i][2];
        int goles_visitante = input[i][3];

        // Actualizar los goles marcados y recibidos de cada equipo
        VRes[local - 1].gols_marcats += goles_local;
        VRes[local - 1].gols_rebuts += goles_visitante;
        VRes[visitante - 1].gols_marcats += goles_visitante;
        VRes[visitante - 1].gols_rebuts += goles_local;

        // Calcular los puntos
        if (goles_local > goles_visitante) {
            VRes[local - 1].punts += 3; // Equipo local gana
        } else if (goles_local == goles_visitante) {
            VRes[local - 1].punts += 1; // Empate
            VRes[visitante - 1].punts += 1;
        } else {
            VRes[visitante - 1].punts += 3; // Equipo visitante gana
        }
    }
}

// Función para ordenar los equipos
bool ordenar(const resultats& v1, const resultats& v2) {
    if (v1.punts != v2.punts) return v1.punts > v2.punts;
    else if (v1.gols_marcats - v1.gols_rebuts != v2.gols_marcats - v2.gols_rebuts) {
        return v1.gols_marcats - v1.gols_rebuts > v2.gols_marcats - v2.gols_rebuts;
    }
    else return v1.num_equip < v2.num_equip;
}

int main() {
    int num_equips, num_jornades;
    cin >> num_equips >> num_jornades;
    vector<resultats> VRespostes(num_equips);

    for (int i = 0; i < num_jornades; ++i) {
        vector<vector<int>> VInput = leer_matriz(num_equips);

        contar(VInput, VRespostes, num_equips);
    }

    // Inicializar los números de equipo
    for (int i = 0; i < num_equips; ++i) {
        VRespostes[i].num_equip = i + 1;
    }

    // Ordenar y mostrar resultados
    sort(VRespostes.begin(), VRespostes.end(), ordenar);
    for (int i = 0; i < num_equips; ++i) {
        cout << VRespostes[i].num_equip << ' ' << VRespostes[i].punts << ' '
             << VRespostes[i].gols_marcats << ' ' << VRespostes[i].gols_rebuts
             << endl;
    }

    return 0;
}
