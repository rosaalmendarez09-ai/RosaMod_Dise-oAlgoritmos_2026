// areas.c Calcular varias áreas en una misma ejecución, eligiendo la figura en un menú.
#include <stdio.h>
#define PI 3.1416

int main(void)
{
    int opcion, salir;
    float lado, base, altura, radio;

    salir = 0;

    // Menu
    do
    {
        printf("   Ingresar los datos de las figuras\n");
        printf("1-Cuadrado  2-Rectangulo  3-Circulo  0-Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Cuadrado\n");
            printf("Lado: ");
            scanf("%f", &lado);
            printf("Area: %.2f\n", lado * lado);
            printf("\n");
            break;

        case 2:
            printf("Rectángulo\n");
            printf("Base: ");
            scanf("%f", &base);
            printf("Altura: ");
            scanf("%f", &altura);
            printf("Area: %.2f\n", base * altura);
            printf("\n");
            break;

        case 3:
            printf("Circulo\n");
            printf("Radio: ");
            scanf("%f", &radio);
            printf("Area: %.2f\n", PI * (radio * radio));
            printf("\n");
            break;

        case 0:
            break;

        default:
            printf("=====================\n");
            printf("¡==Opcion inválida==!\n");
            printf("=====================\n");
            printf("\n");
            break;
        }
    } while (opcion != salir);

    return 0;
}