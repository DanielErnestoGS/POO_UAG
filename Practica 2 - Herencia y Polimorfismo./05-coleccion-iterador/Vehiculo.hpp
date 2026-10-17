#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int velocidadMax;

public:
    Vehiculo(std::string ma, std::string mo, int vel);

    // "virtual" permite que las clases hijas cambien este metodo
    virtual void mostrarInfo();
};

#endif
