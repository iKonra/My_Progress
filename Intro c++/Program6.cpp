// Obtener la liquidación del sueldo de un empleado en base al detalle indicado más
// abajo. La empresa empleadora, bonifica sobre el sueldo básico (SB) la antigüedad
// del empleado con un 1.2% por año. Además paga el presentismo con una monto
// fijo (MP). Entre los descuentos, se deben contabilizar: el aporte jubilatorio (AJ) que
// representa un 11% del sueldo básico; aporte a obra social (OS) con un 3% del
// básico y el aporte gremial (AG) con un 1% del básico. El empleador paga además
// $ 30.00 por esposa y $ 40.00 por cada hijo. Son datos del problema: nombre y
// apellido del empleado, DNI, sueldo básico, antigüedad en años, estado civil ( 1 si
// es casado, 0 si es soltero ), número de hijos, presentismo ( 1 si corresponde
// cobrar, 0 si no cobra ). Obtenga una salida con mensajes alusivos describiendo los
// haberes, los descuentos y el sueldo neto a cobrar.


#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	float AJ = 0.11;float OS = 0.3;float AG = 0.1;
	
	string Nombre; string Apellido; string DNI; int SB;
	int antiguedad; int EstadoC; int Hijos; int Presentismo;
	
	cout << "Cual es el nombre del trabajador: "; cin >> Nombre; cout << " " << endl; cin.ignore();
	cout << "Cual es el apellido del trabajador: "; getline(cin, Apellido); cout << " " << endl;
	cout << "DNI: "; cin >> DNI; cout << " " << endl;
	cout << "Cuanto es el sueldo basico: "; cin >> SB; cout << " " << endl;
	cout << "Cual es su antiguedad en años?: "; cin >> antiguedad; cout << " " << endl;
	cout << "Cual es su estado civil? 1 = Casado, 0 = Soltero: "; cin >> EstadoC; cout << " " << endl;
	cout << "Cuantos hijos tiene?: "; cin >> Hijos; cout << " " << endl;
	cout << "Le corresponde cobrar el presentismo? 1= Si, 0=No: "; cin >> Presentismo; cout << " " << endl;
	
	
	cout << "Empleado: " << Apellido << " " << Nombre << endl;
	cout << "El sueldo mas bonificacion por antiguedad es de: " << SB +((antiguedad*1.2 *SB)/100) << endl;
	int SBA = SB +((antiguedad*1.2 *SB)/100);
	if (Presentismo == 1) {
		cout << "Le corresponde cobrar presentismo" << endl;
	}
	else {
		cout << "No le corresponde cobrar presentismo" << endl;
	}
	cout << "El sueldo bonificado descontando los aportes es de: " << SBA - (SBA*AJ) - (SBA*OS) - (SBA*AG) << endl;
	float sueldofinal = SBA-(SBA*AJ)-(SBA*OS)-(SBA*AG);
	
	if (EstadoC == 1) {
		sueldofinal = sueldofinal + 30;
	}
	if (Hijos > 0) {
		sueldofinal = sueldofinal + Hijos*40;
	}
	cout << "El sueldo final es: " << sueldofinal;
	return 0;
}

