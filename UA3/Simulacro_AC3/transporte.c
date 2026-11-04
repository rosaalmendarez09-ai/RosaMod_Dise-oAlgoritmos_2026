/* Un colegio controla los pases de bus de sus estudiantes y puede registrar hasta 5 pases. De cada
pase se guarda: el código (100 a 999, no se repite), el nombre del estudiante (una sola palabra,
hasta 19 letras), los viajes disponibles y si el pase está activo o dado de baja.
El programa inicia con 3 pases ya cargados (tabla de abajo). Debe mostrar un menú que se repite
hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir.

Dotos de entrada:
Pases cargados al iniciar:
Código   Nombre   Viajes
201     Ana         5
202     Luis        1
203     Sofia       8
*/

// CARGAR LAS BIBLIOTECAS
#include <stdio.h>
#include <string.h>

// Declarar las constantes
#define MAX_PASES 5   // Para los pases disponibles
#define TAM_NOMBRE 20 // 19 CARACTERES O LETRAS + EL \0
#define COD_MIN 100   // codigo minimo
#define COD_MAX 999   // codigo maximo
#define VIAJES_MAX 40 // VIAJES MAXIMOS A INCLUIR

// PROTOTIPOS DE FUNCION (una por tarea)
// Cada funcion cumple una tarea especifica dentro del programa
int leerEntero(const char mensaje[], int minimo, int maximo); // solicitar y validar datos enteros

int buscarCodigo(const int cod[], const int activo[], int n, int codigo); // buscar un pase activo por su codigo

void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad); // agregar un nuevo pase al arreglo

void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n); // mostrar los pases activos con sus datos

int usarViaje(int *viaje); // descontar un viaje disponible si hay saldo

void darDeBaja(int *activo); // poner un pase como inactivo

// FUNCION PRINCIPAL
// Se inicia con una tabla de 3 pases cargados y se repite el menu hasta salir
int main(void)
{
    // Asigno datos de los pases
    int cod[MAX_PASES] = {201, 202, 203};
    char nom[MAX_PASES][TAM_NOMBRE] = {"Ana", "Luis", "Sofia"};
    int viajes[MAX_PASES] = {5, 1, 8};
    int activo[MAX_PASES] = {1, 1, 1};
    int n = 3; // cantidad de pases usados
    int opcion, codigo, pos, cantidad;
    char nombre[TAM_NOMBRE];

    // MENU PRINCIPAL
    // Se repite mientras la opcion elegida no sea 0 (salir)
    do
    {
        printf("\n1. Incluir\n2. Consultar\n3. Registrar viaje\n4. Dar de baja\n5. Buscar\n0. Salir\n");

        // Leemos la opcion y la validamos dentro del rango permitido
        opcion = leerEntero("Opcion", 0, 5);

        // Para las opciones que necesitan un codigo, buscamos si existe un pase activo
        if (opcion >= 3)
        {
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            pos = buscarCodigo(cod, activo, n, codigo);
            if (pos == -1)
            {
                printf("No existe un pase activo con el codigo %d\n", codigo);
                continue;
            }
        }

        // Se ejecuta la accion elegida por el usuario
        switch (opcion)
        {
        case 1:
            // Si ya se llenaron los 5 pases, no se puede incluir otro
            if (n == MAX_PASES)
            {
                printf("No hay espacio para más pases\n");
                break;
            }

            // Leer datos para el nuevo pase
            codigo = leerEntero("codigo", COD_MIN, COD_MAX);
            if (buscarCodigo(cod, activo, n, codigo) != -1)
            {
                printf("El codigo %d ya existe\n", codigo);
                break;
            }

            printf("Nombre (una palabra): ");
            scanf("%19s", nombre);

            cantidad = leerEntero("Viajes", 1, VIAJES_MAX);
            incluir(cod, nom, viajes, activo, &n, codigo, nombre, cantidad);
            printf("Pase incluido (%d de %d)\n", n, MAX_PASES);
            break;

        case 2:
            // Muestra todos los pases activos con su codigo, nombre y viajes
            consultar(cod, nom, viajes, activo, n);
            break;

        case 3:
            // Registra un viaje descontando uno si el estudiante aun tiene viajes
            if (usarViaje(&viajes[pos]))
            {
                printf("Viaje registrado. A %s le quedan %d\n", nom[pos], viajes[pos]);
            }
            else
            {
                printf("%s no tiene viajes disponibles\n", nom[pos]);
            }
            break;

        case 4:
            // Da de baja al pase activo seleccionado
            darDeBaja(&activo[pos]);
            printf("El pase de %s fue dado de baja\n", nom[pos]);
            break;

        case 5:
            // Busca y muestra la informacion del pase activo indicado
            printf("%d %s %d viajes\n", cod[pos], nom[pos], viajes[pos]);
            break;

        case 0:
            printf("Hasta luego\n");
            break;

        default:
            printf("Hasta luego\n");
            break;
        }

    } while (opcion != 0);

    return 0;
}

// =============================================================
// =============================================================
// Lectura validada de un entero
// Permite pedir un dato dentro de un rango definido por el programa
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    int valor;

    valor = 0;
    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);

        if (valor < minimo || valor > maximo)
        {
            printf("Dato erróneo, vuelva a ingresarlo.\n");
        }

    } while (valor < minimo || valor > maximo);

    return valor;
}

// =============================================================
// =============================================================
// Busqueda secuencial de un pase
// Recorre el arreglo y devuelve la posicion si el codigo existe y esta activo
int buscarCodigo(const int cod[], const int activo[], int n, int codigo)
{
    int i;

    for (i = 0; i < n; i++)
    {   // ignora pases dados de baja
        if (cod[i] == codigo && activo[i] == 1)
        {
            return i;
        }
    }
    // No esta activo o no existe
    return -1;
}

// =============================================================
// =============================================================
// Agregar espacio en el primer espacio libre
// Guarda los datos del nuevo pase en la siguiente posicion disponible
void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad)
{
    cod[*n] = codigo;
    strcpy(nom[*n], nombre);
    viajes[*n] = cantidad;
    activo[*n] = 1;
    (*n)++;
}

// =============================================================
// ============================================================
// PASES ACTIVOS Y CUANTOS SON
// Muestra solamente los pases que siguen vigentes y cuenta cuantos hay
void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n)
{
    int i, activos = 0;

    printf("%-6s %-12s %6s\n", "Codigo", "Nombre", "Viajes");
    for (i = 0; i < n; i++)
    {
        if (activo[i] == 1)
        {
            printf("%-6d %-12s %6d\n", cod[i], nom[i], viajes[i]);
            activos++;
        }
    }
    printf("Pases activos: %d\n", activos);
}

// =============================================================
// =============================================================
// Registra si quedan viajes
// Si el estudiante tiene viajes disponibles, los descuenta y devuelve 1
int usarViaje(int *viaje)
{
    if (*viaje == 0)
    {
        return 0;
    }

    (*viaje)--;
    return 1;
}

// =============================================================
// =============================================================
// Dar de baja
// Pone el pase como inactivo para que ya no pueda usarse
void darDeBaja(int *activo)
{
    *activo = 0;
}
