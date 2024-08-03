// En una carrera de ciclismo por etapas, el ganador es el competidor que acumula menor
// cantidad de tiempo sumando sus tiempos de todas las etapas. Escriba un programa que permita ingresar la
// cantidad de competidores de una carrera de tres etapas y a continuación, por cada competidor, ingresar primero
// nombre y apellido, y luego los tres tiempos (uno por cada etapa). Cada tiempo se ingresa mediante dos enteros,
// que corresponden a minutos y segundos. El programa debe mostrar el nombre del ganador y su tiempo total en
// minutos y segundos. Advertencia: 40m 40s + 50m 50s no es 90m 90s, sino 91m 30s.

#include <iostream>
#include <vector>
using namespace std;
struct tiempo {
	int minutos;
	int segundos;
};
struct Competidor {
	string nombre;
	tiempo primer_etapa;
	tiempo segunda_etapa;
	tiempo tercer_etapa;
	tiempo tiempo_final;
};
void finales(vector<Competidor>& v) {
	for(size_t i=0;i<v.size();i++) { 
		v[i].tiempo_final.minutos = v[i].primer_etapa.minutos + v[i].segunda_etapa.minutos + v[i].tercer_etapa.minutos;
		v[i].tiempo_final.segundos = v[i].primer_etapa.segundos + v[i].segunda_etapa.segundos + v[i].tercer_etapa.segundos;
		
		if(v[i].tiempo_final.segundos >= 120) {
			v[i].tiempo_final.minutos = v[i].tiempo_final.minutos + 2; v[i].tiempo_final.segundos -= 120;
		} else if(v[i].tiempo_final.segundos >= 60) {
			v[i].tiempo_final.minutos = v[i].tiempo_final.minutos  +1; v[i].tiempo_final.segundos -= 60;
		}
	}
}
int main() {
	int N;
	cin >> N;
	vector<Competidor> v(N);
	
	for(size_t i=0;i<v.size();i++) { 
		cin.ignore();
		cout << "Nombre del competidor: ";getline(cin, v[i].nombre);
		cout << "\nTiempo Primera Etapa, Minutos: ";cin >> v[i].primer_etapa.minutos; cout << " segundos: "; cin >> v[i].primer_etapa.segundos;
		cout << "\nTiempo Segunda Etapa, Minutos: ";cin >> v[i].segunda_etapa.minutos; cout << " segundos: "; cin >> v[i].segunda_etapa.segundos;
		cout << "\nTiempo Tercer Etapa, Minutos: ";cin >> v[i].tercer_etapa.minutos; cout << " segundos: "; cin >> v[i].tercer_etapa.segundos; cout << "\n------\n";
		
	}
	finales(v);
	string ganador;
	int pos = 0;
	int minutos = 99999;
	int segundos = 999999;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].tiempo_final.minutos < minutos or (v[i].tiempo_final.minutos = minutos && v[i].tiempo_final.segundos < segundos)) {
			minutos = v[i].tiempo_final.minutos;
			segundos = v[i].tiempo_final.segundos;
			pos = i;
			ganador = v[i].nombre;
		}
		
	}
	cout << "El Ganador es: " << ganador << " con un tiempo de: " << minutos << "min y " << segundos << "s";
	return 0;
}

