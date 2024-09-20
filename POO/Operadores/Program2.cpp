//	Para la clase Racional utilizada en el ejercicio anterior, implemente los operadores relacionales
//	<, <=, >, >=, == y !=
//	para comparar dos números racionales. Haga uso de dichos operadores desde un programa cliente.

#include <iostream>
#include <cmath>
using namespace std;
class Racional {
public:
	Racional(float num, float den) : m_num(num), m_den(den) { }
	float VerNum() const { return m_num; }
	float VerDen() const { return m_den; }
private:
		float m_num, m_den;
};
Racional operator+(Racional a, Racional b) {
	Racional suma(a.VerNum() * b.VerDen() + b.VerNum() * a.VerDen(),a.VerDen() * b.VerDen());
	return suma;
}
Racional operator*(Racional a, Racional b) {
	Racional multiplicacion(a.VerNum()*b.VerNum(),a.VerDen()*b.VerDen());
	return multiplicacion;
}
bool operator<(Racional a, Racional b) {
	return ((a.VerNum()/a.VerDen()) < (b.VerNum()/b.VerDen()));
}
bool operator==(Racional a, Racional b) {
	return ((a.VerNum() / a.VerDen()) == (b.VerNum() / b.VerDen()));
}
bool operator<=(Racional a, Racional b) {
	return ((a < b) or (a == b));
}
bool operator>(Racional a, Racional b) {
	return not((a < b) or (a == b));
}
bool operator>=(Racional a, Racional b) {
	return((a > b) or (a == b));
}
bool operator!=(Racional a, Racional b) {
	return not(a == b);
}
int main() {
	Racional a(1, 8), b(2, 3);
	cout <<  (a == b) << endl;
	cout << (a <= b) << endl;
	
	
	return 0;
}
