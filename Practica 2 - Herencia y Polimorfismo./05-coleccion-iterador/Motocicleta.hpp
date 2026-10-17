#ifndef MOTOCICLETA_HPP
#define MOTOCICLETA_HPP

#include "Vehiculo.hpp"

class Motocicleta : public Vehiculo {
private:
    int cilindrada;  // atributo propio

public:
    Motocicleta(std::string ma, std::string mo, int vel, int c);

    void mostrarInfo() override;
};

#endif
