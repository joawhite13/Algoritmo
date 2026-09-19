#include <iostream> 
using namespace std;
int main() {
const int R= 8000;
int cantidadcuotas;
float multa, interescuotas, valortotal, valorcuota, totalinteres, valortotalcuota; 
 
cout << "Ingrese el valor de la multa: ";
cin >> multa;
cout << "Ingrese la cantidad de cuotas deseadas (3;6;12): ";
cin >> cantidadcuotas;
switch (cantidadcuotas) { 
case 3:
interescuotas=1.15;
break;
case 6:
interescuotas=1.25;
break;
case 12:
interescuotas=1.35;
break;
default:
cout << "Error" << endl;
break ;
}
if (cantidadcuotas ==3 || cantidadcuotas ==6 || cantidadcuotas ==12 ) {
valorcuota= (multa * interescuotas)/cantidadcuotas ;
totalinteres= (valorcuota * cantidadcuotas)-multa ;
valortotal= R + multa + totalinteres;
valortotalcuota= valortotal / cantidadcuotas;
cout << "El valor total es: " << valortotal << endl;
cout << "El valor de cada cuota es: " << valortotalcuota << endl; 
cout << "El total de intereses cobrados es: " << totalinteres << endl;
}
else {
cout << "Vuelve a intentarlo más tarde :( )" << endl;
}
return 0;
}