/* Parqueo.c -  Cobro diario de un parqueo

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

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Manipulación de texto

// Definición de constantes
#define TMOTO 500    // Tarifa por hora de las motos
#define TAUTO 800    // Tarifa por hora de los autos
#define TBUSETA 1200 // Tarifa por hora de las busetas
#define TMAX 6000    // Tarira maxima que puede pagar un cliente
#define MAX_V 10     // Cantidad maxima de vehiculos
#define MAX_H 24     // Cantidad maxima de horas
#define MIN 1        // Minimo estandar

// Prototipo de funciones
int verificacion(int minimo, int maximo, int valor);
int registroVehiculo(int minimo, int maximo, int valor);

int main(void)
{
    // Definición de variables
    int opcion;
    double horas[MAX_V];
    char placas[MAX_V][10]; // Arreglo que almacenara hasta 10 placas de 10 caracteres
    double cobro[MAX_V];
    double totalDia = 0;
    double mayorPago = 0;
    int mayor = 0;
    int cantidadV = 0;  // guarda la cantidad de vehiculos por dia
    int cantidadTM = 0; // Cantidad de vehiculos que pagaron la tarifa maxima
    int i;              // indice general
    int f;              // indice filas
    // int c;                  //indice columnas

    // ENTRADA
    printf("===== Registro de vehiculos (Parqueo) =====\n");
    for (i = 0; i < MAX_V; i++)
    {
        printf("-----------------------------------------------------\n");

        printf("1.Moto - 500 por hora\n");
        printf("2.Auto - 800 por hora\n");
        printf("3.buseta - 1200 por hora\n");
        printf("0.Salir\n");

        do // VALIDACION
        {
            printf("Ingrese el tipo de vehiculo: ");
            scanf("%d", &opcion);

            if (opcion < 0 || opcion > 4)
            {
                printf("ERROR: Dato invalido, por favor ingrese una opcion (0-3)\n");
            }

            
        } while (opcion < 0 || opcion > 4);
        // =========================================
        if (opcion == 0)
        {
            break;
        }
        printf("Digite la placa: ");
        scanf("%9s", placas[i]);
        // =============================================
        // valida horas (1-24)
        do
        {
            printf("Ingrese la cantidad de horas: ");
            scanf("%lf", &horas[i]);

            if (horas[i] < MIN || horas[i] > MAX_H)
            {
                printf("ERROR: dato fuera de rango (1-24)\n");
            }
        } while (horas[i] < MIN || horas[i] > MAX_H);

        // PROCESO
        // Calculo de la tarifa por hora

        switch (opcion)
        {
        case 1:
            cobro[i] = TMOTO * horas[i];
            break;

        case 2:
            cobro[i] = TAUTO * horas[i];
            break;

        default:
            cobro[i] = TBUSETA * horas[i];
            break;
        }
        // =====================================================
        // Tope de tarifa(6000)
        if (cobro[i] > TMAX)
        {
            cobro[i] = TMAX;
        }

        // Comprobador de mayor cobro

        if (i == 0 || cobro[i] > mayorPago)
        {
            mayorPago = cobro[i];
            mayor = i;
        }

        // vehiculos con tarifa maxima==================
        if (cobro[i] == TMAX)
        {
            cantidadTM++;
        }
        // ACUMULADOR total de dia==================
        totalDia += cobro[i];
        cantidadV++;
    }
    // SALIDA tabla con resultados
    // Matriz

    if (cantidadV > 0)
    {
        printf("\n%-12s%-7s%-7s\n", "Placa", "Horas ", "Cobro");

        for (f = 0; f < cantidadV; f++)
        {
            printf("%-12s%-7.2f%-7.2f", placas[f], horas[f], cobro[f]);
            //}
            printf("\n");
        }

        // SALIDA
        printf("\nTotal dia: %.2f\n", totalDia);
        printf("\n%s Vehiculo que mas pago: %.2f\n", placas[mayor], mayorPago);
        printf("Cantidad de vehiculos que pagaron la tarifa maxima: %d\n", cantidadTM);
    }

    return 0;
}

/*//Definición de función: registro autos
int registroVehiculo (int minimo, int maximo, int valor){
    int valor;



}

//Definición de función: verificacion
int verificacion (int minimo, int maximo, int valor){
    int valor;
    do {
        printf("Tipo de vehiculo: ");
        scanf("%d", &valor);

        if (valor < minimo || valor > maximo){
            printf("ERROR: Opción fuera de rango\n");
        }

    } while (valor < minimo || valor > maximo);

    return valor;
}*/