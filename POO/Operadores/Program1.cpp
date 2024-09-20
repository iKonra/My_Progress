// • El operador + para sumar dos objetos de la clase Racional.
// • El operador * para multiplicar un objeto de tipo Racional por un entero.
	

#include <iostream>
using namespace std;
class Racional {
public:
	Racional(int num, int den) : m_num(num), m_den(den) { }
	int VerNum() const { return m_num; }
	int VerDen() const { return m_den; }
private:
		int m_num, m_den;
};
Racional operator+(Racional a, Racional b) {
	Racional suma(a.VerNum() * b.VerDen() + b.VerNum() * a.VerDen(),a.VerDen() * b.VerDen());
	return suma;
}
Racional operator*(Racional a, Racional b) {
	Racional multiplicacion(a.VerNum()*b.VerNum(),a.VerDen()*b.VerDen());
	return multiplicacion;
}
int main() {
	Racional a(3, 5), b(2, 3);
	Racional aux = a + b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	aux = a * b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	
	
	return 0;
}
