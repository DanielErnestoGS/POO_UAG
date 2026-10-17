// Ejercicio 5: Coleccion con iterador
#include <vector>
#include "Auto.hpp"
#include "Motocicleta.hpp"
using namespace std;

int main() {
    Auto a1("Volkswagen", "Jetta", 200, 4);
    Auto a2("Chevrolet", "Aveo", 170, 4);
    Motocicleta m1("Kawasaki", "Ninja 400", 190, 399);

    // Vector (lista) de vehiculos
    vector<Vehiculo*> flota;
    flota.push_back(&a1);
    flota.push_back(&m1);
    flota.push_back(&a2);

    // Iterador: empieza en begin() y avanza hasta end()
    vector<Vehiculo*>::iterator it;
    for (it = flota.begin(); it != flota.end(); it++) {
        (*it)->mostrarInfo();
    }

    return 0;
}
