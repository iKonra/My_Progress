/*
Ejer 2 (30pts) Una entidad bancaria desea procesar los movimientos de la cuenta corriente de un día de su cartera de clientes. 
Por cada cliente se tiene: Nro de cuenta, apellido y nombres, saldo y el máximo importe con el que puede operar en descubierto*. 
Escriba un programa C++ que incialmente haga la carga de los datos de los N clientes del banco. 
a) Luego, el programa debe permitir la carga de los movimientos del día. Los datos son: nro de cuenta, tipo de movimiento, importe. 
Los tipos de movimiento pueden ser 1-depósitos, 2-transferencias recibidas o 3- transferencias hechas. 
La carga de movimientos termina con nro de cuenta 0.
b) Codifique una función que retorne la lista de movimientos de un cliente, y otra función que use esa sublista para actualizar el saldo de ese cliente. 
c) Utilizando las funciones de (b) actualice los saldos de todos los clientes e informe por pantalla cuáles clientes terminan con un saldo negativo que 
supere su mayor importe permitido para descubierto.
Nota: "Descubierto" es cuando queda un saldo negativo. Ej: Si en la cuenta del banco se dispone de $10.000 y se efectúan pagos por $15.000; 
el banco lo admite y la cuenta tiene $5000 de descubierto. Muchos bancos tienen acuerdos con clientes para operar en descubierto.
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct cliente {
	int cuenta;
	string nombre;
	float saldo;
	float descubierto;
	
};
struct movimiento {
	float importe;
	int nrocuenta;
	int tipo;
};
void actualizar(vector<movimiento> c,int posicion,vector<cliente>& v) {
	
	for(int i=0;i<c.size();i++) { 
		if(c[i].tipo == 1 or c[i].tipo == 2) {
			v[posicion].saldo += c[i].importe;
		} else {
			v[posicion].saldo -= c[i].importe;
		}
		
	}
	
}
void movimientos(int nrocliente,vector<movimiento> m,vector<cliente> v) {
	vector<movimiento> c;
	int persona = nrocliente;
	for(int i=0;i<m.size();i++) {  
		if(m[i].nrocuenta == nrocliente) {
			c.push_back(m[i]);
			cout << "Movimiento: " << m[i].tipo << " con importe de: " << m[i].importe;
		}
	}
	int pos;
	for(int i=0;i<v.size();i++) { 
		if(v[i].cuenta == nrocliente) 
			pos = i;
		break;
	}
	actualizar(c, pos, v);
	
}
int main() {
	int N;
	cin >> N;
	vector<cliente> v(N);
	
	for(int i=0;i<v.size();i++) { 
		cin >> v[i].cuenta;
		cin.ignore();
		getline(cin,v[i].nombre);
		cin >> v[i].saldo;
		cin >> v[i].descubierto;
	}
	vector<movimiento> m;
	int nrocuenta;
	int pos = 0;
	while(nrocuenta != 0) {
		m.resize(m.size()+1);
		cin >> m[pos].tipo;
		cin >> m[pos].importe;
		cin >> nrocuenta;
		m[pos].nrocuenta = nrocuenta;
		pos++;
		
	}
	for(int i=0;i<v.size();i++) { 
		movimientos(v[i].cuenta,m,v);
	}
	for(int i=0;i<v.size();i++) { 
		if(abs(v[i].saldo) > v[i].descubierto) {
			cout << "La cuenta de : " << v[i].nombre << " supera su maximo";
		}
	}
	
	
	return 0;
}

