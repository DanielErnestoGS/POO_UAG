// Ejercicio 2: Archivo de texto
#include <iostream>
#include "ListaTareas.hpp"

int main() {
    ListaTareas lista("tareas.txt");
    int opcion = 0;

    lista.agregarTarea("Terminar la practica 3 de POO");
    lista.agregarTarea("Estudiar para el examen practico");
    lista.agregarTarea("Subir los ejercicios a GitHub");
    lista.agregarTarea("Revisar la rubrica de evaluacion");
    lista.agregarTarea("Preparar la base de datos del proyecto");

    while (opcion != 3) {
        std::cout << "\n1. Guardar tareas en archivo\n";
        std::cout << "2. Leer tareas del archivo\n";
        std::cout << "3. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        // Si escriben letras, limpio cin para que no se cicle
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            opcion = 0;
        }

        if (opcion == 1) {
            lista.guardarEnArchivo();
        } else if (opcion == 2) {
            lista.leerDeArchivo();
        } else if (opcion != 3) {
            std::cout << "Opcion no valida.\n";
        }
    }
    return 0;
}
