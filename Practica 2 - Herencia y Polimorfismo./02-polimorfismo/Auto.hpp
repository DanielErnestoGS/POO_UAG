#ifndef AUTO_HPP
#define AUTO_HPP

#include "Vehiculo.hpp"

class Auto : public Vehiculo {
private:
    int puertas;  // atributo propio

public:
    Auto(std::string ma, std::string mo, int vel, int p);

    // Sobrescribe el metodo de la clase base
    void mostrarInfo() override;
};

#endif
