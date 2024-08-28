// Ejercicio 1. (35 pts) Un grupo de investigación analiza el comportamiento de
//	120 pacientes hospitalizados y afectados por una epidemia. Se tomaron los valores
//	de presión de oxigeno en sangre y de temperatura, cada 4 hs durante 7 dias 
//	(hay 6 lecturas diarias x paciente). a) Escriba un programa que permita 
//	ingresar estos datos sin orden alguno: por cada medición se ingresan 5 
//	datos: Nro Paciente (1..120), Dia, Hora. Valor presión oxigeno, Valor 
//	temperatura. Ejemplo: 108, 4, 20, 92, 35.6 (paciente 108, dia 4, hora 
//	20, presión oxigeno 92, temperatura 35.6). Organice estos datos en una
//	tabla/matriz de 2 dimensiones: 120 filas (pacientes) x 7 columnas (dias),
//	donde en cada celda guarde la presión de oxigeno media diaria y temperatura
//	media diaria correspondientes (para obtener la temperatura media de un dia
//	promedie las 6 temperaturas obtenidas de ese dia; igual para la presión de 
//	oxigeno). b) Calcule mediante una función que reciba un nro de paciente,
//	en qué dias su temperatura media diaria superó los 37 grados; c) Calcule
//	mediante otra función cuántos pacientes tuvieron hipoxemia (presión 
//	media diaria de oxigeno inferior a 75) durante 2 o más días seguidos. 
//	El programa debe informar los resultados de b) para un paciente
//	que ingrese el usuario y de c)

#include <iostream>
#include <matrix>
#include <vector>
using namespace std;

struct promedios {
	int promOx;
	int promTemp;
	
};
void TempMayor(matrix<float> m,int nro) {
	for(int i=0;i<7;i++) { 
		if(m[nro][i].promTemp > 37) 
			cout << "El dia " << i << " tuvo " << m[nro][i].promTemp << " de temperatura";
	}
}
int hipoxemia(matrix<float> m) {
	int Contador = 0;
	for(int i=0;i<120;i++) { 
		for(int j=0;j<6;j++) { 
			if((m[i][j] && m[i][j+1]) < 75) {
				Contador++
			}
		}
	}
	return Contador
}
int main() {
	matrix<float> m(120,7, 0);
	int paciente, dia, hora, oxigeno, temp;
	for(int i=0;i<3360;i++) { 
		cout << "Que paciente es: "; cin >> paciente;
		cout << "Que dia es: "; cin >> dia;
		cout << "Que hora es: "; cin >> hora;
		cout << "Cual fue la medida de oxigeno: "; cin >> oxigeno;
		cout << "Cual fue la medida de temperatura: "; cin >> temp;
		m[paciente][dia].promOx += oxigeno;
		m[paciente][dia].promTemp += temp;
	}
	for(int i=0;i<120;i++) { 
		for(int j=0;j<7;j++) { 
			m[i][j].promOx = (m[i][j].PromOx/6);
			m[i][j].promTemp = (m[i][j].PromTemp/6);
		}
	}
	pacienteshipoxemia = hipoxemia(m);
	cout << "Hubo " << pacienteshipoxemia << " pacientes con hipoxemia";
	cout << "Que paciente quiere averiguar ";cin >> paciente;
	TempMayor(m,paciente);
	return 0;
}
