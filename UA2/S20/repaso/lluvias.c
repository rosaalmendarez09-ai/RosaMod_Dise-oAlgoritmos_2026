// lluvias.c - Lluvia por region de enero a abril
// ENUNCIADO: la lluvia (en mm) de 3 regiones durante 4 meses ya esta
//   cargada en el programa. Mostrar una tabla con el total y el promedio
//   mensual de cada region y cual fue la region mas lluviosa. Despues,
//   pedir el nombre de una region (con fgets) y mostrar su total.
// QUE SE LOGRA: recorrer una matriz por filas, copiar y comparar cadenas.
// COMO SE LOGRA: for anidados con un ACUMULADOR que se reinicia en cada
//   fila; el arreglo totales guarda el total de cada region; strcpy
//   guarda el nombre de la mas lluviosa; fgets + strcspn leen la region
//   sin el Enter y strcmp la busca en el arreglo de nombres.
// RESULTADO ESPERADO: Norte 310 (77.5), Centro 410 (102.5), Sur 660
//   (165.0); Mas lluviosa: Sur (660 mm); al buscar Centro ->
//   "Centro: 410 mm en 4 meses".
#include <stdio.h>             // printf, fgets
#include <string.h>            // strcpy, strcmp, strcspn
#define REG 3                  // cantidad de regiones = filas
#define MESES 4                // cantidad de meses (ene a abr) = columnas

int main(void) {
    // regiones: nombre de cada fila de la matriz
    char regiones[REG][10] = {"Norte", "Centro", "Sur"};
    // lluvia[r][m]: milimetros de lluvia de la region r en el mes m
    int lluvia[REG][MESES] = {{120, 90, 60, 40},     // Norte
                              {80, 70, 110, 150},    // Centro
                              {200, 180, 150, 130}}; // Sur
    int totales[REG];          // total de lluvia de cada region
    char masLluviosa[10];      // nombre de la region con mas lluvia
    int mayor = 0;             // mayor total encontrado hasta el momento
    char buscada[20];          // region que digita la persona
    int encontrada = -1;            // posicion de la region buscada (-1 = no esta)
    int r, m;                  // r = region (fila), m = mes (columna)
    int total = 0;                 // ACUMULADOR de la fila actual
    float promedio;            // promedio mensual de la region

    printf("%-8s%8s%10s\n", "Region", "Total", "Promedio");
    for (r = 0; r < REG; r++) {
        total = 0;                // se reinicia para cada region
        for (m = 0; m < MESES; m++)
            total += lluvia[r][m];     // suma la fila -> Norte: 310

        totales[r] = total;            // se guarda para la busqueda
        promedio = (float)total / MESES;
        printf("%-8s%8d%10.1f\n", regiones[r], total, promedio);


        if (total > mayor) {           // region con mas lluvia
            mayor = total;
            strcpy(masLluviosa, regiones[r]); // guarda el nombre****
        }
    }
    printf("Mas lluviosa: %s (%d mm)\n", masLluviosa, mayor);

    
    // BUSQUEDA: fgets lee la linea completa, incluido el Enter
    printf("\nRegion a buscar: ");
    fgets(buscada, sizeof(buscada), stdin);
    buscada[strcspn(buscada, "\n")] = '\0';              // quita el Enter



    for (r = 0; r < REG; r++) { // todavia no aparece
        if (strcmp(buscada, regiones[r])== 0)  {         // compara los nombres
            encontrada = r;            // guarda la posicion -> 1
        break;
        }
    }

    if (encontrada >= 0)
        printf("%s: %d mm en %d meses\n", buscada, totales[encontrada],
               MESES);
    else
        printf("Region no encontrada\n");
    

    
    return 0;
}

// printf("[%s]\n", buscada);