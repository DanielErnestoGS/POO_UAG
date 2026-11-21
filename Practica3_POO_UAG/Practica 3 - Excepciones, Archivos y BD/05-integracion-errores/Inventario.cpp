#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Inventario.hpp"

Inventario::Inventario() : conexion(nullptr) { }

Inventario::~Inventario() {
    if (conexion != nullptr) {
        sqlite3_close(conexion);
    }
}

void Inventario::leerArchivo(std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw std::runtime_error("El archivo \"" + nombreArchivo + "\" no existe.");
    }

    // Cada linea tiene el formato: nombre,precio,stock
    std::string linea;
    while (std::getline(archivo, linea)) {
        size_t coma1 = linea.find(',');
        size_t coma2 = linea.find(',', coma1 + 1);
        if (coma1 == std::string::npos || coma2 == std::string::npos) {
            throw std::runtime_error("Linea con formato incorrecto: " + linea);
        }

        Producto p;
        p.nombre = linea.substr(0, coma1);
        p.precio = std::stod(linea.substr(coma1 + 1, coma2 - coma1 - 1));
        p.stock = std::stoi(linea.substr(coma2 + 1));
        productos.push_back(p);
    }
    archivo.close();
    std::cout << "Se leyeron " << productos.size() << " productos de " << nombreArchivo << "\n";
}

void Inventario::conectar(std::string rutaBD) {
    if (sqlite3_open(rutaBD.c_str(), &conexion) != SQLITE_OK) {
        std::string mensaje = sqlite3_errmsg(conexion);
        sqlite3_close(conexion);
        conexion = nullptr;
        throw std::runtime_error("No se pudo conectar a \"" + rutaBD + "\": " + mensaje);
    }

    std::string sql =
        "CREATE TABLE IF NOT EXISTS productos ("
        "nombre TEXT, precio REAL, stock INTEGER);"
        "DELETE FROM productos;";
    sqlite3_exec(conexion, sql.c_str(), nullptr, nullptr, nullptr);
    std::cout << "Conectado a " << rutaBD << "\n";
}

void Inventario::guardarEnBD() {
    if (conexion == nullptr) {
        throw std::runtime_error("No hay conexion con la base de datos.");
    }

    std::string sql = "INSERT INTO productos VALUES (?, ?, ?);";
    for (const auto& p : productos) {
        sqlite3_stmt* sentencia;
        sqlite3_prepare_v2(conexion, sql.c_str(), -1, &sentencia, nullptr);
        sqlite3_bind_text(sentencia, 1, p.nombre.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(sentencia, 2, p.precio);
        sqlite3_bind_int(sentencia, 3, p.stock);
        sqlite3_step(sentencia);
        sqlite3_finalize(sentencia);
    }
    std::cout << "Productos guardados en la base de datos.\n";
}

void Inventario::mostrarProductos() {
    sqlite3_stmt* sentencia;
    sqlite3_prepare_v2(conexion, "SELECT * FROM productos;", -1, &sentencia, nullptr);

    std::cout << "--- Productos en la base de datos ---\n";
    while (sqlite3_step(sentencia) == SQLITE_ROW) {
        std::cout << sqlite3_column_text(sentencia, 0) << " | $"
                  << std::fixed << std::setprecision(2)
                  << sqlite3_column_double(sentencia, 1) << " | "
                  << sqlite3_column_int(sentencia, 2) << " piezas\n";
    }
    std::cout << "-------------------------------------\n";
    sqlite3_finalize(sentencia);
}
