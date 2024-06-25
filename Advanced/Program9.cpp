// Ej 1(30pts) Un salón de videojuegos posee diferentes máquinas. Por cada máquina se conoce el nombre
// del juego, el precio de cada partida, el mejor puntaje, y el nombre del jugador que obtuvo ese puntaje.
// Cada cliente tiene una tarjeta, y cada tarjeta está asociada a un número de tarjeta, el nombre de un
// cliente, un saldo (cantidad de dinero precargado para jugar), una cantidad de créditos que acumula al
// jugar para luego canjear premios, y la fecha de la última vez que se usó. a) Defina un struct para guardar
// los datos de una máquina, y otro para los datos de una tarjeta. Luego implemente las siguientes funciones:
// b) comenzarJuego: que reciba un vector de máquinas, un vector de tarjetas, un nro de tarjeta, el nombre
// de un juego y la fecha actual: la función debe descontar el precio de la partida de la tarjeta del cliente y
// actualizar la fecha de último uso, solo si el cliente tiene suficiente dinero en la tarjeta. Debe retornar un
// bool indicando si puede o no.
// c) finalizarJuego: que reciba los dos vectores de datos, un nro de tarjeta, el nombre de un juego, el puntaje
// obtenido, y la cantidad de créditos para canje que ganó en la partida: la función debe actualizar, si
// corresponde, el mejor puntaje del juego y el nombre asociado, y sumar los créditos para canje en la
// tarjeta.
// d) recargarTarjeta: que reciba el vector de tarjetas, un nro de tarjeta, y un monto que debe sumar al dinero
// disponible en esa tarjeta. La función debe retornar el nuevo monto disponible.
// e) eliminarTarjetas: que reciba el vector de tarjetas y la fecha actual, y elimine del mismo todas las tarjetas
// que no o se hayan utilizado en los últimos 2 años.
// Nota: no debe implementar el programa cliente (main), solo las funciones.

#include <iostream>
using namespace std;

struct maquina {
	string nombre;
	float precio;
	int top;
	string nombretop;
};
struct tarjeta {
	int numero;
	string cliente;
	int saldo;
	int creditos;
	fecha tarjetafecha;
};
struct fecha {
	int dia;
	int mes;
	int anio;
};
bool comenzarJuego(vector<maquina> m,vector<tarjeta> t,int numtarjeta,string nombrejuego,fecha hoy) {
	
	int posjuego = 0;
	int postarjeta = 0;
	
	for(int i=0;i<m.size();i++) { 
		if(m[i].nombre == nombrejuego)
			posjuego = i;
	}
	for(int i=0;i<t.size();i++) { 
		if(t[i].numero == numtarjeta)
			postarjeta = i;
	}
	if(t[postarjeta].saldo > m[posjuego].precio) {
		t[postarjeta].saldo = (t[postarjeta].saldo - m[posjuego].precio);
		t[postarjeta].tarjetafecha.dia = hoy.dia;
		t[postarjeta].tarjetafecha.mes = hoy.mes;
		t[postarjeta].tarjetafecha.anio = hoy.anio;
		return true;
		
	}
	return false;
}
void finalizarJuego(vector<maquina> m,vector<tarjeta> t,int numtarjeta,string nombrejuego,int puntaje, int creditos) {
	int posjuego = 0;
	int postarjeta = 0;
	
	for(int i=0;i<m.size();i++) { 
		if(m[i].nombre == nombrejuego)
			posjuego = i;
	}
	for(int i=0;i<t.size();i++) { 
		if(t[i].numero == numtarjeta)
			postarjeta = i;
	}
	
	if(m[posjuego].top < puntaje) {
		m[posjuego].top = puntaje;
		m[posjuego].nombretop = t[postarjeta].cliente;
	}
	t[postarjeta].creditos += creditos;
	
	
}
int recargarTarjeta(vector<tarjeta> t,int numtarjeta,int monto) {
	
	int postarjeta = 0;
	for(int i=0;i<t.size();i++) { 
		if(t[i].numero == numtarjeta)
			postarjeta = i;
	}
	t[i].saldo += monto;
	
	return t[i].saldo;
	
}
void eliminarTarjetas(vector<tarjeta> t,fecha hoy) {
	
	
	for(int i=0;i<t.size();i++) {  
	if(((hoy.anio - t[i].fechatarjeta.anio) == 2) && (hoy.mes > t[i].fechatarjeta.mes) or (hoy.mes == t[i].fechatarjeta.mes) && (hoy.dia > t[i].fechatarjeta.dia) or ((hoy.anio - t[i].fechatarjeta.anio) > 2))
		for(int j=i;j<t.size();j++) { 
			t[j] = t[j+1];
	}
		t.resize(t.size()-1);
	}
}
int main() {
	
	return 0;
}

