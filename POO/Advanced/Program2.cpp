#include <iostream>
#include <vector>
using namespace std;
class Color {
private:
	float red,green,blue;
public:
	Color(float r,float g,float b): red(r),green(g),blue(b){}
	float VerRed(){return red;}
	float VerBlue(){return blue;}
	float VerGreen(){return green;}
	Color operator+(Color c2) {
		Color suma(this->VerRed()+c2.VerRed(),this->VerBlue()+c2.VerBlue(),this->VerGreen()+c2.VerGreen());
		return suma;
	}
	void Normalizar() {
		if(red > 1) red = 1;
		if(blue > 1) blue = 1;
		if(green > 1) green = 1;
	}
};
ostream &operator<<(ostream &o, Color x) {
	o << "red=" << x.VerRed() << " blue=" << x.VerBlue() << " green=" << x.VerGreen();
	return o;
}
class Personaje {
private:
	Color Inicial;string Nombre;vector<string> Poder;
public:
	Personaje(Color i,string n):Inicial(i),Nombre(n) {}
	Color VerInicial() {cout << Inicial; return Inicial;}
	string VerNom() {return Nombre;}
	bool TienePoder(string p) {
		for(int i=0;i<Poder.size();i++) { 
			if(Poder[i] == p) {
				return true;
			}
			return false;
		}
	}
	bool AgregarPoder(string nuevop,Color poderc) {
		if(TienePoder(nuevop) == true) {
			return false;
		} else {
			Color aux = Inicial + poderc;
			Inicial = aux;
			Inicial.Normalizar();
			Poder.push_back(nuevop);
			return true;
		}
	}
};
int main() {
	
	return 0;
}

