// descuento.c descuento por monto de compra
#include <stdio.h>
// define constante
#define MINIMO 50000.0

int main(void){
    // define variables
    const double TASA = 0.10;
    double compra, descuento, total;

    // ENTRADA
    printf("Monto de compra: ");
    scanf("%lf", &compra);

        if (compra >= MINIMO ){
            descuento = compra * TASA;
        }
        else {
            descuento = 0;
        }

        total = compra - descuento;
    
    printf("Descuento: %.2lf\n", descuento);
    printf("Total a pagar: %.2lf\n", total);

return 0;

}