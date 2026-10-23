// horas.c - Horas de estudio a la semana
/*ENUNCIADO: Regidtrar las horas de estudio de 3 estudiantes de lunes a jueves
Se dijite el nombre y las horas de estudio de cada dia.
Mostrar una tabla con el total de cada estudiante, quién estudio más, el dia con más horas y buscar a una persona del grupo por su nombre. */ 

#include <stdio.h>//Biblioteca para scanf- printf
#include <string.h>//Llamamos a fgets,strlen, otros

//Definir constantes
#define EST 3 //Filas de la MATRIZ
#define DIAS 4//Columnas

int main(void){
    //Arreglo de cadena para los tres nombres
    char nombres[EST][15]; //14 ESPACIOS para el Nombre y el ULTIMO ESPACIO es para '\0'

    // MATRIZ de horas: 3 filas para estudiantes y 4 columnas para los dias
    int horas[EST][DIAS];

    // arreglo de ecadenas: con los nombres CORTOS de los DIAS
    char dias[DIAS][4] = {"Lun","Mar","Mie","Jue"};

    //Se crean los indices de fila y columna
    int e, d;

    //Arreglo total por estudiante: total[e] = suma de la fila e. Guarda y busca al mayor.
    int total[EST];

    // POSICION: quien estudio más.
    int mejor;

    // ACUNULADO de columna(horas del grupo en un día)
    int sumaDia;

    // Suma mayor dia
    int sumaMayor;

    // POSICION:dia con más horas
    int diaMejor;

    // Cadena con el nombre a buscar
    char buscado[15];
    
    // Posicion de el nombre buscado
    int encontrado;

    //  ======== LECTURA CON LOS for anidados ========
    // Ciclo extreno: una vuelta por estudiante(fila)

    for ( e = 0; e < EST; e++)
    {
        // PEDIR nombre del estudiante
        printf("Nombre del estudiante %d:", e+1);
        // leer
        scanf("%14s", nombres[e]);


        // CICLO INTERNO: una vuelta por día(columna) de la fila
      for ( d = 0; d < DIAS; d++)
      {
        // Pedir horas del dia
        printf("Horas del %s: ", dias[d]);
        // Leer un entero en la celda
        scanf("%d",&horas[e][d]);
      } 
    }
    
    // ========== TABLA ==========
    // Con encabezado con la palabra Nombre
    printf("\n%-8s", "Nombre");
    
    // for para recorre los dias para el encabezado
    for ( d = 0; d < DIAS; d++)
    {
       printf("%5s", dias[d]);
    }
    
    // Titulo de la ULTIMA COLUMNA  
    printf("%7s\n", "Total");

    // Una fila de la tabla por estudiante
    for ( e = 0; e < EST; e++)
    {
        // reinicia el total de la fila e
        total[e] = 0;
        // mostrar el NOMBRE
        printf("%-8s", nombres[e]);
        
        // Recorre la columna de la fila e
        for ( d = 0; d < DIAS; d++)
        {
        //    mOSTRAR LAS HORAS DE LA CELDA
        printf("%5d",horas[e][d]);
        // sumar la celda al total
        total[e] += horas[e][d];
        }
        // mostar el total
        printf("%7d\n", total[e]);
    }
    
    // ============ MAYOR del arreglo TOTAL
      mejor = 0;
        // Recorrer los demás estudiantes (posiciones 1 y 2)

     for ( e = 0; e < EST; e++)
    
    //  comparar totales
    if (total[e] > total[mejor])
    mejor = e;

    // mostrar quien estudio mas
    printf("\nEstudio mas: %s (%d horas)\n", nombres[mejor], total[mejor]);

    // ============Dia con MAS horas (suma por columna)
    //mayor suma inicial en 0
    sumaMayor = 0;
    diaMejor = 0;

    // Recorrer columnas
    for ( d = 0; d < DIAS; d++)
    {
        //Reiniciamos el acumulador
        sumaDia = 0;

        // Recorer filas de esa columna
        for ( e = 0; e < EST; e++)

        // Suma de celda
        sumaDia += horas[e][d];

        //comparar la suma del dia con la mayor

        if (sumaDia> sumaMayor)
        {
            // guarda la nueva mayor
           sumaMayor = sumaDia;
        //    guarda la posicion
        diaMejor = d;
        }
    }
    
    // Mostrar el dia con más horas
    printf("Dia con mas horas: %s (%d horas)\n", dias[diaMejor], sumaMayor);

    // ================ BUSQUEDA POR NOMBRE ===============
    // Pedir nombre a buscar
    printf("\nBuscar estudiante: ");
    // Lee la palabre
    scanf("%14s", buscado);
    // Marca que todavia no aparece
    encontrado = -1; //Si el for no lo encuentra sigue en -1

    // Recorrer nombre
    for ( e = 0; e < EST; e++)
    // Compara las dos cadenas
    if (strcmp(buscado, nombres[e]) == 0)//strcmp devuelve 0 si son iguales
    encontrado = e;

   //Revisa si encontro 
   if (encontrado >= 0)
   {
    //Muestra el total encontrado 
    printf("%s estudio %d horas\n", nombres[encontrado], total[encontrado]);
    // En caso que no aparezca
   }else{
    printf("%s no esta en la lista\n", buscado);
    }
   

    return 0;
}
