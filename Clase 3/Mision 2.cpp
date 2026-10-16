#include <iostream>

using namespace std;

int main() {

    int diahoy, meshoy, diacumple, mescumple;

    cout << "Ingrese el dia de hoy: ";
    cin >> diahoy;

    cout << "Ingrese el mes actual: ";
    cin >> meshoy;

    cout << "Ingrese el dia del cumpleaños: ";
    cin >> diacumple;

    cout << "Ingrese el mes del cumpleaños: ";
    cin >> mescumple;

    if (diahoy == diacumple && meshoy == mescumple) {

        cout << "Hoy es el cumpleaños de mama";

    }

    else {

        if (meshoy < mescumple ||
            meshoy == mescumple && diahoy < diacumple) {

            cout << "El cumpleaños todavia no llega";

        }

        else {

            cout << "El cumpleaños ya paso";

        }

    }

    return 0;
}