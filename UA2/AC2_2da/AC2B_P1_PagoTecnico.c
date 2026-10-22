/*
1. Reciba el nombre completo del técnico, no se acepta un nombre vacío). 
2. Reciba las horas trabajadas en la semana (de 1 a 60) y la tarifa por hora (mayor que 0). Un 
dato inválido muestra un mensaje y se vuelve a pedir. 
3. Separe las horas: las primeras 48 son ordinarias; las que pasen de 48 son horas extra y se 
pagan al 150 % de la tarifa. 
4. Calcule el salario bruto (pago ordinario + pago extra), el seguro social (10.5 % del bruto) y el 
salario neto. 
5. Muestre un comprobante con el nombre, las horas y el pago ordinario, las horas y el pago extra, 
el bruto, el seguro y el neto, con dos decimales y alineados.*/
//agrego las bibliotecas printf, scanf y la de gets, otros
#include <stdio.h>
#include <string.h>

//CREO CONSTANTES PARA LOS DATOS QUE NO VARIAN JORNADA, MAXIMO DE HORAS, EL RECARGO Y LA TASA DEL SEGURO

#define JORNADA 48 
#define MAX 60
#define RECARGO 1.5
#define TASA 0.105

int main(void){

    //creo variables para datos de entrada y salida
   char nombre[50];
   int horas;
   double tarifaHora, bruto, extra, seguro, neto;

    do
    {//ingresar nombre: Jose Mora
        printf("Nombre del tecnico: ");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre,"/n")]='\0';

        if (strlen(nombre)==0)//validar que el nombre no quede vacio
        {
              printf("Nombre vacio, ingrese nuevamente ");
        }
    } while (strlen(nombre)==0);//se regresa si el nombre esta vacio y repite el ciclo

   
    
    








    return 0;
}

