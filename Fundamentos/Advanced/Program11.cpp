#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Evento {
	string tipo;
	int jugador;
};

void resumen_partido(vector<Evento>& eventos, int jugador) {
	int ace = 0, errorNoForzado = 0, tiroGanador = 0, dobleFalta = 0;
	
	for (const auto& evento : eventos) {
		if (evento.jugador == jugador) {
			if (evento.tipo == "ace") { ace++; }
			else if (evento.tipo == "error no forzado") { errorNoForzado++; }
			else if (evento.tipo == "tiro ganador") { tiroGanador++; }
			else if (evento.tipo == "doble falta") { dobleFalta++; }
		}
	}
	
	cout << "Jugador " << jugador << ":\n"
		<< ace << " aces, " 
		<< errorNoForzado << " errores no forzados, "
		<< tiroGanador << " tiros ganadores, "
		<< dobleFalta << " doble faltas\n";
}

int main() {
	vector<Evento> eventos;
	string tipoEvento;
	int jugador;
	
	while (true) {
		cout << "Que evento ocurrio? (ace, error no forzado, tiro ganador, doble falta) - 0 para terminar: ";
		getline(cin, tipoEvento);
		if (tipoEvento == "0") break;
		
		cout << "A que jugador? (1 o 2) - 0 para cancelar: ";
		cin >> jugador;
		if (jugador == 0) break;
		
		cin.ignore();  // Ignorar el salto de línea que queda en el buffer
		
		eventos.push_back({tipoEvento, jugador});
	}
	
	cout << "El resumen del jugador 1 es:\n";
	resumen_partido(eventos, 1);
	cout << "El resumen del jugador 2 es:\n";
	resumen_partido(eventos, 2);
	
	return 0;
}
