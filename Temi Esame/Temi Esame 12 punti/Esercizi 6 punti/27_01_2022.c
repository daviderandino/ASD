/*
 Matrice rappresenta la relazione di amicizia tra N persone
 cella contiene 1 --> la coppia (i,j) è una coppia di amici.
 In caso contrario il valore è 0
 Scrivere una funzione ricorsiva in grado di suddividere le persone nel minor numero di gruppi
 possibili facendo in modo che tutte le persone in un gruppo siano mutualmente amiche. E' ammesso
 che ci siano gruppi formati da una singola persona.
 */

#include<stdio.h>
#include<stdlib.h>
#define N 4

/*
 Si utilizza l'algoritmo di ER per calcolare le partitions in k blocchi
 k parte da 1 e aumenta finchè trovo non una sol valida
 */

void SP_rec(int n, int k, int m, int pos, int *sol, int *val,int M[N][N],int *solFound);
void SetPartitions(int n, int k, int *sol, int *val,int M[N][N],int *solFound);

int main(){
    int M[N][N] = {
            {1,1,0,1},
            {1,1,0,1},
            {0,0,1,0},
            {1,1,0,1}
    };
    int k,solFound=0;
    int *sol = malloc(N*sizeof(int));
    int *val = malloc(N*sizeof(int));
    for(int i=0;i<N;i++) val[i] = i;
    for(k=1;k<N;k++) SetPartitions(N,k,sol,val,M,&solFound);

}

void SetPartitions(int n, int k, int *sol, int *val,int M[N][N],int *solFound) {
    SP_rec(n, k, 0, 0, sol, val,M,solFound);
    return;
}

void SP_rec(int n, int k, int m, int pos, int *sol, int *val,int M[N][N],int *solFound) {
    if(*solFound==1) return;
    int i, j,l,isValid;
    if (pos >= n) {
        if (m == k) {
            isValid = 1;
            for (i=0; i<m &&isValid==1; i++) {
                for (j=0; j<n && isValid==1; j++) {
                    for(l=0;l<n &&isValid==1;l++){
                        if (sol[j]==i && sol[l]==i && M[j][l]==0){
                            isValid = 0;
                        }
                    }
                }
            }

            if(isValid==1){
                *solFound = 1;
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

        }
        return;
    }

    for (i=0; i<m; i++) {
        sol[pos] = i;
        SP_rec(n, k, m, pos+1, sol, val,M,solFound);
    }
    sol[pos] = m;
    SP_rec(n, k, m+1, pos+1, sol, val,M,solFound);
}