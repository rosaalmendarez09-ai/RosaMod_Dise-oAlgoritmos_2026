// planilla.c calcula la planilla de un grupo de personas sin saber cuántas son. Centinela -1 indica el final.

#include <stdio.h>

// Constante CENTINELA indica el final
#define CENTINELA -1

int main(void){

    // Variables
int cantidad, i, conExtra;
char nombre[50];
double horas, tarifa, horasExtra, pago, totalPlanilla;

    totalPlanilla = 0.0; //ACUMULADOR: suma todos los pagos
    i = 0; //CONTADOR 1
    conExtra = 0; //CONTADOR 2

    printf("Cantidad de personas colaboradoras(-1 para salir): ");
    scanf("%d", &cantidad);


    // while 
    i = 1; //INICIALIZAR contador
    while (cantidad != CENTINELA)
      {   //PREGUNTAR
        printf("Nombre: \n");
        scanf("%49s", nombre);

        printf("Horas de la semana(0-72): ");
        scanf("%lf", &horas);

            if (horas < 0 || horas > 72)
            {
            printf("Dato inválido, intente de nuevo");
            }
            else {
             printf("Tarifa por hora: \n");
             scanf("%lf", &tarifa);
            }

            if (horas > 48){
            horasExtra = horas - 48;
            pago = (48 * tarifa) + (horasExtra * (tarifa * 1.5));
            conExtra = conExtra + 1;
            }
                else {
                    pago = horas * tarifa;
                }

                    printf("\nPago para %s: %.2f", nombre, pago);
                    totalPlanilla = totalPlanilla + pago;
            }
      i = i++;    //ACTUALIZAR
      printf("\nIngrese nueva cantidad o -1 para salir: ");
      scanf("%d", &cantidad);

      printf("Total de la planilla: %.2f\n", totalPlanilla);
      printf("Personas con horas extra: ", conExtra);

    return 0;
}