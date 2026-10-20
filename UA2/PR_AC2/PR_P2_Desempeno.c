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
    char nombre[50], criterio[3]= {"puntualidad", "calidad", "trabEquipo"};
    float puntaje[3];
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
    printf("Puntaje %s (0-10):  ",criterio[i]);
    scanf("%f", &puntaje[i]);


   if (condition)
   {
    /* code */
   }
   else if (condition)
   {
    /* code */
   }
   else
   {
    /* code */
   }
   
    
} while (puntaje[i] < 0);

   }



// ===========================================
    // Muestra de Resultados
    printf("===============================\n");
    printf("=== EVALUACION DE DESEMPEÑO ===\n");
    printf(" Colaborador: %s\n",nombre);







    return 0;
}
