// Escriba una función que permita calcular la diferencia en años entre dos fechas
// con formato aaaammdd y utilícela desde un programa cliente

#include <iostream>
using namespace std;

int Diferencia(int fecha1,int fecha2);

int main(int argc, char *argv[]) {
	
	int Fecha1, Fecha2;
	
	cout << "Digite la primer fecha en formato aaaammdd "; cin >> Fecha1; cout << "\n";
	cout << "Digite la segunda fecha en formato aaaammdd "; cin >> Fecha2; cout << "\n";
	
	cout << "La diferencia en años entre estas 2 fechas es: " << Diferencia(Fecha1,Fecha2);
	return 0;
}
int Diferencia(int fecha1, int fecha2) { 
	
	int dia1 = fecha1 % 100; int dia2 = fecha2 % 100;
	int mes1 = (fecha1 % 10000) / 100; int mes2 = (fecha2 % 10000) / 100;
	int year1 = fecha1 / 10000; int year2 = fecha2 / 10000;
	
	int Calculo = year2 - year1;
	if(mes2 < mes1 || (mes2 == mes1 && dia2 < dia1)) {
		--Calculo;
	}
		return Calculo;
} 


