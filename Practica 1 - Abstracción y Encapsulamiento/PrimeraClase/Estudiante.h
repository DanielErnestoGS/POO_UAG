#pragma once
#include <string>

class Estudiante {
private:
    std::string nombre;
    std::string matricula;
    float promedio;

public:
    Estudiante(std::string nombre, std::string matricula, float promedio);

    void mostrarInformacion();
    void verificarRiesgoAcademico();
    float getPromedio() const;
    std::string getNombre() const;
};