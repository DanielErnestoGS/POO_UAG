#ifndef FRACCION_HPP
#define FRACCION_HPP

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int n, int d);

    Fraccion operator+(Fraccion otra);   // suma de fracciones
    bool operator==(Fraccion otra);      // compara si son equivalentes

    void mostrar();
};

#endif
