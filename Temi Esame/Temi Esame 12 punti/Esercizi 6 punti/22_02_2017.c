/*
    Si consideri un insieme di n elementi distinti identificati univocamente con un intero da 0 a n-1. Per ogni
    coppia di elementi è noto se questi possono essere separati o no. Tale informazione è riportata in una matrice
    quadrata di dimensione n x n. Ogni cella m[i][j] della matrice riporta il valore 1 (0) se due elementi i e j
    sono (non sono) separabili.
    Si scriva una funzione dal prototipo:
    int *f(int n, int r, int **m)
    il cui obiettivo sia di trovare una partizione dell’insieme di partenza in due sottoinsiemi, il secondo dei quali
    contenga almeno r oggetti, tali per cui nessuna coppia di elementi indivisibili venga separata.
 */
#include<stdio.h>
#include<stdlib.h>
#define N 4

/*
 Ci serve una partizione formata da due elementi
 Utilizzo l'algoritmo di ER fissando k=2 (2 blocchi)
 */

void SP_rec(int n, int k, int m, int pos, int *sol, int *val,int **M,int *solFound,int r);
void SetPartitions(int n, int k, int *sol, int *val,int **M,int *solFound,int r);
int *f(int n, int r, int **m);

int main(){
    int **m;
    f(N,1,m);
}

int *f(int n, int r, int **m){
    m = (int **) malloc(n*sizeof(int *));
    for(int i=0;i<n;i++) m[i] = (int *) malloc(n*sizeof(int));
    m[0][0]=1; m[0][1]=1; m[0][2]=0; m[0][3]=1; m[1][0]=1; m[1][1]=1; m[1][2]=0; m[1][3]=1;
    m[2][0]=0; m[2][1]=0; m[2][2]=2; m[2][3]=0; m[3][0]=1; m[3][1]=1; m[3][2]=0; m[3][3]=1;
    int *sol = malloc(N*sizeof(int));
    int *val = malloc(N*sizeof(int));
    int solFound = 0;
    for(int i=0;i<N;i++) val[i] = i;
    SetPartitions(N,2,sol,val,m,&solFound,r);
}

void SetPartitions(int n, int k, int *sol, int *val,int **M,int *solFound,int r) {
    SP_rec(n, k, 0, 0, sol, val,M,solFound,r);
    return;
}

void SP_rec(int n, int k, int m, int pos, int *sol, int *val,int **M,int *solFound,int r) {
    if(*solFound==1) return;
    int i, j,l,isValid,cnt;
    if (pos >= n) {
        cnt = 0;
        if (m == k) {
            isValid = 1;

            // verifico prima che la seconda partizione abbia almeno r oggetti

            for (j=0; j<n; j++) {
                if (sol[j]==1)
                    cnt++;
            }
            if(cnt<r) isValid = 0;


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
        SP_rec(n, k, m, pos+1, sol, val,M,solFound,r);
    }
    sol[pos] = m;
    SP_rec(n, k, m+1, pos+1, sol, val,M,solFound,r);
}