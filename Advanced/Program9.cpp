//  Ej 1(30pts) Un salón de videojuegos posee diferentes máquinas. Por cada máquina se conoce el nombre
// del juego, el precio de cada partida, el mejor puntaje, y el nombre del jugador que obtuvo ese puntaje.
// ada cliente tiene una tarjeta, y cada tarjeta está asociada a un número de tarjeta, el nombre de un
// cliente, un saldo (cantidad de dinero precargado para jugar), una cantidad de créditos que acumula al
// jugar para luego canjear premios, y la fecha de la última vez que se usó. a) Defina un struct para guardar
// os datos de una máquina, y otro para los datos de una tarjeta. Luego implemente las siguientes funciones:
// ) comenzarJuego: que reciba un vector de máquinas, un vector de tarjetas, un nro de tarjeta, el nombre
// de un juego y la fecha actual: la función debe descontar el precio de la partida de la tarjeta del cliente y
// actualizar la fecha de último uso, solo si el cliente tiene suficiente dinero en la tarjeta. Debe retornar un
// bool indicando si puede o no.
//  finalizarJuego: que reciba los dos vectores de datos, un nro de tarjeta, el nombre de un juego, el puntaje
// obtenido, y la cantidad de créditos para canje que ganó en la partida: la función debe actualizar, si
// corresponde, el mejor puntaje del juego y el nombre asociado, y sumar los créditos para canje en la
// tarjeta.
// d) recargarTarjeta: que reciba el vector de tarjetas, un nro de tarjeta, y un monto que debe sumar al dinero
// disponible en esa tarjeta. La función debe retornar el nuevo monto disponible.
// e) eliminarTarjetas: que reciba el vector de tarjetas y la fecha actual, y elimine del mismo todas las tarjetas
// que no o se hayan utilizado en los últimos 2 años.
// Nota: no debe implementar el programa cliente (main), solo las funciones.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct fecha {
	int dia;
	int mes;
	int anio;
};

struct maquina {
	string nombre;
	float precio;
	int top;
	string nombretop;
};

struct tarjeta {
	int numero;
	string cliente;
	float saldo;
	int creditos;
	fecha tarjetafecha;
};

bool comenzarJuego(vector<maquina>& m, vector<tarjeta>& t, int numtarjeta, string nombrejuego, fecha hoy) {
	int posjuego = 0;
	int postarjeta = 0;
	
	for(int i = 0; i < m.size(); i++) { 
		if(m[i].nombre == nombrejuego)
			posjuego = i;
	}
	for(int i = 0; i < t.size(); i++) { 
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

void finalizarJuego(vector<maquina>& m, vector<tarjeta>& t, int numtarjeta, string nombrejuego, int puntaje, int creditos) {
	int posjuego = 0;
	int postarjeta = 0;
	
	for(int i = 0; i < m.size(); i++) { 
		if(m[i].nombre == nombrejuego)
			posjuego = i;
	}
	for(int i = 0; i < t.size(); i++) { 
		if(t[i].numero == numtarjeta)
			postarjeta = i;
	}
	
	if(m[posjuego].top < puntaje) {
		m[posjuego].top = puntaje;
		m[posjuego].nombretop = t[postarjeta].cliente;
	}
	t[postarjeta].creditos += creditos;
}

int recargarTarjeta(vector<tarjeta>& t, int numtarjeta, int monto) {
	int postarjeta = 0;
	for(int i = 0; i < t.size(); i++) { 
		if(t[i].numero == numtarjeta)
			postarjeta = i;
	}
	t[postarjeta].saldo += monto;
	
	return t[postarjeta].saldo;
}

void eliminarTarjetas(vector<tarjeta>& t, fecha hoy) {
	for(int i = 0; i < t.size(); i++) {  
		if(((hoy.anio - t[i].tarjetafecha.anio) == 2 && hoy.mes > t[i].tarjetafecha.mes) || 
			(hoy.anio - t[i].tarjetafecha.anio) == 2 && hoy.mes == t[i].tarjetafecha.mes && hoy.dia > t[i].tarjetafecha.dia || 
			(hoy.anio - t[i].tarjetafecha.anio) > 2) {
			for(int j = i; j < t.size() - 1; j++) { 
				t[j] = t[j + 1];
			}
			t.resize(t.size() - 1);
			i--;
		}
	}
}

int main() {
	vector<maquina> maquinas = {
		{"Pac-Man", 1.50, 5000, "Juan"},
	{"Space Invaders", 2.00, 7500, "Ana"},
		{"Tetris", 1.00, 6000, "Luis"},
	{"Street Fighter", 2.50, 8000, "Carlos"}
	};
	
	vector<tarjeta> tarjetas = {
		{12345, "Pedro", 10.00, 150, {15, 6, 2022}},
	{67890, "Maria", 5.00, 200, {10, 1, 2023}},
		{11121, "Jose", 20.00, 100, {20, 4, 2021}},
	{14151, "Lucia", 8.50, 50, {25, 12, 2020}}
	};
	
	fecha hoy = {24, 6, 2024};
	
	int opcion;
	do {
		cout << "1. Comenzar Juego" << endl;
		cout << "2. Finalizar Juego" << endl;
		cout << "3. Recargar Tarjeta" << endl;
		cout << "4. Eliminar Tarjetas" << endl;
		cout << "5. Salir" << endl;
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		if (opcion == 1) {
			int numtarjeta;
			string nombrejuego;
			cout << "Ingrese el número de tarjeta: ";
			cin >> numtarjeta;
			cout << "Ingrese el nombre del juego: ";
			cin >> nombrejuego;
			if (comenzarJuego(maquinas, tarjetas, numtarjeta, nombrejuego, hoy)) {
				cout << "Juego iniciado." << endl;
			} else {
				cout << "Saldo insuficiente." << endl;
			}
		} else if (opcion == 2) {
			int numtarjeta, puntaje, creditos;
			string nombrejuego;
			cout << "Ingrese el número de tarjeta: ";
			cin >> numtarjeta;
			cout << "Ingrese el nombre del juego: ";
			cin >> nombrejuego;
			cout << "Ingrese el puntaje obtenido: ";
			cin >> puntaje;
			cout << "Ingrese los créditos obtenidos: ";
			cin >> creditos;
			finalizarJuego(maquinas, tarjetas, numtarjeta, nombrejuego, puntaje, creditos);
			cout << "Juego finalizado." << endl;
		} else if (opcion == 3) {
			int numtarjeta, monto;
			cout << "Ingrese el número de tarjeta: ";
			cin >> numtarjeta;
			cout << "Ingrese el monto a recargar: ";
			cin >> monto;
			int nuevoSaldo = recargarTarjeta(tarjetas, numtarjeta, monto);
			cout << "Nuevo saldo: " << nuevoSaldo << endl;
		} else if (opcion == 4) {
			eliminarTarjetas(tarjetas, hoy);
			cout << "Tarjetas eliminadas." << endl;
		}
	} while (opcion != 5);
	
	return 0;
}
