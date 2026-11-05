// ERROR: cierre for en la funcion, el strcmp y == 0 y arreglo de nombre[N][15]

// POR QUE: Los arreglo solo leen por caracter uno a uno por lo cual si no se agrega strcmp no va a comparar el nombre nunca. y el cierre del for para que se vuelva a iniciar el ciclo y pueda seguir revisandolo

// CORRECCION:  if (strcmp(nombres[i], buscado) == 0)  ombres[N][15] y el cierre del for en la funcion.

#include <stdio.h>
#include <string.h>
#define N 4

int buscar(const char nombres[N][15], int n, const char buscado[])
{
    int i;
    for (i = 0; i <= n; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
            return i;
    }
    return -1;
}

int main(void)
{
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
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
