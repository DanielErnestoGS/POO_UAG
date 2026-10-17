// Ejercicio 3: Sobrecarga de operadores
#include <iostream>
#include "Fraccion.hpp"
using namespace std;

int main() {
    Fraccion f1(1, 2);
    Fraccion f2(1, 3);
    Fraccion f3(2, 4);

    // Suma con el operador +
    Fraccion suma = f1 + f2;
    f1.mostrar(); cout << " + "; f2.mostrar(); cout << " = ";
    suma.mostrar(); cout << endl;

    // Comparacion con el operador ==
    f1.mostrar(); cout << " == "; f3.mostrar(); cout << " ? ";
    if (f1 == f3) cout << "Si son iguales" << endl;
    else          cout << "No son iguales" << endl;

    f1.mostrar(); cout << " == "; f2.mostrar(); cout << " ? ";
    if (f1 == f2) cout << "Si son iguales" << endl;
    else          cout << "No son iguales" << endl;

    return 0;
}
