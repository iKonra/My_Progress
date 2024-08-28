// Leer las calificaciones de un grupo de 30 alumnos que asistieron a una evaluación
// de programación. Mostrar las notas de los alumnos que se encuentren por encima
// del promedio.	

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int alumnos = 0;  // si no se inicializa con 0 toma un valor random
	int contador = 0; // si no se inicializa con 0 toma un valor random
	vector<int> calificaciones(10);
	for(int i=0;i<10;i++) {
		
		cout << "Cual fue la calificacion del alumno " << i << ":";  cin >> calificaciones[i];
		contador = contador + calificaciones[i];
		++alumnos; 
		
	}
	float promedio = (contador/alumnos);
	cout << "El promedio es: " << promedio << "\n";
	for(int i=0;i<10;i++) { 
		if(calificaciones[i] > promedio) {
			cout << "El alumno " << i << " esta por encima del promedio \n";
		}
	}
	
	return 0;
}