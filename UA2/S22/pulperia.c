/* dado.c -  LanzadorDado
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
   
 * ========================================================================== */
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
        printf("1.Listar 2.Vender 3.Reponer 4.Valor 0.Salir");
        opcion = leerEntero("Ingrese un opcion(0-4)", MIN, MAX);

        switch (opcion)
        {
        case 1:
            listar(nombres, precios, existencias, totalProductos);
            break;

        case 2:
            listar(nombres, precios, existencias, totalProductos);
            seleccion = leerEntero("Producto que desea vender: ", 1, 4);
            cantidad = leerEntero("Producto que desea vender: ", 1, 50);

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
 

