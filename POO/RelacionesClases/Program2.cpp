//Ejercicio 2
//	Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase Curso que modele el cursado de
//	una materia. Cada curso tiene un nombre, un profesor a cargo y un numero maximo de alumnos. Implemente un
//	metodo AgregarAlumno(...) que permita agregar un alumno al curso (si es que no se lleg? al cupo), y otro metodo
//	MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los constructores y metodos extra que
//	considere necesarios
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona {
private:
	string apellido,nombre;
	fecha fechaNac;
public:
	Persona(string dnombre,string dapellido,fecha dfechaNac);
	int CalcularEdad(fecha hoy);
};

	//!Metodo EDAD ##########
	int Persona::CalcularEdad(fecha hoy) {
		int edad = (hoy.anio - fechaNac.anio);
		if((hoy.mes < fechaNac.mes) or (hoy.mes == fechaNac.mes and hoy.dia < fechaNac.dia)) {
			--edad;
		}
		return(edad);
	}
	//! ################

class Alumno : public Persona {
private:
	int suma,cantMaterias;
	float promedio;
public:
	Alumno(string nombre,string apellido,fecha fechaNac):Persona(nombre,apellido,fechaNac){cantMaterias = 0;promedio = 0;}
	void AgregarMateria(int nota);
	float CalcularMeritoAcademico();
};

	//!Metodo Agregar Materia ##########
	void Alumno::AgregarMateria(int nota) {
		++cantMaterias;
		suma += nota;
		promedio = suma/cantMaterias;
	}
	//! ################
class Docente : public Persona {
private:
	fecha Ingreso;
public:
	Docente(string nombre,string apellido,fecha fechaNac):Persona(nombre,apellido,fechaNac){}
	int CalcularAntiguedad(fecha hoy);
};

class Curso {
private:
	string m_nombre;
	Docente m_docente;
	vector<Alumno> v;
	int max_alumnos;
public:
	Curso(string d_nombre,Docente d_docente,int max) : m_nombre(d_nombre),m_docente(d_docente),max_alumnos(max){} 
	void AgregarAlumno(Alumno alumno);
	int MejorPromedio();
}
void AgregarAlumno(Alumno alumno) {
	v.pushback(alumno);
}
int Curso::MejorPromedio() {
	float prom = 0; int pos = 0;
	for(int i= 0;i<v.size();i++) {
		if(v[i].promedio > prom) {
			prom = v[i].promedio; pos = i;
		}
	}
	return i;
}

