//	Escriba una función C++ genérica llamada dosmayores_up(...) que reciba un vector como parámetro. La función
//	debe modificadar el vector: debe obtener los 2 mayores y ubicar el primer mayor en el 1er lugar (al comienzo del
//	vector) intercambiando los elementos correspondientes, y al 2do mayor en el 2do lugar, el resto de los elementos
//	quedan en sus posiciones originales.
//	Nota: no utilice estructuras de control iterativas, solo recorra la secuencia a través de las funciones de la biblioteca
//	<algorithm>.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
void dosmayores_up(vector<T>& v) {
	auto it1 = max_element(v.begin(),v.end());
	
	cout << "Primer valor mayor: " << *it1 << endl;
	
	iter_swap(v.begin(),it1);
	
	it1 = max_element(v.begin()+1,v.end());
	
	cout << "Segundo valor mayor: " << *it1 << endl;
	
	iter_swap(v.begin()+1,it1);
}

int main() {
	srand(time(NULL));
	
	vector<int> v;
	for(int i=0;i<20;i++) { 
		int numero = rand()%150;
		v.push_back(numero);
	}
	cout << "Vector antes de la funcion: " << endl;
	for(auto &x : v) {
		cout << x << " ";
	}
	cout << "\n";
	
	dosmayores_up(v);
	
	for(auto &x : v) {
		cout << x << " ";
	}
	
	return 0;
}

