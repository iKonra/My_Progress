// Implemente sobrecargas para pre y post incremento (operador ++) para la clase Racional de los ejercicios anteriores.
//	Proponga un programa de prueba donde se note la diferencia entre uno y otro.
	

#include <iostream>
using namespace std;
class Racional {
public:
	Racional(){}
	void CargarNum(float num) {m_num = num;}
	void CargarDen(float den) {m_den = den;}
	float VerNum() const { return m_num; }
	float VerDen() const { return m_den; }
	Racional &operator++() { // pre
		m_num += 1000;
		return *this;
	}
	Racional operator++(int) { // post
		Racional aux = *this;
		m_num += 3000;
		return aux;
	}
private:
		float m_num, m_den;
};
ostream &operator<<(ostream &o,Racional x) {
	o << x.VerNum() << "/" << x.VerDen() << endl;
	return o;
}
istream &operator>>(istream &i,Racional &x) {
	float a; i >> a; x.CargarNum(a);
	float b; i >> b; x.CargarDen(b);
	return i;
}
int main() {
	
	Racional a;
	cin >> a;
	cout << a;
	++a;
	cout << a;
	
	return 0;
}

