#include <iostream>
#include <iomanip>
#include "BaseDatos.hpp"

BaseDatos::BaseDatos(std::string nombreArchivo)
    : conexion(nullptr), nombreArchivo(nombreArchivo) { }

BaseDatos::~BaseDatos() {
    if (conexion != nullptr) {
        sqlite3_close(conexion);
        std::cout << "Conexion cerrada.\n";
    }
}

bool BaseDatos::conectar() {
    // Si el archivo .db no existe, sqlite lo crea
    if (sqlite3_open(nombreArchivo.c_str(), &conexion) != SQLITE_OK) {
        std::cout << "Error al conectar: " << sqlite3_errmsg(conexion) << "\n";
        return false;
    }
    std::cout << "Conectado a " << nombreArchivo << "\n";
    return true;
}

void BaseDatos::crearTabla() {
    std::string sql =
        "CREATE TABLE IF NOT EXISTS productos ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nombre TEXT NOT NULL, "
        "precio REAL NOT NULL, "
        "stock INTEGER NOT NULL);"
        "DELETE FROM productos;"; // cada prueba empieza con la tabla vacia

    sqlite3_exec(conexion, sql.c_str(), nullptr, nullptr, nullptr);
    std::cout << "Tabla productos lista.\n";
}

void BaseDatos::insertarProducto(std::string nombre, double precio, int stock) {
    // Los ? se reemplazan con los valores (sentencia preparada)
    std::string sql = "INSERT INTO productos (nombre, precio, stock) VALUES (?, ?, ?);";
    sqlite3_stmt* sentencia;

    sqlite3_prepare_v2(conexion, sql.c_str(), -1, &sentencia, nullptr);
    sqlite3_bind_text(sentencia, 1, nombre.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(sentencia, 2, precio);
    sqlite3_bind_int(sentencia, 3, stock);

    if (sqlite3_step(sentencia) == SQLITE_DONE) {
        std::cout << "Insertado: " << nombre << "\n";
    } else {
        std::cout << "Error al insertar: " << sqlite3_errmsg(conexion) << "\n";
    }
    sqlite3_finalize(sentencia);
}

void BaseDatos::consultarProductos() {
    std::string sql = "SELECT id, nombre, precio, stock FROM productos;";
    sqlite3_stmt* sentencia;

    sqlite3_prepare_v2(conexion, sql.c_str(), -1, &sentencia, nullptr);

    std::cout << "\n--- Registros de la tabla productos ---\n";
    // sqlite3_step avanza una fila cada vez
    while (sqlite3_step(sentencia) == SQLITE_ROW) {
        std::cout << sqlite3_column_int(sentencia, 0) << " | "
                  << sqlite3_column_text(sentencia, 1) << " | $"
                  << std::fixed << std::setprecision(2)
                  << sqlite3_column_double(sentencia, 2) << " | "
                  << sqlite3_column_int(sentencia, 3) << " piezas\n";
    }
    std::cout << "---------------------------------------\n";
    sqlite3_finalize(sentencia);
}
