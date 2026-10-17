// planilla.c calcula la planilla de un grupo de personas sin saber cuántas son. Centinela -1 indica el final.SALIDA: cuantas personas, horas extras y totalplanilla.


#include <stdio.h>
#include <string.h> //libreria manejo de fgets- strcspn

// Constante CENTINELA indica el final
#define CENTINELA -1
#define LIMITE 48
#define RECARGO 1.5

int main(void){

// Variables
int cantidad, i = 0, conExtra = 0;//acumula extras
char nombre[50];
double horas, tarifa, horasExtra, pago, totalPlanilla = 0.0;//acumula pagos


    printf("Cuantos colaboradores?(-1:Salir): ");
    scanf("%d", &cantidad);

    // while 
    while (cantidad != CENTINELA){  //preguntar

        i++;//contador de personas
        while (getchar() != '\n'); //limpia el salto del scanf

        printf("Nombre completo %d: ", i);
        fgets(nombre, sizeof(nombre), stdin);

        do{
        printf("Horas de la semana(0-72): ");
        scanf("%lf", &horas);
            if (horas < 0 || horas > 72){
            printf("Dato invalido, ingrese las horas correctas: ");
            scanf("%lf", &horas);
            }
        }while (horas < 0 || horas > 72);
       
        printf("Tarifa por hora: ");
        scanf("%lf", &tarifa);

            if (horas > LIMITE)
            {
            horasExtra = horas - LIMITE; 
            pago = (LIMITE * tarifa) + (horasExtra * (tarifa * RECARGO));
            conExtra += 1;
            }
            else
            {
                horasExtra = 0; // sino hay extras
                pago = horas * tarifa;
            }
        
            totalPlanilla += pago;
    
        printf("\n========================================\n");
        printf("  RESUMEN\n");
        printf("  %s", nombre);
        nombre[strcspn(nombre,"")]='\0';
        printf("  Horas totales : %.1f hrs\n", horas);
        printf("  Horas extras  : %.1f hrs\n", horasExtra);
        printf("  Pago semanal  : ₡%.2f\n", pago);
        printf("========================================\n");

        // 4. RE-LECTURA AL FINAL DEL BUCLE
        printf("\n¿Desea ingresar otro colaborador? (-1: Salir): ");
        scanf("%d", &cantidad);
        }

        printf("\n========================================\n");
        printf("  RESUMEN GENERAL\n");
        printf("  Cantidad de personas: %d\n", i);
        printf("  Con extras: %d\n", conExtra);
        printf("  Total planilla: %.2lf\n", totalPlanilla);
        printf("\n========================================\n");
    return 0;
}