#include <iostream>
#include <string>
#include <algorithm> // Necesario para std::reverse
#include <cctype>    // Necesario para std::tolower

/* 
Procesador de cadenas: programa que reciba una frase y 
muestre: 

    - Número de palabras
    - Número de vocales
    - La frase invertida, 

usando funciones de manejo de cadenas.
*/

class ProcesadorCadenas {
private:
    std::string cadena = "";

public:
    void mostrarNumeroPalabras() {
        if (cadena.empty()) {
            std::cout << "Numero de palabras: 0\n";
            return;
        }
        int espacios = 0;
        // Contamos el número de espacios para conocer cuántas palabras hay
        for (char c : cadena) {
            if (c == ' ') {
                espacios++;
            }
        }
        int palabras = espacios + 1;
        std::cout << "Numero de palabras: " << palabras << "\n";
    }

    void mostrarNumeroVocales() {
        int vocales = 0;
        
        for (char c : cadena) {
            // contamos las vocales, primero ponemos todo minúscula.
            char letra = std::tolower(c);
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
                vocales++;
            }
        }
        std::cout << "Numero de vocales: " << vocales << "\n";
    }

    void mostrarFraseInvertida() {
        std::string cadenaInvertida = cadena;
        // Usamos la biblioteca algorithm para invertir el string.
        std::reverse(cadenaInvertida.begin(), cadenaInvertida.end());
        std::cout << "La frase invertida: " << cadenaInvertida << "\n";
    }

    void ingresarCadena() {
        std::cout << "Ingresa la cadena: ";
        // std::getline permite capturar la frase completa incluyendo espacios
        std::getline(std::cin, cadena); 
    }
};

int main() {
    ProcesadorCadenas clasificador;
    clasificador.ingresarCadena();
    std::cout << "-----------------------------------\n";
    clasificador.mostrarNumeroPalabras();
    clasificador.mostrarNumeroVocales();
    clasificador.mostrarFraseInvertida();
    return 0;
}
