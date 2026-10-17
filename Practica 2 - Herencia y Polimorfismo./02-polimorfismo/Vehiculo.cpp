#include <iostream>
#include "Vehiculo.hpp"
using namespace std;

Vehiculo::Vehiculo(string ma, string mo, int vel) {
    marca = ma;
    modelo = mo;
    velocidadMax = vel;
}

void Vehiculo::mostrarInfo() {
    cout << "Vehiculo: " << marca << " " << modelo
         << " - " << velocidadMax << " km/h" << endl;
}
