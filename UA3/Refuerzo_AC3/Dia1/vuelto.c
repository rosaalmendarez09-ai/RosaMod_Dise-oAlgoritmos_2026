/*vuelto.c -  Vuelto en billetes y monedas
==========================================================================
* ENUNCIADO:
Una caja calcula el vuelto de cada compra.
Se digita el total de la compra (1 a 1 000 000) y el monto pagado, que no puede ser menor que el total (si lo es, se vuelve a pedir).
El programa muestra el vuelto y cuántos billetes o monedas de cada denominación entregar, empezando por la mayor (20 000, 10 000, 5000, 2000, 1000, 500, 100, 50, 25, 10 y 5); solo se muestran las que se usan.
Si sobran colones que no se pueden entregar (menos de 5), se indica.
Al final se muestra la cantidad total de piezas.
Después de cada compra se pregunta si hay otra (S/N).

* QUÉ SE LOGRA:
El cálculo y desglose exacto del vuelto de una compra en colones
Determinando la cantidad de billetes y monedas necesarios por denominación (desde 20 000 hasta 5 colones), detectando sobrantes no entregables.

* CÓMO SE LOGRA:
  -Estructuras repetitivas (while) para múltiples compras consecutivas.
  - (do-while) para asegurar que el total de la compra esté entre 1 y 1 000 000, y que el monto pagado sea igual o superior al total.
  - Almacenamiento de las 11 denominaciones monetarias en un arreglo constante de mayor a menor
  - Una función que utiliza punteros para actualizar el residuo y calcular las piezas necesarias por cada denominación
  - if- else para filtrar e imprimir únicamente las denominaciones utilizadas, además de notificar si quedan colones sobrantes menores a 5.

* RESULTADO ESPERADO:
Mostrar en pantalla el vuelto total, el desglose detallado de los billetes y monedas, la sumatoria total de piezas entregadas, y la consulta final para procesar una nueva compra o finalizar el programa.*/

#include <stdio.h>

// PROTOTIPOS DE FUNCIONES

void limpiar(void); // Para limpiar basura

int leerEntero(const char mensaje[], int minimo, int maximo); // Funcion para solicitar datos: totalcompra,montopagado
char leerSN(const char mensaje[]);                            // Para respuesta si agrega más

int cuantas(int *resto, int denominacion); // Calcular las piezas que se van a entregar

// CONSTANTES
#define MIN 1       // minimo de compra
#define MAX 1000000 // maximo de compra
#define MENOS 5     // vuelto menor de 5 no se pueden entregar

// Inicio funcion principal main
int main(void)
{

    double compra, pagado, vuelto; // Guardan los valores de compra, pago y vuelto
    char respuesta;                // Guarda la respuesta del usuario para otra compra
    int piezas, i, resto;          // piezas y resto se usan en el cálculo del vuelto
    int const dinero[11] = {20000, 10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5}; // Denominaciones de mayor a menor

    do
    {
        // Se pide el total de la compra y se valida que este dentro del rango permitido
        compra = leerEntero("Digita el total de compra", MIN, MAX); // llamamos a la funcion para solicitar total de la compra

        do
        {
            // Se pide el monto con el que paga el cliente y se valida que no sea menor que la compra
            pagado = leerEntero("Digita el monto pagado:", compra, MAX); // llamamos a la funcion para solicitar monto pagado
        } while (pagado < compra);

        // Se calcula el vuelto real: pago menos compra
        vuelto = pagado - compra;
        resto = vuelto;

        // ============salidas======================
        printf("==============CAJA==========\n");
        printf("Total de compra: ₡%.2lf\n", compra);
        printf("Pagó con: ₡%.2lf\n", pagado);
        printf("Vuelto: ₡%.2lf\n", vuelto);
        printf("==========DESGLOCE==========\n");

        int tPiezas = 0; // Se reinicia en cada compra para contar solo el vuelto actual
        for (i = 0; i < 11; i++)
        {
            // Cada denominacion entrega la cantidad de piezas posibles,
            // y actualiza el resto del vuelto para seguir con la siguiente
            piezas = cuantas(&resto, dinero[i]);
            if (piezas > 0)
            { // Solo se muestran las denominaciones que se usan en el vuelto
                printf("%d de ₡%d\n", piezas, dinero[i]);
                tPiezas += piezas; // Cuenta todas las piezas entregadas del vuelto
            }
        }

        // Si sobra un valor menor a 5, no se puede entregar porque no existe denominación
        if (resto > 0 && resto < MENOS)
        {
            printf("Sobran ₡%d que no pueden entregarse\n", resto);
        }

        // Se imprime la cantidad total de piezas entregadas en el vuelto
        printf("Total de piezas entregadas: %d\n", tPiezas);

        // Pregunta si se desea continuar con otra compra
        respuesta = leerSN("Desea agregar otra compra?(S/N)");

    } while (respuesta == 'S' || respuesta == 's'); // si la respuesta es 's' o 'S' vuelve al ciclo

    return 0;
}

// Declaracion de funciones

// ===============limpiar basura========================
void limpiar(void)
{
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}
// =====================================================

// =============================================================
// =============================================================
// leerEntero
// Pide un numero al usuario y valida que se encuentre dentro del rango
// indicado por los parametros minimo y maximo.
// Si el dato sale del rango, lo rechaza y muestra un mensaje de error.
// =============================================================
int leerEntero(const char mensaje[], int minimo, int maximo)
{
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
//========================FIN==========================

// =============================================================
// =============================================================
// leerSN
// Solicita una respuesta del tipo S/N y valida que sea solo una de esas letras.
// Permite mayusculas o minusculas para que el usuario pueda responder facilmente.
// =============================================================
char leerSN(const char mensaje[])
{
    char continuar;
    do
    {
        printf("%s: ", mensaje);
        scanf("%c", &continuar);
        limpiar();

        if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n')
        {
            printf("Dato erróneo, vuelva a ingresarlo.\n");
        }

    } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');

    return continuar;
}
//=====================FIN============================


// =============================================================
// =============================================================
// cuantas
// Recibe un puntero al resto actual del vuelto y una denominacion.
// Calcula cuantas piezas de esa denominacion caben dentro del vuelto,
// actualiza el valor restante y devuelve la cantidad de piezas.
// Ejemplo: si el vuelto es 4500 y la denominacion es 1000, entonces
// caben 4 billetes y sobran 500.
// =============================================================
int cuantas(int *resto, int denominacion)
{
    int cantidad;

    cantidad = *resto / denominacion; // Cuantos caben (monedas o billetes)
    *resto = *resto % denominacion;   // Actualiza residuo en memoria, cuanto queda.

    return cantidad; // devuelve las piezas
}
//=========================FIN===========================