//	Ejercicio 3 [30 pts] Defina Cliente (clase o struct) para representar a un cliente a partir de su nombre y
//	apellido, DNI y Saldo. Diseñe una clase llamada Facturas que permita manejar los datos de un grupo de
//	clientes. La clase debe poseer métodos para: a) Guardar los datos de los clientes en un archivo binario.
//	b) Cargar los datos de los clientes desde un archivo binario. c) Agregar un cliente. d) Eliminar un
//	cliente a partir de su DNI, e) mostrar un cliente dada su posición. 

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Cliente {
	string nombre;
	string apellido;
	int DNI;
	float saldo;
};
class Facturas {
	vector<Cliente> clientes;
public:
	Facturas(string archivo) {
		CargarDatos(archivo);
	}
	void CargarDatos(string archivo) {
		ifstream archi(archivo, ios::binary);
		if(!archi) 
			throw runtime_error("Error al abrir " + archivo);
		
		Cliente cliente;
		while (archi.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente))) {
			clientes.push_back(cliente);
		}
		archi.close();
	}
	void GuardarBinario() {
			ofstream archi("datos.dat",ios::binary);
				if(!archi)
					throw runtime_error("Error al crear el archivo.");
				
			for(auto &x: clientes) {
				archi.write(reinterpret_cast<const char*>(&x),sizeof(x));
			}
			archi.close();
		}
	bool AgregarCliente(Cliente nuevo) { 
		for(auto &x : clientes) {
			if(x.DNI == nuevo.DNI) {
				return false;
			}
		} 
		clientes.push_back(nuevo);
		cout << "Cliente añadido con exito." << endl;
		return true;
	}
	bool EliminarCliente(int dni) {
		for(auto it = clientes.begin(); it != clientes.end(); it++) {
			if(it->DNI == dni) {
				clientes.erase(it);
			return true;
			}
		}
		
		cout << "No se encontro el cliente a eliminar." << endl;
		return false;
	}
	void MostrarCliente(size_t pos) {
		if (pos >= 0 && pos < clientes.size()) {
			const Cliente &cliente = clientes[pos];
			cout << "Nombre: " << cliente.nombre << " " << cliente.apellido << endl;
			cout << "DNI: " << cliente.DNI << endl;
			cout << "Saldo: " << cliente.saldo << endl;
		} else {
			cout << "Posición inválida." << endl;
		}
		
	}
};

int main() {
	// Ejemplo de uso
	Facturas facturas("datos.dat");
	
	// Agregar un cliente
	Cliente nuevoCliente = {"Juan", "Perez", 12345678, 500.00};
	facturas.AgregarCliente(nuevoCliente);
	
	// Guardar clientes en archivo binario
	facturas.GuardarBinario();
	
	// Mostrar un cliente en una posición específica
	facturas.MostrarCliente(0);
	
	return 0;
}
