# MoeScript - Intérprete de Lenguaje de Programación

## Descripción
MoeScript es un lenguaje de programación interpretado con sintaxis inspirada en el anime y la cultura japonesa. El lenguaje incluye características como funciones, estructuras de control, operaciones matemáticas y entrada/salida básica.

## Características
- Tipos de datos: enteros (senpai), flotantes (kohai), booleanos, strings
- Estructuras de control: if-else (moshi-nani), while (kawaii), for (douka)
- Funciones definidas por el usuario (sugoi)
- Entrada/salida (baka/yomu)
- Operadores aritméticos y de comparación
- Soporte para comentarios

## Sintaxis Básica

### Declaración de Variables
```plaintext
senpai x -chan            // Entero
kohai y = 3.14 -chan      // Flotante
```

### Funciones
```plaintext
sugoi suma(a, b) {
    uwu a + b -chan
}
```

### Estructuras de Control
```plaintext
moshi (x > 0) {
    // código
} nani {
    // código else
}

kawaii (condicion) {
    // código while
}
```

### Entrada/Salida
```plaintext
baka("Hola Mundo") -chan          // Imprimir
yomu(variable) -chan              // Leer entrada
```

## Requisitos
- Windows OS
- GCC/G++ (MinGW)
- Flex (win_flex)
- Bison (win_bison)

## Compilación
```bash
win_bison -d parser.y
win_flex lexer.l
g++ -o moescript.exe main.cpp interpreter.cpp y.tab.c lex.yy.c
```

## Uso
```bash
moescript.exe < archivo.ms
```

## Ejemplo
```plaintext
sugoi sumar(a, b) {
    uwu a + b -chan
}

senpai x = 5 -chan
senpai y = 3 -chan
senpai resultado = sumar(x, y) -chan
baka("Resultado: ", resultado) -chan
```

## Estructura del Proyecto
- `lexer.l` - Analizador léxico
- `parser.y` - Analizador sintáctico
- `ast.hpp` - Definiciones del AST
- `interpreter.hpp/cpp` - Intérprete
- `main.cpp` - Punto de entrada
- `calculadora.ms` - Ejemplo de programa

## Características del Intérprete
- Evaluación de expresiones aritméticas
- Manejo de ámbito de variables
- Llamadas a funciones
- Estructuras de control anidadas
- Conversión automática de tipos

## Limitaciones Actuales
- No soporta arrays
- No tiene manejo de excepciones personalizado
- Sin soporte para módulos o imports
- Sin optimizaciones de rendimiento

## Contribuir
Siéntete libre de contribuir al proyecto mediante pull requests o reportando issues.

## Licencia
Este proyecto está bajo la Licencia MIT.