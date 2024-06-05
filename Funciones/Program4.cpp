// En cierta materia, un alumno es regular si tiene al menos 50% en cada parcial (o
// en su recuperatorio, queda siempre la mejor nota) y 60% de asistencia. Y es
// promocionado si tiene al menos 80% en cada parcial y 80% de asistencia. Escriba
// una función que reciba los datos de un alumno y retorne su condición.

#include <iostream>
#include <string>
using namespace std;

string Condicion(int a, int b, int c);

int main(int argc, char *argv[]) {
	int p1, r1;
	int p2, r2;
	string rta; // Cambiado a string para comparaciones de texto
	r1 = 0;
	r2 = 0;
	int asis;
	
	cout << "Cual fue el resultado 0-100 del primer parcial?: "; cin >> p1;
	cout << "El alumno asistio al recuperatorio?: Si/No "; cin >> rta;
	int mayor1 = p1;
	if (rta == "Si" || rta == "si") { // Usar || para comparar con "si"
		cout << "Cual fue el resultado 0-100 del recuperatorio?: "; cin >> r1;
		if(p1 < r1) {
			mayor1 = r1;
		}
	}
	cout << "Cual fue el resultado 0-100 del segundo parcial?: "; cin >> p2;
	cout << "El alumno asistio al recuperatorio?: Si/No "; cin >> rta;
	int mayor2 = p2;
	if (rta == "Si" || rta == "si") { // Usar || para comparar con "si"
		cout << "Cual fue el resultado 0-100 del recuperatorio?: "; cin >> r2;
		if(p2 < r2) {
			mayor2 = r2;
		}
	}
	cout << "Cual fue su porcentaje 0-100 de asistencias?: "; cin >> asis; cout << "\n";
	
	cout << "La condicion del alumno es: " << Condicion(mayor1,mayor2,asis);
	
	return 0;
}

string Condicion(int a, int b, int c) {
	int prom = (a+b)/2;
	string condicion;
	
	if(prom >= 80 && c >= 80) {
		condicion = "Promocion";
		return condicion;
	} else {
		if(prom >= 40 && c >= 80) {
			condicion = "Regular";
			return condicion;
		} else {
			condicion = "Libre";
			return condicion;
		}
	}
}


