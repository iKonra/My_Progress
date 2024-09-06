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
	int suma;
	float promedio;
	int cantMaterias;
public:
	Alumno(string nombre,string apellido,fecha fechaNac):Persona(nombre,apellido,fechaNac){cantMaterias = 0;promedio = 0;}
	void AgregarMateria(int nota);
	float CalcularMeritoAcademico();
	
};
class Docente : public Persona {
private:
	fecha Ingreso;
public:
	Docente(string nombre,string apellido,fecha fechaNac):Persona(nombre,apellido,fechaNac){}
	int CalcularAntiguedad(fecha hoy);

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


int Docente::CalcularAntiguedad(fecha hoy) {
	int antiguedad = (hoy.anio - Ingreso.anio);
	if((hoy.mes < Ingreso.mes) or (hoy.mes == Ingreso.mes and hoy.dia < Ingreso.dia)) {
		--antiguedad;
	}
	return(antiguedad);
	
}

int main() {
	string dnombre,dapellido;
	fecha dNacimiento;
	cout << "Ingrese el nombre: ";cin >> dnombre;
	cout << "\nIngrese el apellido: "; cin >> dapellido ;
	cout << "\nIngrese la fecha de nacimiento: ";cin >> dNacimiento.anio >> dNacimiento.mes >> dNacimiento.dia;
	Alumno A(dnombre,dapellido,dNacimiento);
	char respuesta;
	cin >> respuesta;
	while(respuesta == 'Y' or respuesta == 'y') {
		int nota;
		cout << "Que nota tuvo en la materia el alumno: ";cin >> nota;
		A.AgregarMateria(nota);
		cin >> respuesta;
	}
	float Merito = A.CalcularMeritoAcademico();
	cout << "El merito del alumno fue:" << Merito;
	fecha hoy;
	cout << "Ingrese la fecha de hoy: "; cin >>  hoy.anio >> hoy.mes >> hoy.dia;
	
	
	cout << "---------------------\nDatos del docente\n---------------------";
	cout << "Ingrese el nombre: ";cin >> dnombre;
	cout << "\nIngrese el apellido: "; cin >> dapellido ;
	cout << "\nIngrese la fecha de nacimiento (Año,Mes,Dia) : ";cin >> dNacimiento.anio >> dNacimiento.mes >> dNacimiento.dia;
	fecha dingreso;
	Docente D(dnombre,dapellido,dNacimiento);
	cout << "Ingrese el año, mes y dia de ingreso: "; cin >> dingreso.anio >> dingreso.mes >> dingreso.dia;
	int DocenteAntiguedad = D.CalcularAntiguedad(hoy);
	cout << "La antiguedad del docente es: " << DocenteAntiguedad;
	
	
	
	
	return 0;
}

