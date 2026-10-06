//Hola.c - prueba del entorno de UA2
#include <stdio.h>

int main(void) {
    int edad;
    
    // Muestra msj por pantalla 
    printf("Entorno listo para la UA2\n");
    //Para pedir y leer un número
    printf("Digite su edad: ");
        scanf("%d", &edad);

        //Mostrar la salida
        printf("Edad registrada: %d\n", edad);
        return 0;//define que el programa esté bien y sin errores
}