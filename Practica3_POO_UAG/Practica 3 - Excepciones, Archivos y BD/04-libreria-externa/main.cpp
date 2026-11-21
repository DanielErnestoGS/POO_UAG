// Ejercicio 4: Uso de una libreria externa (nlohmann/json)
// Guardar una lista de libros en un archivo JSON y volver a leerla
#include <iostream>
#include <fstream>
#include <vector>
#include "Libro.hpp"

int main() {
    std::vector<Libro> libros = {
        Libro("Cien anios de soledad", "Gabriel Garcia Marquez", 1967),
        Libro("Pedro Paramo", "Juan Rulfo", 1955),
        Libro("El principito", "Antoine de Saint-Exupery", 1943)
    };

    // 1. Convertir los libros a JSON y guardarlos
    nlohmann::json lista = nlohmann::json::array();
    for (auto& libro : libros) {
        lista.push_back(libro.aJson());
    }

    std::ofstream salida("libros.json");
    salida << lista.dump(4); // dump(4) = con sangria de 4 espacios
    salida.close();
    std::cout << "Contenido de libros.json:\n" << lista.dump(4) << "\n";

    // 2. Leer el archivo y convertir el JSON otra vez a objetos
    std::ifstream entrada("libros.json");
    nlohmann::json leido = nlohmann::json::parse(entrada);
    entrada.close();

    std::cout << "\nLibros leidos desde el archivo:\n";
    for (auto& elemento : leido) {
        Libro libro = Libro::desdeJson(elemento);
        libro.mostrarInfo();
    }
    std::cout << "Total: " << leido.size() << " libros\n";
    return 0;
}
