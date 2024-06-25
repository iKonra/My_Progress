// Una materia tiene 4 evaluaciones codificadas: 1 (parcial 1),2 (recup. parcial 1),3 (parcial 2),4 (recup.
// parcial 2). El Profesor responsable de la materia -en la que hay muchos docentes- quiere saber quién corrigió cada
// parcial o recuperatorio de su materia. a) Escriba un programa que permita ingresar la cantidad de alumnos de la
// materia (N), y luego ternas de datos: nro de alumno (1 a N), nro de evaluación (1 a 4), y nombre del docente que lo
// corrigió. Los datos finalizan con el nro de alumno -1 (porque no todos los alumnos rindieron las 4 instancias).
// Organice estos datos en una matriz de N filas x 4 columnas, donde cada casillero contenga el nombre del docente
// que corrigió un parcial/recuperatorio, o la cadena "No rindió" si el alumno no se presentó a esa evaluación. b) El
// programa debe luego informar cuántos alumnos rindieron cada evaluación; c) mostrar la lista de alumnos que no
// rindieron ninguna de las (4) instancias; y d) permitir al usuario ingresar el nombre de un docente y mostrar cuántos
// parciales/recuperatorios corrigió ese docente.

#include <iostream>
#include <matrix>
using namespace std;

int main() {
	int N;
	int eval;
	int alumno;
	string docente;
	cout << "Cuantos alumnos hay: ";cin >> N;
	matrix<string> calif(N+1,4,"No Rindio");
	cout << "\nQue alumno va a cargar: "; cin >> alumno;
	while(alumno != -1) {
		cout << "\nQue Evaluacion va a calificar (1,2,3,4): ";cin >> eval;
		cout << "\nQue profesor corrigio: ";cin >> docente;
		
		calif[alumno-1][eval-1] = docente;
		
		cout <<"\nQue alumno va a cargar? -1 para terminar: ";cin >> alumno;
	}
	for(int i=0;i<N;i++) { 
		cout << "\nLas evaluaciones del alumno " << i+1 << " fueron corregidas por:";
			for(int j=0;j<4;j++) { 
			cout << "\n" << j+1 <<") " << calif[i][j];
		}
	}
	int contador = 0;
	cout << "\nCantidad de evaluacion realizadas: \n";
	for(int i=0;i<4;i++) {
		for(int j=0;j<N;j++) { 
			if(calif[j][i] != "No Rindio") {
				contador +=1;
			}
		}
		cout << "El parcial " << i+1 << " fue hecho por " << contador << " estudiantes\n";
		contador = 0;
	}
	for(int i=0;i<N;i++) { 
		contador = 0;
		for(int j=0;j<4;j++) { 
			if(calif[i][j] == "No Rindio") {
				contador += 1;
			}
		}
			if(contador == 4) {
				cout << "El alumno " << i+1 << " no realizo ninguna evaluacion.\n";
		}
	}
	contador = 0;
	cout << "Que docente quiere averiguar: ";cin >> docente;
	for(int i=0;i<N;i++) { 
		for(int j=0;j<4;j++) { 
			if(calif[i][j] == docente)
				contador += 1;
		}
	}
	cout << "\nEl docente: " << docente << " corrigio un total de " << contador << " evaluaciones.";
	return 0;
}

