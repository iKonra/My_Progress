// Ingrese un número e informe: a) si es par o impar; 
//	b) si es múltiplo de 5 y 3 a la vez.
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int numero;
	cout << "Que numero quiere analizar?: "; cin >> numero;
	if (numero%2 == 0) {
		cout << "El numero es par" << endl;
	} else {
		cout << "El numero es impar" << endl;
	}
	if (numero%5 == 0 && numero%3 == 0) {
		cout << "El numero es multiplo de 5 y 3 a la vez " << endl;
	} else {
		cout << "El numero no es multiplo de 5 y 3 a la vez " << endl;
	}
	
	return 0;
}

