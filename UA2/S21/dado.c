/* dado.c -  LanzadorDado
==========================================================================
 * ENUNCIADO:
  -Simular 600 lanzamientos de un dado y mostrar cuántas veces salió cada cara con una barra de asteriscos.

 * QUÉ SE LOGRA:
   -Simular 600 lanzamientos de un dado
   -Mostrar cuantas veces salio cada cara 

 * CÓMO SE LOGRA:
   -rand y srand de stdlib.h
   -Arreglo de contadores

 * RESULTADO ESPERADO:
   -Devuelve * por cada 10 lanzamientos
   -Muestra los numero de caras y cuantas veces salio
 * ========================================================================== */

#include <stdio.h>
#include <stdlib.h> //para rand, srand, abs(enteros)

// PROTOTIPOS declaro funciones
int lanzarDado(void); //genera un valor del 1- 6 caras del dado
void mostrarBarra(int cantidad); //cantidad de veces que sale una cara

int main(void){

  int frecuencia[7] = {0};//solo usamos del 1-6 para ser mas exactos con las caras del dado

  srand(2026);//dato fijo; garantiza que la salida coincida con la de referencia

  // LANZAMOS EL DADO: 600 veces.
  for (int i = 0; i < 600; i++)
  {
    int cara = lanzarDado();
    frecuencia[cara]++; //incrementa el contador correspondiente
  }
  
  // IMPRESION: el for recorre 1-6 para dar los resultados
  for (int i = 1; i <= 6; i++)
  {
     printf("Cara %d:%-3d ", i, frecuencia[i]);
     mostrarBarra(frecuencia[i]); // va a dibujar los *
  }
   
  return 0;
}

// FUNCIONES
int lanzarDado(void){
// Devuelve un numero 1 - 6
return (rand() % 6) + 1;
}

void mostrarBarra(int cantidad){
  //calcula cuantos asteriscos son(1 * c/10)
  int asteriscos = cantidad / 10;

  // for para imprimir * consecutivamente
  for (int i = 0; i < asteriscos; i++)
  {
    printf("*");
  }
  printf("\n");
}