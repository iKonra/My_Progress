#include <iostream>
#include <fstream>
using namespace std;
struct par {
	int x;
	float y;
};
int main() {
	
	
	ifstream archi("grupo.dat", ios::binary|ios::ate);
	if(!archi) 
		throw runtime_error("El archivo no se abrio correctamente.");
	
	int N = archi.tellg()/sizeof(par);
	archi.seekg(0);
	
	for(int i=0;i<N;i++) {
	par x;
	archi.read(reinterpret_cast<char*>(&x),sizeof(x)) ;
		cout << x.x << " " << x.y << endl;
	}
		
		
	
	return 0;
}

