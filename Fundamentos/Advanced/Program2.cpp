// Escriba una función buscar que reciba un vector de strings v, un string s, y una posición p. La función
// debe buscar el valor s en el vector v, solo desde la posición p en adelante, y retornar la primera posición donde lo
// encuentre, o -1 en caso de no encontrarlo. b) Utilizando la función buscar, escriba una función reemplazar que
// reciba un vector de strings, y dos strings s1 y s2. La función debe reemplazar todas las ocurrencias de s1 en el
// vector por s2; y retornar la cantidad de reemplazos realizados.
		

#include <iostream>
#include <vector>
using namespace std;

int Buscar(vector<string> v,string s,int p);
int reemplazar(vector<string>& v,string s1,string s2);
int main(int argc, char *argv[]) {
	
	vector<string> v(0);
	string dato;
	string buscar;
	int pos, cont;
	cont = 0;
	string s1,s2;
	
	cout << "Ingrese los datos para el vector de strings, 0 para terminar: \n";
	for(int i=0;i<1000;i++) { 
			cin >> dato; 
		if(dato != "0") {
			v.resize(v.size()+1);
			v[i] = dato;
			cont += 1;
		} else {
			i += 1000;
		}
	}
	cout << "\n Que string quiere buscar dentro del vector: "; cin >> buscar;
	cout << "\n Apartir de que posicion?: "; cin >> pos;
	int Encontrado = Buscar(v,buscar,pos);
	if(Encontrado == -1) {
		cout << "No se ha encontrado" << endl;
	} else {
		cout << "Se encontro en la posicion: " << Encontrado << endl;
	}
	cout << "Que palabra quiere reemplazar: "; cin >> s1; 
	cout << "\n Por que palabra la quiere reemplazar: "; cin >> s2;
	int cantidad = reemplazar(v, s1, s2);
	
	cout << "Se han realizo " << cantidad << " cambios.";
	if(cantidad != 0) {
		cout << "\n El nuevo vector modificado es: \n";
		for(size_t i=0;i<v.size();i++) { 
			cout << " - " << v[i] << "\n";
		}
	} else {
		cout << "El vector sigue como antes.";
	}
	return 0;
}
int Buscar(vector<string> v,string s,int p) {
	for(size_t i=p;i<=v.size();i++) { 
		if(v[i] == s) {
			return i;
		}
	}
 return -1;
}
int reemplazar(vector<string>& v,string s1,string s2) {
	int contador = 0;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i] == s1) {
			v[i] = s2;
			contador += 1;
		}
	}
	return contador;
}
