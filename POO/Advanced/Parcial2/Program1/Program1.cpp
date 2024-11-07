//	Ejercicio 1 [25 pts] Escriba una función genérica para cualquier tipo de elemento llamada
//	vector_a_lista(...) que reciba un std::vector y retorne una std::list que contenga los elementos del vector
//	de entrada, sin repetidos. Debe mantener el orden del vector. Escriba un programa cliente que genere
//	un vector con 40 enteros aleatorios, utilice la función para pasarlos a una lista, y muestre la lista en
//	pantalla.
	

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
list<T> vector_a_lista(const vector<T>& vec) {
	vector<T> vec_aux; 
	list<T> lista;
	
	for(auto &x : vec) {
		cout << x << " ";
	}
	cout << "\n";
	
	for (const auto& x : vec) {
		if (find(vec_aux.begin(), vec_aux.end(), x) == vec_aux.end()) {
			// Si find termina y es igual al final de vec_aux significa que no encontro duplicado
			
			lista.push_back(x);           
			elementos_unicos.push_back(x); 
		}
	}
	
	for(auto &x : lista) {
		cout << x << " ";
	}
	
	return lista;
}

int main() {
	
	vector<int> vec;
	for(int i=0;i<40;i++) { 
		vec.push_back(rand()%30);
	}
	
	vector_a_lista(vec);
	
	return 0;
}

