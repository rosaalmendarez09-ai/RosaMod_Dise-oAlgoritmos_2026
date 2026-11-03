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
    int medidor;
    int tipo;
    int consumo;
    double subtotal;
    int recibos = 0;

    medidor = leerEntero("Digite el numero de medidor: ", 1000, 9999);

    tipo = leerEntero("Digite el tipo (1:Comercial 2:Residencial): ", 1, 2);

    consumo = leerEntero("Digite el consumo del mes: ", MIN, FIJO);

    subtotal = energiaResidencial(consumo);

    // SALIDAS
    printf("IMPRIME %.2lf\n", subtotal);

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
{
    double monto = 0;

    if (kwh <= 200)
    {
        monto = kwh * TARIF1;
    }
    else if (kwh <= 400)
    {
        monto = (200 * TARIF1) + ((kwh - 200) * TARIF2);
    }

    else
    {
        monto = (200 * TARIF1) + (200 * TARIF2) + ((kwh - 400) * TARIF3);
    }

    return monto;
}

// ================================

char leerSN(const char mensaje[])
{
    char respuesta;

    do
    {
        printf("%s (S/N): ", mensaje);
        scanf("%c", &respuesta);
        limpiar();

    } while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n');

    return respuesta;
}