//	Realice una función llamada intercala(...) que recibe como parámetros 2 punteros a vectores de enteros La función debe
//	devolver un nuevo vector con los elementos intercalados de los vectores pasados como parámetro (por ejemplo si
//	a=[2,4,5,1,6,3] y b=[10,20] se deberá obtener [2,10,4,20,5,1,6,3]. Utilice la función en un programa cliente. NOTAS: No
//	usar la clase vector. Usar solo notación de punteros (no usar operador [ ]).

#include <iostream>
using namespace std;

int* intercala(int *a, int *b, int *c, int *d) {
	int tamanio = (c - a) + (d - b);
	int lista1 = (c - a);
	int lista2 = (d - b);
	int *pnuevo = new int[tamanio];
	
	// indice a = i;
	// indice b = j;
	// indice pnuevo = k;
	int i = 0, j = 0, k = 0;
	
	// Intercalar los elementos
	while (i < lista1 && j < lista2) {
		*(pnuevo + k++) = *(a + i++);  // Agregar de la primera lista
		*(pnuevo + k++) = *(b + j++);  // Agregar de la segunda lista
	}
	
	// Si quedan elementos en la primera lista
	while (i < lista1) {
		*(pnuevo + k++) = *(a + i++);
	}
	
	// Si quedan elementos en la segunda lista
	while (j < lista2) {
		*(pnuevo + k++) = *(b + j++);
	}
	
	// Mostrar el resultado intercalado
	for (int i = 0; i < tamanio; i++) {
		cout << *(pnuevo + i) << " ";
	}
	cout << endl;
	
	return pnuevo;
}

int main() {
	int n, r;
	cin >> n >> r;
	
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}
	int *b = new int[r];
	for (int i = 0; i < r; i++) {
		cin >> *(b + i);
	}
	// Puntero a A, puntero a B, final A, final B
	intercala(a, b, (a + n), (b + r));
	
	delete[] a;
	delete[] b;
	
	return 0;
}
