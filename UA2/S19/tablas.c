//tablas.c resuelve la tabla del 7

#include <stdio.h>
#define CENTINELA 0 // 0 Indica que NO HAY tablas

int main(void){

    //Declaracion variables
    int numero, i ;
    int tablas = 0;
    
    //Lectura previa: 1er numero se lee antes del while -> 7
    printf("Numero de la tabla(0 para terminar): ");
    scanf("%d", &numero);

    //WHILE CON CENTINELA: Repita mientras valor no sea 0(cero)
    while (numero != CENTINELA)
    {
       //FOR ANIDADO: 100 VUELTAS POR CADA NUMERO -> 1 = 1, 2 = 2, ..., 10
       for (i = 1; i <= 10; i++){

        //%2d alinea en 2 espacios -> 7 x 1 = 7... 7 x 10 = 70
        printf("%d x %2d = %2d\n", numero, i, numero * i );
       }

       tablas++; //Cuenta la tabla mostrada -> 1 luego 2
       //siguiente dato al final del cuerpo -> 3 luego 0
       printf("Numero de la tabla(0 para terminar): ");
       scanf("%d", &numero);
    }
    
    //Despues de WHILE (se digito 0) -> Las tablas mostradas 2
    printf("Tablas mostradas:  %d\n", tablas);


return 0;
}