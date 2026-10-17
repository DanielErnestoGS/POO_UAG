#include <iostream>

class Calculadora {
private:
    float primerNumero = 0.0;
    float segundoNumero = 0.0;
    float resultado = 0.0;
    char operador = ' ';

public:
    void sumar() {
        resultado = primerNumero + segundoNumero;
        mostrarResultado();
    }

    void restar() {
        resultado = primerNumero - segundoNumero;
        mostrarResultado();
    }

    void multiplicar() {
        resultado = primerNumero * segundoNumero;
        mostrarResultado();
    }

    void dividir() {
        if (segundoNumero != 0) {
            resultado = primerNumero / segundoNumero;
            mostrarResultado();
        } else {
            std::cout << "Error: No se puede dividir entre cero. :(\n";
        }
    }

    void ingresarDatos() {
        std::cout << "Ingresa el primer numero: ";
        std::cin >> primerNumero;
        
        std::cout << "Ingresa el operador (+, -, *, /): ";
        std::cin >> operador;
        
        std::cout << "Ingresa el segundo numero: ";
        std::cin >> segundoNumero;
        
        // Ejecuta la operacion segun el operador ingresado
        switch (operador) {
            case '+': sumar(); break;
            case '-': restar(); break;
            case '*': multiplicar(); break;
            case '/': dividir(); break;
            default:  std::cout << "Operador no valido.\n"; break;
        }
    }

    void mostrarResultado() {
        std::cout << "El resultado es: " << resultado << "\n";
    }
};

int main() {
    Calculadora miCalculadora;
    miCalculadora.ingresarDatos();
    return 0;
}
