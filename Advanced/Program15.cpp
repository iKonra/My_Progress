// Ejercicio 2 (30 pts). Considere el struct postulante (string alumno; int cod, DNI, cant_aprob, cant_insuf float prom:)
// para organizar los datos de un grupo de N alumnos (N es dato) que se postulan a una beca. El miembro alumno se usará 
// para el apellido seguido del nombre, el miembro cod para un entero entre 1 y N. cant aprob es la cantidad de materias 
// aprobadas; cant insuf es la cantidad de insuficientes; prom el promedio de las materias aprobadas. a) Escriba una 
// programa C++ que lea los datos de los N alumnos los cuales deben organizarse en un vector v de tipo postulante. b) El 
// programa debe leer además los datos de una cantidad E de exámenes (E es dato) recientemente rendidos por el grupo. Por 
// cada uno se debe leer el código de alumno (entre 1 y N) y la nota obtenida. Se aprueba con 6 o más. Con estos datos se 
// debe modificar/actualizar el vector v, ya que puede cambiar la cantidad de notas aprobadas o la cantidad de insuficientes, 
// y cambiará el promedio de las materias aprobadas. c) La beca solo puede ser otorgada a alumnos con más de 20 materias 
// aprobadas y no más de 3 insuficientes. Escriba una función para generar un nuevo vector que contenga sólo aquellos 
// alumnos que cumplan este requisito. Informe en el programa cliente el % de alumnos que quedan fuera de la lista. d) 
// Determine a través de otra función los 2 alumnos con mejor promedio (entre los que cumplen los requisitos de c) e 
// informe sus datos (nombre, dni y promedio) en el programa principal. Ayuda: para actualizar el promedio: si un alumno 
// tiene promedio P y cantidad de materias aprobadas C, entonces la suma de sus notas por las materias aprobadas es P*C. 
// Al agregar una nueva nota N, el nuevo promedio será (P*C+N)/(C+1).


#include <iostream>
#include <vector>
using namespace std;

struct postulante {
	string alumno;
	int cod,DNI,cant_aprob,cant_insuf;
	float prom;
};
void becados(vector<postulante>& becas,vector<postulante> v) {
	int cont = 0;
	for(int i=0;i<v.size();i++) { 
		if(v[i].cant_aprob > 20 && v[i].cant_insuf <=3) {
			becas.resize(becas.size() + 1);
			becas[cont].alumno = v[i].alumno;
			becas[cont].cod = v[i].cod;
			becas[cont].DNI = v[i].DNI;
			becas[cont].cant_aprob = v[i].cant_aprob;
			becas[cont].cant_insuf = v[i].cant_insuf;
			becas[cont].prom = v[i].prom; 
			cont++;
			
		}
	}
	
}
void Actualizar(vector<postulante>& v,float nota, int codigo) {
	if(nota >= 6) {
		for(int i=0;i<v.size();i++) { 
			if(v[i].cod == codigo) {
				v[i].cant_aprob += 1;
				v[i].prom = (v[i].prom*v[i].cant_aprob+nota) / (v[i].cant_aprob+1); 
			}
		}
	} else {
		for(int i=0;i<v.size();i++) { 
			if(v[i].cod == codigo) {
				v[i].cant_insuf += 1;
				v[i].prom = (v[i].prom*v[i].cant_aprob+nota) / (v[i].cant_aprob+1); 
	}
}
	}
}
int main() {
	int N; cin >> N;
	vector<postulante> v(N);
	cin.ignore();
	for(int i=0;i<N;i++) { 
		getline(cin,v[i].alumno);
		cin >> v[i].cod;
		cin >> v[i].DNI;
		cin >> v[i].cant_aprob;
		cin >> v[i].cant_insuf;
		cin >> v[i].prom;
		cin.ignore();
	}
	int E;cin >> E;
	float nota; int codigo;
	for(int i=0;i<E;i++) { 
		cin >> codigo;
		cin >> nota;
		
		Actualizar(v,nota,codigo);
	}
	vector<postulante> becas(1);
	becados(becas,v);
	
	for(int i=0;i<becas.size();i++) { 
		cout << becas[i].alumno << "\n";
	}
	cout << "En total un " << ((v.size()-becas.size()) / v.size()) * 100 << "% de alumnos quedaron afuera de la beca";
	return 0;
}

