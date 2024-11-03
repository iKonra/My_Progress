//	Ejercicio 3 [30 pts] Defina Carta (clase o struct) para representar a un naipe que tiene un número y un
//	palo. Diseñe una clase llamada Mazo que permita manejar los datos de un grupo de cartas. La clase
//	debe poseer métodos para: a) Guardar los datos de las cartas en un archivo binario. b) Cargar los datos
//	de los cartas desde un archivo binario. c) Agregar una nueva carta . d) Eliminar una carta indicando su
//	palo y número, e) retornar una carta dada su posición en el mazo. Tener en cuenta que no hay cartas
//	repetidas en el mazo.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Carta {
	string palo;
	int numero;
};
class Mazo {
	vector<Carta> cartas;
public:
	Mazo(string archivo) { CargarDatos(archivo);}
	void CargarDatos(string &archivo) {
		ifstream archi(archivo,ios::binary); 
		if(!archi) {
			throw runtime_error("Error al abrir el archivo.");
		}
		Carta carta;
		while (archi.read(reinterpret_cast<char*>(&carta), sizeof(Carta))) {
			cartas.push_back(carta);
		}
		archi.close();
	}
	void GuardarDatos() {
		fstream archi("cartas.dat",ios::binary|ios::out);
		for(Carta &x: cartas) {
			archi.write(reinterpret_cast<const char*>(&x), sizeof(Carta));
		}
	}
	bool AgregarCarta(int num_carta, string palo_carta) {
		for(auto &x : cartas) {
			if((x.palo == palo_carta) && (x.numero == num_carta)) {
				cout << "La carta ya esta en el mazo." << endl;
				return false;
			}
		}
		Carta Nueva;
		Nueva.palo = palo_carta; Nueva.numero = num_carta;
		cartas.push_back(Nueva);
		cout << "La carta se ha añadido correctamente " << endl;
		return true;
	}
	bool EliminarCarta(int num_carta, string palo_carta) {
		for (auto it = cartas.begin(); it != cartas.end(); ++it) {
			if (it->numero == num_carta && it->palo == palo_carta) {
				cartas.erase(it);
				cout << "La carta se borró correctamente." << endl;
				return true;
			}
		}
		cout << "No se encontró la carta y no se borró." << endl;
		return false;
	}
	Carta RetornarCarta(int posicion) {
		if (posicion >= 0 && posicion < cartas.size()) {
			return cartas[posicion];
		} else {
			throw out_of_range("La posición indicada está fuera del rango del mazo.");
		}
	}
	
};

int main() {
	string archivo = "cartas.dat";
	Mazo mazo(archivo);
	
	int opcion;
	do {
		cout << "\nOpciones:\n"
			<< "1. Agregar carta\n"
			<< "2. Eliminar carta\n"
			<< "3. Mostrar carta en una posición\n"
			<< "4. Guardar mazo\n"
			<< "0. Salir\n"
			<< "Elige una opción: ";
		cin >> opcion;
		
		switch(opcion) {
		case 1: {
			int numero;
			string palo;
			cout << "Escriba el numero y palo de la carta que quiere añadir: ";
			cin >> numero >> palo;
			mazo.AgregarCarta(numero, palo);
			break;
		}
		case 2: {
			int numero;
			string palo;
			cout << "Escriba el numero y palo de la carta que quiere eliminar: ";
			cin >> numero >> palo;
			mazo.EliminarCarta(numero, palo);
			break;
		}
		case 3: {
			int posicion;
			cout << "Ingrese la posición de la carta que desea ver: ";
			cin >> posicion;
			try {
				Carta carta = mazo.RetornarCarta(posicion);
				cout << "Carta en posición " << posicion << ": " << carta.numero << " de " << carta.palo << endl;
			} catch (const out_of_range& e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 4: {
			mazo.GuardarDatos();
			cout << "Datos guardados en el archivo." << endl;
			break;
		}
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción no válida." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}

