#include <iostream>
#include <vector>
using namespace std;

struct puesto {
	string nombre;
	int sector;
	int rubro;
	float montofijo;
	float porcentaje;
	float importe;
	int ventas;
};
struct recaudado {
	int recaudadacion;
};
pair mayores(vector<puesto> v) {
	float mayor1 = 0; float mayor2 = 0;
	int ventas1 = 0;int ventas2 = 0;
	int pos1 = 0; int pos2 = 0;
	
	for(int i=0;i<v.size();i++) { 
		if(v[i].importe > mayor1) {
			mayor2 = mayor1;
			pos2 = pos1;
			mayor1 = v[i].importe
			pos1 = i;
			ventas2 = ventas1;
			ventas1 = v[i].ventas
		} else if(v[i].importe == mayor1) {
			if(v[i].ventas > ventas1) {
				mayor2 = mayor1;
				pos2 = pos1;
				mayor1 = v[i].importe
				pos1 = i;
				ventas2 = ventas1;
				ventas1 = v[i].ventas
			}
		} else if(v[i].importe > mayor2) {
			mayor2 = v[i].importe
			pos2 = i;
			ventas2 = v[i].ventas
		} else if(v[i].importe == mayor2) {
			if(v[i].ventas > ventas2) {
				mayor2 = v[i].importe
					pos2 = i;
				ventas2 = v[i].ventas
			}
		}
	}
	pair p;
	p.first = pos1;
	p.second = pos2;
}
int main() {
	cin >> N;
	vector<puesto> v(N);
	
	int montofijo;
	float por1, por2, por3, por4;
		cin >> montofijo;
		cin >> por1 >> por2 >> por3 >> por4
		
	for(int i=0;i<N.size();i++) { 
		v[i].montofijo = montofijo;
		cin >> v[i].sector;
		if(v[i].sector == 1) {v[i].porcentaje = por1}
		if(v[i].sector == 2) {v[i].porcentaje = por2}
		if(v[i].sector == 3) {v[i].porcentaje = por3}
		if(v[i].sector == 4) {v[i].porcentaje = por4}
		cin.ignore();
		getline(cin,v[i].nombre);
		cin >> v[i].rubro;
	}
	int puesto;
	int importe;
	while(puesto != 0) {
		cin >> puesto;
		cin >> importe;
		v[puesto].importe += importe;
		v[puesto].ventas++;
	}
	pair p = mayores(v);
	cout << "Primero con mas ventas: " << p.first << " a cargo de " << v[p.first].nombre;
	cout << "Segundo con mas ventas: " << p.second << " a cargo de " << v[p.second].nombre;
	
	vector<recaudado> r(7);
	
	for(int i=0;i<v.size();i++) { 
		r[v[i].rubro].recaudacion += v[i].importe * v[i].porcentaje];
	}
	
	for(int i=0;i<7;i++) { 
		cout << "Rubro: " << i << "Recaudo: " << r[i];
	}
	
	return 0;
}

