/*Sistema calculo de nomina
1. Reciba el nombre completo del empleado (puede tener espacios; no se acepta un nombre
vacío).
2. Reciba el salario bruto, que debe ser mayor que 0; si no, muestra un mensaje y lo vuelve a
pedir.
3. Calcule los descuentos sobre el salario bruto: CAJA (9.5 %), IESS (2.5 %) e impuesto sobre la
renta (10 %, solo si el salario bruto supera 800).
4. Calcule el salario neto (bruto menos todos los descuentos).
5. Muestre un comprobante con el nombre, el salario bruto, cada descuento y el salario neto, con
dos decimales y los montos alineados.*/

#include <stdio.h>
#include <string.h>

#define CAJA 0.095
#define IESS 0.025
#define RENTA 0.10

int main(void){
    char nombre[50];
    double salario, descuentos, bruto, caja, iess, renta, neto; 

   do
   {
    printf("Ingrese nombre completo: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre,"\n")]='\0';/* code */

    if ((strlen(nombre) == 0))
    {
       printf("Nombre vacio..\n"); /* code */
    }
    
   } while (strlen(nombre) == 0);
   

    // INGRESAR SALARIO Y VALIDAR QUE SEA MAYOR 
    do
    {
     printf("Ingrese salario bruto: ");
     scanf("%lf", &bruto);

     if (bruto <= 0)
     {
        printf("Dato inválida, debe ser mayor que 0.\n");
     }
     
    } while (bruto <= 0);

    caja = bruto * CAJA;
    iess = bruto * IESS;

    // IMPUESTO DE RENTA SI BRUTO ES MAYOR A 800
    if (bruto > 800)
    {
        renta = bruto * RENTA;
    }
    else
    {
      renta = 0;  /* code */
    }

    neto = bruto - caja - iess - renta;

    // SALIDA DE DATOS
    printf("=== COMPROBANTE DE PAGO ===\n");
    printf("Empleado:        \t%s\n", nombre);
    printf("Salario bruto:         \t%.2lf \n", bruto);
    printf("Descuento CAJA(9.5%%): \t%.2lf \n", caja);
    printf("Descuento IESS(2.5%%): \t%.2lf \n", iess);
    printf("Descuento RENTA(10%%): \t%.2lf \n", renta);
    printf("Salario neto:      \t%.2lf \n", neto);

    return 0;
}




