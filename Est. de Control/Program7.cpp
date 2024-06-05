// Escriba todos los caracteres del código ASCII. 
// b) Sólo las letras del abecedario en mayúsculas. 
// c) Las letras del abecedario en minúsculas.

// Codigo modificado para mas opciones
	

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	char Inicio;
	char Final;
	char Eleccion;
	
	cout << "Menu: \n";
	cout << "a)Escribir todo el codigo ASCII \n";
	cout << "b)Escribir solo las letras mayusculas \n";
	cout << "c)Escribir solo las letras minusculas\n";
	cout << "Elija una opcion: "; cin >> Eleccion;
	
	if(Eleccion == 'a') {
		for(int i=0;i<256;i++) { 
			char c = i; // se crea otra variable char ya que si i fuera de tipo char cuando toma el valor de 255 se reinicia a 0 y nunca termina
			cout << c << " ";
		}
	} else if (Eleccion == 'b') {
		for(int i='A';i<='Z';i++) { 
			char c = i;
			
			cout << c << " ";
			
		}
	} else if(Eleccion == 'c') {
		for(int i='a';i<='z';i++) { 
			char c = i;
			
			cout << c << " ";
			
		}
	} else {
		cout << "La opcion no es valida.";
	}
	
	// switch (Eleccion) {
	//case 'a':
	//	for (int i = 0; i < 256; ++i) {
	//		char c = i;
	//		cout << c << " ";
	//	}
	//	break;
	//case 'b':
	//	for (int i = 'A'; i <= 'Z'; ++i) {
	//		char c = i;
	//		cout << c << " ";
	//	}
	//	break;
	//case 'c':
	//	for (int i = 'a'; i <= 'z'; ++i) {
	//		char c = i;
	//	}
	//	break;
	//default:
	//	cout << "La opcion no es valida.";
	//	break;
	//}
	
	
	return 0;
}

