//	Ejercicio 2 [25 pts] Escriba una función genérica para cualquier tipo de elemento llamada
//	lista_a_vector(...) que reciba un std::list y retorne un std::vector que contenga los elementos de la lista
//	de entrada, sin repetidos. Escriba un programa cliente que genere una lista con 30 enteros aleatorios,
//	utilice la función para pasarlos a un vector, y muestre el vector en pantalla.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
vector<T> lista_a_vector(list<T> lista) {
	
	vector<T> vec;
	
	for(auto &x : lista ) {
		if(find(vec.begin(),vec.end(),x) == vec.end()) {
			vec.push_back(x);
		}
	}
	for(auto &x : vec) {
		cout << x << " ";
	}
	return vec;
}

int main() {
	
	list<int> lista;
	for(int i=0;i<30;i++) { 
		lista.push_back(rand()%20);
	}
	for(auto &x : lista) {
		cout << x << " ";
	}
	cout << "\n";
	lista_a_vector(lista);
	
	return 0;
}

