/* Reciba el nombre del colaborador y el puntaje de cada criterio (0 a 10); un puntaje fuera de
rango se vuelve a pedir. El mensaje debe mostrar el nombre del criterio.
2. Calcule el promedio y el nivel: EXCELENTE (9 o más), BUENO (7 o más, pero menos de 9) o
NECESITA MEJORAR (menos de 7).
3. Indique el criterio con el puntaje más bajo y su puntaje.*/
/*Resultado esperado:
Colaborador: Laura Solis
Promedio: 9.17
Nivel: EXCELENTE
Puntaje mas bajo: calidad (8.5)*/

#include <stdio.h>
#include <string.h>

#define EXCELENTE 9
#define BUENO 7

int main(void)
{
    char nombre[50], *criterio[3] = {"puntualidad", "calidad", "trabEquipo"};
    float puntaje[3], promedio, suma = 0, menor;
    int i, masBajo;

    // INGRESAR NOMBRE
    printf("Nombre colaborador: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    // SOLICITAR PUNTAJE
    // VALIDAR QUE EL VALOR INGRESADO SEA CORRECTO
    for (i = 0; i < 3; i++)
    {
        do
        {
            printf("Puntaje %s (0-10):  ", criterio[i]); // solicita puntualidad, calidad y trabEquipo uno por uno
            scanf("%f", &puntaje[i]);                    // guarda los datos ingresados

            if (puntaje[i] < 0 || puntaje[i] > 10)
            {
                printf("Dato erróneo, vuelva a ingresarlo.\n");
            }
         } while (puntaje[i] < 0 || puntaje[i] > 10);
            
                suma += puntaje[i]; // Sumamos los puntajes ingresados
            }

            // CALCULAR PROMEDIO
            promedio = suma / 3.0;

            // PUNTAJE MAS BAJO
            menor = puntaje[0];//asumo que la mas baja esta en la posicion (0)
            masBajo = 0; //aca guardamos la posicion mas baja
            for (i = 1; i < 3; i++)//como ya sacamos el primer valor, vamos a empezar a recorrer el arreglo desde la pocision 2 que seria puntaje(1)
            {
                if (puntaje[i] < menor)
                {
                    menor = puntaje[i];
                    masBajo = i;
                }
            }

            // Muestra de Resultados
            printf("===============================\n");
            printf("=== EVALUACION DE DESEMPEÑO ===\n");
            printf(" Colaborador: %s\n", nombre);
            printf("Promedio: %.2f\n", promedio);
            printf("Nivel: ");

            // ESPECIFICAR SU NIVEL
            if (promedio >= EXCELENTE)
            {
                printf("EXCELENTE\n");
            }
            else if (promedio >= BUENO)
            {
                printf("BUENO\n");
            }
            else
            {
                printf("MEJORAR\n");
            }
        
            printf("Puntaje mas bajo: %.1f\n", menor);

        return 0;
    }
