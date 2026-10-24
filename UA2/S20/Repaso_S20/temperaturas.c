/* temperaturas.c -  Temperaturas de la semana
==========================================================================
 * ENUNCIADO:
    Solicitar temperatura maxima del dia, mostrar el nombre del dia: lunes a domingo.(0-45°C)
    Si esta fuera de rango vuelve a pedir el valor.
    Guardarlas en un arreglo de 7 posiciones.
    Calcular el promedio de la semana

 * QUÉ SE LOGRA:
    Encontrar el dia más caluroso.
    El promedio.

 * CÓMO SE LOGRA:
    -do-while para validar el rango de temperatura aceptada
    -Arreglo para guardar temperaturas
    -for para sacar al mas caluros
    -for para recorrer los dias

 * RESULTADO ESPERADO:
   Muestra la temperatura de cada dia.
   El promedio de temperatura (float: dos decimales)
   El dia mas caluroso
   La lista de dias que superaron el promedio con su cantidad
 * ========================================================================== */

//  Acceder a las bibliotecas
#include <stdio.h>
#include <string.h>

#define MIN 0  // Rango minimo de temperatura
#define MAX 45 // Rango maximo de temperatura
#define DIAS 7 // Filas

int main(void)
{
    char dias[DIAS][4] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};
    float temp[DIAS];
    int i, temperaturas, sobrePromedio = 0, diaCaliente = 0;
    float promedio, suma = 0, masCaliente = 0;
    int diasMas = 0;

    // Solicitar temperatura
    for (i = 0; i < DIAS; i++)
    {

        do
        {
            printf("Temperatura del %s(0-45):", dias[i]);
            scanf("%f", &temp[i]);

            // Validar que esté en rango correcto
            if (temp[i] < MIN || temp[i] > MAX)
            {
                printf("Temperatura fuera de rango, vuelva a ingresarla.\n");
            }
        } while (temp[i] < MIN || temp[i] > MAX);
    }

    // Calcular promedio
    for (i = 0; i < DIAS; i++)
    {
        suma += temp[i];
        promedio = suma / DIAS;
    }

    // Para buscar, comparar usamos for con if; en este caso para el dia mas caluroso
    for (i = 0; i < DIAS; i++)
    {
        if (temp[i] > masCaliente)
        {
            masCaliente = temp[i];
            diaCaliente = i;
        }
    }

    // SALIDA DE DATOSS
    printf("===== Temperaturas de la semana =====\n");
    for (i = 0; i < DIAS; i++)
    {
        printf("Temperatura del %s(0-45): %.1f\n", dias[i], temp[i]);
    }
    printf("Promedio: \t%.2f C\n", promedio);
    // dIA MÁS CALIENTE
    printf("Mas caluroso: %s (%.1fC)\n", dias[diaCaliente], masCaliente);


    // Los dias que esten arriba de promedio
    for (i = 0; i < DIAS; i++)
    {
        if (temp[i] > promedio)
        {
            sobrePromedio = sobrePromedio + 1;
            printf("Dia mayor a promedio: %s (%.1fC)\n", dias[i], temp[i]);
        }
    }

    return 0;
}
