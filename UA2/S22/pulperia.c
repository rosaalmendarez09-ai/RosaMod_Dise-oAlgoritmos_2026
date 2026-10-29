/* pulperia.c -  Inventario de una pulperia
==========================================================================
 * ENUNCIADO:
   Programar el inventario de una pulpería con un menú que permita listar los productos,
   vender (solo si hay existencias), reponer y consultar el valor del inventario.

 * QUÉ SE LOGRA:
   -Recibir mensaje
   -Mostrar, sumar, restar y reponer existencias

 * CÓMO SE LOGRA:
   -Funciones, do-while y switch: muestran numero, nombre, precio y existencias

 * RESULTADO ESPERADO:
   -Mostrar lista de productos: menu
   -Cantidades vendidas
   -Unidades existentes
   -Opcion seleccionada
   -Monto total del invemtario

 ========================================================================== */
#include <stdio.h>
// Constantes para valores minimo y maximo
#define MIN 0
#define MAX 4

int leerEntero(const char mensaje[], int minimo, int maximo);
void listar(const char nombres[][15], const double precios[], const int existencias[], int totalProductos);
int vender(int *existencia, int cantidad);

int main(void)
{
    int opcion;
    const char nombres[4][15] = {"Arroz 2 k", "Frijoles 1 kg", "Cafe 1 kg", "Aceite 1 L"};
    const double precios[MAX] = {2400, 1800, 4500, 3200};
    int existencias[MAX] = {20, 15, 12, 8};
    int totalProductos = MAX;
    int cantidad;
    int seleccion;

    do
    {
        // MUESTRA MENU
        printf(" ===========================\n");
        printf(" 1.Listar\n 2.Vender\n 3.Reponer\n 4.Valor\n 0.Salir\n");
        opcion = leerEntero("Ingrese un opcion(0-4): ", MIN, MAX);

        switch (opcion)
        {
        case 1: // Muestra lista productos
            listar(nombres, precios, existencias, totalProductos);
            break;

        case 2:
            listar(nombres, precios, existencias, totalProductos);
            seleccion = leerEntero("Producto que desea vender: ", 1, 4);
            cantidad = leerEntero("Cantidad a vender: ", 1, 50);

            if (vender(&existencias[seleccion - 1], cantidad == 1))
            {
                printf("Vendido: %d x %s %.2f\n", cantidad, nombres[seleccion - 1], precios[seleccion - 1] * cantidad);
            }
            else
            {
                printf("Solamente existen  %d x unidades\n", existencias[seleccion - 1]);
            }
            break;

        case 3:
            listar(nombres, precios, existencias, totalProductos);

        case 4:
            listar(nombres, precios, existencias, totalProductos);

        default:
            break;
        }

    } while (opcion != 0);

    return 0;
}

// Implementacion codigo
//===============FUNCION leerEntero=====================
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    int valor;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &valor);
    } while (valor < minimo || valor > maximo);
    return valor;
}
//==============FUNCION listar==========================
void listar(const char nombres[][15], const double precios[], const int existencias[], int totalProductos)
{
    printf("\n%-5s %-20s %-12s %-12s\n", "N.", "Producto", "Precio", "Existencias"); // Encabezados.

    /* Recorre todos los indices validos de los arreglos. */
    for (int i = 0; i < totalProductos; i++)
    {
        /* Muestra numero, nombre, precio y existencias del producto actual. */
        printf("%-5d %-20s %-12.2f %-12d\n",
               i + 1, nombres[i], precios[i], existencias[i]);
    }
}
//==================FUNCION vender=======================
int vender(int *existencia, int cantidad)
{
    if (cantidad <= *existencia)
    {
        *existencia = *existencia - cantidad;
    return 1;
    }
    return 0;
}
