#include <stdio.h>
int main(void) {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int f, c, t;
    for (c = 0; c < 3; c++) {
        t = 0;
        for (f = 0; f < 2; f++)
            t += m[f][c];
        printf("%d ", t);
    }
    printf("\n");
    return 0;
}
