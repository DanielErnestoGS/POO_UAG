# Herencia y Polimorfismo en C++

Cinco ejercicios de Programación Orientada a Objetos. En cada carpeta, cada clase tiene su archivo `.hpp` (declaración) y su `.cpp` (implementación), además de un `main.cpp` que la prueba.

## Ejercicios

| Carpeta | Tema | Qué hace |
|---|---|---|
| `01-jerarquia-simple/` | Herencia | Clase `Vehiculo` y sus hijas `Auto` y `Motocicleta` |
| `02-polimorfismo/` | Polimorfismo | Arreglo de `Vehiculo*` con autos y motos; cada uno muestra su propia info |
| `03-sobrecarga-operadores/` | Operadores | Clase `Fraccion` con `+` y `==` |
| `04-sobrecarga-metodos/` | Métodos | Clase `Calculadora` con tres versiones de `sumar()` |
| `05-coleccion-iterador/` | Iterador | `vector` de vehículos recorrido con un iterador |

## Cómo ejecutar

```bash
cd 01-jerarquia-simple
g++ *.cpp -o programa
./programa
```

`*.cpp` compila juntos todos los archivos `.cpp` de la carpeta. Se hace igual en cada una. En Windows se ejecuta `programa.exe`.

## Autor

Daniel Garrido — UAG, Jul–Dic 2026
