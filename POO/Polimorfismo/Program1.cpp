#include <iostream>
#include <cmath>
using namespace std;
class Tanque {
private:
	float peso;
public:
	virtual ~Tanque() {}
	Tanque(float d_peso) : peso(d_peso){};
	virtual void CalcularVolumen() = 0;
	virtual float MostrarVolumen() = 0;
	
};
class Cilindro: public Tanque {
private:
	float radio, altura, volumen;
public:
	Cilindro(float d_radio,float d_altura, float d_peso):Tanque(d_peso),radio(d_radio),altura(d_altura){}
	void CalcularVolumen() override;
	float MostrarVolumen() override;
};
class Esfera: public Tanque {
private:
	float radio, altura, volumen;
public:
	Esfera(float d_radio,float d_altura,float d_peso):Tanque(d_peso),radio(d_radio),altura(d_altura){}
	void CalcularVolumen() override;
	float MostrarVolumen() override;
};
void Cilindro::CalcularVolumen() {
	float area = 3.1416*pow(radio,2);
	volumen = area*altura;
}
float Cilindro::MostrarVolumen() {
	return volumen;
}
void Esfera::CalcularVolumen() {
	volumen = 4/3 * 3.1416 * pow(radio,3);
}
float Esfera::MostrarVolumen() {
	return volumen;
}
int main() {
	float d_radio, d_altura, d_peso;
	cout << "Cual es el radio: "; cin >> d_radio;
	cout << "\nCual es el altura: ";cin >> d_altura;
	cout << "\nCual es el peso: "; cin >> d_peso;
	Tanque *p = new Cilindro(d_radio,d_altura,d_peso);
	p->CalcularVolumen();
	float d_volumen = p->MostrarVolumen();
	cout << "El volumen del tanque cilindrico: " << d_volumen;
	delete p;
	cout << "\nCual es el radio: "; cin >> d_radio;
	cout << "\nCual es el altura: ";cin >> d_altura;
	cout << "\nCual es el peso: "; cin >> d_peso;
	p = new Esfera(d_radio,d_altura,d_peso);
	p->CalcularVolumen();
	d_volumen = p->MostrarVolumen();
	cout << "\nEl volumen del tanque esferico: " << d_volumen;
	
	return 0;
}

