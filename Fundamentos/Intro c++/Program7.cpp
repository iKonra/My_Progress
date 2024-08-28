// Escriba un programa C++ que permita ingresar los nombres y fechas de
//    nacimiento de dos personas. Las fechas de nacimiento deben ingresarse como un
//  único entero con el formato aaaammdd, es decir que los cuatro primeros dígitos
//    corresponden al año, los dos siguientes al mes, y finalmente los últimos dos al día.
//    El programa mostrar nombre y fechas de nacimiento de las 2 personas ingresadas
//    con un formato similar al siguiente:
// Luis....:dd/mm/aaaa

#include <iostream>
using namespace std;

int main() {
	string nombre1, nombre2;
	int fecha1, fecha2;
	
	cout << "Ingrese el nombre de la primera persona: ";
	cin >> nombre1;
	cout << "Cual es la fecha de nacimiento de la primera persona? (aaaammdd): ";
	cin >> fecha1;
	
	cout << "Ingrese el nombre de la segunda persona: ";
	cin >> nombre2;
	cout << "Cual es la fecha de nacimiento de la segunda persona? (aaaammdd): ";
	cin >> fecha2;
	
	int dia1 = fecha1 % 100; int dia2 = fecha2 % 100;
	int mes1 = (fecha1 % 10000) / 100; int mes2 = (fecha2 % 10000) / 100;
	int year1 = fecha1 / 10000; int year2 = fecha2 / 10000;
	
	cout << "Persona 1:\n";
	cout << "Nombre: " << nombre1 << ": " << dia1 << "/" << mes1 << "/" << year1 << endl;
	
	cout << "\nPersona 2:\n";
	cout << "Nombre: " << nombre2 << ": " << dia2 << "/" << mes2 << "/" << year2 << endl;
	
	return 0;
}
