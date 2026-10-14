// patrones.c dibujar figuras en la terminal para entender como un ciclo interno depende del extreno

#include <stdio.h>

int main(void){
    int filas = 4, e, n;

  printf("__________________\n"); 
   printf("\n"); 
  printf("Cantidad de filas: %d\n", filas);

    // Controlar filas
    for(e = 1; e <= filas; e++){
        // bucle interno
        for (n = 1; n <= e; n++){ 
            printf("*");
        }
        printf("\n"); //Cuanto termine la linea pasa a la siguente
    }

        // 2. Patrón de números
    for (e = 1; e <= filas; e++) {
        for (n = 1; n <= e; n++) {
            printf("%d", n);
        }
        printf("\n");
    }
    return 0;
}