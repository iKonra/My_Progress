// Ej2 (30 pts) El director del departamento de tránsito quiere analizar el cumplimiento de la ley en ciertas esquinas
// complicadas de la ciudad. Para ello, a cada hora registran la cantidad de pasos con semáforo en rojo en cada una.
// a) Escriba un programa que permita ingresar por cada una de las esquinas N (dato) de la ciudad, las 24 cantidades
// (una cant. por hora) de infracciones por paso en rojo. Organice estos datos en una matriz. b) Luego el programa
// debe informar cuál es la hora en que más pasos en rojo se registran (sumando todas las esquinas); c) cuál es la
// esquina en que más pasos en rojo se registran (sumando todo el día); y d) permitir ingresar una cantidad de pasos
//con semáforo en rojo y listar cuáles esquinas y a qué hora superan esa cantidad.

#include <matrix>
#include <iostream>
using namespace std;

int main() {
	int N;
	cout << "Cuantas esquinas va analizar: "; cin >> N;
	matrix<int> infra(N,24);
	int dato;
	for(int i=0;i<N;i++) { 
		cout << "\nEscriba las infracciones de la esquina " << i << "\n";
		for(int j=0;j<24;j++) { 
			cout << " - ";cin >> dato; cout << "\n";
			infra[i][j] = dato;
		}
	}
	int maximo = 0;
	int maxhora = 0;
	int contador = 0;
		for(int i=0;i<24;i++) { 
			for(int j=0;j<N;j++) { 
				contador += infra[j][i];
			}
		if(contador > maximo) {
				maxhora = i;
				maximo = contador;
			}
		contador = 0;
		}
		cout << "La hora con mas semaforos en rojo fue: " << maxhora << " con un total de: " << maximo << " infracciones";
	contador = 0;
	maximo = 0;
	int esquina;
	for(int i=0;i<N;i++) { 
		for(int j=0;j<24;j++) { 
			contador += infra[i][j];
		}
		if(contador > maximo) {
			maximo = contador;
			esquina = i;
		}
		contador = 0;
	}
	cout << "\nLa esquina con mas infracciones fue: " << esquina << " con un total de: " << maximo;
	int semaforos;
	cout << "Apartir de cuantos semaforos quiere averiguar: ";cin >> semaforos;
	for(int i=0;i<N;i++) { 
		for(int j=0;j<24;j++) { 
			if(infra[i][j] > semaforos) {
				cout << "\nLa esquina " << i << " supera la cantidad de " << semaforos << " semaforos a las " << j;
			}
		}
	}
	
	return 0;
}

