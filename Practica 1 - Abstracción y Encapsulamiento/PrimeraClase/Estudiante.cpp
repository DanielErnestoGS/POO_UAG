#include <iostream>
#include "Estudiante.h"

Estudiante::Estudiante(
    std::string nombre, 
    std::string matricula, 
    float promedio
) : nombre(nombre), matricula(matricula), promedio(promedio) { }

void Estudiante::mostrarInformacion() {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Promedio: " << promedio << "\n";
}

void Estudiante::verificarRiesgoAcademico() {
    if(promedio > 7) {
        std::cout << nombre << " NO se encuentra en riesgo academico.\n";
    } else {
        std::cout << nombre << " se encuentra en riesgo academico.\n";
    }
}

float Estudiante::getPromedio() const { return promedio; }
std::string Estudiante::getNombre() const { return nombre; }
