#include <iostream>
#include "Motocicleta.hpp"
using namespace std;

Motocicleta::Motocicleta(string ma, string mo, int vel, int c) : Vehiculo(ma, mo, vel) {
    cilindrada = c;
}

void Motocicleta::mostrarInfo() {
    cout << "Motocicleta: " << marca << " " << modelo
         << " - " << velocidadMax << " km/h"
         << " - " << cilindrada << " cc" << endl;
}
