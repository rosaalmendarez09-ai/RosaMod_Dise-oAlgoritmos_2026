// bisiesto.c año es bisiesto o no lo es.
#include <stdio.h>

int main(void){
    int year;
    int esBisiesto;

    printf("Año: ");
    scanf("%d", &year);

    esBisiesto = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

   printf("%d %s bisiesto\n", year, esBisiesto? "es" : "no es");

    return 0;
}