// Utilice los operadores aritméticos de C++ para plantear las expresiones que se
// proponen coloquialmente. Si es posible exprese también la forma abreviada
// correspondiente.
// a) El cociente entre m y n.
// b) El resto de la división entera entre p y q.
// c) Incrementar x en 1.
// d) Incrementar x sumando a x el contenido de c.
// e) Modificar z, asignándole el valor que precede a z.
	

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int m,n,p,q,x,c,z;
	cout << "Ingrese 7 numeros > 0, separados por espacio: ";
	cin >> m >> n >> p >> q  >> x >> c >> z;
	
	int cociente = m/n;
	cout << "El cociente entre m y n es: " << cociente << endl;
	cout << "El resto de la division entre p y q es: " << p%q << endl;
	cout << "El incremento de x en 1 es: " << ++x << endl;
	cout << "El incremento de x sumando x+c es: " << x+c << endl;
	x = x+c;
	z = --z;
	cout << "El valor de z modificado es: " << z << endl;
	
	return 0;
}

