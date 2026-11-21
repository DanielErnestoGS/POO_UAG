#include <iostream>
#include "Libro.hpp"

Libro::Libro(std::string titulo, std::string autor, int anio)
    : titulo(titulo), autor(autor), anio(anio) { }

nlohmann::json Libro::aJson() {
    nlohmann::json j;
    j["titulo"] = titulo;
    j["autor"] = autor;
    j["anio"] = anio;
    return j;
}

Libro Libro::desdeJson(nlohmann::json j) {
    return Libro(j["titulo"], j["autor"], j["anio"]);
}

void Libro::mostrarInfo() {
    std::cout << titulo << " - " << autor << " (" << anio << ")\n";
}
