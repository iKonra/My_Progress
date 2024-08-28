// Se lee un arreglo ordenado en forma creciente de 100 palabras (orden alfabético) y
// se desea insertar un nuevo elemento de forma que se preserve el orden alfabético.
// Codifique dos funciones llamadas busca_pos() e inserta(). La primera debe
// localizar y devolver la posición en la que debería insertarse un elemento para
// mantener el arreglo ordenado, mientras que la segunda debe recibir el elemento y
// la posición e insertarlo en el arreglo.
	

#include <iostream>
#include <vector>
using namespace std;

int busca_pos(vector<string> arreglo, string palabra);
void inserta(vector<string>& arreglo, int posicion, string palabra);

int main(int argc, char *argv[]) {
	
	vector<string> arreglo(5);
	string palabra;
	
	cout << "Liste las 100 palabras: \n";
	for(int i=0;i<5;i++) { 
		cout << i << ")  "; getline(cin,arreglo[i]);
	}
	cout << "\nQue palabra quiere insertar: "; cin >> palabra;
	int posicion = busca_pos(arreglo, palabra);
	cout << "La nueva palabra se va a insertar en la pos: " << posicion << endl;
	inserta(arreglo,posicion,palabra);
	for(unsigned int i=0;i<arreglo.size();i++) { 
		cout << i << ") " << arreglo[i] << "\n";
	}
	
	return 0;
}
int busca_pos(const vector<string> arreglo,string palabra) {
	for (unsigned int i = 0; i < arreglo.size(); i++) {
		if (arreglo[i] > palabra) {
			return i;
		}
	}
	return arreglo.size();
}
void inserta(vector<string>& arreglo, int posicion, string palabra) {
	arreglo.resize(arreglo.size() + 1);
	for (int i = arreglo.size() - 1; i > posicion; i--) {
		arreglo[i] = arreglo[i - 1];
	}
	arreglo[posicion] = palabra;
}
