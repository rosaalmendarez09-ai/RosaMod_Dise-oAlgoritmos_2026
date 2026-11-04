
#include <stdio.h>

void contar(int *total)
{
    (*total)++; // incrementa al valor donde apunta
}

int main(void)
{
    int t = 0;

    contar(&t); // pasa a valer 1
    contar(&t); // pasa a valer 2
    printf("Total: %d\n", t);
    return 0;
}
