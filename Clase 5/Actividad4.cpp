
#include <iostream>
using namespace std;

int capacidadtotal, vagonesllenos, vagonincompleto, vacios, vagoneusado;

void calculototal(int pasajeros, int vagones, int capacidadvagon) {
    capacidadtotal = vagones * capacidadvagon;
    vagonesllenos = pasajeros / capacidadvagon; // Calculate full wagons based on capacity
    vagonincompleto = pasajeros % capacidadvagon; // Calculate remaining passengers for the incomplete wagon

    if (vagonincompleto == 0) {
        vagoneusado = 0;
    } else {
        vagoneusado = 1;
    }

    vacios = vagones - vagonesllenos - vagoneusado;
}

int main() {
    int pasajeros, vagones, capacidadvagon;

    cout << "Ingrese la cantidad de pasajeros: ";
    do {
        cin >> pasajeros;
        if (pasajeros < 1) {
            cout << "La cantidad de pasajeros debe ser mayor que 1. Intente nuevamente: ";
        }
    } while (pasajeros < 1);

    cout << "Ingrese la capacidad de cada vagon: ";
    do {
        cin >> capacidadvagon;
        if (capacidadvagon < 1) {
            cout << "La capacidad del vagon debe ser mayor que 1. Intente nuevamente: ";
        }
    } while (capacidadvagon < 1);

    cout << "Ingrese la cantidad de vagones disponibles: ";
    do {      
        cin >> vagones;
        if (vagones < 1) {
            cout << "La cantidad de vagones debe ser mayor que 1. Intente nuevamente: ";
        }
    } while (vagones < 1);
    do {
        capacidadtotal = vagones * capacidadvagon;
        if (capacidadtotal < pasajeros) {
            cout << "La cantidad de vagones no es suficiente para los pasajeros. Intente nuevamente: ";
            cin >> vagones;
        }
    } while (capacidadtotal < pasajeros);

    calculototal(pasajeros, vagones, capacidadvagon);

    cout << "La cantidad de vagones completos es: " << vagonesllenos << endl;
    if (vagonesllenos == 0) {
        cout << "No hay vagones completos" << endl;
    }
    if (vagonesllenos == vagones) {
        cout << "Todos los vagones estan completos" << endl;
    }

    if (vagonincompleto != 0) {
        cout << "El numero de pasajeros en el vagon incompleto es de: " << vagonincompleto << endl;
    }

    if (vacios != 0) {
        cout << "La cantidad de vagones vacios es de: " << vacios << endl;
    } else {
        cout << "No hay vagones vacios" << endl;
    }

    return 0;
}