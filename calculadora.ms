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

senpai opcion -chan
kohai x = 0 -chan
kohai y = 0 -chan
kohai resultado = 0 -chan

baka("Calculadora MoeScript") -chan
baka("1. Sumar") -chan
baka("2. Restar") -chan
baka("3. Multiplicar") -chan
baka("4. Dividir") -chan
baka("Elige una opcion: ") -chan
yomu(opcion) -chan

baka("Ingresa el primer número: ") -chan
yomu(x) -chan
baka("Ingresa el segundo número: ") -chan
yomu(y) -chan

moshi (opcion == 1) {
    resultado = sumar(x, y) -chan
    baka("Resultado: ", resultado) -chan
}
moshimoshi (opcion == 2) {
    resultado = restar(x, y) -chan
    baka("Resultado: ", resultado) -chan
}
moshimoshi (opcion == 3) {
    resultado = multiplicar(x, y) -chan
    baka("Resultado: ", resultado) -chan
}
moshimoshi (opcion == 4) {
    resultado = dividir(x, y) -chan
    baka("Resultado: ", resultado) -chan
}
nani {
    baka("Opcion no valida") -chan
}