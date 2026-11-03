#include <stdio.h>
int main(void) {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int f, c, tot = 0;
    for (f = 0; f < 2; f++) {
        for (c = 0; c < 3; c++)
            tot += m[f][c];
        printf("Fila %d: %d\n", f, tot);
    }
    return 0;
}
