//	Escriba un programa que permita al usuario ingresar 15 valores por teclado, los almacene en un vector y luego:
//	 1. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes:
//		• utilizando el operador []
//		• utilizando iteradores
//		• utilizando el for basado en rangos
//		• ¿en qué caso es conveniente utilizar cada mecanismo?
//	 2. Calcule y muestre:
//		• los valores de los elementos máximo y mínimo
//		• la suma de todos los elementos del arreglo
//		• el promedio y la mediana de los elementos del arreglo
//	 3. Permita al usuario ingresar un valor, e informe si se encuentra en el vector, y en caso afirmativo, en qué posición.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*//  Ejercicio 1*/
void Mostrar1(vector<int> v1) {
	for(size_t i=0;i<v1.size();i++) { 
		cout << v1[i] << " ";
	}
}
void Mostrar2(vector<int> v1) {
	for(auto it= v1.begin();it != v1.end(); ++it) {
		cout << *it << " ";
	}
}
void Mostrar3(vector<int> v1) {
	for(int &x : v1) {
		cout << x << " ";
	}
}
/*//  Terminar Ejercicio 1*/

int main() {
	vector<int> v1;
	
	int numero;
	for(int i=0;i<15;i++) { 
		numero = rand()%100;
		v1.push_back(numero);
	}
	Mostrar1(v1); cout << "\n";
	Mostrar2(v1); cout << "\n";
	Mostrar3(v1); cout << "\n";
	
	
//	/*Ejercicio 2 Inicio*/
	int menor = *min_element(v1.begin(),v1.end());
	int mayor = *max_element(v1.begin(),v1.end());
	
	cout << "Mayor: " << mayor << " Menor: " << menor << endl;
	
//	/*Ejercicio 2 Final*/
	
// /*Ejercicio 3 Inicio*/
	
	int buscar; cin >> buscar;
	auto it = find(v1.begin(),v1.end(),buscar);
	if(it == v1.end())
		cout << "No se encontro el valor en el vector";
	else 
		cout << "Se encontro el valor en la posicion: " << (it-v1.begin());
		
	
// /*Ejercicio 3 Final*/	
	
	return 0;
}

