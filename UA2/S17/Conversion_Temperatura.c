//Convertir temperaturas Celsius-Fahrenheit
#include <stdio.h>

int main(void){
float celsius, fahrenheit;

printf("Temperatura en grados celsius: ");
scanf("%lf", &celsius);

fahrenheit = celsius * (9 / 5) + 32;

printf("Celsius equivale a:  %.2lf °f", fahrenheit);


return 0;
}
