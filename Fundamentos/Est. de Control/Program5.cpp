// Deseamos saber si un estudiante de primer año vota en las próximas
// elecciones, para ello debe ser mayor de 18 años. Se ingresan la fecha de
// nacimiento y de votación con formato día, mes y año. Informe con un mensaje
// alusivo.


#include <iostream>
using namespace std;

int main() {
	int DiaN, MesN, YearN;
	int DiaV, MesV, YearV;
	
	cout << "Ingrese la fecha de nacimiento separado por espacios (dia mes año): ";
	cin >> DiaN >> MesN >> YearN;
	
	cout << "Ingrese la fecha de votacion separado por espacios (dia mes año): ";
	cin >> DiaV >> MesV >> YearV;
	
	int edad = YearV - YearN;
	
    // Si el mes de nacimiento es mayor al mes de votacion o igual pero el dia de nacimiento es mayor
    // al dia de votacion se resta 1 a la edad 
	if (MesN > MesV || (MesN == MesV && DiaN > DiaV)) {
		edad--;
	}
	
    // si la edad es mayor o igual a 18 puede votar
	if (edad >= 18) {
		cout << "El estudiante puede votar en las próximas elecciones." << endl;
	} else {
		cout << "El estudiante no puede votar en las próximas elecciones." << endl;
	}
	
	return 0;
}
