// Ejercicio 3. (25 pts) Considere el struct ficha (int DNI, float altura;) 
// 	que define como miembros el DNI y la altura de un grupo de personas. 
// 	Escriba una función C++ que reciba como parámetros un vector A de tipo ficha
// 	ya ordenado en forma decreciente por altura. En el grupo organizado en A
// 	hay varias personas con la misma altura. Acomode los elementos del vector
//	de modo que si hay personas de igual altura se ubique antes en el vector 
//	la persona de menor edad (número de DNI mayor). Se sabe que en el grupo 
//	no hay más de 3 personas con igual altura. No debe usar algoritmos
//	ni métodos de la STL.

#include <iostream>
using namespace std;

struct ficha {
	int DNI;
	float altura;
};
void OrdenarEdad(vector<ficha>& A) {

	for(int i=0;i<A.size()-1;i++) { 
		if(A[i].altura == A[i+1].altura && A[i].DNI < A[i+1].DNI {
			int dni_aux; float alt_aux;
			dni_aux = A[i].altura; alt_aux = A[i].DNI;
			A[i].altura = A[i+1].altura; A[i].DNI = A[i+1].DNI;
			A[i+1].altura = dni_aux; A[i].DNI = alt_aux;
		};
	}
	
};
int main() {
	
	vector<ficha> A(100)
	
	return 0;
}

