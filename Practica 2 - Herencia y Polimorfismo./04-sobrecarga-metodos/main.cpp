// Ejercicio 4: Sobrecarga de metodos
#include <iostream>
#include "Calculadora.hpp"
using namespace std;

int main() {
    Calculadora calc;

    cout << "Dos enteros: 5 + 7 = " << calc.sumar(5, 7) << endl;
    cout << "Tres enteros: 1 + 2 + 3 = " << calc.sumar(1, 2, 3) << endl;
    cout << "Dos decimales: 2.5 + 3.75 = " << calc.sumar(2.5, 3.75) << endl;

    return 0;
}
