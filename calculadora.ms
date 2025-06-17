sugoi sumar(a, b) {
    uwu a + b -chan
}

sugoi restar(a, b) {
    uwu a - b -chan
}

sugoi multiplicar(a, b) {
    uwu a * b -chan
}

sugoi dividir(a, b) {
    moshi (b == 0) {
        baka("No se puede dividir por cero") -chan
        uwu 0 -chan
    }
    nani {
        uwu a / b -chan
    }
}

sugoi minimo(a, b) {
    moshi (a < b) {
        uwu a -chan
    }
    nani {
        uwu b -chan
    }
}

sugoi resultadoExponente(x, y) {
    
    senpai resultado= 1 -chan
    kawaii (y > 0){
        resultado = resultado * x -chan
        y = y - 1 -chan
    }
    uwu resultado -chan
}

senpai opcion -chan
kohai x = 0 -chan
kohai y = 0 -chan
kohai resultado = 0 -chan

baka("Calculadora MoeScript o(^▽^)o") -chan
baka("1. Sumar") -chan
baka("2. Restar") -chan
baka("3. Multiplicar") -chan
baka("4. Dividir") -chan
baka("5. Exponente") -chan
baka("Elige una opcion: ") -chan
yomu(opcion) -chan

baka("Ingresa el primer numero: ") -chan
yomu(x) -chan
baka("Ingresa el segundo numero: ") -chan
yomu(y) -chan

moshi ( 0 < opcion) {
    moshi ( opcion < 6) {
        moshi (opcion == 1) {
            resultado = sumar(x, y) -chan
            baka("Resultado: ", resultado) -chan
        }
        moshi (opcion == 2) {
            resultado = restar(x, y) -chan
            baka("Resultado: ", resultado) -chan
        }
        moshi (opcion == 3) {
            resultado = multiplicar(x, y) -chan
            baka("Resultado: ", resultado) -chan
        }
        moshi (opcion == 4) {
            resultado = dividir(x, y) -chan
            baka("Resultado: ", resultado) -chan
        }
        moshi (opcion == 5) {
            resultado = resultadoExponente(x, y) -chan
            baka("Resultado: ", resultado) -chan
        }
    }
    nani {
        baka ("Opcion no valida") -chan
    }
}

nani {
    baka("Opcion no valida") -chan
}