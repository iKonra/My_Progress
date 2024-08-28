// Se tiene un arreglo dinámico de n enteros, y se quiere aumentar su tamaño a un nuevo tamaño c. Implemente una
//	función redimensionar() que reserve dinámicamente memoria para un nuevo arreglo que contenga lugar suficiente
//	para guardar c datos (los n datos anteriores y los c-n nuevos). Copie en la nueva memoria los datos del vector viejo
//	e inicialice con ceros los nuevos elementos. La memoria del primer arreglo debe ser liberada y el struct actualizado
//	para que el programa cliente pueda seguir operando con el nuevo arreglo. 

#include <iostream>
using namespace std;
struct arreglo {
	int size;
	int *p;
};
void redimensionar(arreglo &v,int c) {
	arreglo v2;
	v2.size = c;
	v2.p = new int[c];
	int cont = 0;
	
	while(cont < v.size) {
		*(v2.p+cont) = *(v.p+cont);
		cont++;
	};
	for(int i=v.size;i<c;i++) { 
		*(v2.p+i) = 0;
	}
	v2.size = c;
	delete []v.p;
	v.p = v2.p; // Se apunta al nuevo vector
	
}
int main() {
	int N; cin >> N;
	arreglo v;
	v.size = N;
	v.p = new int[v.size];
	for(int i=0;i<N;i++) { 
		*(v.p+i) = rand()%150;
	}
	int c; cin >> c;
	redimensionar(v,c);
	
	for(int i=0;i<c;i++) { 
		cout << *(v.p+i) << "  ";
		if(i > 1) {
			if(i%10 == 0)
				cout << "\n";
		}
	}
	return 0;
}

