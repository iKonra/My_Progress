// Hacer un programa que determine e informe los primeros 1000 numeros primos
// Determinar si un numero N es primo

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	
	int cPrimos = 0;
	int Num = 2;
	
	do {
		bool Primo = true;
		for(int i=2;i<Num;++i) { 	
			if(Num%i == 0)
				Primo = false;
			break;
		}	
		if(Primo == true) {
			++cPrimos;
			cout << "Numero primo "<< cPrimos << ": " << Num << endl;
		}
		++Num;
	} while(cPrimos < 100);
	
	int Averiguar;
	bool esPrimo = true;
	cout << "¿Que numero quiere averiguar si es primo?: "; cin >> Averiguar;cout << "\n";
	for(int i=2;i<=sqrt(Averiguar);i++) { 
		if(Averiguar%i == 0)
			esPrimo = false;
	}
	if(esPrimo == true) {
		cout << "El numero " << Averiguar << " es primo";
	} else {
		cout << "El numero " << Averiguar << " no es primo";
	}
	
	return 0;
}

