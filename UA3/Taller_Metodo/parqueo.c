/* parqueo.c -  Cobro diario de un parqueo
==========================================================================
* ENUNCIADO:
 
Un parqueo registra los vehículos del día (de 1 a 10). De cada uno se digita la placa (una palabra), el tipo de vehículo (1 Moto 500 por hora, 2 Auto 800 por hora, 3 Buseta 1200 por hora) y las horas que estuvo (de 1 a 24); un dato inválido se vuelve a pedir. El cobro es la tarifa por las horas, pero nunca supera la tarifa máxima diaria de 6000. Mostrar una tabla con placa, horas y cobro, el total del día, el vehículo que más pagó y cuántos pagaron la tarifa máxima.

* QUÉ SE LOGRA:
Se logra desarrollar un sistema que organiza y mantiene un control sobre los usuarios de un parqueo, dando pie a una mejor organización en dicha empresa. 

* CÓMO SE LOGRA:
Mediante el desarrollo de una aplicación, la cual mediante la definición de constantes, uso de librerías y el uso funciones, va a permitir que dicha aplicación funcione conforme a las exigencias, restricciones y los datos ingresados por el usuario.

* RESULTADO ESPERADO:
Un sistema infalible que puede mantener el funcionamiento de una empresa, en este caso, un parqueo, de manera indefinida sin presentar errores y dando resultados concisos y certeros. 
========================================================================== */

#include <stdio.h>

#define MOTO 500
#define AUTO 800
#define BUSETA 1200
#define TMAX 6000 //TARIFA MAXIMA
#define MAHORAS 24
#define MAXVEHI 10
#define MIN 0

// PROTOTIPOS FUNCIONES
int validarRango(int minimo, int maximo, const char mensaje[]);
double calcularCobro(int tipo, int horas);


int main(void){
    char placas[MAXVEHI][10];
    int tipos[MAXVEHI];
    double horas[MAXVEHI];
    double horas, cobro;
    int opcion, f, c;
  
    // Entradas
leerPlaca("ingrese el tipo de vehiculo");



    // PROCESOS

    





}

// DEFINICION FUNCIONES
int leerPlaca(const char mensaje[], int minimo, int maximo){
int minimo;
int maximo;


printf("============================\n");
    printf("====== VENTA ENTRADAS ======");
    printf("\nINGRESA EL TIPO DE VEHICULO:\n 1.MOTO       500H\n 2.AUTO          800H\n 3.BUSETA  1200H        4.SALIR\n");


}


int verificacion(int minimo, int maximo, int valor){

 int valor;

    printf("=========PARQUEO=============\n");
    printf("1.MOTO - 500h\n");
    printf("2.AUTO - 800H\n");
    printf("3.BUSETA:\n");
    printf("O.SALIR:\n");
    printf("INGRESE EL TIPO DE VEHICULO:\n"); 

 
    do{
        printf("Ingrese el tipo de vehiculo: ");
        scanf("%d", &valor);
 
        if (valor < minimo || valor > maximo){
            printf("Dato invalido......\n");
        }
 
    } while (valor < minimo || valor > maximo);
}


doble cobroTarifa()
switch (expression)
{
case constant expression:
    /* code */
    break;

default:
    break;
}

printf("\n%-12s%9s%12s\n", "clientes", "Entradas", "totales"){

printf("\n\n==================================================\n");
    printf("             REPORTE DIARIO DE PARQUEO             \n");
    printf("==================================================\n");
    printf("%-15s | %-6s | %-10s\n", "PLACA", "HORAS", "COBRO (₡)");
    printf("--------------------------------------------------\n");

}