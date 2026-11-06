/*soda.c - Registro de ventas semanales de una soda
==========================================================================
* ENUNCIADO:
Registrar lo que se vende cada dia de la semana.(L-D)
Solicitar venta del dia (0-500 000)Si rango inválido, volver a pedir
Mostrar tabla: dia y venta.
Total de la semna.
Promedio diario.
El dia de mayor venta y el de menor venta.
Cual dia o dias vendieron mas que el promedio y cuantos fueron

* QUÉ SE LOGRA:
Registrar las ventas de la semana de una soda

* CÓMO SE LOGRA:
do-while para validaciones
if- else para encontrar el mayor y el menor.
Funciones, arreglos y matrices y for para recorrerlas e imprimir datos

* RESULTADO ESPERADO:
Un programa que muestre las ventas del dia y el total de la semana, el promedio diario.El mayor y el menor, Cuales dias se vendio mas
*/

#include <stdio.h> //libreria

// Prototipos de funciones
void limpiar(void);
double leerVenta(const char dia[]);
void estadisticas(const double v[], int n, double *total, double *prom, int *posMax, int *posMin);
int diasSobre(const double v[], const char nombres[][4], int n, double prom);

// constantes
#define MIN 0      // Minimo de ventas
#define MAX 500000 // Maximo de ventas
#define DIAS 7     // Cantidad de dias

// ====================funcion principal main===================
int main(void)
{
    const char dias[DIAS][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    double ventas[DIAS];
    double prom = 0.0;
    int posMax = 0, i;
    int posMin = 0;
    double total = 0.0;

    // Lee las ventas diarias y valida rango
    for (i = 0; i < DIAS; i++)
    {
        ventas[i] = leerVenta(dias[i]);
    }
    // Aca se traen todos los calculos realizados en la funcion
    estadisticas(ventas, DIAS, &total, &prom, &posMax, &posMin);

    printf("===VENTAS SEMANALES===\n");
    printf("%-12s %-12s\n", "dias", "ventas");
    for (i = 0; i < DIAS; i++)
    {
        printf("%-12s %-12.2lf\n", dias[i], ventas[i]);
    }
    printf("Total semanal: %.2lf\n", total);
    printf("Promedio de ventas diarias: %.2lf\n", prom);
    printf("Dia con mayor venta: %s %.2lf\n", dias[posMax], ventas[posMax]);
    printf("Dia con menor venta: %s %.2lf\n", dias[posMin], ventas[posMin]);

    return 0;
}
// ======================FIN MAIN=================================

// Definicion de funciones
// ====================Funcion limpiarBuffer======================
void limpiar(void)
{
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}
// =============================FIN================================

// ========================Funcion leerVentas======================
double leerVenta(const char dia[])
{
    int i;
    double ventas = 0;
    do
    {
        printf("Ingresa las ventas del %s: ", dia);
        if (scanf("%lf", &ventas) != 1)
        {
            printf("Error, dato no numerico ingrese nuevamente.\n"); // No deje ingresar texto
            ventas = -1;                                             // fuerza el valor para repetir el do- while
            limpiar();                                               // limpiar las letras que puedan causar error
        }
        else if (ventas < MIN || ventas > MAX)
        {
            printf("Monto inválido digite nuevamente.\n");
        }
    } while (ventas < MIN || ventas > MAX);
    limpiar();

    return ventas;
}
// ==========================FIN================================

// ====================Funcion leerVentas======================
void estadisticas(const double v[], int n, double *total, double *prom, int *posMax, int *posMin)
{
    int i;

    *total = 0.0;
    *posMax = 0;
    *posMin = 0;

    for (i = 0; i < n; i++)
    {
        *total += v[i];

        if (v[i] > v[*posMax]) // Compara valor actual buscando el mayor
        {
            *posMax = i;
        }

        if (v[i] < v[*posMin]) // Compara el valor actual buscando el menor
        {
            *posMin = i;
        }
    }
    *prom = *total / n;
}
// ==========================FIN================================

// ====================Funcion leerVentas======================
int diasSobre(const double v[], const char nombres[][4], int n, double prom)
{
}
// ==========================FIN================================