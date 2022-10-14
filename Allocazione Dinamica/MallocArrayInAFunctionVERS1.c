#include <stdio.h>
#include <stdlib.h>

void alloca_vett(int **V);

int main() {
    int *V;
    alloca_vett(&V);
    printf("%d",V[0]);
}

void alloca_vett(int **V){
    (*V) = (int *) malloc(3*sizeof(int));
    (*V)[0] = 0; (*V)[1] = 1; (*V)[2] = 2;
}
