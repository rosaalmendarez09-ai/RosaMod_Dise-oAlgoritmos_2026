#include <stdio.h>
int sumaFila(int m[][], int f) {
    return m[f][0] + m[f][1] + m[f][2];
}
int main(void) {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%d\n", sumaFila(m, 1));
    return 0;
}
