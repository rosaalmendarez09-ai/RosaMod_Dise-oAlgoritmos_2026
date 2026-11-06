// ERROR: 

// POR QUE: Los arreglo solo leen por caracter uno a uno por lo cual si no se agrega strcmp no va a comparar el nombre nunca. y el cierre del for para que se vuelva a iniciar el ciclo y pueda seguir revisandolo

// CORRECCION: La función buscar: usa strcmp para comparar nombres y devuelve la posición encontrada, o -1 si no existe. También coinciden N y la cantidad de productos.

#include <stdio.h>
#include <string.h>
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
            return i;
    }
    return -1;
}

int main(void)
{
    char nombres[][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;
    printf("Producto: ");
    scanf("%14s", buscado);
    pos = buscar(nombres, N, buscado);
    if (pos == -1)
        printf("No existe\n");
    else
        printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
    return 0;
}
