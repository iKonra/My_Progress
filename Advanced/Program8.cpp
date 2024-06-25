//  a) Escriba un programa C++ que lea los presupuestos anuales asignados a 10 hospitales de
// una provincia al inicio del año 2023 destinado a insumos. Estos datos se leen de a pares: cod hospital
// (1..10), monto del presupuesto anual. Luego se deben ingresar los 4 datos de cada gasto efectuado por
// cada hospital en el año: cod. hospital (1..10), dia (1..31), mes (1..12), monto.. Estos datos terminan con
// cod. hospital cero. El programa debe organizar una matriz de 10 filas (hospitales) por 12 columnas
// (meses) donde se indiquen en cada celda los montos por gastos de cada hospital en cada mes del año
// 2023. Considere que en un mismo mes un mismo hospital puede realizar varios gastos por mes. Luego el
// programa de informar: b) Cuáles hospitales terminaron con déficit al finalizar el año (mayores gastos que
// el presupuesto anual); c) Por cada mes, cuántos hospitales tuvieron un gasto mayor al mes anterior; d) El
// mes y monto de mayor gasto de un hospital que el usuario ingresa como dato.
//Nota: para los puntos c) y d) debe utilizar funciones.

#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

int MesAnterior(matrix<int> m,int mes);
pair<int,int> MayorGasto(matrix<int> m,int cod);
int main() {
	int CodHospital,presupuesto;
	int dia,mes,monto;
	vector<int> presupuestos(10);
	for(int i=0;i<10;i++) {
		cout << "Cual es el presupuesto del hospital " << i+1 << "?: ";cin >> presupuesto;
		presupuestos[i] = presupuesto;
		cout << endl;
	}
	matrix<int> m(10,12);
	vector<int> GastosT(10, 0);
		cout << "\nCual es el codigo del hospital que quiere cargar: ";cin >> CodHospital;
		while(CodHospital != 0) {
			cout << "\nQue dia fue: ";cin >> dia;
			cout << "\nQue mes: ";cin >> mes;
			cout << "\nCual fue el monto que se gasto: ";cin >> monto;
			
			m[CodHospital-1][mes-1] += monto;
			GastosT[CodHospital-1] += monto;
			
			cout << "\nCual es el codigo del hospital que quiere cargar, 0 para terminar: ";cin >> CodHospital;
		} 
		cout << "Los hospitales ";
	for(int i=0;i<10;i++) { 
			if(GastosT[i] > presupuestos[i]) {
				cout << i+1 << " ";
			}
		}
	cout << " tuvieron deficit" << endl;
	
	cout << "Que mes quiere averiguar: ";cin >> mes;
	int cant = MesAnterior(m,mes-1);
	cout << "\nUna cantidad de " << cant << " hospitales gastaron mas que el mes pasado";
	
	cout << "\nQue hospital quiere averiguar: ";cin >> CodHospital;
	pair<int,int> p = MayorGasto(m,CodHospital);
	cout << "\nEl hospital " << CodHospital << " tuvo su mayor gasto en el mes " << p.second+1 << " con un gasto de: " << p.first;
	return 0;
}
int MesAnterior(matrix<int> m,int mes)  {
	int contador = 0;
	for(int i=0;i<10;i++) { 
		if(m[i][mes] > m[i][mes-1]) 
			contador += 1;
	}
	return contador;
}
pair<int,int> MayorGasto(matrix<int> m,int cod) {

	pair<int,int> p;
	int mayor = 0;
	int pos = 0;
	for(int i=0;i<12;i++) { 
		if(m[cod][i] > mayor) {
			mayor = m[cod][i];
			pos = i;
		}
	}
	p.first = mayor;
	p.second = pos;
	return p;
}
