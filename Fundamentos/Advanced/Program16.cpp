/*
Se pretende analizar el rendimiento académico de 200 egresados de una carrera cuyo plan
contiene 35 materias. Escriba un programa que permita:
a) ingresar 200x35 ternas de datos compuestas por número de alumno (1 a 200),
número de materia (1 a 35) y nota final (6 a 10) y muestre:
b) el mejor promedio de la carrera;
c) la materia más difícil (la que tenga menor promedio de nota), y
d) la nota que obtuvo el alumno del mejor promedio para esa materia más difícil.
*/



#include <iostream>
#include <matrix>

using namespace std;
struct {
    int nota_final;
    float promedio;
}
int main() {
    matrix<int> alumno(200,35);
int suma = 0;
for (size_t i = 0; i < 200; i++) {
    for (size_t j = 0; j < 35; j++) {
        cin >> alumno[i][j].nota_final;
        suma += alumno[i][j].nota_final;
    }
    alumno[i].promedio = suma/35;
    suma = 0;
}
int pos;
int mejorpromedio = 0;


for(int i = 0; i < 200; i++) {
    if(alumno[i].promedio > mejorpromedio) {
        pos = i;
        mejorpromedio = alumno[i].promedio;
    }
}
cout << "El mejor promedio fue el del alumno: " << pos << " con un promedio de: " << mejorpromedio << endl;

int peor_materia = 9999; // Numero alto ya que se busca la materia con peor promedio
int posicion;
int suma = 0;
for(int i = 0; i < 35; i++) {
    for (size_t j = 0; j < 200; j++) {
    suma += alumno[j][i].nota_final;
    }
    if(suma < peor_materia) {
        peor_materia = suma;
        posicion = i;
    }
}
cout << "La peor materia fue: " << posicion << " con un promedio de: " << peor_materia << endl;
cout << "El alumno tuvo un promedio de: " << alumno[pos][posicion].promedio;

}