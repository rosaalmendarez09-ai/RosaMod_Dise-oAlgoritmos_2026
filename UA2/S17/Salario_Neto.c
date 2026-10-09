//Salario_Neto.c
#include <stdio.h>


int main(){
  
    //DEFINIR VARIABLES
    double horas, tarifaHora, bruto, montoDeduccion, neto;

    const double DEDUCCION = 0.10;

        // ENTRADA DATOS
        printf("Horas trabajadas: ");
        scanf("%lf", &horas);

        printf("Pago por hora:  ");
        scanf("%lf", &tarifaHora);

    // PROCESO
    bruto = horas * tarifaHora;

    montoDeduccion = bruto * DEDUCCION;

    neto = bruto - montoDeduccion;

    // SALIDA
    printf("Salario bruto: %.2lfcol\n", bruto);
    printf("Deduccion: %.2lfcol\n", montoDeduccion);
    printf("Salario neto: %.2lfcol\n", neto);

    return 0;
}