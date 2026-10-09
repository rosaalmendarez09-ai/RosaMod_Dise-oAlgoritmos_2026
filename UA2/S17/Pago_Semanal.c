// Pago_Semanal.c calcula pago semanal
#include <stdio.h>

// CONSTANTE
#define BONO 5000.0

int main(void){

    // DEFINO VARIABLES
    double horas, pagoHora, bono, salario;

        // Entrada
    printf("Horas trabajadas en la semana:  ");
    scanf("%lf", &horas);

    printf("Pago por hora:  ");
    scanf("%lf", &pagoHora);

    // Proceso
    salario = (horas * pagoHora) + BONO;

    // Salida: COLOCAR EL SALTO LUEGO DE LA INDICACION DE TIPO DE SALIDA
    printf("=================================\n");
    printf("%-18s %10.2f\n","Horas:", horas);

    printf("%-18s %10.2f\n","Pago por hora:", pagoHora);

    printf("%-18s %10.2f\n","Bono:", BONO);

    printf("%-18s %10.2f\n","Pago semanal:", salario);

    printf("=================================\n");


    return 0;
}