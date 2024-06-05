// Escriba un programa en C++ que pida al usuario que ingrese su nombre (el
//nombre no debe contener espacios). El programa debe saludar al usuario
//imprimiendo por pantalla el mensaje “Saludos <usuario>!”, donde se debe
// reemplazar <usuario> por el nombre ingresado.
#include <iostream>
using namespace std;

int main() {
	string Nombre; cout << "¿Cuál es tu nombre? "; // Utiliza el operador de inserción "<<" para imprimir el mensaje
	cin >> Nombre; // Lee el nombre del usuario desde la entrada estándar
	cout << "Saludos " << Nombre << endl;
	
	return 0;
}
