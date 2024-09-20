//	Ej1(30pts) a) Diseñe una clase Pasajero para guardar los datos de un pasajero de un vuelo de avión.
//	La clase debe guardar un string con apellido y nombre, tipo de pasaje (estándar o 1ra clase) y peso del
//	equipaje a despachar. Estos datos deben inicializarse en el constructor de la clase.
//	b) Reutilizando la clase Pasajero, diseñe una clase Vuelo para representar los datos de un vuelo. La
//	clase debe tener un constructor que permita definir los aeropuertos de origen y destino, y la cantidad de
//	asientos disponibles de cada tipo. Debe tener además:
//	- c) un método para agregar un pasajero al vuelo; este método deberá retornar true si el pasajero debe
//	pagar por exceso de equipaje (si su equipaje supera los 15ks para un pasaje estándar, o los 30ks para
//	1ra clase).
//	- d) un método para consultar la cantidad de asientos disponibles de un cierto tipo (el tipo será el
//	argumento, estándar o 1ra clase, y se calcula restando al total los ocupados por pasajeros ya
//	cargados).
//	- e) un método para obtener el peso total del equipaje (sumando el de todos los pasajeros).
//	Declare en ambas clases todos los métodos que considere adecuados o necesarios, pero implemente
//	solo los constructores y los métodos que se piden explícitamente en c, d y e (para los demás, solo
//	escriba el prototipo).
		
	

#include <iostream>
#include <vector>
using namespace std;
class Pasajero {
private:
	string m_apellido, m_nombre;
	int m_tipo;
	float m_peso;
public:
	Pasajero(string apellido,string nombre, int tipo, float peso):m_apellido(apellido),m_nombre(nombre),m_tipo(tipo),m_peso(peso){}
	string VerApellido(){return m_apellido;}
	int VerTipo(){return m_tipo;}
	float VerPeso(){return m_peso;}
	
	
};
class Vuelo {
private:
	vector<Pasajero> v;
	string m_origen,m_destino;
	int m_asientos_estandar;
	int m_asientos_primera;
	int m_ocupados_estandar = 0;
	int m_ocupados_primera = 0;
public:
	Vuelo(string origen, string destino,int estandar,int primera):m_origen(origen),m_destino(destino),m_asientos_estandar(estandar),m_asientos_primera(primera){}
	bool AgregarPasajero(Pasajero pasajero);
	int CantidadAsientos(int tipobuscar){
		if(tipobuscar == 0) { 
			int disponibles; disponibles = m_asientos_estandar - m_ocupados_estandar;
			return disponibles;
		} else if(tipobuscar == 1) {
			int disponibles; disponibles = m_asientos_primera - m_ocupados_primera;
			return disponibles;
		}
		return 0;
	}
	float CalcularPeso(){int peso = 0;for(size_t i=0;i<v.size();i++) { peso += v[i].VerPeso();} return peso;  return 0;}
	
};
bool Vuelo::AgregarPasajero(Pasajero pasajero) {
	v.push_back(pasajero);
	if(pasajero.VerTipo() == 0) {
		++m_ocupados_estandar;
	}else {
		++m_ocupados_primera;
	}
	if((pasajero.VerTipo() == 0) and (pasajero.VerPeso() > 15.00)) {
		return true;
	} else if((pasajero.VerTipo() == 1) and (pasajero.VerPeso() > 30.00)) {
		return true;
	}
	return false;
}
int main() {
	Vuelo vuelo("Buenos Aires", "Madrid", 2, 2); // 2 asientos estándar y 2 de primera clase
	
	// Crear pasajeros
	Pasajero p1("Gomez", "Juan", 0, 20.0); // Estándar, 20 kg (exceso)
	Pasajero p2("Lopez", "Ana", 1, 25.0);  // Primera clase, 25 kg (sin exceso)
	Pasajero p3("Perez", "Carlos", 0, 10.0); // Estándar, 10 kg (sin exceso)
	Pasajero p4("Sanchez", "Maria", 1, 35.0); // Primera clase, 35 kg (exceso)
	
	// Agregar pasajeros al vuelo y verificar exceso de equipaje
	cout << "Agregando pasajero 1: " << (vuelo.AgregarPasajero(p1) ? "Debe pagar por exceso." : "No debe pagar.") << endl;
	cout << "Agregando pasajero 2: " << (vuelo.AgregarPasajero(p2) ? "Debe pagar por exceso." : "No debe pagar.") << endl;
	cout << "Agregando pasajero 3: " << (vuelo.AgregarPasajero(p3) ? "Debe pagar por exceso." : "No debe pagar.") << endl;
	cout << "Agregando pasajero 4: " << (vuelo.AgregarPasajero(p4) ? "Debe pagar por exceso." : "No debe pagar.") << endl;
	
	// Consultar asientos disponibles
	cout << "Asientos disponibles estándar: " << vuelo.CantidadAsientos(0) << endl;
	cout << "Asientos disponibles primera clase: " << vuelo.CantidadAsientos(1) << endl;
	
	// Calcular peso total del equipaje
	cout << "Peso total del equipaje: " << vuelo.CalcularPeso() << " kg" << endl;
	
	return 0;
}

