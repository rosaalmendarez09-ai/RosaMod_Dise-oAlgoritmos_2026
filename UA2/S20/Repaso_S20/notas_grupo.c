/* notas.c -  Notas deel grupo
==========================================================================
 * ENUNCIADO:
    -Pedir el nombre (una palabra) de 4 estudiantes
    -Pedir las notas de 3 evaluaciones(0-100).Una nota invalida volver a solicitarla
    -Guardar las notas en una matriz de 4 filas x 3 columnas

 * QUÉ SE LOGRA:
   -Mostrar la tabla con el nombre, las 3 notas y el promedio(.2f) de cada estudiante.
   -El estudiante con mejor promedio
   -Buscar un nombre: Si está, mostrar su promedio y su condicion: Aprobado/No aprobado.
   -Sino está mostrarlo con un mensaje

 * CÓMO SE LOGRA:
    -Crear arreglos, matrices, constantes( para valores que no cambian: min-max) y variables a utilizar tipo float, char, int.
    -Trabajar con acumulador.
    -Utilizar for anidados para recorrer la matriz(externo/filas e interno/columnas), ingresar notas
    -Utilizar float para trabajar con dos decimales.
    -Usar strcmp para buscar y break para encontrary strcpy (if-else)para guardar ambas condiciones.
    -Utilizar print para

 * RESULTADO ESPERADO:
   Muestra nombre, promedio, notas, mejor promedio y buscar un nombre: si encontrado mostrar promedio y condicion.
 * ========================================================================== */

//  Incluyo bibliotecas para usos de printf/scanf y fgets, strcmp, strcpy.
#include <stdio.h>
#include <string.h>

//  Constantes para valor maximo y minimo
#define MAX 100
#define MIN 0
// constantes para filas y columnas
#define ESTUDIANTES 4
#define EVALUACIONES 3

// constantes para condicion
#define APROBADO 70

int main(void)
{
    // Creo variables a utilizar
    int i = 0, j, encontrado = 0, notas[ESTUDIANTES][EVALUACIONES];                                 // Guarda las 4 notas de las evaluaciones
    char busqueda[15] /*Aca se guarda temporalmente el nombre a buscar*/, nombres[ESTUDIANTES][15]; // Guardar los 4 nombres(una palabra)
    float mayorP, promedio[ESTUDIANTES];                                                            // Guardar los 4 promedios

    for (i = 0; i < ESTUDIANTES; i++)//for externo para ingresar los nombres(4)
    {
        printf("\nIngrese el nombre del estudiante %d: ", i + 1);//solicito nombre
        scanf("%14s", nombres[i]); // Coloco cantidad de caracteres a usar para evitar desbordamiento y guardo sin & porque es un char

        
        for (j = 0; j < EVALUACIONES; j++)// for interno para ingresar las tres notas
        {
           
            do // do-while para validar el rango de las notas
            {
                printf("Ingrese la nota %d de %s(0-100): ", j + 1, nombres[i]);//solicito notas
                scanf("%d", &notas[i][j]);//guardo notas

                if (notas[i][j] < MIN || notas[i][j] > MAX)
                {
                    printf("Nota inválida,ingrese nuevamente\n");
                }
            } while (notas[i][j] < MIN || notas[i][j] > MAX);
        }
    }

        return 0;
    }
