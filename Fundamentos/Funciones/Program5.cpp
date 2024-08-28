// Desarrolle una función llamada Intercambia(...) que reciba dos variables enteras
//	por referencia e intercambie sus valores. Escriba dos sobrecargas de la función
//	que permitan realizar el mismo procedimiento con dos datos de tipo real, y dos de
//	tipo caracter. Pruebe las funciones desde un programa cliente.
	

#include <iostream>
using namespace std;

void Intercambia(int &x,int &y);
// void Intercambia(char &x, char &y);
// void Intercambia(float &x,float &y);

int main(int argc, char *argv[]) {
	int x,y; // char x,y; float x,y;
	cout << "Cual es el primer dato: "; cin >> x;
	cout << "Cual es el segundo dato: "; cin >> y;
	Intercambia(x,y);
	cout << "\n\n\nAhora el primer dato vale: " << x << endl;
	cout << "Y el segundo dato vale: " << y;
	return 0;
}
void Intercambia(int &x,int &y) {
	int aux;
	aux = x; x = y; y = aux;
	return;
}
// void Intercambia(char &x, char &y) {
// char aux; aux = x; x = y; y = aux;
// return;
// }

// void Intercambia(float &x,float &y) {
// float aux; aux = x; x = y; y = aux;
// return;
// }