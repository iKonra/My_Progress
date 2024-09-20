// Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el volumen del cuerpo conociendo el
// radio de su base y la altura del mismo.
// 1. La interfaz pública de la clase debe estar compuesta por los métodos AsignarDatos(...) y ObtenerVolumen(...)
// para asignar los datos del problema y obtener el volumen del cuerpo.
// 2. Escriba un programa cliente que utilice dicha clase. Defina 2 instancias de Cilindro llamadas c1 y c2. El objeto
// c1 debe utilizar datos ingresados por el usuario, mientras que para c2 utilice 5.3cm y 10.2cm para el radio y la
// altura respectivamente.
// 3. Agregue un constructor a la clase Cilindro que reciba 2 parámetros para inicializar el radio y la altura. Luego
// intente compilar nuevamente el programa. ¿Puede explicar por qué se produce un error? Proponga una
// solución.

#include <iostream>
using namespace std;
class Cilindro {
	private:
		float radio,altura,volumen;
	public:
		Cilindro(float datoradio,float datoaltura);
		void ObtenerVolumen();
		float ver_vol() {return volumen;};
};
Cilindro::Cilindro(float datoradio,float datoaltura) {
	radio = datoradio;
	altura = datoaltura;
}
void Cilindro::ObtenerVolumen() {
	volumen = 3.14*altura*(radio*radio);
}
int main() {
	float datoradio,datoaltura;
	cout << "Ingrese el radio: "; cin >> datoradio;
	cout << "\n Ingrese la altura: "; cin >> datoaltura;
	Cilindro c1(datoradio,datoaltura);
	c1.ObtenerVolumen();
	cout << "\nEl volumen del cilindro 1 es: " << c1.ver_vol();
	float datoradio2 = 5.3;
	float datoaltura2 = 10.2;
	Cilindro c2(datoradio2,datoaltura2);
	c2.ObtenerVolumen();
	cout << "\nEl volumen del cilindro 2 es: " << c2.ver_vol();
	
	
	return 0;
}

