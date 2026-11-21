#ifndef BASEDATOS_HPP
#define BASEDATOS_HPP

#include <string>
#include <sqlite3.h>

class BaseDatos {
private:
    sqlite3* conexion;
    std::string nombreArchivo;

public:
    BaseDatos(std::string nombreArchivo);
    ~BaseDatos(); // cierra la conexion

    bool conectar();
    void crearTabla();
    void insertarProducto(std::string nombre, double precio, int stock);
    void consultarProductos();
};

#endif
