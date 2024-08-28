// Escriba un programa C++ que permita ingresar natural N como dato. Obtener
// todos los pares menores a N. Tener en cuenta que el dato puede ser tanto par
// como impar. Debe dar al usuario la posibilidad de seleccionar por un menú la
// opción de visualizar el listado:
// a) En forma creciente.
// b) En forma decreciente.
	

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	
	int n;
	int i = 2;
	cout << "Ingrese un numero entero: "; cin >> n;
	char opcion;
	cout << "Menu \n" << "a)Mostrar pares en forma creciente \n" << "b)Mostrar pares en forma decreciente \n";
	cout << "Ingrese su eleccion (a - b): "; cin >> opcion;
	
	if (n%2 != 0) {
		--n;
		if(opcion == 'b') {
			cout << n << " ";
		}
	}
	
	while (opcion == 'a' && n<200) {
		n+= i;
		cout << n << " ";
	}
	while (opcion == 'b' && n>i) {
		n-= i;
		cout << n << " ";
	}
		return 0;
}

