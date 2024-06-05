// Reescriba el "Program16" (determinar e informar los 1000 primeros números
// primos) utilizando una función auxiliar para determinar si un número es primo.

#include <iostream>
#include <cmath>
using namespace std;

bool esPrimo(int x);

int main(int argc, char *argv[]) {
	int cPrimos = 0;
	int Num = 2;
	int Averiguar;
	
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
	} while(cPrimos < 10);
	
	cout << "¿Que numero quiere averiguar si es primo?: "; cin >> Averiguar;cout << "\n";
	if(esPrimo(Averiguar) == true) {
		cout << "El numero es primo";
	} else {
		cout << "El numero no es primo";
	}
}
bool esPrimo(int x) {
	bool Primo = true;
	for(int i=2;i<=sqrt(x);i++) { 
		if(x%i == 0) 
			Primo = false;
 }return Primo;
}
