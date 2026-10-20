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

#define CENTINELA "FIN"
#define CENTINELA2 "fin"
#define AnchoP 50

int main(void){
    char titulos[10][AnchoP], decision[3];
    int cantidad, maximo, cantidadT;
    double precio, total = 0;

    while (strcmp(CENTINELA, "FIN") = 0 || strcmp(CENTINELA, "fin") == 0)
    {
        for (maximo = 0; maximo < 10; maximo++)
        {
            printf("Desea agregar libro?: ");
            scanf("%2s", decision);

            if (strcspn(decision, "SI") == 0)
            {
               printf("Ingrese el titulo del libro: ");
               fgets(titulos[maximo], sizeof(AnchoP), stdin);
               titulos[0][strcspn(titulos, "\n")] = '\0';

              //PRECIOS LIBROS
               do
               {
                 printf("Ingrese cantidad de libro: ");
                 scanf("%lf", &precio);
                  if (precio < 0)
                { 
                    printf("Dato erroneo, ingrese monto correcto.");
                }
               } while (precio < 0);

               total += precio;


              //CANTIDAD
                do
               {
                 printf("Ingrese cantida de libro: ");
                 scanf("%lf", &precio);
                  if (precio < 0)
                { 
                    printf("Dato erroneo, ingrese monto correcto.");
                }
               } while (precio < 0);
            
                cantidadT += precio;

            }
           else 
           {
            break;
           }

           for (maximo = 0; maximo < 10; maximo++)
           {
            printf("libros son: %s", titulos[maximo]);
           }
           
          
        }
        
    }
    





    return 0;
}