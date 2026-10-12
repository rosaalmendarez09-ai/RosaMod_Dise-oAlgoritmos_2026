// segundos.c convertir segundos a formato reloj
#include <stdio.h>

int main(void){
    int tSegundos, horas, minutos, segRestantes;

    printf("Ingresa la cantidad de segundos(s): ");
    scanf("%d", &tSegundos);

        // Conversion de segundos
        horas = tSegundos/3600;
        segRestantes = tSegundos % 3600;
        minutos = segRestantes /60;
        segRestantes = segRestantes % 60;
        printf("%02d:%02d:%02d\n", horas, minutos, segRestantes);

            // Operador ternario ? valor en plural o singular
            printf("%d %s\n", horas, (horas == 1)? "Hora" : "Horas");
    

        return 0;
}