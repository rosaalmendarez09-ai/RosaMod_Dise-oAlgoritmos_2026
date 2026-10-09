//Convertir temperaturas Celsius-Fahrenheit
#include <stdio.h>

int main(void){
float celsius, fahrenheit;

printf("Temperatura en grados celsius: ");
scanf("%f", &celsius);

fahrenheit = celsius * (9.0 / 5.0) + 32;

printf("%.0f °C equivale a:  %.0f °f\n", celsius, fahrenheit);


return 0;
}
