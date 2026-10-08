//Factura con IVA

#include <stdio.h>

int main(void){
    //constante para el IVA
    const double TASA_IVA = 0.13;

    //Variables enteras para cantidad y reales para montos
    int cantidad;
    double precio, subtotal, iva, total;

    //ENTRADA: pedir y almacenar cantidad, Leer entero = 3 
    printf("Cantidad: ");
    scanf("%d", &cantidad);

    //Leer un double precio = 5000
   printf("Precio unitario: ");
   scanf("%lf", &precio);

   //PROCESO: int * double -> subtotal = 15000
   subtotal = cantidad * precio;

   //Sacamos IVA con la constante -> iva = 1950
   iva = subtotal * TASA_IVA;

   //total -> 16950
   total = subtotal + iva;

   //salidas: usar dos decimales, 10 espacios
   printf("Subtotal: %10.2f\n", subtotal);
   printf("IVA(13%%): %10.2f\n", iva);
   printf("Total: %10.2f\n", total);

return 0;
}