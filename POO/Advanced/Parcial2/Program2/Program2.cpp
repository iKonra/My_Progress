#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Usuario {
private:
    int codigo;        // Codigo unico del usuario
    string sector;     // Sector al que pertenece el usuario
    string apellido;   // Apellido del usuario
    string nombre;     // Nombre del usuario
    string password;   // Password generado para el usuario

public:
    // Constructor que inicializa los atributos y llama a GeneraPassword para crear la contrasena
    Usuario(int cod, const string &sec, const string &apell, const string &nom)
        : codigo(cod), sector(sec), apellido(apell), nombre(nom) {
        GeneraPassword(); // Genera la contrasena usando el nombre, apellido y sector
    }

    // Funcion que genera la contrasena del usuario concatenando sector, 
    // la primera letra del nombre, y el apellido completo
    void GeneraPassword() {
        char primeraLetra = nombre[0]; // Obtiene la primera letra del nombre
        // La funcion string(1, primeraLetra) convierte 'primeraLetra' en un string de un caracter
        // Esto permite la concatenacion con 'sector' y 'apellido' de forma mas facil
        password = sector + string(1, primeraLetra) + apellido;
    }

    // Metodo que escribe los datos del usuario en un archivo binario
    void CreaBinario(ofstream &archivoBinario) const {
        // Escribe el codigo como un entero directamente en el archivo binario
        archivoBinario.write(reinterpret_cast<const char*>(&codigo), sizeof(codigo));

        // Escribe el tamanio y contenido del sector en el archivo binario
        size_t sizeSector = sector.size();
        archivoBinario.write(reinterpret_cast<const char*>(&sizeSector), sizeof(sizeSector));
        
        // 'sector.c_str()' convierte 'sector' a un puntero const char*
        // Esto es necesario porque ofstream::write solo acepta const char* en lugar de un string
        archivoBinario.write(sector.c_str(), sizeSector);

        // Escribe el tamanio y contenido del apellido
        size_t sizeApellido = apellido.size();
        archivoBinario.write(reinterpret_cast<const char*>(&sizeApellido), sizeof(sizeApellido));
        archivoBinario.write(apellido.c_str(), sizeApellido);

        // Escribe el tamanio y contenido del nombre
        size_t sizeNombre = nombre.size();
        archivoBinario.write(reinterpret_cast<const char*>(&sizeNombre), sizeof(sizeNombre));
        archivoBinario.write(nombre.c_str(), sizeNombre);

        // Escribe el tamanio y contenido de la contrasena
        size_t sizePassword = password.size();
        archivoBinario.write(reinterpret_cast<const char*>(&sizePassword), sizeof(sizePassword));
        archivoBinario.write(password.c_str(), sizePassword);
    }
};

int main() {
    // Abre el archivo de texto para leer
    ifstream archivoTexto("USUARIOS.TXT");
    if (!archivoTexto) {
        cerr << "Error al abrir el archivo USUARIOS.TXT" << endl;
        return 1;
    }

    // Abre el archivo binario para escritura
    ofstream archivoBinario("USUARIOS.dat", ios::binary);
    if (!archivoBinario) {
        cerr << "Error al crear el archivo USUARIOS.dat" << endl;
        return 1;
    }

    string linea;
    // Lee el archivo de texto linea por linea
    while (getline(archivoTexto, linea)) {
        if (linea.empty()) continue; // Ignora lineas vacias

        // Usa stringstream para dividir la linea en codigo, sector, apellido y nombre
        stringstream ss(linea);
        int codigo;
        string sector, apellido, nombre;

        ss >> codigo >> sector >> apellido >> nombre;

        // Crea un objeto Usuario usando los datos extraidos
        Usuario usuario(codigo, sector, apellido, nombre);

        // Escribe los datos del usuario en el archivo binario
        usuario.CreaBinario(archivoBinario);
    }

    // Cierra los archivos
    archivoTexto.close();
    archivoBinario.close();

    cout << "Archivo binario USUARIOS.dat creado exitosamente." << endl;

    return 0;
}
