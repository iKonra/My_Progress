//	Ejercicio 3 (30pts) Un archivo binario guarda datos de usuarios de un sistema. Por
//	cada usuario se guarda código (entero), nombre (cadena) y contraseña (cadena). Se
//	quiere encontrar contraseñas comunes para sugerirle a esos usuarios que las
//	modifiquen. Escriba un programa que: a) lea los datos y genere una lista de todas las
//	contraseñas que estén repetidas más de 10 veces (que más de 10 usuarios tengan la
//	misma). La lista debe estar ordenada por cantidad de repeticiones (primero las que
//	más se repiten); y b) modifique el archivo estableciendo la cadena vacía como
//	contraseña para todos los usuarios que tengan alguna de las contraseñas de la lista.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Usuario {
	int codigo;
	char nombre[256];
	char password[256];
	
	bool operator==( Usuario& otro)  {
		return string(password) == string(otro.password);
	}
};
struct Pass {
	string valor;
	int cant;
};

bool operator<(Pass a, Pass b) {
	return(a.cant < b.cant);
}

int main() {
	
	ifstream archi("archive.dat", ios::binary | ios::ate);
		if(!archi) throw runtime_error("error al iniciar el archivo.");
		
	vector<Usuario> vec;
	vector<Pass> contra;
	
	int cantBytes = archi.tellg();
	int CantUsuarios = cantBytes / sizeof(Usuario);
	
	for(int i=0;i<CantUsuarios;i++) { 
		Usuario aux;
		
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Usuario));
		vec.push_back(aux);
	}
	
	archi.close();
	
	for (size_t i = 0; i < vec.size(); i++) {
		int count = 0;
		for (size_t j = 0; j < vec.size(); j++) {
			if (vec[i] == vec[j]) { // Utilizamos el operador `==` sobrecargado
				count++;
			}
		}
		
		// Solo agregamos a la lista las contraseñas que se repiten más de 10 veces
		if (count > 10) {
			bool encontrado = false;
			// Verificamos si ya hemos agregado esta contraseña
			for (auto& pass : contra) {
				if (pass.valor == vec[i].password) {
					encontrado = true;
					break;
				}
			}
			if (!encontrado) {
				Pass aux2 = {vec[i].password, count};
				contra.push_back(aux2);
			}
		}
	}
	
	sort(contra.begin(),contra.end());
	reverse(contra.begin(),contra.end());
	
	for(size_t i=0;i<vec.size();i++) { 
		for(size_t j=0;j<contra.size();j++) { 
			if(vec[i].password == contra[j].valor) {
				strcpy(vec[i].password, "");
			}
		}
	}
	
	
	ofstream archi2("archive.dat", ios::binary | ios::trunc);
		if(!archi2) throw runtime_error("error al inicializar");
	
	for(size_t i = 0;i < vec.size(); i++) {
		Usuario aux;
		vec[i] = aux;
	archi2.write(reinterpret_cast<char*>(&aux),sizeof(Usuario));
	}
	return 0;
}


