/* 1. Reciba el nombre completo del empleado (puede tener espacios; no se acepta un nombre
vacío).
2. Reciba el salario bruto, que debe ser mayor que 0; si no, muestra un mensaje y lo vuelve a
pedir.
3. Calcule los descuentos sobre el salario bruto: CAJA (9.5 %), IESS (2.5 %) e impuesto sobre la
renta (10 %, solo si el salario bruto supera 800).
4. Calcule el salario neto (bruto menos todos los descuentos).
5. Muestre un comprobante con el nombre, el salario bruto, cada descuento y el salario neto, con
dos decimales y los montos alineados.*/

#include <stdio.h>
#define MAX 10
#define NOM 50

int main(void){
    char nombre[50];
    char product[MAX][NOM];
    double precios[MAX], subProduct, totalDesc, subtotal, impuesto, totalPagar;
    int cantidades[MAX], i= 0, totalP = 0 ;

    printf("Ingrese nombre completo: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre,"\n")]='\0';

    do
    {
        printf("Ingrese producto %d:", );
        fgets(product[i], sizeof(product[i]),stdin); 

    } while (condition);
    





}