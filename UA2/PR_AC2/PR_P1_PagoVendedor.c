/* Reciba el nombre del vendedor y las ventas de cada una de las 4 semanas del mes en un
arreglo. Ninguna venta puede ser negativa (se vuelve a pedir).
2. Calcule las ventas del mes, la comisión (5 % de las ventas) y un bono de 50 si las ventas del
mes superan 2000.
3. Calcule la retención (2 % de la comisión más el bono) y el pago (comisión + bono − retención).
4. Muestre las ventas de cada semana, las ventas del mes y el detalle del pago con dos
decimales.*/

#include <stdio.h>  //libreria printf y scanf
#include <string.h> // uso de fgets, otros: no me deja escribir nombre compuesto por eso lo voy a utilizar

#define BONO 50
#define LIMITE 2000
#define COMISION 0.05
#define RETENCION 0.02

int main(void)
{
    double ventas[4], pago, comision, bono = 0, mes = 0, retencion;
    int i;
    char nombre[50];

    printf("Nombre del vendedor: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    // ingresar las ventas de las 4 semanas y validar negativos
    for (i = 0; i < 4; i++)
    {
        do
        {
            printf("Ingrese ventas semana %d: ", i + 1);
            scanf("%lf", &ventas[i]);

            if (ventas[i] < 0)
            {
                printf("Dato erroneo, no puede ser negativo, vuelva a introducir dato: \n");
            }
        } while (ventas[i] < 0);

        mes += ventas[i]; // ventas del mes
    }

    // Calcular comision y bono
    comision = mes * COMISION;
    if (mes > LIMITE)
    {
        bono = BONO;
    }
    else
    {
        bono = 0;
    }

    // Calculo de retencion y pago
    retencion = (comision + bono) * RETENCION;
    pago = (comision + bono) - retencion;

    // Muestra de resultados
    printf("====PAGO DE COMISIONES DEL MES====\n");
    printf("VENDEDOR: %s\n", nombre);
    // muestra ventas por semana
    for (i = 0; i < 4; i++)
    {
        printf("Ventas semana %d: %.2lf\n", i + 1, ventas[i]);
    }
    printf("Ventas del mes: %.2lf\n", mes);
    printf("Comision(5%%): %.2lf\n", comision);
    printf("Bono: %.2lf\n", bono);
    printf("Retencion(2%%): %.2lf\n", retencion);
    printf("Pago del mes: %.2lf\n", pago);

    return 0;
}
