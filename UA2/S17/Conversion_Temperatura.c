//Convertir temperaturas Celsius-Fahrenheit
#include <stdio.h>

int main(void){
float celsius, fahrenheit;

printf("Temperatura en grados celsius: ");
scanf("%f", &celsius);

fahrenheit = celsius * (9.0 / 5.0) + 32;

printf("%.1f °C equivale a  %.1f °F\n", celsius, fahrenheit);


return 0;
}
