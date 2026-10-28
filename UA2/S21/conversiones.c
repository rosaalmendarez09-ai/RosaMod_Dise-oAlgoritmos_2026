// conversiones.c Enunciado: Convertir en funcionses cuatro algoritmos
//Conversion de températura / conversion de moneda (colones por dolar)

#include <stdio.h>
#define TIPO_CAMBIO 510.0 //colones por dolar

//PROTOTIPOS DE LAS FUNCIONES
double celsiusAFahrenheit(double celsius);//devuelve los grados F
double colonesADolares(double colones);//devuelve dolares
int esBisiesto(int anio);//devuelve 1 o 0
int esNotaValida(double nota);//devuelve 1 o 0

int main (void){
    // PRUEBA DE TEMPERATURA 77.0
    printf("25 C = %.1f F (esperado 77.0)\n", celsiusAFahrenheit(25));

     // PRUEBA DE MONEDA 10.00
    printf("5100 colones = %.2f dolares(esperado 10.00)\n", colonesADolares(5100));

     // PRUEBA ANIO BISIESTO -> 1 VERDADERO
    printf("2024 bisiesto: %d (esperado 1))\n", esBisiesto(2024));

     // PRUEBA ANIO NO BISIESTO -> 0 FALSO
    printf("1900 bisiesto: %d (esperado 0)\n", esBisiesto(1900));

     // PRUEBA NOTA INVÁLIDA -> 0 FALSO
    printf("Nota 105 valida: %d (esperado 0)\n", esNotaValida(105));

        // PRUEBA NOTA VÁLIDA -> 1 VERDADERO
    printf("Nota 85 valida: %d (esperado 1)\n", esNotaValida(85));

    return 0;
}
    // CONVERSIONE: TEMPERATURA

double celsiusAFahrenheit(double celsius){
        return celsius * 9.0 / 5.0 + 32;
}

    // CONVERSIONE: MONEDA
double colonesADolares(double colones){
    return colones / TIPO_CAMBIO;
}

    // CONVERSIONE: ANIO BISIESTO
int esBisiesto(int anio){
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

      // CONVERSIONES: VALIDAR NOTA
int esNotaValida(double nota){
    return (nota >= 0 && nota <= 100);
}