
#include <stdio.h>

int main(void){

    int ana=0, luis=0, sofia=0, nulo=0, centinela=1, opcion, votos=0, i;

    while (centinela != 0)
    {

        printf("===========================================\n");
        printf("        Por quien desea votar: \n");
        printf("    1-ANA  2-LUIS  3-SOFIA  0- SALIR\n");
         printf("CUALQUIER OTRA OPCION SE TOMARÁ COMO NULA\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ana += 1;
            votos += 1;
            break;

        case 2:
            luis += 1;
            votos += 1;
            break;

        case 3:
            sofia += 1;
            votos += 1;
            break;

        case 0:
            centinela = 0;
            break;
        
        default:
            nulo += 1;
            votos += 1;
            printf("VOTO NULO\n");
            break;
        }
    }
    

    printf("\n");
    printf("===========================================\n");
    printf("VOTOS RECIBIDOS: %d\n", votos);

    printf("VOTOS ANA: ");
    for ( i = 1; i <= ana; i++)
    {
        printf("*");/* code */
    }
    printf(" (%d)\n", ana);

    printf("VOTOS LUIS: ");
    for ( i = 1; i <= luis; i++)
    {
        printf("*");/* code */
    }
    printf(" (%d)\n", luis);

    printf("VOTOS SOFIA: ");
    for ( i = 1; i <= sofia; i++)
    {
        printf("*");/* code */
    }
    printf(" (%d)\n", sofia);

    printf("VOTOS NULOS: ");
    for ( i = 1; i <= nulo; i++)
    {
        printf("*");/* code */
    }
    printf(" (%d)\n", nulo);
    
    if (ana == luis || ana == sofia || luis == sofia)
    {
        printf("HAY UN EMPATE SE DEBE VOLVER A REPETIR LA VOTACIÓN\n");
    }
    
    
    

    return 0;
}