// El código fuente de un proyecto de software muy grande está dividido en muchos archivos. Se desea
// analizar la longitud de cada uno y del proyecto completo. a) Escriba un programa que permita cargar por cada uno
//de los N (dato) archivos 3 valores: nombre, cantidad de líneas de código, cantidad de funciones que define; y guarde
// toda esta información en un único vector. b) Luego debe informar por cada archivo el promedio de líneas por
// función; c) los nombres de los dos archivos con más líneas de código; y d) las cantidades totales de líneas y de
// funciones sumando todos los archivos. Importante: Resuelva implementando una función para cada uno de los ítems
// c) y d) que calcule lo que se requiere informar desde el programa principal (main)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Archivo {
	string nombre;
	int lineas, funciones;
};

pair<string, string> max(vector<Archivo> archivos);
pair<int, int> suma(vector<Archivo> archivos);

int main() {
	int N;
	cout << "Ingrese la cantidad de archivos: ";
	cin >> N;
	pair<string, string> c;
	pair<int, int> d;
	vector<Archivo> archivos(N);
	
	for (int i = 0; i < N; ++i) {
		cout << "Ingrese el nombre del archivo " << i + 1 << ": ";
		cin >> archivos[i].nombre;
		cout << "Ingrese la cantidad de lineas de codigo del archivo " << i + 1 << ": ";
		cin >> archivos[i].lineas;
		cout << "Ingrese la cantidad de funciones del archivo " << i + 1 << ": ";
		cin >> archivos[i].funciones;
	}
	for (int i = 0; i < N; i++) { 
		if (archivos[i].funciones != 0) {
			cout << "\nEl archivo " << archivos[i].nombre << " tiene un promedio de: " << archivos[i].lineas / archivos[i].funciones;
		} else {
			cout << "\nEl archivo " << archivos[i].nombre << " tiene un promedio de: N/A (no se pueden dividir líneas entre 0 funciones)";
		}
	}
	c = max(archivos);
	cout << "\nLos dos archivos con mas lineas son: " << c.first << " y " << c.second << endl;
	d = suma(archivos);
	cout << "La suma de lineas de codigo son: " << d.first << endl;
	cout << "La suma de funciones son: " << d.second << endl;
	
	return 0;
}

pair<string, string> max(vector<Archivo> archivos) {
	int max1 = 0; int max2 = 0;
	string nombre1, nombre2;  
	pair<string, string> p;
	
	for (int i = 0; i < archivos.size(); i++) {
		if (archivos[i].lineas > max1) { 
			max2 = max1;
			nombre2 = nombre1;
			max1 = archivos[i].lineas;
			nombre1 = archivos[i].nombre;
		} else if (archivos[i].lineas > max2) { 
			max2 = archivos[i].lineas;
			nombre2 = archivos[i].nombre;
		}
	}
	p.first = nombre1;
	p.second = nombre2;
	return p;
}

pair<int, int> suma(vector<Archivo> archivos) {
	int lineas = 0; int funciones = 0;
	pair<int, int> d;
	for (int i = 0; i < archivos.size(); i++) { 
		lineas += archivos[i].lineas;
		funciones += archivos[i].funciones;
	}
	d.first = lineas;
	d.second = funciones;
	return d;
}
