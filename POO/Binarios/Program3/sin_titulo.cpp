//	Escriba un programa que genere un archivo binario con una lista de 100 enteros ordenados de forma creciente (por
//	ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba otro programa que permita insertar (no reemplazar) un nuevo dato
//	de tipo entero, ingresado por el usuario, en el archivo manteniendo el orden creciente. Importante: no debe utilizar
//	arreglos/vectores auxiliares.

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Generacion del archivo binario con 100 enteros ordenados crecientemente
    ofstream archi("creciente.dat", ios::binary);
    if (!archi) {
        cout << "El archivo no se pudo abrir." << endl;
        return 1; // Terminar el programa si el archivo no se abre
    }
    
    for (int i = 0; i < 100; i += 5) {
        archi.write(reinterpret_cast<const char*>(&i), sizeof(i));
    }
    
    cout << "Archivo generado" << endl;
    archi.close();

    // Solicitar un nuevo numero al usuario para insertarlo
    int nuevoNumero;
    cout << "Ingrese un numero para insertar en el archivo manteniendo el orden: ";
    cin >> nuevoNumero;

    // Abrir el archivo en modo lectura y escritura
    fstream archivo("creciente.dat", ios::in | ios::out | ios::binary | ios::ate);
    if (!archivo) {
        cout << "El archivo no se pudo abrir para insercion." << endl;
        return 1; // Terminar el programa si el archivo no se abre
    }

    // Variables para lectura/escritura de datos
    int numeroActual;
    long posInsercion = -1;  // Posicion donde se debe insertar el nuevo numero

    // Volver al inicio del archivo para buscar la posicion de insercion
    archivo.seekg(0, ios::beg);

    // Encontrar la posicion de insercion del nuevo numero
    while (archivo.read(reinterpret_cast<char*>(&numeroActual), sizeof(numeroActual))) {
        if (numeroActual > nuevoNumero) {
            posInsercion = archivo.tellg() - sizeof(numeroActual);
            break; // Salir del bucle cuando encontramos la posicion de insercion
        }
    }

    // Si no se encontro una posicion, el numero se debe insertar al final del archivo
    if (posInsercion == -1) {
        archivo.clear();
        posInsercion = archivo.tellp();
    }

    // Mover todos los numeros despues de la posicion de insercion hacia adelante
    archivo.seekp(0, ios::end);
    long fin = archivo.tellp(); // Posicion final del archivo

    // Desplazar cada numero hacia adelante, comenzando desde el final hacia la posicion de insercion
    for (long i = fin - sizeof(int); i >= posInsercion; i -= sizeof(int)) {
        archivo.seekg(i, ios::beg);
        archivo.read(reinterpret_cast<char*>(&numeroActual), sizeof(numeroActual));
        
        // Escribir el numero leido en la posicion siguiente para crear espacio
        archivo.seekp(i + sizeof(int), ios::beg);
        archivo.write(reinterpret_cast<const char*>(&numeroActual), sizeof(numeroActual));
    }

    // Escribir el nuevo numero en su posicion de insercion
    archivo.seekp(posInsercion, ios::beg);
    archivo.write(reinterpret_cast<const char*>(&nuevoNumero), sizeof(nuevoNumero));

    cout << "Numero insertado correctamente." << endl;
    archivo.close();

    return 0;
}

