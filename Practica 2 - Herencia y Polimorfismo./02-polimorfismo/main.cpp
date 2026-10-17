// Ejercicio 2: Polimorfismo en accion
#include "Auto.hpp"
#include "Motocicleta.hpp"

int main() {
    Auto a1("Nissan", "Versa", 175, 4);
    Auto a2("Mazda", "MX-5", 215, 2);
    Motocicleta m1("Honda", "CBR500R", 190, 471);
    Motocicleta m2("Italika", "FT150", 95, 150);

    // Arreglo de punteros a Vehiculo que guarda Autos y Motocicletas
    Vehiculo* lista[4] = { &a1, &m1, &a2, &m2 };

    // Se llama al mismo metodo, pero cada objeto responde distinto
    for (int i = 0; i < 4; i++) {
        lista[i]->mostrarInfo();
    }

    return 0;
}
