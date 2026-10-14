// promedio.c promediar datos sin aceptar cantidad != 1-10 notas!= 0-100

#include <stdio.h>

int main(void){
    int cantidad, i;
    float nota, suma = 0.0, promedio, notas[10];//arreglo para guardar las notas ingresadas
   //Inicializar el acumulador suma

    
    do{ //valida que esté entre 1-10 sino es asi vuelve a solicitar la cantidad correcta
        printf("¿Cuántas notas va a digitar?(1-10): ");
        scanf("%d", &cantidad);

        if (cantidad < 1 || cantidad > 10){
            printf("Cantidad inválida (Valor entre 1 y 10)\n");
        }
    } while (cantidad < 1 || cantidad > 10);

// ============================================================= //
           
            //Registra y valida cada nota 
    for (i = 1; i <= cantidad; i++){


        do {
            printf("Nota %d (0-100): ", i); //Muestra numero de nota
            scanf("%f", &nota);

            // Si la nota es inválida, vuelve a solicitarla
            if (nota < 0 || nota > 100){
            printf("Nota inválida. Intente de nuevo.\n" );    
                // condicion falsa, vuelve a pedir la nota y no suma la incorrecta
            }
        } while (nota < 0 || nota > 100);

            // Guardamos las notas en el arreglo
            notas[i-1] = nota;

            // Acumula solo notas validas
            suma = suma + nota;
     }//cierra for

            // Calculo de promedio
            promedio = suma/cantidad;

                // Resultados finales
            printf("====DETALLE NOTAS====\n");  
            printf("Caantidad notas ingresadas: %d\n", cantidad);
            // salida: notas ingresadas almacenadas en el arreglo
            for (i = 0; i < cantidad; i++){
                 printf("Nota %.d: %.0f\n",i + 1, notas[i]);  
            }  
            printf("Suma: %.2f\n", suma);
            printf("Promedio: %.2f\n", promedio);

    return 0;
    }