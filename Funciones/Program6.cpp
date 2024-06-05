// El algoritmo de Euclides es un método antiguo y eficaz para calcular el máximo
//	común divisor (MCD) de dos números enteros. Fue propuesto originalmente por
//	Euclides en su obra Elementos y enuncia que el MCD entre dos números a y b
//	puede obtenerse de manera recursiva aplicando las siguientes propiedades:
//	Si a>b, entonces MCD(a,b) = MCD(a-b,b)
//	Si a<b, entonces MCD(a,b) = MCD(a, b-a)
//	Si a=b, entonces MCD(a,b) = a
	

#include <iostream>
using namespace std;

int MCD(int a,int b);

int main(int argc, char *argv[]) {
	
	int a,b;
	cout << "De que numeros quiere conocer el MCD: "; cin >> a >> b; cout << endl;
	cout << "El maximo comun divisor es: " << MCD(a,b);
	
	
	return 0;
}
int MCD(int a,int b) {
	if(a > b) {
		return MCD(a-b,b);
	} else if(a < b) {
		return MCD(a, b-a);
	} else {
		return a;
	}
	
}
