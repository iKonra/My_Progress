// Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadráticas de la forma ????2 + ???? + ?? = 0 .
// La clase debe incluir:
// 1. Un constructor que reciba los valores de los coeficientes a, b y c.
// 2. Un método TieneRaicesReales(...) que retorne verdadero si las raíces de la ecuación son reales.
// 3. Dos métodos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las raíces reales (en caso de que lo sean).
// 4. Dos métodos VerParteReal(...) y VerParteImag(...) que permitan obtener las partes real e imaginaria de
// las raíces complejas (en caso de que lo sean).
// 5. Cree un programa cliente que utilice un objeto de la clase EcuaciónCuadratica para determinar las raíces de
// una ecuación cuadrática cuyos coeficientes sean ingresados por el usuario, y las muestre en el formato que
// corresponda (según sean reales o complejas).
#include <iostream>
#include <cmath> 

using namespace std;

class EcuacionCuadratica {
private:
	double a, b, c, discriminante;
public:
	EcuacionCuadratica(float dato_a, float dato_b, float dato_c);
	bool TieneRaicesReales();
	float VerRaiz1();
	float VerRaiz2();
	float VerParteReal();
	float VerParteImag();
};
EcuacionCuadratica::EcuacionCuadratica(float dato_a, float dato_b, float dato_c) {
	a = dato_a; b = dato_b; c = dato_c;
	discriminante = pow(b,2)-4*a*c;
}
bool EcuacionCuadratica::TieneRaicesReales() {
	return discriminante >= 0;
}
float EcuacionCuadratica::VerRaiz1() {
	if (TieneRaicesReales()) {
		return (-b + sqrt(discriminante)) / (2 * a);
	}
	return 0; 
}
float EcuacionCuadratica::VerRaiz2() {
	if (TieneRaicesReales()) {
		return (-b - sqrt(discriminante)) / (2 * a);
	}
	return 0;
}
float EcuacionCuadratica::VerParteReal() {
	if (!TieneRaicesReales()) {
		return -b / (2 * a);
	}
	return 0;
}
float EcuacionCuadratica::VerParteImag() {
	if (!TieneRaicesReales()) {
		return sqrt(-discriminante) / (2 * a);
	}
	return 0;
}

int main() {
	float a, b, c;
	cout << "Ingrese el coeficiente a: ";
	cin >> a;
	cout << "Ingrese el coeficiente b: ";
	cin >> b;
	cout << "Ingrese el coeficiente c: ";
	cin >> c;
	
	EcuacionCuadratica ecuacion(a, b, c);
	
	if (ecuacion.TieneRaicesReales()) {
		cout << "Las raíces reales son: " << ecuacion.VerRaiz1() << " y " << ecuacion.VerRaiz2() << endl;
	} else {
		cout << "Las raíces complejas son: " << ecuacion.VerParteReal() << " ± " << ecuacion.VerParteImag() << "i" << endl;
	}
	
	return 0;
}
