#include <stdio.h>
#include <string.h>
/*
Enunciado:
Un taller paga a sus tecnicos por hora trabajada.
Las primeras 48 horas se pagan normalmente y las horas
adicionales se pagan al 150% de la tarifa por hora.
Que se logra:
Leer y validar los datos del tecnico, calcular el salario
bruto, el seguro social y el salario neto, e imprimir
un comprobante ordenado con dos decimales.
Como se logra:
Se utilizan fgets y strlen para el nombre, do-while para
validar los datos, if-else para separar las horas ordinarias
de las extraordinarias y constantes para los porcentajes.
Salida esperada:
Un comprobante con el nombre, las horas trabajadas,
los pagos correspondientes, el seguro social y el salario neto.
*/

// Constantes del programa
#define JORNADA 48
#define MAX 60
#define RECARGO 1.5
#define TASA 0.105

static void limpiarBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main(void)
{
    // Variables para almacenar los datos del tecnico
    char nombre[50];
    int horas = 0;
    double tarifaHora = 0.0;

    // Variables para calcular el salario
    int horasOrdinarias;
    int horasExtra;
    double pagoOrdinario;
    double pagoExtra;
    double bruto;
    double seguro;
    double neto;
    int lecturaCorrecta;

    // Solicitar y validar el nombre del tecnico
    do
    {
        printf("Nombre del tecnico: ");
        if (fgets(nombre, sizeof(nombre), stdin) == NULL)
        {
            printf("No se pudo leer el nombre.\n");
            return 1;
        }

        // Eliminar el salto de linea del nombre
        nombre[strcspn(nombre, "\n")] = '\0';

        if (strlen(nombre) == 0)
        {
            printf("Nombre vacio, ingrese nuevamente.\n");
        }
    } while (strlen(nombre) == 0);

    // Solicitar y validar las horas trabajadas
    do
    {
        printf("Ingrese horas trabajadas (1-%d): ", MAX);
        lecturaCorrecta = scanf("%d", &horas);

        if (lecturaCorrecta != 1)
        {
            printf("Dato invalido. Ingrese un numero entero.\n");
            horas = 0;
            limpiarBuffer();
        }
        else if (horas < 1 || horas > MAX)
        {
            printf("Las horas deben estar entre 1 y %d.\n", MAX);
            limpiarBuffer();
        }
        else
        {
            limpiarBuffer();
        }
    } while (horas < 1 || horas > MAX);

    // Solicitar y validar la tarifa por hora
    do
    {
        printf("Ingrese tarifa por hora: ");
        lecturaCorrecta = scanf("%lf", &tarifaHora);

        if (lecturaCorrecta != 1)
        {
            printf("Dato invalido. Ingrese un numero.\n");
            tarifaHora = 0.0;
            limpiarBuffer();
        }
        else if (tarifaHora <= 0)
        {
            printf("La tarifa debe ser mayor que cero.\n");
            limpiarBuffer();
        }
        else
        {
            limpiarBuffer();
        }
    } while (tarifaHora <= 0);

    // Separar las horas ordinarias de las extraordinarias
    if (horas <= JORNADA)
    {
        horasOrdinarias = horas;
        horasExtra = 0;
    }
    else
    {
        horasOrdinarias = JORNADA;
        horasExtra = horas - JORNADA;
    }

    // Calcular los pagos
    pagoOrdinario = horasOrdinarias * tarifaHora;
    pagoExtra = horasExtra * tarifaHora * RECARGO;

    // Calcular salario bruto, seguro social y salario neto
    bruto = pagoOrdinario + pagoExtra;
    seguro = bruto * TASA;
    neto = bruto - seguro;

    // Imprimir el comprobante
    printf("\n");
    printf("===============================================\n");
    printf(" COMPROBANTE DE PAGO\n");
    printf("===============================================\n");
    printf("Tecnico: %s\n", nombre);
    printf("Tarifa por hora: %14.2f\n", tarifaHora);
    printf("-----------------------------------------------\n");
    printf("%-25s %8s %14s\n", "Concepto", "Horas", "Monto");
    printf("-----------------------------------------------\n");
    printf("%-25s %8d %14.2f\n", "Horas ordinarias", horasOrdinarias, pagoOrdinario);
    printf("%-25s %8d %14.2f\n", "Horas extraordinarias", horasExtra, pagoExtra);
    printf("-----------------------------------------------\n");
    printf("%-34s %14.2f\n", "Salario bruto:", bruto);
    printf("%-34s %14.2f\n", "Seguro social (10.5%):", seguro);
    printf("%-34s %14.2f\n", "Salario neto:", neto);
    printf("===============================================\n");

    return 0;
}
