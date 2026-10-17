#include <iostream>
#include "Fraccion.hpp"
using namespace std;

Fraccion::Fraccion(int n, int d) {
    numerador = n;
    denominador = d;
}

// a/b + c/d = (a*d + c*b) / (b*d)
Fraccion Fraccion::operator+(Fraccion otra) {
    int n = numerador * otra.denominador + otra.numerador * denominador;
    int d = denominador * otra.denominador;
    return Fraccion(n, d);
}

// a/b es igual a c/d si a*d == c*b
bool Fraccion::operator==(Fraccion otra) {
    return numerador * otra.denominador == otra.numerador * denominador;
}

void Fraccion::mostrar() {
    cout << numerador << "/" << denominador;
}
