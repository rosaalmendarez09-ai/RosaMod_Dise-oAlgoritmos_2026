// texto_subrayado.c subraya la cantidad de caracteres que imprime la consola

#include <stdio.h>

int main(void){
    int longitud = printf("COMPROBANTE DE PAGO\n");

    // Resta el caracter de salto de línea para que subraye unicamente el texto y sus espacios entre el
    int subrayado = longitud - 1;

    // %.* le dice a printf que imprima la cantidad de caracteres desde la variable
    printf("%.*s\n",subrayado, "===============================================================================");

    return 0;
}