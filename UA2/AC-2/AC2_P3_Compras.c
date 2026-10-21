/*1. Reciba el nombre del cliente.
2. Permita registrar varios productos (máximo 10): nombre (puede tener espacios), precio
unitario y cantidad. Después de cada producto pregunta si desea agregar otro (S/N); solo
acepta S o N (mayúscula o minúscula).
3. Valide que el precio y la cantidad sean positivos.
4. Muestre el subtotal de cada producto (precio × cantidad) al ingresarlo y acumule el total.
5. Aplique el descuento según el total: menos de 100, sin descuento; de 100 a menos de 500, 5 %;
de 500 a 1000, 10 %; más de 1000, 15 %.
6. Calcule el total con descuento y el impuesto (13 % sobre el total con descuento).
7. Muestre una factura con el cliente, el detalle de cada producto (nombre, precio, cantidad y
subtotal), la cantidad de productos, el subtotal, el descuento, el total con descuento, el impuesto
y el total a pagar.*/

#include <stdio.h>
#include <string.h>
#define MAX 10
#define NOM 50

int main(void){
    char nombre[50], resp;
    char product[MAX][NOM];
    double precios[MAX], subProduct, totalDesc, subtotal, impuesto, totalPagar;
    int cantidades[MAX], i = 0, totalP = 0 ;

    printf("Ingrese nombre completo: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre,"\n")]='\0';

    do 
    {   
        printf("Ingrese producto:" );
        fgets(product[i], sizeof(product[i]),stdin); 
        product[i][strcspn(product, "\n")] = '\0';

        //validar precio != negativo
        do
        {
        printf("Ingrese precio producto: \n");
        scanf("%lf", &precios[i]);

        if (precios[i]<0)
        {
            printf("Precio invalido: \n");
        }

        } while (precios[i] < 0);


        // VALIDAR CANTIDAD != 0
        do
        {
           printf("Ingrese cantidad: \n");

           if (cantidades[i] < 0)
           {
            printf("Cantidad invalida \n");
           }
           
           } while (cantidades[i] < 0);

        // calculo producto subtotal
        subProduct = precios[i] * cantidades[i];
        
        printf("Subtotal: %.2f\n", subProduct);


        // calcular compra subtotal
        subtotal += subProduct;

        // productos ingresados
        totalP++; 
        i++;

        while (getchar() != '\n')
       
        if (totalP < MAX)
        {
            do
            {
            printf("Desea agregar mas S/N: \n");
            scanf("%c", &resp)
            if (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n')
            {
            printf("Formato no valido");
            }
            
            } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');
            
        }
        

    } while (resp == 'S' || resp == 's') && totalP < MAX);
    




    return 0;
}