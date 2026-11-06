/* biblioteca.c - AC3 parte 2: prestamo de libros (PLANTILLA DE INICIO)
 ENUNCIADO: Registrar 5 libros y guardar el codigo(100 a 999 no repetir), titulo(una sola palabra,MAX 19caracteres), ejemplares disponibles. Indicar si el libro esta activo o dado de baja. Se inicia con 3 libros cargados. Menu que se repita hasta digitar 0. Toda opcion fuera de rango volver a solicitarla.
 QUE SE LOGRA: Crear un sistema para controlar el prestamo de los libros de la biblioteca de un colegio.
 COMO SE LOGRA: Por medio de un do-while para recorrer el menu cuantas veces se requiera.Prototipos y Funciones que ayudan a trabajar de manera mas limpia y ordenada el main.for para recorrer los arreglos.Y contanstes para trabajar mas ordenados los rangos
 RESULTADO ESPERADO: 

 Paso Acción Resultado esperado
1- 2 Consultar Los 3 libros iniciales; libros activos: 3.
2- 1 Incluir, código 102 El código 102 ya existe.
3- 1 Incluir: 104, Platero, 25 (inválido) y luego 2 Pide de nuevo los ejemplares; libro incluido (4 de 5).
4- 3 Prestar 102, tres veces Disponibles 1, luego 0; la tercera vez: no hay ejemplares disponibles.
5- 4 Dar de baja 101 Libro Quijote dado de baja.
6- 5 Buscar 101 No existe un libro activo con el código 101.
7- 5 Buscar 103 103 Cocori: 4 disponibles.
8- Opción 9 (inválida) y luego 2 Consultar Pide de nuevo la opción; muestra 102 (0), 103 (4) y 104 (2);
libros activos: 3. */

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 5  // espacios para libros
#define TAM_TITULO 20 // 19 letras + el '\0'
#define COD_MIN 100   // codigo minimo
#define COD_MAX 999   // codigo maximo
#define EJEM_MAX 20   // ejemplares maximos al incluir

// Prototipos: ya estan escritos. Fijese en los que llevan * (punteros).
int leerEntero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod[], char tit[][TAM_TITULO], int disp[], int activo[],
             int *n, int codigo, const char titulo[], int ejemplares);
void consultar(const int cod[], const char tit[][TAM_TITULO],
               const int disp[], const int activo[], int n);
int prestar(int *disponibles);
void darDeBaja(int *activo);

int main(void)
{
    // Los arreglos usan el mismo indice para guardar los datos de cada libro.
    int cod[MAX_LIBROS] = {101, 102, 103};
    char tit[MAX_LIBROS][TAM_TITULO] = {"Quijote", "Principito", "Cocori"};
    int disp[MAX_LIBROS] = {3, 2, 4};
    int activo[MAX_LIBROS] = {1, 1, 1}; // 1 activo, 0 dado de baja
    int n = 3;                          // espacios usados
    int opcion, codigo, pos, ejemplares;
    char titulo[TAM_TITULO];

    do // El do permite ejecutar el menu las veces que sean necesarias
    {
        printf("\n=== Biblioteca escolar ===\n");
        printf("1 Incluir  2 Consultar  3 Prestar  4 Dar de baja\n");
        printf("5 Buscar  0 Salir\n");
        opcion = leerEntero("Opcion", 0, 5);

        // Las opciones 3, 4 y 5 necesitan un libro: se busca una sola vez.
        if (opcion >= 3)
        {
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            pos = buscarCodigo(cod, activo, n, codigo);
            if (pos == -1)
            {
                printf("No existe un libro activo con el codigo %d\n",
                       codigo);
                continue;
            }
        }
        switch (opcion)
        {
        case 1:
            // No se permite agregar libros cuando el arreglo esta lleno.
            if (n == MAX_LIBROS)
            {
                printf("No hay espacio para mas libros\n");
                break;
            }
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            if (buscarCodigo(cod, activo, n, codigo) != -1)
            {
                printf("El codigo %d ya existe\n", codigo);
                break;
            }
            printf("Titulo (una palabra): ");
            scanf("%19s", titulo);
            ejemplares = leerEntero("Ejemplares", 1, EJEM_MAX);
            // Se envia la direccion de n para que incluir actualice el total.
            incluir(cod, tit, disp, activo, &n, codigo, titulo,
                    ejemplares);
            printf("Libro incluido (%d de %d)\n", n, MAX_LIBROS);
            break;
        case 2:
            consultar(cod, tit, disp, activo, n);
            break;
        case 3:
            // &disp[pos]: la DIRECCION de los disponibles de ese libro
            if (prestar(&disp[pos]))
                printf("Prestado. Disponibles de %s: %d\n", tit[pos],
                       disp[pos]);
            else
                printf("No hay ejemplares disponibles de %s\n",
                       tit[pos]);
            break;
        case 4:
            // &activo[pos]: la DIRECCION del estado de ese libro
            darDeBaja(&activo[pos]);
            printf("Libro %s dado de baja\n", tit[pos]);
            break;
        case 5:
            printf("%d %s: %d disponibles\n", cod[pos], tit[pos],
                   disp[pos]);
            break;
        default:
            printf("Hasta luego\n");
        }
    } while (opcion != 0);
    return 0;
}

// Solicita un entero dentro del rango indicado y vuelve a pedirlo si no es valido.
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    int valor = 0;
    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);
    } while (valor < minimo || valor > maximo);
    return valor;
}

// Busca un codigo entre los libros activos y devuelve su indice, o -1 si no existe.
int buscarCodigo(const int cod[], const int activo[], int n, int codigo)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (cod[i] == codigo && activo[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

// Guarda un libro en la siguiente posicion libre y aumenta la cantidad registrada.
void incluir(int cod[], char tit[][TAM_TITULO], int disp[], int activo[],
             int *n, int codigo, const char titulo[], int ejemplares)
{
    cod[*n] = codigo;
    strcpy(tit[*n], titulo);
    disp[*n] = ejemplares;
    activo[*n] = 1;
    (*n)++;
}


void consultar(const int cod[], const char tit[][TAM_TITULO],
               const int disp[], const int activo[], int n)
{
    int i, activos = 0;

    // Solo se muestran libros activos; el contador se calcula durante el recorrido.
    printf("%-6s %-12s %6s\n", "Codigo", "Titulo", "Disponible");
    for (i = 0; i < n; i++)
    {
        if (activo[i] == 1)
        {
            printf("%-6d %-12s %6d\n", cod[i], tit[i], disp[i]);
            activos++;
        }
    }
    printf("Libros activos: %d\n", activos);
}


// Descuenta un ejemplar si hay existencias; devuelve 1 si se presto y 0 si no.
int prestar(int *disponibles)
{
    if (*disponibles == 0)
    {
        return 0;
    }

    (*disponibles)--;

    return 1;
}

// Da de baja el libro sin borrar sus datos: solo cambia su estado a inactivo.
void darDeBaja(int *activo)
{
    *activo = 0;
}
