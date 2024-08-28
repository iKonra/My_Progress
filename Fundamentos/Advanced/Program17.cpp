// Implemente una función que inserte un vector como nueva fila en una matriz en una posición dada.
// Se debe insertar, no reemplazar, es decir, por parámetro llega una matriz, una posición y un vector.
// Ejemplo: matriz de 4x5, vector de 5 elementos enteros, la matriz resultante quedaría de 5x5.
// No debe usar una matriz auxiliar. La función debe retornar un valor lógico que será verdadero
// cuando efectivamente se inserte la fila. Si el vector no tiene el tamaño adecuado o el índice de
// fila es menor a 0, la inserción no puede realizarse. Si el índice de fila es mayor al tamaño de
// la matriz, la función debe redimensionarla agregando filas de 0s hasta el tamaño necesario
// (por ej., en una matriz de 3x3, si se quiere insertar el vector en una 6ta fila, hay que completar
// con 2 filas de 0s antes). Nota: no se pide el programa cliente, solo la función.


#include <iostream>
#include <vector>
using namespace std;

bool Insertar(vector<vector <int>>& M,vector<int> v,int pos) {
	if(pos < 0 or v.size() != M[0].size()) {
		return false;
	} else {
		if(pos >= M.size() {
			M.resize(pos+1,vector<int>(M[0].size(),0));
			M[pos] = v;
			
			return true;
		} else {
			M.resize(M.size()+1);
			for(int i=M.size()-1;i>pos;i--) { 
				M[i] = M[i-1];
			}
			M[pos] = v;
			return true;
		}
	}
}

int main() {
	
	return 0;
}

