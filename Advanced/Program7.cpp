// Ejercicio 1 (30pts.) En una competencia de programación se han presentado 24 equipos
// de diferentes universidades (codificados 1...24) que deben resolver 7 problemas en el
// menor tiempo posible. No todos los equipos llegan a completas los problemas, dejando
// algunos sin resolver. Resulta triunfador el equipo que más problemas resuelve, en
// caso de empate en la cantidad de problemas gana el equipo que empleo menos tiempo en
// total. Escriba un programa C++ que ingrese como datos: cod. Universidad (1...24), cod.
// Problema (1...7), tiempo empleado en minutos. Estos datos terminan con cod. Universidad
// cero (solo se leen los datos de problemas resueltos). El programa debe generar un
// conjunto de funciones que permitan determinar:
// a) Los códigos de los 2 equipos que ocuparon el primer y segundo puesto.
// b) El problema que mayor dificultad causó en la competencia (mayor tiempo total,
// considerando todos los equipos y considerando solo los resueltos).

#include <iostream>
#include <matrix>
using namespace std;

pair<int,int> Ganadores(matrix<int> resultados);
int Dificil(matrix<int> resultados);
int main() {
	
	matrix<int> resultados(24,7,-1);
	int uni, problema, tiempo;
	
	cout << "Codigo de universidad: ";cin >> uni;
	while(uni != 0) {
		cout << "\nCual es el codigo del problema: ";cin >> problema;
		cout << "\nEn que tiempo en minutos se termino ";cin >> tiempo;
		resultados[uni][problema] = tiempo;
		cout << "\nCodigo de universidad, 0 para terminar: ";cin >> uni;
	}
	pair<int,int> p = Ganadores(resultados);
	cout << "Las dos universidades ganadoras son: " << p.first << " y " << p.second;
	
	return 0;
}
pair<int,int> Ganadores(matrix<int> resultados) {
	int ganador1 = 0;
	int ganadortiempo = 0;
	int ganadortiempo2 = 0;
	int tiempo = 0;
	int pos1 = 0;
	int pos2 = 0;
	int ganador2 = 0;
	int contador = 0;
	
	for(int i=0;i<24;i++) { 
		for(int j=0;j<7;j++) { 
			if(resultados[i][j] != -1) {
				contador += 1;
				tiempo += resultados[i][j];
			}
		}
		if(contador > ganador1) {
			ganador2 = ganador1;
			pos2 = pos1;
			ganador1 = contador;
			pos1 = i;
			ganadortiempo2 = ganadortiempo;
			ganadortiempo = tiempo;
		} else if(contador == ganador1) {
		   if(tiempo < ganadortiempo) {
			ganador2 = ganador1;
			pos2 = pos1;
			ganador1 = contador;
			pos1 = i;
			ganadortiempo2 = ganadortiempo;
			ganadortiempo = tiempo;
		}
	} else if(contador > ganador2) {
			ganador2 = contador;
			pos2 = i;
			tiempo = ganadortiempo2;
		} else if(contador == ganador2) {
			if(tiempo < ganadortiempo2) {
				ganador2 = contador;
				pos2 = i;
				tiempo = ganadortiempo2;
			}
	}
}
	pair<int,int> d;
	d.first = pos1;
	d.second = pos2;
	return d;
}
int Dificil(matrix<int> resultados) {
	int dificil = 0;
	
		fori(7)
	
}
