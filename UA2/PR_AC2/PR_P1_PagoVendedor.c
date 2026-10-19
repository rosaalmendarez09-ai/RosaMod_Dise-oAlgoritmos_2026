/* Reciba el nombre del vendedor y las ventas de cada una de las 4 semanas del mes en un
arreglo. Ninguna venta puede ser negativa (se vuelve a pedir).
2. Calcule las ventas del mes, la comisión (5 % de las ventas) y un bono de 50 si las ventas del
mes superan 2000.
3. Calcule la retención (2 % de la comisión más el bono) y el pago (comisión + bono − retención).
4. Muestre las ventas de cada semana, las ventas del mes y el detalle del pago con dos
decimales.*/

#include <stdio.h>
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
    scanf("%s", nombre);

    // ingresar las ventas de las 4 semanas y validar negativos
    for (i = 0; i < 4; i++)
    {
        do 
        {
            printf("\nIngrese ventas semana %d: ", i + 1);
            scanf("%lf", &ventas[i]);

            if (ventas[i] < 0)
            {
                printf("Dato erroneo, no puede ser negativo, vuelva a introducir dato: \n");
            }
        } while (ventas[i] < 0);

        mes += ventas[i]; // ventas del mes
    }

    

    return 0;
}
