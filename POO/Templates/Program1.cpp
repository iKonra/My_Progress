// 1. Implemente una función templatizada llamada mayor(...) que reciba dos valores y devuelva el mayor.
//	Compruebe el correcto funcionamiento de la rutina utilizándola desde un programa cliente con valores de tipo
//	int, float y string

//	2. Programe una sobrecarga de la función mayor(...) que reciba un std::vector y retorne la posición del mayor
//	elemento del mismo. Pruebe la función sobrecargada desde un programa cliente con diversos tipos de datos.

//3. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado en el recuadro? Justifique su
//	respuesta. Si responde que no, implemente los cambios necesarios.
	

#include <iostream>
#include <vector>
using namespace std;

struct Persona {
	string nombre;
	string apellido;
	int dni;
};

template <typename T>
T Mayor(T valor1, T valor2) {
	
	T Resultado;
		
	if(valor1 > valor2) 
		return valor1;
		
	return valor2;
}

bool operator>(Persona a,Persona b) {
	if(a.dni < b.dni) {
		return true;
	}
	return false;
}

template <typename T>
int Mayor(vector<T> v) {
	
	int pos = 0;
	for(size_t i=1;i<v.size();i++) { 
		if(v[pos]< v[i]) {
			pos = i;
		}
	}
	return pos;
}


int main(int argc, char *argv[]) {
	
	
	string mayor = Mayor("zzzzz", "aaaaa");
	cout << mayor << endl;
	
	
	/////////////////////////////////////////////////////
	vector<float> v(30);
	int cont = 0;
	for(size_t i=0;i<v.size();i++) { 
		v[i] = rand()%145/13.36;
		
		cout << i << ". " << v[i] <<  " ";
		cont++;
			if(cont = 10) {
			cont = 0; cout << "\n";
			}
		
	}
	
	int busqueda = Mayor(v);
	cout << "Posicion: " << busqueda << " Valor: " << v[busqueda] << endl; 
	
	//////////////////////////////////////////////////////
	
	
	Persona people1; Persona people2;
	people1.nombre = "Conrado"; people1.apellido = "De Napoli";people1.dni = 47137014;
	people2.nombre = "John";people2.apellido = "Doe";people2.dni = 99999999;
	
	Persona personamayor = Mayor(people1,people2);
	
	cout << "La persona mayor es: " << personamayor.nombre << " " << personamayor.apellido << " con dni: " << personamayor.dni;
	
	
	
	
	
	return 0;
}
