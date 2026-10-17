#include <iostream>
#include "Auto.hpp"
using namespace std;

// Llama al constructor del padre y luego guarda su atributo propio
Auto::Auto(string ma, string mo, int vel, int p) : Vehiculo(ma, mo, vel) {
    puertas = p;
}

void Auto::mostrarInfo() {
    cout << "Auto: " << marca << " " << modelo
         << " - " << velocidadMax << " km/h"
         << " - " << puertas << " puertas" << endl;
}
