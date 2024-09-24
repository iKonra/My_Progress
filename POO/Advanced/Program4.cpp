//	Programar una clase Animal que tenga un método desplazarse() y otro método tipo(). Programe las
//	clases Mamifero, Ave y Pez, que son hijas de la clase Animal. Los atributos de las clases son el tipo y
//	la especie del animal, cuyos valores deben ser pasados al constructor de la clase base. Además deberá
//	sobreescribir los métodos desplazarse() y tipo(), de tal manera que el primer método devuelve una
//	cadena de texto indicando el tipo de desplazamiento según el tipo: “camina” para el tipo “mamífero”,
//	“vuela” para el tipo “ave” y “nada” para el tipo “pez”. Escriba un programa cliente que permita modelar un
//	Parque y almacene la información de los animales en un único arreglo de 30 elementos y luego emita
//	un listado de los mismos describiendo el tipo y la forma de desplazamiento de cada animal. Finalmente
//	responda: ¿Hay entre las clases algún método virtual puro?¿Por qué?
	

#include <iostream>
#include <vector>
using namespace std;

class Animal {
protected:
	string m_tipo;
	string m_especie;
public:
	Animal(string tipo, string especie) : m_tipo(tipo), m_especie(especie) {}
	virtual string desplazarse() = 0;
	string VerTipo() { return m_tipo; }
	string VerEspecie() { return m_especie; }
};

class Mamifero : public Animal {
public:
	Mamifero(string especie) : Animal("mamifero", especie) {}
	string desplazarse() override { return "camina"; }
};

class Ave : public Animal {
public:
	Ave(string especie) : Animal("ave", especie) {}
	string desplazarse() override { return "vuela"; }
};

class Pez : public Animal {
public:
	Pez(string especie) : Animal("pez", especie) {}
	string desplazarse() override { return "nada"; }
};

class Parque {
private:
	vector<Animal*> animales;
public:
	Parque(vector<Animal*> a) : animales(a) {}
	void VerAnimales() {
		for (int i = 0; i < animales.size(); i++) {
			cout << "Tipo: " << animales[i]->VerTipo() 
				<< " Especie: " << animales[i]->VerEspecie()
				<< " Desplazamiento: " << animales[i]->desplazarse() << endl;
		}
	}
};

int main() {
	// Crear una lista de 30 animales
	vector<Animal*> animales;
	
	// Añadir 10 mamíferos
	animales.push_back(new Mamifero("leon"));
	animales.push_back(new Mamifero("tigre"));
	animales.push_back(new Mamifero("elefante"));
	animales.push_back(new Mamifero("gato"));
	animales.push_back(new Mamifero("perro"));
	animales.push_back(new Mamifero("vaca"));
	animales.push_back(new Mamifero("caballo"));
	animales.push_back(new Mamifero("jirafa"));
	animales.push_back(new Mamifero("raton"));
	animales.push_back(new Mamifero("koala"));
	
	// Añadir 10 aves
	animales.push_back(new Ave("aguila"));
	animales.push_back(new Ave("halcon"));
	animales.push_back(new Ave("loro"));
	animales.push_back(new Ave("pinguino"));
	animales.push_back(new Ave("pato"));
	animales.push_back(new Ave("cisne"));
	animales.push_back(new Ave("buho"));
	animales.push_back(new Ave("paloma"));
	animales.push_back(new Ave("gaviota"));
	animales.push_back(new Ave("cuervo"));
	
	// Añadir 10 peces
	animales.push_back(new Pez("delfin"));
	animales.push_back(new Pez("tiburon"));
	animales.push_back(new Pez("piraña"));
	animales.push_back(new Pez("pez payaso"));
	animales.push_back(new Pez("pez espada"));
	animales.push_back(new Pez("bagre"));
	animales.push_back(new Pez("sardina"));
	animales.push_back(new Pez("atún"));
	animales.push_back(new Pez("mero"));
	animales.push_back(new Pez("trucha"));
	
	// Crear el parque con los animales
	Parque parque(animales);
	
	// Ver la lista de animales en el parque
	parque.VerAnimales();
	
	// Liberar memoria
	for (auto animal : animales) {
		delete animal;
	}
	
	return 0;
}
