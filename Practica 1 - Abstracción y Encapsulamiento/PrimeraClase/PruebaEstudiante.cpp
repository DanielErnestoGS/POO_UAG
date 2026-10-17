#include <iostream>
#include "Estudiante.h"

int main() {
    Estudiante estudiante("Daniel Garrido", "5211038", 9.0);
    estudiante.mostrarInformacion();
    estudiante.verificarRiesgoAcademico();
    return 0;
}