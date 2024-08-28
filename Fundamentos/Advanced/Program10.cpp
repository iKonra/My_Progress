// Ej 1 (30pts) a) Diseñe una función C++ que se la invoque de la siguiente forma: e = edad(f_nac,f_hoy);
// siendo f_nac y f_hoy de tipo Fecha: un struct con 3 miembros enteros: dia, mes, anio. La función debe
// devolver la edad de una persona que nació en la fecha f_nac, siendo f_hoy la fecha de hoy. b) Considere
// un club deportivo barrial que tiene N socios, y cada socio paga una cuota de acuerdo a su categoría:
// infantiles (hasta 12 años inclusive), juveniles (hasta 18 años inclusive) y mayores (más de 18 años).
// Escriba un programa C++ que organice en un único vector los datos de cada asociado: apellido, nombres,
// dni, categoría, fecha de nacimiento (de tipo Fecha). Debe leer primero los 3 valores de la cuota (de cada
// categoría), y a continuación los datos de los N socios. c) El programa debe actualizar el vector de socios
// considerando la fecha de hoy a través de una función actualizar(..), pues varios socios pueden haber
// cambiado de categoría al cambiar su edad; y luego d) calcular la recaudación mensual del club si todos
// los socios pagaran su cuota al día de hoy.

#include <iostream>
#include <vector>
using namespace std;

struct Fecha {
	int dia;
	int mes;
	int anio;
};
struct Socio {
	string apellido;
	string nombres;
	int dni;
	string categoria;
	Fecha nacimiento;
};
int edad(Fecha f_nac,Fecha f_hoy) {
	int edad = f_hoy.anio - f_nac.anio;
	if (f_hoy.mes < f_nac.mes || (f_hoy.mes == f_nac.mes && f_hoy.dia < f_nac.dia)) {
		edad--;
	}
	return edad;
}
void actualizar(vector<Socio>& socios,Fecha f_hoy) {
	for(int i=0;i<socios.size();i++) {
		int Edad = edad(socios[i].nacimiento, f_hoy);
		if (Edad <= 12) {
			socios[i].categoria = "infantiles";
		} else if (Edad <= 18) {
			socios[i].categoria = "juveniles";
		} else {
			socios[i].categoria = "mayores";
		}
	}
}
int main() {
	float infantiles,juveniles,mayores;
	
	cout << "Cual es el valor de la cuota infantil: ";cin >> infantiles; cout << endl;
	cout << "Cual es el valor de la cuota juvenil: ";cin >> juveniles; cout << endl;
	cout << "Cual es el valor de la cuota mayores: ";cin >> mayores; cout << endl;
	int N = 5;
	cin.ignore();
	vector<Socio> socios(N);
	
	for(int i=0;i<socios.size();i++) { 
		cout << "Apellido: ";getline(cin,socios[i].apellido);cout << endl;
		cout << "Nombres: ";getline(cin,socios[i].nombres);cout << endl;
		cout << "Dni: ";cin >> socios[i].dni;cin.ignore();cout << endl;
		cout << "Categoria: ";getline(cin,socios[i].categoria);cout << endl;
		cout << "Fecha de nacimiento (dia mes anio): "; 
		cin >> socios[i].nacimiento.dia >> socios[i].nacimiento.mes >> socios[i].nacimiento.anio; cin.ignore(); cout << endl;
	}
	
	Fecha f_hoy = {24, 6, 2024};
	
	actualizar(socios,f_hoy);
	
	int recaudacion = 0;
	for(int i=0;i<socios.size();i++) { 
		if(socios[i].categoria == "infantiles")
			recaudacion += infantiles;
		if(socios[i].categoria == "juveniles")
			recaudacion += juveniles;
		if(socios[i].categoria == "mayores")
			recaudacion += mayores;
	}
	cout << "La recaudacion mensual del club es: " << recaudacion << endl;
	return 0;
}

