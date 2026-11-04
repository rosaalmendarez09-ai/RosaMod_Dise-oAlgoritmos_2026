/* recibo.c -  Recibo de electricidad

==========================================================================

* ENUNCIADO:
Una cooperativa eléctrica emite recibos.
Se digita el número de medidor (1000 a 9999), el tipo de cliente (1 Residencial, 2 Comercial) y el consumo del mes en kWh (0 a 3000); un dato inválido se vuelve a pedir.
Residencial: los primeros -> 200 kWh a ₡80 c/u  ->201 a 400 a ₡110  -> 400 o más a ₡150. Comercial: ₡130 por kWh más un cargo fijo de ₡3000.
A todos se les suma alumbrado público: 2 % del monto de energía.
Después de cada recibo se pregunta si hay otro (S/N).

* QUÉ SE LOGRA:


* CÓMO SE LOGRA:
  arreglo para medidor y tipo de cliente
  if anidado tarifa
  switch opciones


* RESULTADO ESPERADO:
Mostrar cuántos recibos se emitieron, el total facturado y el medidor con el recibo mayor.

========================================================================== */

#include <stdio.h> //

// Prototipos de variables
void limpiar();
int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
double energiaResidencial(int kwh);
double calcularRecibo(int tipo, int kwh);

// constantes
#define FIJO 3000
#define MIN 0
#define PUBLICO 0.02
#define TARIF1 80
#define TARIF2 110
#define TARIF3 150
#define COMERCIAL 130

int main(void)
{
    int medidor, medidorMayor = 0;
    int tipo, recibosTotal = 0;
    int consumo;
    double totalFacturado, montoMayor = 0, totalFinal = 0;
    char continuar;

    do
    {
        medidor = leerEntero("Digite el numero de medidor: ", 1000, 9999);

        tipo = leerEntero("Digite el tipo 1:Comercial 2:Residencial ", 1, 2);

        consumo = leerEntero("Digite el consumo del mes: ", MIN, FIJO);

        totalFacturado = calcularRecibo(tipo, consumo);

        totalFinal += totalFacturado;

        if (recibosTotal == 0 || totalFacturado > montoMayor)
        {
            montoMayor = totalFacturado;
            medidorMayor = medidor;
        }


        recibosTotal++; // Para contar los reciboes esmitidos
        continuar = leerSN("Desea ingresar otro recibo?(S/N)");

    } while (continuar == 'S' || continuar == 's');

    // ===============================================
    // SALIDAS =======================================

    printf("\n========================================\n");
    printf("\t RESUMEN\n");
    printf(" Total de recibos emitidos: %d\n", recibosTotal);
    printf(" Total facturado: ₡%.2lf\n", totalFinal);
    if (recibosTotal > 0)
    {
        printf(" Medidor con el recibo mayor: %d (₡%.2lf)\n", medidorMayor, montoMayor);
    }

    return 0;
}

// Definicion de funciones

void limpiar()
{
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}

// ==========================================================
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    // Variable local para el dato
    int valor;

    valor = 0;
    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);
        limpiar();

        if (valor < minimo || valor > maximo)
        {
            printf("Dato erróneo, vuelva a ingresarlo.\n");
        }

    } while (valor < minimo || valor > maximo);

    // regresa valor
    return valor;
}

// ========================================================

double energiaResidencial(int kwh)
{ //Se van restando 
    double monto = 0;

    if (kwh <= 200)
    {
        monto = kwh * TARIF1; //₡80
    }
    else if (kwh <= 400)
    {
        monto = (200 * TARIF1) + ((kwh - 200) * TARIF2); //₡110
    }

    else
    {
        monto = (200 * TARIF1) + (200 * TARIF2) + ((kwh - 400) * TARIF3); //₡150
    }

    return monto;
}

// ================================

char leerSN(const char mensaje[])
{
    char respuesta;

    do
    {
        printf("%s: ", mensaje);
        scanf("%c", &respuesta);
        limpiar();

        if (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n')
        {
            printf("Dato erróneo, vuelva a ingresarlo.\n");
        }

    } while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n');

    return respuesta;
}

// ============================================

double calcularRecibo(int tipo, int kwh)
{
    double energia = 0;
    double cargoComercial = 0;
    double alumbrado;
    double total;

    switch (tipo)
    {

    case 1:
        energia = energiaResidencial(kwh);
        break;

    case 2:
        energia = kwh * COMERCIAL;
        cargoComercial = FIJO;
        break;
    }

    // Es el 2% DEL MONTO DE ENERGIA
    alumbrado = energia * PUBLICO;

    // TOTAL DEL RECIBO
    total = energia + alumbrado + cargoComercial;

    return total;
}
