// Ejercicio 5: Integracion con manejo de errores
// Archivo de texto + base de datos SQLite + excepciones
#include <iostream>
#include <stdexcept>
#include "Inventario.hpp"

int main() {
    // Prueba 1: el archivo no existe
    std::cout << "Prueba 1: leer un archivo que no existe\n";
    try {
        Inventario inventario;
        inventario.leerArchivo("productos_viejos.txt");
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    // Prueba 2: la conexion a la base de datos falla
    std::cout << "\nPrueba 2: conectar a una carpeta que no existe\n";
    try {
        Inventario inventario;
        inventario.conectar("carpeta_inexistente/inventario.db");
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    // Prueba 3: todo correcto
    std::cout << "\nPrueba 3: archivo y base de datos correctos\n";
    try {
        Inventario inventario;
        inventario.leerArchivo("productos.txt");
        inventario.conectar("inventario.db");
        inventario.guardarEnBD();
        inventario.mostrarProductos();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\nEl programa termino sin cerrarse de golpe.\n";
    return 0;
}
