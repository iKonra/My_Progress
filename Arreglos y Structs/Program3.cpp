// Leer los nombres y calificaciones de un grupo de alumnos que asistieron a una
//	evaluación de programación. Los datos finalizan con la calificación 0. Generar un
//	vector con los nombres de los alumnos aprobados (calificación>=6) y otro con los
//	nombres de los no aprobados. Mostrar luego ambos vectores.
	

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int calif;
	int n1 = 0;
	int n2 = 0;
	int  cont = 0;
	
	vector<int> aprobados(0);
	vector<int> noaprobados(0);
	cout << "Cual es la califacion del alumno 1: "; cin >> calif;
	while(calif != 0) {
		if(calif >=6) {
			cont += 1;
			n1 += 1;
				aprobados.push_back(cont);
			cout << "Se añadio un alumno a la lista de aprobados que ya tiene " << aprobados.size() << " alumnos";
			cout << "\n Cual es la califacion del alumno " << cont+1 << ":  "; cin >> calif;
			
		} else {
			cont += 1;
			n2 += 1;
			noaprobados.push_back(cont);
			cout << "Se añadio un alumno a la lista de no aprobados que ya tiene " << noaprobados.size() << " alumnos";
			cout << "\n Cual es la califacion del alumno " << cont+1 << ":  "; cin >> calif;
			
		}
	};
	cout << "La lista de aprobados es: \n";
	for(int i=0;i<n1;i++) { 
		cout << aprobados[i] << " ";
	}
	cout << "\n La lista de no aprobados es: \n";
		for(int i=0;i<n2;i++) { 
		cout << noaprobados[i] << " ";
	}
	
	
	return 0;
}

