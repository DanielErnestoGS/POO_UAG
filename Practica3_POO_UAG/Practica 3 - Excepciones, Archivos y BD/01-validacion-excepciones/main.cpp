// Ejercicio 1: Validacion con excepciones
#include <iostream>
#include <stdexcept>
#include <string>
#include "Usuario.hpp"

int main() {
    Usuario usuario;
    std::string entrada;
    bool valido = false;

    // Se repite hasta que la edad sea correcta
    while (!valido) {
        std::cout << "Ingresa tu edad: ";
        std::getline(std::cin, entrada);
        try {
            usuario.setEdad(entrada);
            valido = true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    valido = false;
    while (!valido) {
        std::cout << "Ingresa tu correo: ";
        std::getline(std::cin, entrada);
        try {
            usuario.setCorreo(entrada);
            valido = true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "\nDatos registrados:\n";
    usuario.mostrarInfo();
    return 0;
}
