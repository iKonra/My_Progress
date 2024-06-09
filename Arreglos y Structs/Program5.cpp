// Leer en un arreglo lineal una lista de N datos numéricos. Eliminar del arreglo el
// valor 523. Si este dato aparece más de una vez eliminar todas las ocurrencias y
// mostrar el modificado. Para hacerlo, codifique y utilice una función llamada
// buscar() que devuelva la posición que un determinado elemento ocupa dentro del
// arreglo, y otra función eliminar() que borre de un arreglo el elemento ubicado en
// una posición especificada.
	

#include <iostream>
#include <vector>
using namespace std;


int buscar(vector<int>& arreglo);
int main(int argc, char *argv[]) {
	
	vector<int> arreglo = {4,523, 3, 4, 5, 1, 6, 7, 4, 6, 523};
	vector<int> posiciones(0);
	int posicion;
	
	for(int i=0;i<arreglo.size();i++) { 
		if(arreglo[i] == 523) {
			posicion = buscar(arreglo);
			if(posicion != -1) {
				posiciones.push_back(posicion);
			}
		}
	}
	for(int i=0;i<posiciones.size();i++) { 
		cout << posiciones[i] << " ";
	}
	
	return 0;
}
int buscar(vector<int>& arreglo) {
	int pos = -1;
	for(int i=0;i<arreglo.size();i++) { 
		if(arreglo[i] == 523) {
			pos = i;
			arreglo[i] = 0;
			return pos;
		}
	} return pos;
}
