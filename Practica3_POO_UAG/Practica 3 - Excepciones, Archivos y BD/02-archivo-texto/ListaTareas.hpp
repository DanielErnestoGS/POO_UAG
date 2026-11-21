#ifndef LISTATAREAS_HPP
#define LISTATAREAS_HPP

#include <string>
#include <vector>

class ListaTareas {
private:
    std::string nombreArchivo;
    std::vector<std::string> tareas;

public:
    ListaTareas(std::string nombreArchivo);

    void agregarTarea(std::string tarea);
    void guardarEnArchivo();
    void leerDeArchivo();
};

#endif
