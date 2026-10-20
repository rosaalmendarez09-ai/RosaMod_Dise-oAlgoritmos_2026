/* Reciba el nombre del colaborador y el puntaje de cada criterio (0 a 10); un puntaje fuera de
rango se vuelve a pedir. El mensaje debe mostrar el nombre del criterio.
2. Calcule el promedio y el nivel: EXCELENTE (9 o más), BUENO (7 o más, pero menos de 9) o
NECESITA MEJORAR (menos de 7).
3. Indique el criterio con el puntaje más bajo y su puntaje.*/
/*Resultado esperado: 
Colaborador: Laura Solis
Promedio: 9.17
Nivel: EXCELENTE
Puntaje mas bajo: calidad (8.5)*/

#include <stdio.h>
#include <string.h>

#define EXCELENTE 9
#define BUENO 7
#define MEJORAR 7

int main(void){
    char nombre[50];
    float puntualidad[3], calidad[3], equipo[3];
    int i;


    // INGRESAR NOMBRE
    printf("Nombre colaborador: ");
    fgets(nombre, sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")]='\0';

   // SOLICITAR PUNTAJE
   for (i = 0; i < 3; i++)
   {
//    VALIDAR QUE EL VALOR INGRESADO SEA CORRECTO
do
{
    printf("Puntaje puntualidad %d(0-10): ",i+1);
    scanf("%f", &puntualidad[i]);

    printf("Puntaje calidad %d(0-10): ",i+1);
    scanf("%f", &calidad[i]);

    printf("Puntaje trabajo %d(0-10): ",i+1);
    scanf("%f", &equipo[i]);

    if (puntajes[i] < 0)
    {
       printf("Dato erroneo, no puede ser negativo, vuelva a introducir dato: \n");
    }
} while (puntajes[i] < 0);

   }



// ===========================================
    // Muestra de Resultados
    printf("===============================\n");
    printf("=== EVALUACION DE DESEMPEÑO ===\n");
    printf(" Colaborador: %s\n",nombre);







    return 0;
}
