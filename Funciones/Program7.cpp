// Un año "bisiesto" es un año en el que el mes de Febrero tiene un día más 
// (29 en lugar de 28). Un año es bisiesto si es divisible por 4, a menos que sea divisible por
// 100 y no por 400. Ejemplos:
// - 2004 es porque es divisible por 4.
// - 2005 no es porque no es divisible por 4.
// - 2100 es divisible por 4, pero no es porque es divisible por 100 pero no por 400.
// - 2000 sí porque, aunque es divisible por 100, también es divisible por 400.
// a) Escriba una función para determinar si un año es bisiesto.
	

#include <iostream>
using namespace std;

bool bisiesto(int x);

int main(int argc, char *argv[]) {
	
	int year;
	cout << "Que año quiere averiguar si es bisiesto: "; cin >> year; cout << endl;
	if (bisiesto(year) == true) {
		cout << "El año es bisiesto";
	} else {
		cout << "El año no es bisiesto";
	}
	
	return 0;
}
bool bisiesto(int x) {
	bool Bisis = false;
	if (x > 399) {
		if( x%4==0){
			if(x%100 == 0) {
				if(x%400 == 0) {
					Bisis = true;
				}
			} else {
				Bisis = true;
			}
		}
	} else if(x%4==0) {
		Bisis = true; 
	}
	return Bisis;
}

