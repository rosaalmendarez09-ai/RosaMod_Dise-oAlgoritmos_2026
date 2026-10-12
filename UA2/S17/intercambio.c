// inytercambio.c  mostrar valores antes y despues de cambiarlas
#include <stdio.h>

int main(void){

// Definir variables
int  a = 5, b = 9, aux;

    //Imprime valores iniciales
    printf("a = %d b = %d  \n", a, b);
    aux = a ;  
    a = b;
    b = aux;

        // Cambio de valores
        printf("a = %d b = %d\n", a, b);

    return 0;
}
