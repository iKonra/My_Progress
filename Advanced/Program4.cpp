// Una empresa de colectivos urbanos quiere analizar la utilización de sus colectivos. Se registran los kms
// que hace cada colectivo y la cantidad de pasajeros que suben y bajan durante una semana. a) Escriba un programa
// que permita ingresar por cada una de los N (dato inicial) colectivos, 3 valores: patente, cantidad de kms, cantidad de
// pasajeros que subieron; y guarde toda esta información en un único vector. Luego el programa debe informar: b) Las
// patentes de los dos colectivos que menos pasajeros trasladaron; c) El promedio de kms recorridos entre todos los
// colectivos; d) La cantidad de colectivos que superan por 500 km recorrido al promedio. Importante: Resuelva (a) (b)
// y (c) implementando una función para cada ítem, que calcule lo que hay que informar desde el programa principal
// main.
			

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

struct Datos {
	int km,pasajeros;
	string patente;
};
void cargar(vector <Datos>& cole,int &N);
pair<string,string> Menores(vector<Datos> cole, int N);
float prom(vector <Datos> cole);


int main(int argc, char *argv[]) {
	
	int N;
	vector<Datos> cole(N);
	cargar(cole,N);
	int promedio = prom(cole);
	cout << "El promedio entre todas las lineas fue de : " << promedio << endl;
	pair<string,string> p;
	p = Menores(cole, N);
	cout << "Los dos colectivos con menos pasajeros fueron: " << p.first << " y " << p.second << endl;
	
	int contador = 0;
	cout << "La lista de colectivos con mas de 500km son: \n";
	for(int i=0;i<N;i++) { 
		if(cole[i].km > promedio+500) {
			contador += 1;
			cout << " - " << cole[i].patente << " con " << cole[i].km;
		}
	}
	cout << "\nQue suman un total de " << contador << " colectivos.";
	
	return 0;
}
void cargar(vector <Datos>& cole,int &N) {
	cout << "¿Cuantos colectivos va a cargar? ";cin >> N;
	for(int i=0;i<N;i++) { 
		cout << "Cual es la patente: "; cin >> cole[i].patente;
		cout << "\nCuantos KM recorrio: ";cin >> cole[i].km;
		cout << "\nCuantos pasajeros: ";cin >> cole[i].pasajeros;
	}
}
pair<string,string> Menores(vector <Datos> cole, int N) {
	string patentem1 = "None1";
	string patentem2 = "None2";
	int MinKm1 = 20000000;
	int MinKm2 = 20000000;
	pair<string, string> d;
	for (int i = 0; i < N; i++) {
		if (cole[i].pasajeros < MinKm1) { 
			MinKm2 = MinKm1;
			patentem2 = patentem1;
			MinKm1 = cole[i].pasajeros;
			patentem1 = cole[i].patente;
		} else if (cole[i].pasajeros < MinKm2) { 
			MinKm2 = cole[i].pasajeros;
			patentem2 = cole[i].patente;
		}
	}
	d.first = patentem1; 
	d.second = patentem2;
	return d;
	
}
float prom(vector <Datos> cole) {
	int promedio = 0;
	for(int i=0;i<cole.size();i++) { 
		promedio += cole[i].km;
	}
	promedio = promedio/cole.size();
	return promedio;
}
