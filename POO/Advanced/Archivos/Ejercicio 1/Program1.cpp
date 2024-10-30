//	Escriba un programa que cargue en un vector de strings una lista de palabras desde un archivo de texto (que
//	contendrá una palabra por línea), muestre en pantalla la cantidad de palabras leídas, las ordene en el vector
//	alfabéticamente, y reescriba el archivo original con la lista ordenada. Ayuda: para ordenar un vector v de principio a
//	fin puede utilizar la sentencia sort(v.begin(), v.end());.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream archi("palabras.txt"); // Abro el archivo con las palabras
	if(not archi.is_open()) {
		throw runtime_error("No se pudo abrir el archivo.");
	}
	vector<string> palabras; // Creo el vector para almacenar cada linea del txt
	string palabra;
	int cont = 0; // Contador de palabras
	
	while(archi >> palabra) { // Si hay una linea para leer la condicion es = true
		cont++;
		palabras.push_back(palabra); 
	}
	archi.close(); 
	cout << cont << " palabras han sido leidas." << endl; 
	
	sort(palabras.begin(), palabras.end()); // Ordena el vector alfabeticamente, los argumentos son los delimitadores
	
	ofstream salida("palabrasOrdenadas.txt"); 
	
	for(size_t i = 0; i < palabras.size(); i++) { // Recorre cada palabra en el vector
		salida << palabras[i] << endl; 
	}
	salida.close(); 
	
	return 0;
}
