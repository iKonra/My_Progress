// Utilizando notación de punteros, generar un arreglo dinámico y lineal de N elementos numéricos enteros, con valores
// aleatorios entre 1000 y 1500, y muestre en pantalla la dirección de memoria del mayor elemento. N es un dato
// ingresado por el usuario.

#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int *v = new int[N];
	int mayor = 0; int pos = 0;
	for(int i=0;i<N;i++) { 
		*(v+i) = (rand()%501)+1000;
		if(i >= 1) {
			if(v[i] > mayor) {
				pos = i; 
				mayor = v[i];
			}
		} else {
			pos = i;
			mayor = v[i];
		}
	}
	
	cout << v[pos] << " " << &v[pos] << endl;
	delete []v;
	
	return 0;
}

