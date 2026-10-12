// nota.c ingresa nota hasta valor valido
#include <stdio.h>

int main(void){
    float nota;

    printf("Ingresa nota(0-100): ");
        scanf("%f", &nota);
    
    if (nota < 0 || nota  > 100){
        printf("Nota invalida, ingrese nota correcta: ");
        scanf("%f", &nota);
        }
  
    else if (nota >= 70){
        printf("Nota: %.2f - Aprobado\n", nota);
    }
    else {
        printf("Nota: %.2f - Reprobado\n", nota);
    }
    
         return 0;
    }

    
        

   
