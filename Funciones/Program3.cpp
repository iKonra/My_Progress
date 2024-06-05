// Escriba una función que determine el mayor de 3 valores enteros positivos.
// Modifique la función para que, utilizando parámetros por defecto, sirva también
// para determinar el mayor de 2 parámetros.

#include <iostream>
using namespace std;

int mayor(int a, int b, int c =-1);

int main(int argc, char *argv[]) {
	
	int a,b,c;
	cout << "Ingrese 2 o 3 valores para compararlos: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "El mayor es: " <<  mayor(a,b,c);
}
int mayor(int a, int b, int c) {
	if(a>b and a>c) {
		return a;
	} else
	   if(b>c) return b;
	   else return c;
	}

