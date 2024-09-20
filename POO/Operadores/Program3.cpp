//	Implemente sobrecargas para los operadores >> y << para leer un objeto de tipo Racional desde la consola (mediante
//	cin) y mostrarlo en pantalla (mediante cout). La lectura se debe realizar leyendo el numerador y denominador por
//	separado (es decir, separados por un espacio o salto de línea). El operador << debe mostrar el numerador y el
//	denominador separados por el carácter '/'.


#include <iostream>
using namespace std;

class Racional {
public:
	Racional(){}
	void CargarNum(float num) {m_num = num;}
	void CargarDen(float den) {m_den = den;}
	float VerNum() const { return m_num; }
	float VerDen() const { return m_den; }
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
	return 0;
}

