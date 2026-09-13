#include <iostream>
#include <string>

class ClasificadorCalificaciones {
private:
    int calificacionNumerica = 0;
    std::string calificacionSimbolica = "";

public:
    void convertir() {
        switch (calificacionNumerica) {
        case 0 ... 59:
            calificacionSimbolica = "NA";
            mostrarResultado();
            break;
        case 60 ... 69:
            calificacionSimbolica = "S";
            mostrarResultado();
            break;
        case 70 ... 79:
            calificacionSimbolica = "B";
            mostrarResultado();
            break;
        case 80 ... 89:
            calificacionSimbolica = "MB";
            mostrarResultado();
            break;
        case 90 ... 100:
            calificacionSimbolica = "E";
            mostrarResultado();
            break;
        default:
            std::cout << "Error: No se está en los rangos permitidos :(\n";
            break;
        }
    }

    void ingresarDatos() {
        std::cout << "Ingresa la calificación del rango 0 a 100: ";
        std::cin >> calificacionNumerica;
        convertir();
    }

    void mostrarResultado() {
        std::cout << "El resultado equivalente es: " << calificacionSimbolica << "\n";
    }
};

int main() {
    ClasificadorCalificaciones clasificador;
    clasificador.ingresarDatos();
    return 0;
}
