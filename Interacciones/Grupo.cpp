// Grupo/Grupo.cpp
#include <iostream>
#include <string>
#include <vector>
#include "../PrimeraClase/Estudiante.h"

class Grupo {
private:
    std::string nombre = "Clase POO UAG";
    std::string nombreMaestro = "Maestro";
    
    // Inicializamos el vector enviándole los parámetros requeridos por el constructor
    std::vector<Estudiante> estudiantes = {
        Estudiante("Daniel Garrido", "5211038", 9.0),
        Estudiante("Ana Lopez", "5211039", 6.5),
        Estudiante("Carlos Perez", "5211040", 8.2),
        Estudiante("Maria Gomez", "5211041", 5.8),
        Estudiante("Jorge Ruiz", "5211042", 9.5)
    };

public:
    void mostrarListaEstudiantes() {
        std::cout << "--- Lista de Estudiantes ---\n";
        for (size_t i = 0; i < estudiantes.size(); i++) {
            std::cout << i + 1 << ". " << estudiantes[i].getNombre() 
                      << " (Promedio: " << estudiantes[i].getPromedio() << ")\n";
        }
        std::cout << "----------------------------\n";
    }

    void mostrarPromedioGrupo() {
        if (estudiantes.empty()) {
            std::cout << "El grupo no tiene estudiantes.\n";
            return;
        }

        float sumaPromedios = 0.0;
        for (const auto& est : estudiantes) {
            sumaPromedios += est.getPromedio();
        }
        
        float promedioGrupo = sumaPromedios / estudiantes.size();
        std::cout << "Promedio General del Grupo: " << promedioGrupo << "\n";
        std::cout << "----------------------------\n";
    }

    void mostrarDatosGrupo() {
        std::cout << "Grupo: " << nombre << "\n";
        std::cout << "Profesor: " << nombreMaestro << "\n";
        std::cout << "----------------------------\n";
        mostrarListaEstudiantes();
        mostrarPromedioGrupo();
    }
};

int main() {
    Grupo grupoDePOO;
    grupoDePOO.mostrarDatosGrupo();
    return 0;
}
