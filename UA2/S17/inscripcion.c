// inscripcion.c viene de algoritmo inscripcion cursos

#include <stdio.h>
#define COSTO_MODULO 15000.0;

int main(void){

    //CADENAS: arreglos de caracteres 
    char nombre[30], cedula[15];
    int cantidadModulos;
    double total;

     //Logica en C (1 = V y 0 = F)
    int tieneDescuento;
     
     //Entrada DATOS s=stream al usar stream no se usa & (Ampersand) para almacenar
     printf("Nombre: ");
     scanf("%29s", nombre);

    //Leer la cedula    
     printf("Cedula: ");
     scanf("%14s", cedula);

     //Pedir y almacenar cantidad de modulos
     printf("Cantidad modulos: ");
     scanf("%d", &cantidadModulos);

     //PROCESOS total = 3 * 15000 -> 45000
    total = cantidadModulos * COSTO_MODULO;
    //A la pregunta tiene descuento se responde con 1 para si o 2 para no

    tieneDescuento = cantidadModulos >= 3;

    //SALIDAS
    printf("Estudiante: %s (%s)\n", nombre, cedula);
    printf("Total de la inscripcion: %.2f\n", total);
    printf("¿Aplica para descuento?: %d (1 = si, 0 = no)\n", tieneDescuento);


    return 0;
}