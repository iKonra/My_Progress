// Escriba un programa que permita Ingresar tres números e informe el valor del
// mayor de ellos.

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	
	int a, b, c;
	cout << "Ingrese 3 numeros separados por espacio "; cin >> a >> b >> c; cout << "\n";
	
	if(a > b && a > c) {
		cout << "El numero a: " << a << " es el mayor de todos \n";
	} else {
		if(b > a && b > c) {
			cout << "El numero b: " << b << " es el mayor de todos \n";
		} else {
			cout << "El numero c: " << c << " es el mayor de todos \n";
		}
	}
	
	
	return 0;
}

