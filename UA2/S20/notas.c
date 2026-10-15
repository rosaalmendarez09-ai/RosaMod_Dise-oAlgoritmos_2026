//notas.c la trabajamos con arreglo, Ahora las notas se guardan en el arreglo

#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void){
    double notas[N]; //Definicion del arreglo
    double suma = 0, promedio, mayor, menor;
    int i;

    //Lectura de datos
    for (i = 0;i < N; i++){
        //VALIDACION
        do {
            printf("Nota: %d (0-100): ", i+1);
            scanf("%lf", &notas[i]); //Guarda dato en el arreglo notas[i]
        } while (notas[i] < 0 || notas[i] > 100);

        suma+= notas[i];    
    }

    promedio = suma / N;
    
    //Mayor- Menor, se comienza desde la primer nota y compara con el resto
    mayor = notas[0];//primer nota esta en casilla 0
    menor = notas[0];

    for ( i = 1; i < N; i++) {
       if (notas[i] > mayor){
        mayor = notas[i];
       }
       if (notas[i] < menor){
        menor = notas[i];
    }
}
    printf("Promedio %.2lf\n", promedio);
    printf("Mayor: %.lf Menor: %.lf\n", mayor, menor);

    //SEGUNDO RECORRIDO
    printf("Sobre el promedio; ");
    for ( i = 0; i < N; i++){
       if (notas[i] > promedio){
        printf(" %.lf", notas[i]);
       }
    }

    printf("\n");

    system("pause");

    return 0;
    
}