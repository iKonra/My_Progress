// a) Defina un struct equipoF1{..} para guardar los datos de un equipo de Fórmula 1 que tiene 4
//	miembros: nombre del equipo, nombre piloto titular 1, nombre piloto titular 2, nombre piloto de reserva. b) Escriba
//	una función sustituir_piloto(..) que reciba un vector de tipo equipoF1 y el nombre de un piloto titular de uno de los
//	equipos. La función debe buscar en el vector al piloto por su nombre e intercambiarlo (nombre y nro) por el piloto de
//	reserva de ese mismo equipo. La función debe retornar el vector de equipos con la modificación realizada, o la
//	cadena "no encontrado" en caso de que no encuentre al piloto a reemplazar dentro de la lista. c) Escriba un
//	programa cliente para probar la función: que permita cargar una lista de equipos, sustituir un piloto que elija el
//	usuario, y mostrar la nueva lista (o un mensaje de error si la sustitución no se realiza).

#include <iostream>
#include <vector>
using namespace std;
struct equipoF1{
	string Equipo,Titular1,Titular2,Reserva;
};
bool sustituir_piloto(vector<equipoF1>& equipo, string nombre);

int main() {
	string nombre;
	
	vector<equipoF1> vec = {
		{"Mercedes", "Lewis Hamilton", "Valtteri Bottas", "George Russell"},
		{"Test1","Test2","Test3","Test4"},
		{"Red Bull Racing", "Max Verstappen", "Sergio Perez", "Alex Albon"},
		{"Ferrari", "Charles Leclerc", "Carlos Sainz", "Antonio Giovinazzi"},
		{"McLaren", "Lando Norris", "Daniel Ricciardo", "Stoffel Vandoorne"},
		{"Aston Martin", "Sebastian Vettel", "Lance Stroll", "Nico Hülkenberg"}
	};
	
	
	cout << "Ingrese el nombre: "; getline(cin, nombre); cout << "\n";
		
	if((sustituir_piloto(vec , nombre)) == true) {
		for(unsigned int i=0;i<vec.size();i++) { 
			cout << "Equipo: " << vec[i].Equipo << endl;
			cout << "Titular: " << vec[i].Titular1 << "\nTitular 2:" << vec[i].Titular2 <<  endl;
			cout << "Reserva: " << vec[i].Reserva << "\n\n";
		} 
	} else 
	   cout << "No encontrado";
	
	return 0;
}
bool sustituir_piloto(vector<equipoF1>& equipo, string nombre) {
	for(unsigned int i=0;i<equipo.size();i++) { 
		if(equipo[i].Titular1 == nombre) {
			equipo[i].Titular1 = equipo[i].Reserva;
			equipo[i].Reserva = nombre;
			
		return true;
		}
	}
	return false;
}