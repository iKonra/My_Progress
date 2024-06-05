// Escriba un programa en C++ que permita ingresar un valor numérico
// correspondiente a una medida en pies y devuelva la cantidad equivalente en
// metros. Nota: 1 pie = 0,3048 metros.

#include <iostream>
using namespace std;

int main() {
	
	int Pies;
	cout << "¿Cuantos pies quiere convertir? "; cin >> Pies;
	float cambio = Pies*0.3084;
	cout << Pies << " Pies, es igual a " << cambio << " metros.";
	
	return 0;
}
