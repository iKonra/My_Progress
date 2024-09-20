// Este código implementa una estructura de clases que modela personas, alumnos y docentes en un sistema educativo.
// a) Se define una clase base llamada Persona que contiene los atributos básicos: apellido, nombre y fecha de nacimiento,
// así como un método CalcularEdad para obtener la edad actual de la persona.
// b) Se extiende la clase Persona para crear una clase Alumno que añade los atributos de promedio y cantidad de materias aprobadas,
// además de los métodos AgregarMateria para actualizar los datos académicos y CalcularMeritoAcademico que retorna el mérito académico del alumno.
// c) Similarmente, se crea la clase Docente que también extiende de Persona, añadiendo la fecha de ingreso y un método 
// CalcularAntiguedad que calcula la antigüedad laboral del docente.
// d) Finalmente, un programa cliente crea instancias de Alumno y Docente, utilizando los métodos de cada clase para verificar su funcionamiento.

#include <iostream>
using namespace std;
struct fecha {
	int anio, mes, dia;
};
class Persona {
private:
	string apellido,nombre;
	fecha fechaNac;
public:
	Persona(string dnombre,string dapellido,fecha dfechaNac);
	int CalcularEdad(fecha hoy);
};
class Alumno : private Persona {
private:
	int suma = 0;
	float promedio = 0;
	int cantMaterias = 0;
public:
	Alumno(string nombre,string apellido,fecha fechaNac):Persona(nombre,apellido,fechaNac){cantMaterias = 0;promedio = 0;}
	void AgregarMateria(int nota);
	float CalcularMeritoAcademico();
	
};
Persona::Persona(string dnombre,string dapellido,fecha dfechaNac) {
	apellido = dapellido; fechaNac = dfechaNac;
}

int Persona::CalcularEdad(fecha hoy) {
	int edad = (hoy.anio - fechaNac.anio);
	if((hoy.mes < fechaNac.mes) or (hoy.mes == fechaNac.mes and hoy.dia < fechaNac.dia)) {
		--edad;
	}
	return(edad);
}


void Alumno::AgregarMateria(int nota) {
	++cantMaterias;
	suma += nota;
	promedio = suma/cantMaterias;
}

float Alumno::CalcularMeritoAcademico() {
	int merito = promedio*cantMaterias;
	return(merito);
}
class Docente : public Persona {
private:
	fecha Ingreso;
	int antiguedad;
public:
	Docente(string nombre,string apellido,fecha fechaNac):Persona(nombre,apellido,fechaNac){}
	void FechaIngreso(fecha d_ingreso);
	int CalcularAntiguedad(fecha hoy);
	
};

int Docente::CalcularAntiguedad(fecha hoy) {
	antiguedad = (hoy.anio - Ingreso.anio);
	if((hoy.mes < Ingreso.mes) or (hoy.mes == Ingreso.mes and hoy.dia < Ingreso.dia)) {
		--antiguedad;
	}
	return(antiguedad);
	
}
void Docente::FechaIngreso(fecha d_ingreso) {
	Ingreso.anio = d_ingreso.anio;
	Ingreso.mes = d_ingreso.mes;
	Ingreso.dia = d_ingreso.dia;
}
int main() {
	string dnombre,dapellido;
	fecha dNacimiento;
	cout << "Ingrese el nombre: ";cin >> dnombre;
	cout << "\nIngrese el apellido: "; cin >> dapellido ;
	cout << "\nIngrese la fecha de nacimiento: año - mes - dia ";cin >> dNacimiento.anio >> dNacimiento.mes >> dNacimiento.dia;
	Alumno A(dnombre,dapellido,dNacimiento);
	char respuesta;
	cout << "Quiere agregar una nota al alumno?: Y/N: "; cin >> respuesta;
	while(respuesta == 'Y' or respuesta == 'y') {
		int nota;
		cout << "Que nota tuvo en la materia el alumno: ";cin >> nota;
		A.AgregarMateria(nota);
		cout << "\nQuiere agregar una nota al alumno?: Y/N: "; cin >> respuesta;
	}
	float Merito = A.CalcularMeritoAcademico();
	cout << "\nEl merito del alumno fue: " << Merito;
	fecha hoy;
	cout << "\nIngrese la fecha de hoy anio - mes - dia : "; cin >>  hoy.anio >> hoy.mes >> hoy.dia;
	
	
	cout << "\n---------------------Datos del docente---------------------\n";
	cout << "\nIngrese el nombre: ";cin >> dnombre;
	cout << "\nIngrese el apellido: "; cin >> dapellido ;
	cout << "\nIngrese la fecha de nacimiento (Anio,Mes,Dia) : ";cin >> dNacimiento.anio >> dNacimiento.mes >> dNacimiento.dia;
	fecha d_ingreso;
	Docente D(dnombre,dapellido,dNacimiento);
	cout << "Ingrese el anio, mes y dia de ingreso: "; cin >> d_ingreso.anio >> d_ingreso.mes >> d_ingreso.dia;
	D.FechaIngreso(d_ingreso);
	int DocenteAntiguedad = D.CalcularAntiguedad(hoy);
	cout << "La antiguedad del docente es: " << DocenteAntiguedad << " años.";
	
	
	
	
	return 0;
}
