//	Se dispone de un archivo de textos llamado “datos.txt” generado por un equipo que mide una vez al día la
//	altura del río. Para simplificar, suponer que todos los meses tienen 30 días; entonces el archivo tendrá
//	30*12=360 datos.
//	a) Escriba un programa C++ que lea el archivo y organice todos los datos en un único contenedor STL.
//	b) Obtenga el mayor valor de cada mes, y genere con estos 12 valores un nuevo vector donde cada posición
//	contenga una terna de datos: nro de mes, valor máximo de ese mes, y cuántas veces se repitió ese valor
//	máximo en el mes.
//	c) Ordene el nuevo vector de mayor a menor (según el valor máximo de cada terna) y luego guarde estas 12
//	ternas en un archivo binario “máximos.dat”.

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

struct Maximos {
	float valor;
	int nromes;
	int cant_de_repetidos;
};

bool operator>(Maximos a, Maximos b) {
	return(a.valor > b.valor);
}

vector<Maximos> EncontrarMaximos(vector<float> v) {
	
	vector<Maximos> vec;
	Maximos elemento;
	int cont = 0;
	
	for(int i=0;i<v.size();i += 30) { 
		auto it = max_element(v.begin()+i,v.begin()+ 30 + i);
		
			for(int j=0;j<30;j++) { 
				if(v[i+j] == *it) 
					cont++;
			}
		
		elemento = {*it,i/30+1,cont};
			cont = 0;
		
		vec.push_back(elemento);
	}
	return vec;
}

int main() {
	
	
	vector<float> alturas;
	
	ifstream archi("datos.txt");
		if(!archi) throw runtime_error("Error al abrir el archivo");
	
	float valor;
	
	for(int i=0;i<360;i++) { 
		archi >> valor;
		alturas.push_back(valor);
	}
	archi.close();
	
	vector<Maximos> vec = EncontrarMaximos(alturas);
	sort(vec.begin(),vec.end(),greater<Maximos>());
	
	for(int i=0;i<vec.size();i++) {
		cout << vec[i].nromes << " - Valor: " << vec[i].valor << " cantidad de repeticiones: " << vec[i].cant_de_repetidos << endl; 
	}
	
	
	ofstream archi2("maximos.dat", ios::binary);
	Maximos aux;
	for(size_t i=0;i<vec.size();i++) { 

		aux = vec[i];
		archi2.write(reinterpret_cast<char*>(&aux), sizeof(Maximos));
	}
	

	
	
	return 0;
}

