#include <iostream>
#include <fstream>
#include "ListaTareas.hpp"

ListaTareas::ListaTareas(std::string nombreArchivo) : nombreArchivo(nombreArchivo) { }

void ListaTareas::agregarTarea(std::string tarea) {
    tareas.push_back(tarea);
}

void ListaTareas::guardarEnArchivo() {
    std::ofstream archivo(nombreArchivo); // crea o sobrescribe el archivo
    if (!archivo.is_open()) {
        std::cout << "No se pudo crear " << nombreArchivo << "\n";
        return;
    }

    for (const auto& tarea : tareas) {
        archivo << tarea << "\n"; // una tarea por linea
    }
    archivo.close();
    std::cout << "Se guardaron " << tareas.size() << " tareas en " << nombreArchivo << "\n";
}

void ListaTareas::leerDeArchivo() {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "El archivo " << nombreArchivo << " todavia no existe.\n";
        return;
    }

    std::string linea;
    int numero = 1;
    std::cout << "--- Tareas pendientes ---\n";
    while (std::getline(archivo, linea)) {
        std::cout << numero << ". " << linea << "\n";
        numero++;
    }
    std::cout << "-------------------------\n";
    archivo.close();
}
