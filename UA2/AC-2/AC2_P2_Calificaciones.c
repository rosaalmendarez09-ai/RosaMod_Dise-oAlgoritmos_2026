/*1. Reciba el nombre completo del estudiante.
2. Reciba tres calificaciones de 0 a 100 y las guarde en un arreglo. Cada calificación fuera de
rango se rechaza con un mensaje y se vuelve a pedir.
3. Calcule el promedio de las tres calificaciones y busque la calificación más alta recorriendo el
arreglo.
4. Determine la condición: APROBADO si el promedio es 70 o más; EN RIESGO si es 60 o más,
pero menor que 70; NO APROBADO si es menor que 60. Guarde la condición en una cadena.
5. Muestre el nombre, las tres calificaciones, el promedio (dos decimales), la calificación más alta y
la condición.*/

#include <stdio.h>
#include <string.h>

#define MIN 0
#define MAX 100

int main(void)
{
    char nombre[50], condicion[15];
    float calificaciones[3], suma = 0, promedio = 0, mayor = 0;
    int i;

    // solicitar nombre
    printf("Ingrese nombre completo: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    // recibir calificaciones y validar
    for (i = 0; i < 3; i++)
    {
        do
        {
            printf("Ingrese calificacion(0-100) %d: \n", i+1);
            scanf("%f", &calificaciones[i]);

            if (i < MIN || i > MAX){
                printf("CALIFICACION INVALIDA(0-100). \n");
            }
        } while (i < MIN || i > MAX);

        suma += calificaciones[i];
        
    }


    // PROMEDIO y mayor
    promedio = suma / 3.0;
    mayor = calificaciones[0];
    for ( i = 0; i < 3; i++)
    {
        if (calificaciones[i] > mayor)
        {
            mayor = calificaciones[i];/* code */
        }
    }


    // Determinar condicion
    if (promedio >= 70) {
        strcpy(condicion, "APROBADO");
    } else if (promedio >= 60) {
        strcpy(condicion, "EN RIESGO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }
    
    // Salida en pantalla
    printf("\n----- RESULTADOS -----\n");
    printf("Estudiante: %s\n", nombre);
    for ( i = 0; i < 3; i++)
    {
        printf("Calificaciones: %.1f \n", calificaciones[i]);
    }
    printf("Promedio:       %.2f\n", promedio);
    printf("Nota mas alta:  %.1f\n", mayor);
    printf("Condicion:    %s\n", condicion);


        return 0;
    }