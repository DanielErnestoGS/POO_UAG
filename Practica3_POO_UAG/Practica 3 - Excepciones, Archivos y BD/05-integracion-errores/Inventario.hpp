#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <string>
#include <vector>
#include <sqlite3.h>

struct Producto {
    std::string nombre;
    double precio;
    int stock;
};

class Inventario {
private:
    sqlite3* conexion;
    std::vector<Producto> productos;

public:
    Inventario();
    ~Inventario();

    // Lanzan std::runtime_error si algo falla
    void leerArchivo(std::string nombreArchivo);
    void conectar(std::string rutaBD);
    void guardarEnBD();

    void mostrarProductos();
};

#endif
