/* 1. Lea el título de cada libro hasta que se digite FIN o fin (máximo 10 títulos). Para cada libro lea
el precio y la cantidad, ambos positivos.
2. Cuente las unidades (suma de cantidades) y acumule el total de libros.
3. Aplique un descuento del 10 % si el pedido tiene 5 unidades o más.
4. Calcule el envío: 8 si el total de libros es menor que 50, 4 si es menor que 150 y gratis desde
150.
5. Calcule el impuesto (13 % del total con descuento) y el total a pagar (total − descuento +
impuesto + envío).
6. Muestre el detalle de cada libro y el resumen del pedido.*/

#include <stdio.h>
#include <string.h>

// CONSTANTES: FUNCIONES GLOBALES
#define CENTINELA "FIN"
#define CENTINELA2 "fin"
#define LIBROS 10
#define ANCHOP 50

int main(void){
    char titulos[LIBROS][ANCHOP];
    int cantidad[LIBROS]/*unidades de libros*/,contadorL=0, totalCantidades = 0;
    double precio[LIBROS]/*10 precios, total = 0*/,total = 0;
    char tituloTemp[ANCHOP];

    // LECTURA PREVIA
    printf("Ingrese el titulo del libro ( \"fin\" para terminar). \n");
    fgets(tituloTemp, sizeof(tituloTemp), stdin);//Guarda texto en tituloTemp
    tituloTemp[strcspn(tituloTemp, "\n")] ='\0';//Elimina salto de linea por default

    // INICIO PARA VERIFICAR CENTINELA
    while (strcmp(CENTINELA, "FIN") != 0/*si lo encuentra regresa 0*/ && strcmp(CENTINELA2, "fin") != 0 && contadorL < LIBROS)/*Si contador es menor a 10*/
    {
        strcpy(titulos[contadorL],tituloTemp);//Guarda titulo en matriz
    

    // VALIDAR PRECIO 
    do
    {
       printf("Ingrese el precio:");
       scanf("%lf", &precio[contadorL]);

       precio[contadorL] < 0 ? printf("VALOR INCORRECTO") : "VALIDO";
  
    } while (precio[contadorL] < 0 );
    

    // VALIDAR CANTIDADES
    do
    {
       printf("Ingrese la cantidad:");
       scanf("%d", &cantidad[contadorL]);

       cantidad[contadorL] < 0 ? printf("VALOR INCORRECTO") : "VALIDO";
  
    } while (cantidad[contadorL] < 0 );

    while ((getchar()) != '\n') //eliminar saltos de linea 

    // ACUMULADORES: TOTAL PRECIO, TOTAL CANTIDADES
    totalCantidades += cantidad[contadorL];
    total = cantidad[contadorL];

    contadorL += 1;

    // volve a solicitar informacion previa
    printf("Ingrese el titulo del libro ( \"fin\" para terminar). \n");
    fgets(tituloTemp, sizeof(tituloTemp), stdin);//Guarda texto en tituloTemp
    tituloTemp[strcspn(tituloTemp, "\n")] ='\0';
}

for ( contadorL = 0; contadorL < 10; contadorL++)
{
   printf("%s\n",titulos[contadorL]);
   printf("%d\n",cantidad[contadorL]);

}


    return 0;
}