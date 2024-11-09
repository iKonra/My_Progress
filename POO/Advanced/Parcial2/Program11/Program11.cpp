//	Ej 2 (30pts) a) Escriba un programa C++ que lea un archivo de texto "inscriptos.txt" con los nombres de los
//	inscriptos a un sorteo (hay uno por línea). b) Solo se admite el formato "Apellido, Nombre", pero se sabe que
//	hay datos mal cargados. Si una línea no tiene apellido y nombre separados por coma (por ej: "Juan Alberto
//	Perez") deberá corregirse asumiendo que el apellido es la última palabra (el ejemplo debería quedar "Perez,
//	Juan Alberto"). c) Luego deberá eliminar los datos repetidos (dejando solamente uno de cada uno) ya que
//	hubo personas que se anotaron varias veces. d) Finalmente actualice el archivo guardando los nuevos datos
//	(solo los válidos, y sin repetidos) agregando además un número de línea/participante antes de cada uno.
//	

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct Inscripto {
	int numero;
	string nombre;
	
	bool operator==(string b) {
		return(this->nombre == b);
	}
	
};


int main() {
	
	ifstream archi("inscriptos.txt");
	string linea;
	vector<Inscripto> vec;
	vector<Inscripto> InscriptosFinal;
	
	while(getline(archi,linea)) {
		Inscripto aux;
		if(linea.find(",") == string::npos) {
			int pos = linea.find_last_of(" ");
			aux.nombre = linea.substr(pos+1,linea.size()) + "," + linea.substr(0,pos);
			vec.push_back(aux);
		} else {
			Inscripto aux;
			int pos = linea.find(",");
			aux.nombre = linea.substr(pos,linea.size()) + "," + linea.substr(0,pos);
			vec.push_back(aux);
		}
	}
	archi.close();
	int cont = 1;
	for(auto &x : vec) {
		if(find(InscriptosFinal.begin(),InscriptosFinal.end(),x.nombre) == InscriptosFinal.end()) {
			Inscripto aux;
			aux.nombre = x.nombre;
			aux.numero = cont;
			InscriptosFinal.push_back(aux);
			cont++;
		}
	}
	
	ofstream archi2("inscriptosactualizado.txt");
		
	for(auto &x : InscriptosFinal) {
		
		archi2 << x.numero << " " << x.nombre << endl;
		
	}
	
	return 0;
}

