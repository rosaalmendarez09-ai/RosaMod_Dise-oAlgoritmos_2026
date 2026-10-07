//Convertir numero decimal 0-15 a abinario de 4 bits
#include <stdio.h>

int main(void) { //Esta funcion no recibe ningun parámetro o argumento del sistema
    int numero;//Declaración de variables de tipo entero
    int cociente;
    int b0, b1, b2, b3;//Un bit (residuo) por cada division
    

    //ENTRADA: Lee el número -> numero = 13
    printf("Numero decimal (0 a 15): ");
    scanf("%d", &numero) ;

    //VALIDACION: con 4 bits solo se representan los valores de 0 a 15
    if (numero < 0 || numero > 15) {
        printf("Fuera de rango: use un número de 0 a 15\n");
        return 1;//Terminna indicando que hubo un error
    }

    //Se empieza dividiendo el número completo -> cociente =13
    cociente = numero;

    //Division entre 1: el residuo es el bit de las unidades -> b0 =1
    b0 = cociente % 2;

    // Muestra el paso de 13 / 2 = 6 residuo 1
    printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b0);

    cociente = cociente /2;
     //El cociente pasa a la division cociente =6

      //Muestra division 2: 6/2 = 3 resiiduo 0 b1 = 0
    b1 = cociente % 2;

    // Muestra el paso de 13 / 2 = 6 residuo 1
    printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b1);
  
   cociente = cociente /2;
   //Muestra division 3: 3/2 = 1 resiiduo 1 b2 = 1
    b2 = cociente % 2;

    

      // Muestra el paso de 13 / 2 = 6 residuo 1
    printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b2);
    cociente = cociente /2;



    //Muestra division 4: 1/2 = 0 residuo 1 -> b3 = 1
    b3 = cociente % 2;
    printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b3);


    // Resultado: Los residuos se leem de abajo hacia arriba -> 1101
    printf("En binario : %d%d%d%d\n", b3, b2, b1, b0);

    // Comprobacion: %o muestra en octal y %X en hexadecimal <> 15 y D
    printf("Comprobacion: octal %o, hexadecimal %X\n", numero, numero);
    return 0;
}