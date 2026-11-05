// ERROR: El scanf no tenia el &. y el puntero de la funcion
// POR QUE: Al no estar no almacena el dato, no trae el dato de la funcion al no apuntar donde guardar
// CORRECCION: colocar ampersand delante de compra en el scanf, se coloca el puntero en la funcion y el ampersand que guarda el dato en el main

#include <stdio.h>

void sumarPuntos(int *puntos, int compra)
{
    *puntos = *puntos + (compra / 1000);
}

int main(void)
{
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++)
    {
        printf("Compra %d: ", i);
        scanf("%d", &compra);
        sumarPuntos(&puntos, compra);
    }
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
