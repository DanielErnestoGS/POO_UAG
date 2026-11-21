#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
private:
    int edad;
    std::string correo;

public:
    Usuario();

    // Lanzan std::invalid_argument si el dato no es valido
    void setEdad(std::string texto);
    void setCorreo(std::string texto);

    void mostrarInfo();
};

#endif
