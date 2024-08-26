// Escriba una función que utilice punteros para buscar y retornar la dirección de un entero dentro de un arreglo. Se
//	pasan como parámetros el arreglo, su tamaño y el entero a buscar. Si el dato no se encuentra, debe retornar
//	la dirección de memoria nula (nullptr). 

#include <iostream>
using namespace std;

int *buscar(int *v,int N,int numero) {
	for(int i=0;i<N;i++) { 
		if(*(v+i) == numero) {
			cout << "Encontrado";
			return (v+i);
		}
	}
	return nullptr;
}
int main() {
	int N;
	cout << "Cuanto mide el arreglo: "; cin >> N; cout << endl;
	int *v = new int[N];
	
	for(int i=0;i<N;i++) { 
		*(v+i) = rand()%100;
	}
	int numero;
	cout << "Que numero quiere buscar: "; cin >> numero;
	int *p = buscar(v,N,numero);
	cout << "\n " << p << endl;
	return 0;
}

