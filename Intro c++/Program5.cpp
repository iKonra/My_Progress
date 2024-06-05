// Un usuario desea conocer cuánto le cuesta el combustible de cada viaje que
//	realiza en su auto. Para ello anota el kilometraje que marca el odómetro justo antes
// 	de iniciar el viaje, y toma nota nuevamente justo al llegar a destino. Conoce
//	además el consumo de nafta del vehículo en ruta (es decir, cuantos litros gasta en
//	promedio por cada kilómetro recorrido), y el precio del litro de nafta. Escriba un
//	algoritmo para calcular el costo de un viaje. ¿Cómo modificaría el algoritmo para
//	considerar un % de descuento para los días en que hay promociones para clientes
//	habituales en la estación de servicio?


#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int kmi, kmf;
	cout << "¿Cual es el kilometraje inicial? "; cin >> kmi;
	cout << "¿Cual es el kilometraje final? "; cin >> kmf;
	int recorrido = kmf-kmi;
	float litros, precio;
	cout << "Cual es el consumo de nafta en litros: "; cin >> litros;
	cout << "Cual es el precio por litro de nafta: "; cin >> precio;
	float costo = recorrido*litros*precio;
	
	string Descuento; cout << "Hay un descuento el dia de hoy, Yes/No: ";
	cin >> Descuento;
	if (Descuento == "Yes" ) {
		float promo;
		cout << "De cuanto es el descuento? "; cin >> promo;
		float costopromo = (costo/100)*promo;
		cout << "El precio con la promocion de " << promo << " es de: " << costopromo << endl;
	}
	else {
		cout << "El costo del viaje fue de: " << costo << endl;
		
	}
	return 0;
}

