#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
 float e = 2.7182;
 float a,b,c,x;
 
 cout << "Primera ecuacion: \n";
 cout << "Escriba los valores de a-b-c separados por espacio: ";
 cin >> a >> b >> c; cout << "\n";
 
 float cuadratica1 = (-b+(sqrt(pow(b,2)-4*a*c)))/(2*a);
 float cuadratica2 = (-b-(sqrt(pow(b,2)-4*a*c)))/(2*a);
 
 cout << "x1: " << cuadratica1 << " x2: " << cuadratica2 << "\n";
 cout << "Nota: Si el programa muestra nan es debido a que el resultado no es positivo \n";
 
 cout << "Segunda ecuacion: \n";
 cout << "Escriba los valores de a y x separados por espacio: ";
 cin >> a >> x;
 float rta = log(2*x -1) + (-exp(2*x)+(pow(pow(x,a)-3*a*x,1.0/5.0))) / (2*x-1);
 cout << rta;
 
 
 
	return 0;
}

