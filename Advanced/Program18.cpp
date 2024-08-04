// codifique una funcion que reciba un vector v de enteros que puede tener valores repetido 
// y retorne un nuevo vector x de structs, donde cada struct/elemento tenga dos datos: 
// un valor del vector v y la cantidad de veces que se repite(ese valor en v). 
// Este nuevo vector x debe estar ordenado segun el valor. 
// Por ejemplo, si el vector inicial es v={80,20,80,30,40,30,80}, el vector resultante sera 
// x={(20;1),(30;2),(40;1),(80;3)}.
// ayuda: utilice una funcion auxiliar para buscar/insertar valores en x, que reciba un valor 
// de v, lo busque en x (busque un struct que tenga ese valor como primer dato), 
// y si no lo encuentra lo inserte donde corresponda para mantener el orden.

#include <iostream>
#include <vector>

using namespace std;

struct ValorContador {
	int valor;
	int contador;
};
void insertarValor(vector<ValorContador>& x, int numero) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i].valor == numero) {
			x[i].contador++;
			return;
		}
	}
	ValorContador nuevonumero;
	nuevonumero.valor = numero;
	nuevonumero.contador = 1;
	
	int pos = 0;
	while (pos < x.size()) { // Si es el primer elemento x.size = 0, entonces el while no comienza
		if(x[pos].valor >= numero) {
			break;
		}
		pos++;
	};
	x.push_back(nuevonumero);
	
	for(int i=x.size() -1 ;i>pos;i--) { 
		x[i] = x[i-1];
	}
	x[pos] = nuevonumero;
}
vector<ValorContador> procesarVector(vector<int>& v) {
	
	vector<ValorContador> x;
	
	for (int i = 0; i < v.size(); i++) {
		insertarValor(x, v[i]);
	}
	
	return x;
}

int main() {
	// Ejemplo de uso
	vector<int> v = {80, 20, 80, 30, 40, 30, 80, 40, 50, 20, 30, 10, 20, 60, 70, 40, 20, 60 ,40};
	vector<ValorContador> x = procesarVector(v);
	
	// Imprimir el resultado
	for (int i = 0; i < x.size(); i++) {
		cout << "(" << x[i].valor << "; " << x[i].contador << ")" << endl;
	}
	
	return 0;
}
