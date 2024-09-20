// Una fábrica de tanques los hace de forma de cilindro y de esfera. 
// En ambos envases debemos rotular el volumen en m3 y el peso en kg.
// Modele una clase base Tanque con un constructor que reciba el peso,
// 	un método para consultarlo, y un método virtual para calcular su volumen.
// 	Modele la clase hija Cilindro que se construirá a partir de los argumentos 
// 	adicionales radio y altura, cuya fórmula de volumen es: área de la base * altura,
// 	donde el área de la base se calcula como pi * radio^2; y otra clase hija Esfera 
// 	con el radio como argumento adicional, cuya fórmula de volumen es: 4/3 * pi *radio^3.
// 	En el programa principal debe usar un único puntero de tipo Tanque
// 	para crear primero un Cilindro y mostrar su volumen, y luego una Esfera y también mostrar su volumen.

#include <iostream>
#include <vector>
using namespace std;
class Tecla {
private: 
	string nombre;
public:
	bool estado;
	Tecla(string d_nombre): nombre(d_nombre){};
	string VerNota() {return nombre;};
	virtual void Apretar(int numerotecla) = 0;
	virtual void Soltar(int numerotecla) = 0;
	bool EstaApretada() {return estado;};
};
class Pedal {
private: 
	float presion;
public:
	Pedal(float d_presion): presion(d_presion) {};
	void ModificarPresion(float newpresion);
	float ConsultarPresion();
};
void Pedal::ModificarPresion(float newpresion) {
	presion = newpresion;
}
float Pedal::ConsultarPresion() {
	return presion;
}
class Instrumento {
private:
	string nombre;
public:
	Instrumento(string d_nombre): nombre(d_nombre) {}
	string VerNombre() { return nombre; }
	virtual string Sonido();
	virtual ~Instrumento() {}
};
class Piano : public Tecla {
private:
	Pedal pedal;
public:
	Piano(Pedal d_pedal): pedal(d_pedal){}
	void Apretar(int numerotecla) override;
	void Soltar(int numerotecla) override;
	void PresionarPedal(float d_pedal);
};
int main() {
	
	return 0;
}

