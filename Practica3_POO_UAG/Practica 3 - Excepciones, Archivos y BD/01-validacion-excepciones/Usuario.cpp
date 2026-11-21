#include <iostream>
#include <stdexcept>
#include <cctype>
#include "Usuario.hpp"

Usuario::Usuario() : edad(0), correo("") { }

void Usuario::setEdad(std::string texto) {
    // Reviso que todos los caracteres sean digitos
    if (texto.empty()) {
        throw std::invalid_argument("La edad no puede estar vacia.");
    }
    for (char c : texto) {
        if (!isdigit(c)) {
            throw std::invalid_argument("La edad debe ser un numero entero.");
        }
    }

    // Mas de 3 digitos ya no cabe en el rango (y evita un numero enorme)
    if (texto.size() > 3) {
        throw std::invalid_argument("La edad debe estar entre 1 y 120.");
    }

    int valor = std::stoi(texto);
    if (valor < 1 || valor > 120) {
        throw std::invalid_argument("La edad debe estar entre 1 y 120.");
    }
    edad = valor;
}

void Usuario::setCorreo(std::string texto) {
    size_t arroba = texto.find('@');
    size_t punto = texto.rfind('.');

    // Formato minimo: algo@algo.algo
    if (arroba == std::string::npos || arroba == 0) {
        throw std::invalid_argument("El correo debe tener un usuario y una @.");
    }
    if (punto == std::string::npos || punto < arroba + 2 || punto == texto.size() - 1) {
        throw std::invalid_argument("El correo debe tener un dominio, por ejemplo: uag.mx");
    }
    correo = texto;
}

void Usuario::mostrarInfo() {
    std::cout << "Edad: " << edad << "\n";
    std::cout << "Correo: " << correo << "\n";
}
