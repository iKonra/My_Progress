// En un archivo de texto llamado lista.txt, como el que se muestra en el recuadro, se encuentran los nombres y notas
//	de los alumnos de una comisión de Programación Orientada a Objetos.
//		Lopez Javier
//		56 90
//		Garcia Ana
//		77 81
//		Farias Daniel
//		60 62
//	a) Escriba una función que reciba el nombre de un alumno y dos notas, y modifique el archivo reemplazando las dos
//	notas de ese alumno.
//	b) Escriba una función que lea la lista del archivo y genere otro archivo de texto promedios.txt con una tabla
//	donde cada línea posea el nombre, el promedio, y la condición final de cada uno de los alumnos. Ayuda: utilice
//	manipuladores de flujo (setw, right, left, fixed, setprecision) para dar formato a la tabla del archivo que se
//	genera en b.

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;

struct Alumno {
	string nombre;
	int nota1, nota2;
};

void CambiarNotas(string nombre, int nota1, int nota2,vector<Alumno> &v) { // Creo la funcion que modifica las notas
	
	
	ofstream actualizado("lista.txt", ios::trunc); // ios::trunc para vaciar el archivo apenas se abre
	if (!actualizado) 
		throw runtime_error("No se abrió correctamente el archivo para actualizar.");
	
	
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].nombre == nombre) {
			
			v[i].nota1 = nota1;
			v[i].nota2 = nota2;
		}
		
		// Como vacie el archivo lo tengo que reescribir con los datos actualizados 
		
		actualizado << setw(2) << right << v[i].nombre << endl; // Setw
		actualizado << setw(4) << right << v[i].nota1 << " " << v[i].nota2 << endl;
	}
	actualizado.close();
}
void Promedios(vector<Alumno> v) {
	
	ofstream salida("promedios.txt");
	for(size_t i=0;i<v.size();i++) { 
		float prom = (v[i].nota1+v[i].nota2)/2;
		salida << "Alumno: " << v[i].nombre << " Promedio: " << prom;
		if(prom < 40) {
			salida << " Condicion: " << "Libre" << endl;
		} else if(prom >= 40 && prom < 70) {
			salida << " Condicion: " << "Regular" << endl;
		} else
				  salida << " Condicion: " << "Promocion" << endl;
	}
}
int main() {
	
	Alumno aux;
	vector<Alumno> v;
	ifstream archi("lista.txt");
	if (!archi) 
		throw runtime_error("No se abrió correctamente la lista.");
	
	while (getline(archi, aux.nombre) && archi >> aux.nota1 >> aux.nota2) {
		archi.ignore();
		v.push_back(aux);
	}
	archi.close();
	
	CambiarNotas("Garcia Ana", 65, 85,v);
	Promedios(v);
	cout << "Notas cambiadas con éxito." << endl;
	
	
	return 0;
}

