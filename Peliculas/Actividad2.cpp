#include <iostream>
#include <string>

int main() {

int n1, n2, n3;
float promedio;
std::string condicion;
int cantidaddesaprobados, cantidadaprobados;
float promedioaprobado;
float promediodesaprobado;

cantidadaprobados = 0;
cantidaddesaprobados = 0;

for (int i = 1; i <= 30; i++) {

std::cout << "El alumno numero: " << i << std::endl;

do {
std::cout << "Inserte la primer nota: ";
std::cin >> n1;
} while (n1 < 0 || n1 > 10);

do {
std::cout << "Inserte la segunda nota: ";
std::cin >> n2;
} while (n2 < 0 || n2 > 10);

do {
std::cout << "Inserte la tercer nota: ";
std::cin >> n3;
} while (n3 < 0 || n3 > 10);

promedio = (n1 + n2 + n3) / 3.0;

if (promedio >= 6) {
condicion = "aprobado";
cantidadaprobados = cantidadaprobados + 1;
}
else {
condicion = "desaprobado";
cantidaddesaprobados = cantidaddesaprobados + 1;
}

std::cout << "Su condicion es: " << condicion << std::endl;

}

promedioaprobado = (cantidadaprobados * 100.0) / 30;
promediodesaprobado = (cantidaddesaprobados * 100.0) / 30;

std::cout << "El porcentaje de Aprobados es: " << promedioaprobado << "%" << std::endl;
std::cout << "El porcentaje de Desaprobados es: " << promediodesaprobado << "%" << std::endl;

return 0;

}