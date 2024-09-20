// Implemente una clase Monomio para representar un monomio de la forma a.x^n a partir de un coeficiente (a) y un
//	exponente (n), con un método Evaluar(...) que reciba un real y retorne el valor del monomio evaluado con ese
//	real, y los demás métodos que considere necesarios. Implemente, luego, una clase Polinomio que reutilice la clase
//	Monomio para modelar un polinomio, y añada un método Evaluar(...) para evaluar un polinomio en un valor x real
//	dado.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Monomio {
private:
	float coeficiente;
	int exponente;
public:
	Monomio(float d_coeficiente,int d_exponente):coeficiente(d_coeficiente),exponente(d_exponente){}
	float Evaluar(float num_real);
};
float Monomio::Evaluar(float num_real) {
	float resultado = coeficiente*pow(num_real,exponente);
	return resultado;
}

class Polinomio {
private:
	vector<Monomio> monomios;
public:
	Polinomio(vector<Monomio> d_monomios) : monomios(d_monomios){}
	float Evaluar(float num_real);
};
float Polinomio::Evaluar(float num_real) {
	int resultado = 0;
	for(size_t i=0;i<monomios.size();i++) { 
		resultado += monomios[i].Evaluar(num_real);
	}
	return resultado;
}
int main() {
	Monomio m1(3, 2);  
	Monomio m2(2, 1);  
	Monomio m3(1, 0);  
	vector<Monomio> monomios = {m1, m2, m3};
	Polinomio p(monomios);
	float valor = 2.0;  
	float resultado = p.Evaluar(valor);
	cout << "El resultado del polinomio evaluado en x = " << valor << " es: " << resultado << endl;
	return 0;
}
