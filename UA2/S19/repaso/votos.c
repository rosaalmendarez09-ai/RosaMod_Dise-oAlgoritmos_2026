/*El grupo va a elegir a su representante entre tres candidatos: 1 Ana, 2 Luis y 3 Sofía. Cada estudiante pasa a la computadora y digita el número de su candidato. No se sabe cuántas personas votarán: la votación termina cuando alguien digita 0.
Cualquier otro numero es voto nulo. Al final se muestra una barra de *** con los votos del candidato */

#include <stdio.h> //Trae printf y scanf
#include <stdlib.h> 
#define FIN 0 //definimos constantes e iniciallizamos

int main(void){ //Funcion principal 

    int voto, cantidad/*numero que digita cada estudiante -> 1,2,3 otro o 0 */, c/*candidato que dibuja al for externo 1 a 3*/, i/*contador de for interno: interno:1 vuelta por cada asterisco */; 
    int total = 0; //contador de votos recibidos ( validos como nulos)
    int ana = 0, luis = 0, sofia = 0, nulos = 0; //contadores
    int mayor; //mayor candidad votos
    int empat; //candidatos con misma cantidad votos

    
    printf("=======Elección de representantes ========\n");
    printf("1 Ana 2 Luis 3 Sofia (0 cierra)\n\n");

    // Lecturas previas
    printf("voto: ");
    scanf("%d", &voto);

    // while con centinela. Se repite mientras el voto no sea 0
    while (voto != FIN)
    {
       total++; //Cuenta voto -> 1, 2, 3, ....,

        // SWITCH: sumar 1 al contador del candidato elegido
       switch (voto){
       case 1: ana++;break;
        case 2: luis++;break;
         case 3: sofia++;break;
       default: //cualquier otro numero != 1, 2, 3, 0
        nulos++;
        printf("Voto nulo\n");
       }

    //NUEVA LECTURA: sin la nueva el voto no cambia y el while no termina
     printf("voto: ");
     scanf("%d", &voto);
    }

      printf("\nVotos recibidos: %d\n", total);

        //FOR EXTERNO: Una vuelta por candidato -> c = 1, 2, 3 
        for ( c= 1; c <= 3; c++){
            switch (c){
            case 1: printf("Ana "); cantidad = ana; break;
               case 2: printf("Luis "); cantidad = luis; break;
                 default: printf("Sofia "); cantidad = sofia; break;}
            // FOR INTERNO: (ANIDADO) un for * y otro por voto -> Ana ***
            for (i = 1; i <= cantidad; i++)
            printf("*");
            printf(" (%d)\n", cantidad);
        }
         printf("Nulos: %d\n", nulos);

            // MAYOR de tres; 1er lugar
            mayor = ana;
            if (luis > mayor) mayor = luis;
            if (sofia > mayor) mayor = sofia;

            // EMPATADOS
            empat = 0;
            if (ana == mayor) empat++;
            if (luis == mayor) empat++;
            if (sofia == mayor) empat++;


        // decision: solo se ejecuta el primer 
        if (mayor == 0)
        printf("No hubo votos válidos\n");

        else if (empat > 1)
        printf("Empate con %d votos: se repite la votación\n", mayor);

        else if (ana == mayor)
        printf("Gana Ana con %d votos\n", mayor);//3 votos


        else if (luis == mayor)
        printf("Gana Luis con %d votos\n", mayor);


        else if (sofia == mayor)
        printf("Gana Sofía con %d votos\n", mayor);//3 votos

        system("pause");
    return 0;

}