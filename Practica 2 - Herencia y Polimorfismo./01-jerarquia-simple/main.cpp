// Ejercicio 1: Jerarquia simple
#include "Auto.hpp"
#include "Motocicleta.hpp"

int main() {
    Vehiculo v("Generico", "Base", 100);
    Auto a("Toyota", "Corolla", 180, 4);
    Motocicleta m("Yamaha", "MT-07", 210, 689);

    v.mostrarInfo();
    a.mostrarInfo();
    m.mostrarInfo();

    return 0;
}
