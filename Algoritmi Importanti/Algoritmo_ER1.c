#include <stdio.h>
#include <stdlib.h>

void SP_rec(int n, int m, int p, int *sol, int *val);
void SetPartitions(int n, int *sol, int *val);

int main(void){
    int *sol;

    printf("\n");
    printf("\nCalcolo delle partizioni di un insiemi di n elementi in 1 .. n blocchi\n");
    int val[] = {1,2,3,4},n=4;
    sol = calloc(n, sizeof(int));

    printf("Le partizioni di %d elementi in 1 .. %d blocchi sono \n", n, n);
    SetPartitions(n, sol, val);

    return 0;
}

void SetPartitions(int n, int *sol, int *val) {
    SP_rec(n, 0, 0, sol, val);
    return;
}

void SP_rec(int n,int m,int pos,int *sol,int *val) {
    int i, j;
    if (pos >= n) {
        printf("partizione in %d blocchi: ", m);
        for (i=0; i<m; i++) {
            printf("{ ");
            for (j=0; j<n; j++)
                if (sol[j]==i)
                    printf("%d ", val[j]);
            printf("}  ");
        }
        printf("\n");
        return;
    }
    for (i=0; i<m; i++) {
        sol[pos] = i;
        SP_rec(n, m, pos+1, sol, val);
    }
    sol[pos] = m;
    SP_rec(n, m+1, pos+1, sol, val);
}

