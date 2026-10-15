//ventas.c Ventas de una cadena de sodas por sucursal y por dia
//Que logra: Guardar en una matriz las ventas de 3 sucursales en 4 dias
/*Suma cada sucursal(fila) y cada dia por medio de la (columna) e identificar la sucursal que más vendio, con su nombre guardado en una cadena.
RESULTADO ESPERADO: Centro 470, Norte 350, Sur 410; por dia 330 270 330; Sucursal con más ventas: Centro(470)*/

#include <stdio.h>
#include <string>
#include <stdlib.h> //strcpy

//CONSTANTES
#define SUC 3 //Filas sucursales
#define DIAS 4 //Columnas dias

int main(void){
    //Arreglo de cadenas: una fila por nombre(hats 9 letras + '\0')
    char nombres[SUC] [10] = {"Centro", "Norte", "Sur"};

    //Ventas en miles de colones
    int ventas[SUC] [DIAS] = { {120, 100, 130, 120},
                              {90, 80, 100, 80},
                              {120, 90, 100, 100} };

    char mejor[10]; //Nombre de la sucursal ganadora
    int s, d, total, totalDia, mayor = 0; 
    
    //Encabezado: D1 a D4
    printf("%-8s", "");

    for(d = 0; d < DIAS; d++){
        printf("  D%d + d+1"); 
    }
    printf("  |  Total\n");

    //RECORRIDO POR FILAS
    for(s = 0; s < SUC; s++){
       total = 0; //reinicia cada fila en 0
       printf(" %-8s", nombres[s]); //nombre a la izquierda
       for ( d = 0; d < DIAS; d++){
        printf("%5d", ventas[s] [d]);
        total += ventas[s] [d];
       }

       printf("  | %5d\n", total); //470, 350, 410

       //Guardar la avariable con mayor total; strcpy copia el nombre
       if( total > maypr){
        mayor = total;
        strcpy(mejor, nombres[s]);
       }
    }
    
    //RECORRIDO POR COLUMNAS. el for externo recorre los dias
    printf("%-8s", DIAS);

    for( d= 0; d < DIAS; d++){
       totalDia = 0;

       for ( s = 0; s < SUC; s++){
       totalDia += ventas [s] [d];
       }
       printf("%d", totalDia); //330 270 330 300
    }
    printf("\n");

    //SALIDAS: Sucursalcon mas ventas: Centro 470
    printf("Sucursal con más ventas: %s (%d)\n", mejor, mayor);

    sistem("pause");

    
    return 0;
}


