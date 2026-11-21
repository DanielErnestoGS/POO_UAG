// Ejercicio 3: Conexion a base de datos (SQLite)
#include <iostream>
#include "BaseDatos.hpp"

int main() {
    BaseDatos bd("tienda.db");

    if (!bd.conectar()) {
        return 1;
    }
    bd.crearTabla();

    bd.insertarProducto("Teclado mecanico", 899.50, 12);
    bd.insertarProducto("Mouse inalambrico", 349.00, 25);
    bd.insertarProducto("Monitor 24 pulgadas", 3499.90, 8);

    bd.consultarProductos();
    return 0;
}
