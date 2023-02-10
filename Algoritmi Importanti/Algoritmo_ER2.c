#include <stdio.h>
#include <stdlib.h>

void SP_rec(int n, int k, int m, int p, int *sol, int *val);
void SetPartitions(int n, int k, int *sol, int *val);

int main(void){
    int *sol;
    int val[] = {1,2,3,4},n=4,k=2;
    printf("\nCalcolo delle partizioni di un insiemi di %d elementi in %d blocchi\n",n,k);
    sol = calloc(n, sizeof(int));
    SetPartitions(n, k, sol, val);
    return 0;
}

void SetPartitions(int n, int k, int *sol, int *val) {
    SP_rec(n, k, 0, 0, sol, val);
    return;
}

void SP_rec(int n, int k, int m, int pos, int *sol, int *val) {
    int i, j;
    if (pos >= n) {
        if (m == k) {
            for (i=0; i<m; i++) {
                printf("{ ");
                for (j=0; j<n; j++) {
                    if (sol[j]==i)
                        printf("%d ", val[j]);
                }
                printf("}  ");
            }
            printf("\n");
        }
        return;
    }

    for (i=0; i<m; i++) {
        sol[pos] = i;
        SP_rec(n, k, m, pos+1, sol, val);
    }
    sol[pos] = m;
    SP_rec(n, k, m+1, pos+1, sol, val);
}

