// Declare una variable entera común y otra variable entera utilizando memoria dinámica (almacenando su dirección
// de memoria en un puntero). Asigne a la primera variable el valor 10 y a la segunda variable un valor ingresado por
// el usuario. Muestre luego los valores y las direcciones de memoria de ambas variables. IMPORTANTE: No olvide
// liberar la memoria de la segunda variable antes de salir

#include <iostream>
using namespace std;

int main() {
	
	int valor1 = 10;
	int *p = &valor1;
	int *p2 = new int;
	cout << "Que valor va a tener la segunda variable: "; cin >> *p2;
	cout << "Los valores son: " << *p  << " y " << *p2 << endl;
	cout << "Las posiciones son: " << p << " y " << p2;
	delete p2;
	
	
	return 0;
}

