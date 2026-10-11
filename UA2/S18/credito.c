// credito.c aprobacion de credito por capacidad de pago y sin deudas
#include <stdio.h>

int main(void){
    double salario, cuota;
    int antiguedad;
    char respDeudas, respFiador;
    // LOGICA
    int capacidadPago, tieneDeudas, tieneFiador, aprobado;

    // ENTRADA DATOS
    printf("Salario mensual: ");
    scanf("%lf", &salario);

    printf("Cuota mensual del credito: ");
    scanf("%lf", &cuota);

    printf("Tiene deudas atrasadas(S/N): ");
    scanf(" %c", &respDeudas);

    printf("Años de antiguedad laboral: ");
    scanf("%d", &antiguedad);

    printf("Tiene fiador: (S/N): ");
    scanf(" %c", &respFiador);

    // PROCESO: condiciones
  capacidadPago = (salario >= cuota * 3);

  tieneDeudas = (respDeudas == 'S' || respDeudas == 's');

  tieneFiador = (respFiador == 'S' || respFiador == 's');

  // REGLA

  aprobado = capacidadPago && !tieneDeudas && (antiguedad >= 1 || tieneFiador);

  if (aprobado){
    printf("Credito aprobado\n");
 }
 else{
    printf("Credito rechazado\n");
 }

 return 0;
}