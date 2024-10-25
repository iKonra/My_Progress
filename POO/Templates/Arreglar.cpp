//	Programe una clase templatizada llamada VectorDinamico (similar a la de la guía 2). La clase debe poseer:
//	1. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria necesaria.
//	2. Un destructor que se encargue de liberar la memoria reservada.
//	3. Una sobrecarga del operador [] que reciba el número de elemento, devuelva su valor, y permita modificarlo.
//	4. Modifique o sobrecargue el constructor para que permita generar valores aleatorios con los cuales inicializar
//	las posiciones del arreglo que reserva.
//	5. Utilice la clase desde un programa cliente creando vectores aleatorios con diversos tipos de datos (int, double,
//	string, etc).
	

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
class VectorDinamico {
	
T* tamanio;
	
public: 
	VectorDinamico(int n){ 
		tamanio = new T[n];
	
		char b;
		string c;
		for(int i=0;i<n;i++) { 
			for(int i=0;i<10;i++) { 
				b = 97 + (rand()%(122 - 97));
				c += b;
			}
			tamanio[i] = c;
			c = " ";
			cout << tamanio[i] << endl;
		}
		
	}
	T& operator[](int pos) {
		
		char rta;
		cout << "Desea modificar el valor  (Y/N): " << endl; cin >> rta;
		if(rta == 'Y' or 'y') {
			cin >> tamanio[pos];
		}
		return tamanio[pos];
	}
	~VectorDinamico() {delete tamanio;}

};
int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int n = 300000;
	VectorDinamico<string> a(n);
		
	
	
	return 0;
}

