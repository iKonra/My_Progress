// Diseñe una clase Polinomio que contenga:
// 1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
// 2. un método que permita cambiar un coeficiente.
// 3. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
// 4. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
//5. una función que permita sumar dos polinomios retornando un tercer polinomio con el resultado (ej. p_res =
// Sumar(p1, p2);). 

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Polinomio {
private:
	vector<int> v;
public:
	Polinomio(int grado) { v.resize(grado,0);}
	void CambiarCoeficiente(int pos,float coeficiente);
	float EvaluarPolinomio(float valorx);
	void MostrarPolinomio(float valorx);
	Polinomio Sumar(Polinomio p1);
};
void Polinomio::CambiarCoeficiente(int pos, float coeficiente) {
	v[pos] = coeficiente;
}
float Polinomio::EvaluarPolinomio(float valorx) {
	double resultado = 0;
	for(int i=v.size();i>0;i--) {
		resultado += v[i]*(pow(valorx,i));
	}
	return resultado;
}
void Polinomio::MostrarPolinomio(float valorx) {
	cout << "\nEl Polinomio evaluado fue f(" << valorx << ") = ";
	for(int i=v.size();i>0;i--) {
		cout << v[i] << ".x^" << (i) << " + ";
	}
}
Polinomio Polinomio::Sumar(Polinomio p2) {
	int grado = v.size() - 1;
	Polinomio resultado(grado);
	
	for (int i = 0; i <= grado; i++) {
		resultado.CambiarCoeficiente(i, v[i] + p2.v[i]);
	}
	
	return resultado;
}
int main() {
	int grado; float valorx;
	cout << "Ingrese el grado del polinomio: "; cin >> grado; Polinomio p(grado);
	char respuesta;
	cout << "\nQuiere cambiar algun coeficiente Y/N : "; cin >> respuesta;
	int pos; float coeficiente;
	while(respuesta == 'Y' or respuesta == 'y') {
		cout << "Ingrese la posicion y el coeficiente: "; cin >> pos >> coeficiente;
		if(pos <= grado) {
			p.CambiarCoeficiente(pos,coeficiente);
		} else {
			cout << "La posicion esta por fuera de los limites";
			break;
		}
		cout << "\nQuiere cambiar algun coeficiente mas Y/N :"; cin >> respuesta;
	}
	cout << "\nIngrese el valor de x para el cual quiere evaluar el polinomio : ";cin >> valorx;
	cout << "Al evaluar el polinomio da como resultado: " << p.EvaluarPolinomio(valorx);
	p.MostrarPolinomio(valorx);
	return 0;
}

