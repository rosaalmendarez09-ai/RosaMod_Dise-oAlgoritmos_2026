// Caso integrador de la unidad 2 del curso Diseño de Algoritmos
// Enunciado:El sistema registra notas de un grupo de 16 estudiantes
// Contiene un menu1. Agregar (nota de 0 100 validarla). 2. Ver notas(cada una con aprobado si es 70 o más, o reprobado), 3. Estadisticas (Promedio, mayor y menos). y 0 para salir

#include <stdio.h>
#define MAX 16

// DEFINICION PROTOTIPOS
// Leer nota no recibe datos y devuelve una nota válida
double leerNota(void);

// Recibe el arreglo y direccion de la cantidad
void agregarNota(double notas[], int *cantidad);

// Mostrar notas: recibe el arreglo y la cantidad por valor
void mostrarNotas(const double notas[], int cantidad);

// Calcula estadisticas: recibe el arreglo y cantidad y tres punteros
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor);

int main(void)
{
    // Arreglo de notas 16
    double notas[MAX];

    // Cantidad de notas guardadas y opcion del menu
    int cantidad = 0, opcion;

    // Resultados de las estadísticas
    double promedio, mayor, menor;

    // Ciclo del menu para repetir hasta 0
    do
    {
        // Mostrar el menu
        printf("\n1. Agregar 2.Ver notas 3.Estadistica 0.Salir\n");
        // Seleccionar opcion del menu
        printf("Opcion: ");
        // Leer opcion
        scanf("%d", &opcion);

        // Elige la rama segun opcion
        switch (opcion)
        {
            // ================================================================
        case 1:
            agregarNota(notas, &cantidad);
            break; // sale del switch
                   // ================================================================
        case 2:
            mostrarNotas(notas, cantidad);
            break; // lista de notas
                   // ================================================================
        case 3:    // estadisticas
            if (cantidad == 0)
            {
                printf("No hay notas registradas\n");
            }
            else
            {
                // Hacer la llamada que devuelva 3 resultados
                calcularEstadisticas(notas, cantidad, &promedio, &mayor, &menor);
                // Mostrar los resultados
                printf("Promedio: %0.f Mayor: %.1f Menor: %.1f\n", promedio, mayor, menor);
            }
            break;
            // ================================================================
        case 0:
            printf("Hasta luego\n");
            break;
            // ================================================================
            // Cualquier otra opcion que no sea del menu
        default:
            printf("Opcion inválida\n");
        }
        // REPITA MIENTRAS NO SE ELIJA 0
        // ================================================================
    } while (opcion != 0);

    return 0;
}

// FUNCIONES
// Definicion de leer nota, repite hasta que nota este entre 0 y 100
double leerNota(void)
{
    double nota;
    // Ciclo de validacon
    do
    {
        //    Pedir nota
        printf("Nota(0-100): ");
        scanf("%lf", &nota);
        // Repite si esta fuera de rango
    } while (nota < 0 || nota > 100);
    // Devuelve una nota valida
    return nota;
}

// Definicion agregar nota
void agregarNota(double notas[], int *cantidad)
{
    // Revisar si esta vacio
    if (*cantidad < MAX)
    {
        //    Guarde la nota
        notas[*cantidad] = leerNota();
        // Aumentar la cantidad
        (*cantidad)++;
    }
    else
    {
        printf("El gruppo ya tiene %d notas\n", MAX);
    }
}

// DEFINICION PARA MOSTRAR NOTAS
void mostrarNotas(const double notas[], int cantidad)
{
    // Indice local para recorrer el arreglo
    int i;
    // for para recorrer las notas
    for (i = 0; i < cantidad; i++)
    {
        // mostrar numero, nota y condicion
        printf("%2d. %5.lf %s\n", i + 1,notas[i], notas[i] >= 70 ? "APROBADO" : "REPROBADO");
    }
}

// DEFINICION DE CALCULAR ESTADISTICAS
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor)
{
    // Acumulador local
    double suma = 0;
    // Indice local para recorrer el arreglo
    int i;
    // Se supone que la primera nota es mayor
    *menor = notas[0];
    // for para recorrer notas
    for (i = 0; i < cantidad; i++)
    {
        suma += notas[i];
        // Compare con el mayor
        if (notas[i] > *mayor)
        {
            //Guardar el nuevo mayor
            *mayor = notas[i];
        }
    }
    // Calculo promedio
    *promedio = suma / cantidad;
}
