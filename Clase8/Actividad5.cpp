// Clase 8 - Actividad 5: Instituto (opcion a)
#include <iostream>
#include <string>
using namespace std;

const int N = 1; // cantidad de alumnos (5 para agilizar la prueba)

struct Alumno {
    string NomyApe;
    int DNI;
    char SEXO;
};

struct LEGAJO {
    Alumno Estudiante;
    float Notas[3];
    int Amon[3];
    int Faltas[3];
};

// ---------- Validaciones ----------

// Lee un entero entre min y max (valida tipo y valor)
int LeerEntero(string msj, int min, int max) {
    int x = min - 1;
    do {
        cout << msj;
        if (!(cin >> x)) {
            cout << "ERROR: debe ingresar un numero entero." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            x = min - 1;
        } else if (x < min || x > max) {
            cout << "ERROR: el valor debe estar entre " << min << " y " << max << "." << endl;
        }
    } while (x < min || x > max);
    return x;
}

// Lee un real entre min y max (valida tipo y valor)
float LeerReal(string msj, float min, float max) {
    float x = min - 1;
    do {
        cout << msj;
        if (!(cin >> x)) {
            cout << "ERROR: debe ingresar un numero." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            x = min - 1;
        } else if (x < min || x > max) {
            cout << "ERROR: el valor debe estar entre " << min << " y " << max << "." << endl;
        }
    } while (x < min || x > max);
    return x;
}

// Lee un texto que no puede quedar vacio (acepta espacios)
string LeerCadena(string msj) {
    string s;
    do {
        cout << msj;
        getline(cin >> ws, s);
    } while (s.length() == 0);
    return s;
}

// Lee el sexo: solo F o M
char LeerSexo() {
    char s;
    do {
        cout << "Sexo (F/M): ";
        cin >> s;
        s = toupper(s);
        if (s != 'F' && s != 'M') cout << "ERROR: ingrese F o M." << endl;
    } while (s != 'F' && s != 'M');
    return s;
}

// ---------- Carga de datos ----------
void CargarDatos(LEGAJO Leg[N]) {
    for (int i = 0; i < N; i++) {
        cout << "\n****** ALUMNO " << i + 1 << " ******" << endl;
        Leg[i].Estudiante.NomyApe = LeerCadena("Nombre y apellido: ");
        Leg[i].Estudiante.DNI = LeerEntero("DNI: ", 1000000, 99999999);
        Leg[i].Estudiante.SEXO = LeerSexo();
        for (int a = 0; a < 3; a++) {
            cout << "-- Año " << a + 1 << " --" << endl;
            Leg[i].Notas[a] = LeerReal("Nota promedio (1 a 10): ", 1, 10);
            Leg[i].Amon[a] = LeerEntero("Amonestaciones: ", 0, 1000);
            Leg[i].Faltas[a] = LeerEntero("Faltas: ", 0, 1000);
        }
    }
}

// ---------- Opcion a ----------

// Muestra los alumnos con mas de 15 amonestaciones en total y cuantos son
void MasDe15Amon(LEGAJO Leg[N]) {
    int totAmon, totFaltas, cant = 0;
    cout << "\n¡ALUMNOS CON MAS DE 15 AMONESTACIONES!" << endl;
    for (int i = 0; i < N; i++) {
        totAmon = 0;
        totFaltas = 0;
        for (int a = 0; a < 3; a++) {
            totAmon = totAmon + Leg[i].Amon[a];
            totFaltas = totFaltas + Leg[i].Faltas[a];
        }
        if (totAmon > 15) {
            cout << Leg[i].Estudiante.NomyApe << " --- DNI: " << Leg[i].Estudiante.DNI
                 << " --- Faltas totales: " << totFaltas << endl;
            cant++;
        }
    }
    cout << "Cantidad de alumnos que cumplen: " << cant << endl;
}

// Muestra el promedio de faltas y de amonestaciones de cada anio
void PromediosPorAnio(LEGAJO Leg[N]) {
    int sumF, sumA;
    cout << "\nPROMEDIOS POR AÑO" << endl;
    for (int a = 0; a < 3; a++) {
        sumF = 0;
        sumA = 0;
        for (int i = 0; i < N; i++) {
            sumF = sumF + Leg[i].Faltas[a];
            sumA = sumA + Leg[i].Amon[a];
        }
        cout << "Año " << a + 1 << ": Promedio faltas= " << (float)sumF / N
             << "  --- Promedio amonestaciones= " << (float)sumA / N << endl;
    }
}

// ---------- Programa principal ----------
int main() {
    LEGAJO Leg[N];
    CargarDatos(Leg);
    MasDe15Amon(Leg);
    PromediosPorAnio(Leg);
    return 0;
}