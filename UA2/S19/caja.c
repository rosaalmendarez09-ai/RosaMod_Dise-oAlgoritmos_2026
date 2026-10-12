//caja.c - Caja Registradora con menu

#include <stdio.h>

int main(void){
    
    //Declaracion de Variables
    int opcion; //opcion elegida en el menu
    int productos = 0; //CONTADOR de productos de la venta
    double precio; //precio para cada producto
    double total = 0;//ACUMULADOR de la venta

    //DO - WHILE: El menú se muestra al menos una vez
    do {
        //mostrar el menu y lee la opcion -> 11
        printf("\n1. Agregar 2. Ver total 3.Cobrar 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        //SWITCH: (SEGUN): Salta al case que coincida con la opcion elegida
        switch (opcion){
        case 1: //REPITE mientras precio no sea positivo

        do {
            printf("Precio del producto: ");
            scanf("%lf", &precio); //-> 1500 (- 200)

            if (precio <= 0){
                printf("Precio invalido\n");
            }
        }

        while (precio <= 0);

        productos++; //cuenta productos
        total += precio;//suma el producto
        break;

        //Muestra el avance 
        case 2: 
        printf("Productos: %d Total: %.2f\n", productos, total);
        break;

        case 3:
        //Cobra y reinicia el contador y acumulador
        printf("Cobrado: %.2f. Nueva ventana\n", total);
        productos = 0;
        total = 0;
        break;

        case 0: 
        printf("Caja Cerrada\n");
        break;

        default:
        //NINGUN CASE COINCIDE -> 9

        printf("Opción Inválida\n");
        }
    //Repita el menu mientras no se elija el 0
     }
    
    while (opcion != 0);

    return 0;
}