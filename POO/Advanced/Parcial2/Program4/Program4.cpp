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
class SinNombre {
	string apellido;
	string gmail;
	string nombre;
	int DNI;
	
public:
	SinNombre(string m_apellido,string m_nombre,int m_DNI): apellido(m_apellido),nombre(m_nombre),DNI(m_DNI) {}
	
	void GeneraEmail() {
		char inicial = nombre[0];
		gmail = inicial + apellido + "@gmail.com";
	}
	void CreaBinario() {
		ofstream archi("binario.dat", ios::binary);
		size_t sizeNombre = nombre.size(); size_t sizeApellido = apellido.size();
		size_t sizeGmail = gmail.size(); 
		
		archi.write(reinterpret_cast<const char*>(&sizeNombre), sizeof(sizeNombre));
		archi.write(nombre.c_str(), sizeNombre);
		archi.write(reinterpret_cast<const char*>(&sizeApellido), sizeof(sizeApellido));
		archi.write(apellido.c_str(), sizeApellido);
		archi.write(reinterpret_cast<const char*>(&DNI), sizeof(DNI));
		
		archi.write(reinterpret_cast<const char*>(&sizeGmail), sizeof(sizeGmail));
		archi.write(nombre.c_str(), sizeGmail);
	}
	string VerGmail() {return gmail;}
	string VerNombre() {return nombre;}
	string VerApellido() {return apellido;}
	int VerDNI() {return DNI;}
	
};


int main() {
	ifstream archivoTexto("EQUIPO.TXT");  // Abrir el archivo de texto para lectura
	if (!archivoTexto) {
		cerr << "Error al abrir el archivo EQUIPO.TXT" << endl;
		return 1;  // Salir si no se puede abrir el archivo
	}
	
	string linea;
	while (getline(archivoTexto, linea)) {  // Leer el archivo línea por línea
		if (linea.empty()) continue;  // Saltar líneas vacías
		int dni;
		string apellido, nombre;
		
		archivoTexto >> dni >> apellido >> nombre;  // Asumimos que el formato es correcto y que hay un solo espacio
		
		// Crear un objeto SinNombre
		SinNombre empleado(apellido, nombre, dni);
		
	}
	
	// Cerrar el archivo
	archivoTexto.close();
	
	return 0;
}


