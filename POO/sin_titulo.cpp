// ) Escriba a través de un programa C++ un archivo binario llamado grupo.dat, formado por un conjunto de 200 pares
//	de números generados aleatoriamente. Cada par de datos se conforma por un entero y un flotante.
//	b) Escriba otro programa que lea el archivo generado por el primero para verificar si se escribieron correctamente.	

#include <iostream>
#include <fstream>
using namespace std;

struct par {
	int x;
	float y;
};
int main() {
	
	par Par[200];
	
	ofstream archi("grupo.dat",ios::binary);
	if(!archi)
		throw runtime_error("El archivo no se pudo abrir.");
	
	for(int i=0;i<200;i++) { 
		Par[i].x = rand()%100;
		Par[i].y = rand() / 10.53;
		
		archi.write(reinterpret_cast<const char*>(&Par[i]), sizeof(par));
	}
	cout << "Archivo generado.";
	
	return 0;
}

