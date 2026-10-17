# Prácticas - 2do Parcial

## Unidad 3: Herencia y Polimorfismo

> Alumno: Daniel Ernesto Garrido Sánchez
> Matrícula: 5211038
> Licenciatura: Ing. de Software y Minería de Datos

Esta práctica integra 5 ejercicios para aplicar herencia, polimorfismo y sobrecarga en C++. Cada ejercicio separa la declaración de las clases (`.hpp`) de su implementación (`.cpp`) y cuenta con un `main.cpp` para comprobar su funcionamiento.

### Ejercicios.

| # | Programa | Descripción / Requisitos | Captura de pantalla |
|---|---|---|---|
| 1 | Jerarquía simple | Crear la clase base `Vehiculo` y las clases derivadas `Auto` y `Motocicleta`; mostrar la información de cada objeto. | ![](01-jerarquia-simple/jerarquia.png) |
| 2 | Polimorfismo en acción | Guardar autos y motocicletas en un arreglo de punteros `Vehiculo*` y mostrar su información mediante un mismo método. | ![](02-polimorfismo/polimorfismo.png) |
| 3 | Sobrecarga de operadores | Crear la clase `Fraccion` y sobrecargar los operadores `+` y `==` para sumar y comparar fracciones. | ![](03-sobrecarga-operadores/sobrecarga.png) |
| 4 | Sobrecarga de métodos | Crear la clase `Calculadora` con distintas versiones del método `sumar()` para enteros y decimales. | ![](04-sobrecarga-metodos/sobrecarga.png) |
| 5 | Colección con iterador | Crear un `vector` de vehículos y recorrerlo con un iterador para mostrar la información de cada elemento. | ![](05-coleccion-iterador/coleccion-iterador.png) |

#### Reflexión de los ejercicios

**Ejercicio 1 — Jerarquía simple.** Al principio repetí los atributos de marca, modelo y velocidad en `Auto` y `Motocicleta`, en lugar de concentrarlos en `Vehiculo`.
Eso dificultaba inicializar los objetos y hacía que la jerarquía no aportara una ventaja real.
Lo corregí usando el constructor de la clase base para compartir esos datos.
En una futura versión diseñaría primero qué atributos son comunes y cuáles son exclusivos de cada clase antes de escribir el código.

**Ejercicio 2 — Polimorfismo en acción.** Mi error inicial fue pensar que un arreglo de `Vehiculo*` mostraría automáticamente los datos particulares de autos y motos.
Al probarlo, entendí que el método debía declararse como virtual en la clase base para que cada objeto respondiera de forma distinta.
Después comprobé el resultado recorriendo el arreglo y llamando al mismo método en cada posición.
Para mejorar, verificaría desde el inicio qué métodos requieren comportamiento polimórfico y documentaría esa decisión en el diseño.

**Ejercicio 3 — Sobrecarga de operadores.** Al comparar `1/2` con `2/4`, cometí el error de pensar que bastaba revisar numerador y denominador directamente.
Esa comparación falla aunque ambas fracciones representan el mismo valor, por lo que tuve que considerar productos cruzados.
Además, noté que la suma actual conserva fracciones equivalentes sin simplificarlas, como `5/6` cuando aplica.
En una siguiente iteración crearía una función para normalizar fracciones y validaría casos con denominadores negativos o cero.

**Ejercicio 4 — Sobrecarga de métodos.** Al definir las versiones de `sumar()`, confundí la sobrecarga con cambiar solamente el tipo de retorno.
Descubrí que las firmas deben diferenciarse por sus parámetros, como cantidad o tipo de argumentos.
Probé dos enteros, tres enteros y dos decimales para confirmar que el compilador seleccionara cada método correcto.
En el futuro escribiría primero una tabla con las firmas esperadas para evitar métodos ambiguos o repetidos.

**Ejercicio 5 — Colección con iterador.** Inicialmente intenté recorrer el `vector` como si guardara objetos completos, aunque en realidad almacena punteros a `Vehiculo`.
Eso me llevó a equivocarme al acceder al método y tuve que usar la desreferenciación del iterador antes de llamar a `mostrarInfo()`.
La prueba con autos y una motocicleta confirmó que el recorrido conservaba el comportamiento polimórfico.
Para una mejora posterior usaría punteros inteligentes o almacenaría objetos con una estrategia de propiedad clara para evitar problemas de memoria.
