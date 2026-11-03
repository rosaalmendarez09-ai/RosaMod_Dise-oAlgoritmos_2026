#include <stdio.h>
int main(void) {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int f, c;
    for (f = 0; f < 3; f++)
        for (c = 0; c < 2; c++)
            printf("%d ", m[f][c]);
    printf("\n");
    return 0;
}
