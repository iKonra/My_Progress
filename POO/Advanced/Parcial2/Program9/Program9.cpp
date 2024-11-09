//	Ejercicio 1 [25 pts] Se dispone de un archivo de textos EQUIPO.TXT donde cada línea contiene el
//	DNI, apellido y nombre correspondiente a un grupo de trabajo. Por persona hay un solo nombre y
//	apellido y están separados por un espacio en blanco. Escriba una clase que posea entre sus métodos: a)
//	la función GeneraEmail( ), encargada de formar la dirección de correo electrónico de cada empleado
//	del archivo, colocando la inicial del primer nombre y el apellido, seguido de @gmail.com y otra
//	funcion CreaBinario( ) que genere un archivo binario que contenga los datos referentes al nombre,
//	apellido, dni y email de cada persona. Programa los métodos adicionales que considere necesarios.

#include <iostream>
#include <fstream>
using namespace std;

struct empleado {
	int DNI;
	string apellido;
	string nombre;
	string email;
	
};

class Equipo {
	vector<empleado> vec;
public:
	Equipo(string archivo) {
		ifstream archi(archivo);
			if(!archi) throw runtime_error("error al abrir el archivo");
		
		empleado aux;
		while(archi >> aux.DNI >> aux.apellido >> aux.nombre) {
			vec.push_back(aux);
		}
		
	}
	void GeneraEmail() {
		string gmail;
		for(int i=0;i<vec.size();i++) { 
			vec[i].email = vec[i].nombre[0] + vec[i].apellido + "@gmail.com";
		}
		
	}
	void CrearBinario(string archivo) {
		ofstream archi(archivo,ios::binary);
			if(!archi) throw runtime_error ("error al crear el archivo.");
		
		for(size_t i=0;i<vec.size();i++) { 
			
			char aux1[256];
			char aux2[256];
			char aux3[256];
			strcpy(aux1,vec[i].apellido.c_str());
			strcpy(aux2,vec[i].nombre.c_str());
			strcpy(aux3,vec[i].email.c_str());
				archi.write(reinterpret_cast<char*>(&vec[i].DNI),sizeof(vec[i].DNI));
				archi.write(reinterpret_cast<char*>(&aux1),sizeof(aux1));
				archi.write(reinterpret_cast<char*>(&aux2),sizeof(aux2));
				archi.write(reinterpret_cast<char*>(&aux3),sizeof(aux3));
		
			
			
		}
	}
};

int main() {
	
	return 0;
}

