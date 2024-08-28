// Escriba un programa C++ que calcule el área y el perímetro de un círculo cuyo
// radio se ingresa como dato.
#include <iostream>
using namespace std;

int main() {
	float radio;
	cout << "¿Cual es el radio del circulo? "; cin >> radio;
	float Area = 3.1416*(radio*radio);
	float Perimetro = (3.1416*2)*radio;
	cout << "El area del circulo es: " << Area << " y el perimetro " << Perimetro;
	
	return 0;
}

