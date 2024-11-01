// Escriba un programa abra el archivo generado en el ejercicio anterior y solicite al usuario que ingrese un entero, un
// flotante y una posición. El programa debe sobrescribir el par en la posición ingresada por el usuario por el nuevo par.
// Luego muestre la lista de datos en consola mostrando un par por línea.


#include <iostream>
#include <fstream>
using namespace std;
struct par {
	int x;
	float y;
};
int main() {
	
	
	ifstream archi("grupo.dat", ios::binary|ios::ate);
	if(!archi) 
		throw runtime_error("El archivo no se abrio correctamente.");
	
	int N = archi.tellg()/sizeof(par);
	archi.seekg(0);
	
	for(int i=0;i<N;i++) {
		par x;
		archi.read(reinterpret_cast<char*>(&x),sizeof(x)) ;
		cout << x.x << " " << x.y << endl;
	}
	archi.close();
	
	
	//	SEGUNDA PARTE
	
	
	int pos; cout << "Que posicion quiere modificar 1-200: "; cin >> pos; pos--;
	int entero; cout << "\nQue entero ingresara: "; cin >> entero;
	float flotante; cout << "\nQue flotante ingresara: "; cin >> flotante;
	
	par x;
	x.x = entero;
	x.y = flotante;
	
	fstream archi_escribir("grupo.dat",ios::binary|ios::in|ios::out);
	archi_escribir.seekp(sizeof(par) * pos);
	archi_escribir.write(reinterpret_cast<const char*>(&x), sizeof(x));
	
	archi_escribir.seekg(0);
	for(int i=0;i<N;i++) {
		par y;
		archi_escribir.read(reinterpret_cast<char*>(&y),sizeof(y)) ;
		cout << y.x << " " << y.y << endl;
	}
	archi.close();
	
	
	
	
	
	return 0;
}
