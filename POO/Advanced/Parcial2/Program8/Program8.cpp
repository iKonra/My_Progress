//	a) Diseñe una función genérica promedio(...) que reciba una lista (list) de datos de cualquier tipo y calcule el
//	promedio de los elementos.
//	b) Escriba un programa en C++ que sea un cliente de la función promedio(...). El programa debe invocar la
//	función tres veces para las siguientes listas:
//	i) Una lista de números flotantes ingresados por el usuario desde el teclado.
//	ii) Una lista de números enteros generados aleatoriamente en el rango de 1 a 100.
//	iii) Una lista de números complejos (struct Complejo { float p_real, p_imag; }) que deben leerse
//	desde un archivo binario "complejos.dat". Nota: implemente todas las funciones auxiliares que considere
//	necesarias para que el programa funcione.

#include <iostream>
#include <list>
#include <numeric>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Complejo {
	float p_real;
	float p_imag;
};

list<Complejo> LeerComplejos(string archivo) {
	ifstream archi(archivo, ios::binary | ios::ate);
	if(!archi) {
		throw runtime_error("error al inicializar");
	}
	int bytes = archi.tellg();
	int CantComplejos = bytes/sizeof(Complejo);
	archi.seekg(0);
	list<Complejo> lista;
	Complejo aux;
	
	for(int i=0;i<CantComplejos;i++) { 
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Complejo));
		lista.push_back(aux);
	}
	
	return lista;
	
}
Complejo operator/(Complejo a,int b) {
	Complejo aux;
	
	aux.p_real =  a.p_real / b;
	aux.p_imag = a.p_imag / b;
	
	return aux;
}
Complejo operator+ (Complejo a, Complejo b) {
	Complejo aux;
	
	aux.p_real = a.p_real + b.p_real;
	aux.p_imag = a.p_imag + b.p_imag;
	
	return aux;
}

template<typename T>
	T Promedio(list<T> lista) {
	T cont = T();
	for(auto &x : lista) {
		cont = cont + x;
	}
	T Prom = cont/lista.size();
	return Prom;
}		
	int main() {
		int N = 5;
		list<float> lista;
		for(int i=0;i<N;i++) { 
			float numero;
			cin >> numero; lista.push_back(numero);
		}
		
		float prom1 =  Promedio(lista);
		
		list<int> lista2;
		for(int i=0;i<100;i++) { 
			lista2.push_back(rand()%100+1);
		}
		
		float prom2 =  Promedio(lista2);
		
		list<Complejo> lista3 = LeerComplejos("complejos.dat");
		Complejo prom3 = Promedio(lista3);
		
		
		return 0;
	}
	
	
