// Clase 7 - Actividad 4: Torneo ARGENTINA
// Programa del Anexo + carga de resultados + ranking + Actividad 2 opcion a
#include <iostream>
using namespace std;

const int NE = 4; // cantidad de equipos
const int NP = 6; // cantidad de partidos (todos contra todos)
// Columnas de Partidos: 0 equipo1, 1 equipo2, 2 goles eq1, 3 goles eq2, 4 amarillas eq1, 5 amarillas eq2

// ---------- Programa original (Anexo) ----------
void CargarDatos(char Equipos[NE]) {
    int j, Ind = 0; char equi;
    do {
        cout << "Ingrese nombre del Equipo " << Ind + 1 << ": ";
        cin >> equi;
        j = 0;
        while (j < Ind && Equipos[j] != equi) j++;
        if (j < Ind) cout << "Ya ingreso este equipo" << endl;
        else { Equipos[Ind] = equi; Ind++; }
    } while (Ind < NE);
}

void Inicializo(int Partidos[NP][6]) {
    int par = 0;
    for (int Ind = 0; Ind < NE; Ind++)
        for (int pos = Ind + 1; pos < NE; pos++) {
            Partidos[par][0] = Ind;  Partidos[par][1] = pos;
            Partidos[par][2] = 0;    Partidos[par][3] = 0;
            Partidos[par][4] = 0;    Partidos[par][5] = 0;
            par++;
        }
}

void MuestroPartidos(char Equipos[NE], int Partidos[NP][6]) {
    cout << "\nPARTIDOS" << endl;
    for (int Ind = 0; Ind < NP; Ind++)
        cout << Equipos[Partidos[Ind][0]] << " vs " << Equipos[Partidos[Ind][1]] << endl;
}

// ---------- Actividad 4: carga de resultados ----------
int LeerNoNegativo(string msj) {
    int x;
    do { cout << msj; cin >> x; } while (x < 0);
    return x;
}

void CargarResultados(char Equipos[NE], int Partidos[NP][6]) {
    cout << "\nCARGA DE RESULTADOS" << endl;
    for (int p = 0; p < NP; p++) {
        char e1 = Equipos[Partidos[p][0]], e2 = Equipos[Partidos[p][1]];
        cout << "Partido " << p + 1 << ": " << e1 << " vs " << e2 << endl;
        Partidos[p][2] = LeerNoNegativo(string("  Goles de ") + e1 + ": ");
        Partidos[p][3] = LeerNoNegativo(string("  Goles de ") + e2 + ": ");
        Partidos[p][4] = LeerNoNegativo(string("  Amarillas de ") + e1 + ": ");
        Partidos[p][5] = LeerNoNegativo(string("  Amarillas de ") + e2 + ": ");
    }
}

// ---------- Actividad 4: ranking ----------
void CalcularPuntos(int Partidos[NP][6], int Puntos[NE], int Dif[NE]) {
    for (int e = 0; e < NE; e++) { Puntos[e] = 0; Dif[e] = 0; }
    for (int p = 0; p < NP; p++) {
        int e1 = Partidos[p][0], e2 = Partidos[p][1];
        int g1 = Partidos[p][2], g2 = Partidos[p][3];
        if (g1 > g2) Puntos[e1] += 3;
        else if (g1 < g2) Puntos[e2] += 3;
        else { Puntos[e1] += 1; Puntos[e2] += 1; }
        Dif[e1] += g1 - g2;
        Dif[e2] += g2 - g1;
    }
}

void MostrarRanking(char Equipos[NE], int Partidos[NP][6]) {
    int Puntos[NE], Dif[NE], Orden[NE];
    CalcularPuntos(Partidos, Puntos, Dif);
    for (int e = 0; e < NE; e++) Orden[e] = e;
    // Burbuja: ordena por puntos y, si empatan, por diferencia de gol
    for (int i = 0; i < NE - 1; i++)
        for (int j = 0; j < NE - 1 - i; j++) {
            int a = Orden[j], b = Orden[j + 1];
            if (Puntos[b] > Puntos[a] || (Puntos[b] == Puntos[a] && Dif[b] > Dif[a])) {
                Orden[j] = b; Orden[j + 1] = a;
            }
        }
    cout << "\nRANKING\nPuesto  Equipo  Puntos  Dif.Gol" << endl;
    for (int i = 0; i < NE; i++)
        cout << "  " << i + 1 << "       " << Equipos[Orden[i]] << "      "
             << Puntos[Orden[i]] << "       " << Dif[Orden[i]] << endl;
    cout << "1er puesto (GANADOR): " << Equipos[Orden[0]] << endl;
    cout << "2do puesto: " << Equipos[Orden[1]] << endl;
}

// ---------- Actividad 2 - Opcion a ----------
// Procedimiento: muestra el/los equipo/s con mas goles a favor (contempla empates)
void EquipoGoleador(char Equipos[NE], int Partidos[NP][6]) {
    int Goles[NE], p, e, max;
    for (e = 0; e < NE; e++) Goles[e] = 0;
    for (p = 0; p < NP; p++) {
        Goles[Partidos[p][0]] += Partidos[p][2];
        Goles[Partidos[p][1]] += Partidos[p][3];
    }
    max = Goles[0];
    for (e = 1; e < NE; e++)
        if (Goles[e] > max) max = Goles[e];
    cout << "Equipo/s goleador/es (" << max << " goles): ";
    for (e = 0; e < NE; e++)
        if (Goles[e] == max) cout << Equipos[e] << " ";
    cout << endl;
}

// Funcion: devuelve el promedio de tarjetas amarillas por partido
float PromedioAmarillas(int Partidos[NP][6]) {
    int p, total = 0;
    for (p = 0; p < NP; p++) total += Partidos[p][4] + Partidos[p][5];
    return (float)total / NP;
}

int main() {
    char Equipos[NE]; int Partidos[NP][6];
    CargarDatos(Equipos);
    Inicializo(Partidos);
    MuestroPartidos(Equipos, Partidos);
    CargarResultados(Equipos, Partidos);
    MostrarRanking(Equipos, Partidos);
    cout << endl;
    EquipoGoleador(Equipos, Partidos);
    cout << "Promedio de amarillas por partido: " << PromedioAmarillas(Partidos) << endl;
    return 0;
}