#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>
#include <nlohmann/json.hpp> // libreria externa

class Libro {
private:
    std::string titulo;
    std::string autor;
    int anio;

public:
    Libro(std::string titulo, std::string autor, int anio);

    nlohmann::json aJson();                    // Libro -> JSON
    static Libro desdeJson(nlohmann::json j);  // JSON -> Libro
    void mostrarInfo();
};

#endif
