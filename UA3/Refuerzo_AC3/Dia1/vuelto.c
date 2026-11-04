/*vuelto.c -  Vuelto en billetes y monedas
==========================================================================
* ENUNCIADO:
Una caja calcula el vuelto de cada compra. 
Se digita el total de la compra (1 a 1 000 000) y el monto pagado, que no puede ser menor que el total (si lo es, se vuelve a pedir). 
El programa muestra el vuelto y cuántos billetes o monedas de cada denominación entregar, empezando por la mayor (20 000, 10 000, 5000, 2000, 1000, 500, 100, 50, 25, 10 y 5); solo se muestran las que se usan. 
Si sobran colones que no se pueden entregar (menos de 5), se indica. 
Al final se muestra la cantidad total de piezas. 
Después de cada compra se pregunta si hay otra (S/N).

* QUÉ SE LOGRA:
El cálculo y desglose exacto del vuelto de una compra en colones
Determinando la cantidad de billetes y monedas necesarios por denominación (desde 20 000 hasta 5 colones), detectando sobrantes no entregables.

* CÓMO SE LOGRA:
  -Estructuras repetitivas (while) para múltiples compras consecutivas.
  - (do-while) para asegurar que el total de la compra esté entre 1 y 1 000 000, y que el monto pagado sea igual o superior al total.
  - Almacenamiento de las 11 denominaciones monetarias en un arreglo constante de mayor a menor 
  - Una función que utiliza punteros para actualizar el residuo y calcular las piezas necesarias por cada denominación
  - if- else para filtrar e imprimir únicamente las denominaciones utilizadas, además de notificar si quedan colones sobrantes menores a 5.

* RESULTADO ESPERADO:
Mostrar en pantalla el vuelto total, el desglose detallado de los billetes y monedas, la sumatoria total de piezas entregadas, y la consulta final para procesar una nueva compra o finalizar el programa.*/

#include <stdio.h>

// PROTOTIPOS DE FUNCIONES

void limpiar();//Para limpiar basura

int leerEntero(const char mensaje[], int minimo, int maximo); //Funcion para solicitar datos: totalcompra,montopagado
char leerSN(const char mensaje[]);// Para respuesta si agrega más

int cuantas(int *resto, int denominacion);//Calcular las piezas que se van a entregar

// CONSTANTES
#define MIN 1 //minimo de compra
#define MAX 1000000 //maximo de compra
#define MENOS 5 //vuelto menor de 5 no se pueden entregar

// Inicio funcion principal main
int main(void){

    double compra, pagado, vuelto;
    char respuesta;
    int tPiezas = 0;

    do
    {
        compra = leerEntero("Digita el total de compra",MIN,MAX);//llamamos a la funcion para solicitar total de la compra

        do
        {
        pagado = leerEntero("Digita el monto pagado:",compra,MAX);//llamamos a la funcion para solicitar monto pagado
        } while (pagado < compra);
        

        





    } while (respuesta == 'S' || respuesta == 's');
    

    





}
// Declaracion de funciones

// ===============limpiar basura========================
void limpiar()
{
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}
// =====================================================
 

// ===============funcion leerEntero======================
int leerEntero(const char mensaje[], int minimo, int maximo){

int valor;

    valor = 0;
    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);
        limpiar();

        if (valor < minimo || valor > maximo)
        {
            printf("Dato erróneo, vuelva a ingresarlo.\n");
        }

    } while (valor < minimo || valor > maximo);

    // regresa valor
    return valor;
}
//========================FIN==========================





// ===============funcion leerSN======================
char leerSN(const char mensaje[]){
  char continuar;

    do
    {
        printf("%s: ", mensaje);
        scanf("%c", &continuar);
        limpiar();

        if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n')
        {
            printf("Dato erróneo, vuelva a ingresarlo.\n");
        }

    } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');

    return continuar;
}

//======================FIN===============================



// ===============funcion cuantas======================
int cuantas(int *resto, int denominacion){






}


//=========================FIN===========================