/*Enunciado: Un cine registra las compras de una funcion (1-10). De cada compra se digita el nombre del cliente(una palabra), el tipo de entrada(1-General 3500 2-Niño 2500 3-Adulto Mayor 2000) y la cantidad de entradas(1-8).Un dato inválido se vuelve a pedir. Si se compran 5 o más entradas, tiene descuento de 10%. Mostrar: tabla con nombre cliente - tipo entrada - cantidad de compra - total vendido - compra mayor - cuantas con descuento -
 */

#include <stdio.h>

// Definir constantes
#define MAX_COMPRAS 10
#define PRECIO_GENERAL 3500
#define PRECIO_NINO 2500
#define PRECIO_MAYOR 2000
#define MIN_DESCUENTO 5
#define TASA_DESCUENTO 0.10

// PROTOTIPOS DE FUNCIONES
int leerEntero(const char mensaje[], int minimo, int maximo);
double precioEntrada(int tipo);
double calculaTotal(int tipo, int cantidad);
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento);

int main(void)
{
    // Definir arreglos y variables
    char clientes[MAX_COMPRAS][15]; // Nombre cliente
    int cantidades[MAX_COMPRAS];    // Cantidad de compras maximas 10
    double totales[MAX_COMPRAS];    // Total de cada compra
    // Cantidad de compras, indice y el tipo de entrada
    int n, i, tipo;
    // Cantidad de compras
    double totalVendido;
    // Resultados resumen
    int posMayor, conDescuento;

    // PORTADA
    printf("==== venta de Entradas ====\n");
    printf("Tipos: 1.General 3500, 2.Nino 2500, 3.Adulto Mayor 2000\n");

    // Leer cantidad de compras -> 4
    n = leerEntero("Cantidad de compras", 1, MAX_COMPRAS);

    // FOR para una vuelta por compra
    for (i = 0; i < n; i++)
    {
        printf("Compras %d\nCliente: ", i + 1);
        scanf("%14s", clientes[i]);

        // Leer el tipo de entrada
        tipo = leerEntero("Tipo", 1, 3); // validar sin usar do-while

        // Leer cantidad de entradas

        // Calcular total de la compra
        totales[i] = calculaTotal(tipo, cantidades[i]);
        cantidades[i] = leerEntero("Entradas", 1, 8); // Valida sin usar do-while
    }

    // Calcular el resumen de una pasada
    resumir(cantidades, totales, n, &totalVendido, &posMayor, &conDescuento);

    // Encabezado de tabla
    printf("\n%-12s%9s%12s\n", "clientes", "Entradas" , "totales");

    // Recorrer las compras
    for (i = 0; i < n; i++)
    {
        // Mostrar fila
        printf("%-12s%9d%12.2f\n", clientes[i], cantidades[i], totales[i]);

        // Total vendido
        printf("Total vendido: %12.2f\n", totalVendido);
        // Compra mayor
        printf("Compra Mayor: %s (%.2f)\n", clientes[posMayor], totales[posMayor]);

        // Compras con descuento
        printf("Con descuento: %d compra(s)\n", conDescuento);

        // Termina main con el return por valor
        return 0;
    }
}

// DEFINICION. LeerEntero=================================================
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    // Variable localpara el dato
    int valor;

    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);
    } while (valor < minimo || valor > maximo);

    // regresa valor
    return valor;
}

// DEFINICION. precioEntrada====================================================
double precioEntrada(int tipo)
{
    switch (tipo)
    {
    case 1:
        return PRECIO_GENERAL; // RETURN termina la funcion no hace falta el break

    case 2:
        return PRECIO_NINO;

    default:
        /* code */
        return PRECIO_MAYOR;
    }
}

// DEFINICION. calcularTotal============================================================
double calculaTotal(int tipo, int cantidad)
{
    double total = precioEntrada(tipo) * cantidad;

    if (cantidad >= MIN_DESCUENTO)
    {
        total = total * (1 - TASA_DESCUENTO);
    }
    return total;
}

// DEFINICION resumir
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento)
{
    int i;

    // Inicializo los tres resultados en la memoria de main
    *total = 0;
    *posMayor = 0;
    conDescuento = 0;

    // Recorrer las compras
    for (i = 0; i < n; i++)
    {
        *total += tot[i];
        // Comparar la compra mayor
        if (tot[i] > tot[*posMayor])
        {
            *posMayor = i;
        }

        if (cant[i] > MIN_DESCUENTO)
            (*conDescuento)++;
        
    }
}
