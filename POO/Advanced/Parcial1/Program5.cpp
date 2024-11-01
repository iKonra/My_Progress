//a) En la clase Alumno: ya están completos los datos o atributos; proponga un constructor para iniciar sus datos: nombre,
//	DNI y nota_final; un método para determinar la condición: 'R' o 'L' ('R' es Regular si nota_final>=4, 'L' es Libre si
//	nota_final<4) y otros métodos que considere necesarios o adecuados para consultar los datos de la clase.
//	b) Proponga una clase Materia, que reutilice la clase Alumno mediante la relación que considere más adecuada. La clase
//	Materia debe permitir definir el nombre de la materia, el nombre del profesor, y registrar varios alumnos. Proponga un
//	constructor, y métodos para obtener la cantidad de regulares y de libres; y otros métodos que crea necesarios.
//	Solo proponga las clases y codifique sus métodos (no hacer programa cliente).


#include <iostream>
#include <vector>
using namespace std;

class Alumno {
	string nombre;
	int DNI, nota_final;
	char condicion;
public:
	Alumno(string m_nombre,int m_dni,int m_notafinal) : nombre(m_nombre),DNI(m_dni),nota_final(m_notafinal){}
	char Condicion() {
		if(nota_final  >= 4) {
			condicion = 'R';
		}
		else {
			condicion = 'L';
		}
		return condicion;
	}
	string VerNombre() {return nombre;}
};
class Materia {
	string nombre,profesor;
	vector<Alumno> alumnos;
	int regulares = 0,libres = 0;
public:
	Materia(string m_nombre,string m_profesor,vector<Alumno> m_alumnos):nombre(m_nombre),profesor(m_profesor),alumnos(m_alumnos){}
	void CalcularCondiciones() {
		for(size_t i=0;i<alumnos.size();i++) { 
			if(alumnos[i].Condicion() == 'R') {
				regulares++;
			} else {
				libres++;
			}
	}
	}
	int Regulares() {return regulares;}
	int Libres() {return libres;}
	
};
int main() {
	Alumno a1("Juan", 12345678, 7);  // Regular
	Alumno a2("Maria", 87654321, 3); // Libre
	Alumno a3("Pedro", 23456789, 5); // Regular
	Alumno a4("Ana", 98765432, 2);   // Libre
	
	// Lista de alumnos
	vector<Alumno> lista_alumnos = {a1, a2, a3, a4};
	
	Materia matematicas("Matemáticas", "Profesor Pérez", lista_alumnos);
	matematicas.CalcularCondiciones();
	
	// Mostrar resultados
	cout << "Cantidad de alumnos regulares: " << matematicas.Regulares() << endl;
	cout << "Cantidad de alumnos libres: " << matematicas.Libres() << endl;
	return 0;
}

