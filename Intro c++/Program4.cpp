// Se necesita un programa en C++ que calcule las soluciones o raíces de una
//	ecuación cuadrática del tipo ax2+bx+c=0, siendo que el usuario del programa
//	ingresa como datos los coeficientes a, b y c. Suponga que el usuario siempre
//	ingresa datos que corresponden a ecuaciones de raíces reales.

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	
	cout << "Ingrese los coeficientes separados por espacios: ";
	float a,b,c;
	cin >> a >> b >> c;
	float raiz1 = (-b+(sqrt(b*b-4*a*c)))/(2*a);
	float raiz2 = (-b-(sqrt(b*b-4*a*c)))/(2*a);
	cout << "La raiz 1 es: " << raiz1 << endl << "La raiz 2 es: " << raiz2; 
	
	return 0;
}

