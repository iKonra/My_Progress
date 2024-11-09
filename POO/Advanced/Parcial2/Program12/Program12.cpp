//	Ej 2 (30 ptos) Un estudio de juegos indie te contrata como programador. Tu primer trabajo es programar una
//	clase llamada TDP (abreviatura de “Tabla De Puntajes”) que le será de utilidad al estudio para sus proyectos
//	actuales y próximos. El estudio te solicita que la clase maneje la TDP de un juego en particular, la cual se
//	guardará en la base de datos del estudio como un archivo binario con el nombre “puntuaciones_juego.dat”
//	donde “juego” se reemplaza con el nombre del juego. Pero hay un problema: los distintos juegos de la
//	empresa tienen distintos criterios de puntaje. Mientras que el juego SPACE SHOOTERS guarda sus puntajes
//	como una lista de enteros, el juego FROG RACING guarda sus puntajes como floats, y es posible que los
//	próximos lanzamientos de la empresa utilicen distintos criterios. Se sabe que no importa el criterio que usen,
//	siempre se pueden comparar los puntajes para ver qué jugador obtuvo el mejor puntaje, y que los mismos se
//	identifican a través de un atributo nom (que no es más que un arreglo de 5 chars, e identifica a un único
//	jugador, por lo que dos puntajes se consideran iguales si tienen el mismo nom). Entonces, para demostrarle a
//	la empresa que hicieron bien en contratarte:
//	a) Implemente la clase genérica TDP que resuelva este problema para la empresa. La clase recibe en su
//	constructor el nombre del juego, y debe cargar en memoria los datos de la tabla de puntuaciones del
//	juego.
//	b) También debe ser posible agregar puntajes. Si el jugador a agregar ya tenía un puntaje, debe actualizarlo
//	(se guarda el último puntaje, no el mejor).
//	c) Y debe poder mostrar una lista ordenada de los noms de menor a mayor.
//	d) Finalmente, la clase debe poseer una forma de actualizar el archivo binario de la base de datos (y debe
//	actualizarse automáticamente cuando la clase se destruye).
	

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template<typename D>
struct Tabla {
	char nom[5];
	D puntaje;
	bool operator<(Tabla b) {
		return(puntaje < b.puntaje);
	}
};

template<typename T>
class TDP {
string juego;
vector<Tabla<T>>puntajes;

public:
	TDP(string nombre_juego): juego(nombre_juego) {
		ifstream archi("puntuaciones_"+juego+".dat", ios::binary | ios::ate);
		
		Tabla<T>juego;
		
		int bytes = archi.tellg();
		int cantpuntajes = bytes/ (sizeof(juego.puntaje) + sizeof(juego.nom));
		archi.seekg(0);
		
			if(!archi) throw runtime_error("Error al abrir el archivo.");
			
		for(int i=0;i<cantpuntajes;i++) { 
			archi.read(reinterpret_cast<char*>(&juego),sizeof(Tabla<T>));
			
			puntajes.push_back(juego);
		
		}
	}
	void AgregarPuntaje(char nomb[5],T puntaje) {
		for(auto &x : puntajes) {
			if(x.nom == nomb) {
				x.puntaje = puntaje;
				return;
			}
		}
		Tabla<T> aux;
		aux.nom == nomb; aux.puntaje = puntaje;
		puntajes.push_back(aux);
	}
	void MostrarLista() {
		sort(puntajes.begin(),puntajes.end());
		for(auto &x : puntajes) {
			cout << x.puntaje << endl;
		}
	}
	void ActualizarBinario() {
		ofstream archi("puntuaciones_"+juego+".dat",ios::binary | ios::trunc);
		
		
			
		for(size_t i=0;i<puntajes.size();i++) { 
			
			Tabla<T>juego = puntajes[i];
			
			archi.write(reinterpret_cast<char*>(&juego), sizeof(Tabla<T>));
		}
	}
	
};

int main() {
	
	return 0;
}

