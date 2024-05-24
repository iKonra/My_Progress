// Generar aleatoriamente un arreglo lineal de 20 elementos numéricos, con enteros
// aleatorios entre 100 y 150 y mostrarlo en pantalla. Luego leer dos valores en las
// variables m y p. El valor m debe ser insertado en la posición p del arreglo. Mostrar
// el arreglo modificado.	

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int m,p;
	vector<int> valores(20);
	for(int i=0;i<20;i++) { 
		int r = 100 + (rand()%(151-100));
		valores[i] = r;
		cout << "Valor " << i+1 <<" ingresado: " << valores[i] << "\n";
	}
	cout << "Que dato quiere ingresar: "; cin >> m;
	cout << "En que posicion lo quiere insertar: "; cin >> p;
	valores.resize(21);
	for(int i=20;i>p-1;i--) {
		valores[i+1] = valores[i]; 
	}
	valores[p] = m;
	for(int i=0;i<21;i++) { 
		cout << valores[i] << "\n";
	}
	
	return 0;
}

