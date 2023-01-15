/*
    Siano una matrice di interi mat ,le sue dimensioni r e c e un intero k i parametri della funzione f con il
    seguente prototipo:
    void f(int **mat, int r, int c, int k);
    La funzione deve trovare e stampare (se esiste) uno qualsiasi dei sottoinsiemi dei valori della matrice:
    di cardinalità minima
    di cardinalità massima
    la somma dei cui elementi sia k.
 */

#include<stdio.h>
#include<stdlib.h>

void f(int **mat, int r, int c, int k);
int powerset(int pos,int *val,int *sol,int n,int start,int cnt,int sum,int *min_card,int *max_card,int *best_card_min,int *best_card_max);

int main(){
    int r=3,c=4,k=10;
    int **mat;
    mat = (int **) malloc(r*sizeof(int));
    for(int i=0;i<r;i++) mat[i] = (int *) malloc(c*sizeof(int));
    mat[0][0] = 2; mat[0][1] = 3; mat[0][2] = 1; mat[0][3] = 2; mat[1][0] = 6; mat[1][1] = 4; mat[1][2] = 2; mat[1][3] = 5; mat[2][0] = 2; mat[2][1] = 4; mat[2][2] = 3; mat[2][3] = 2;
    f(mat,r,c,k);
}

/*
 Soluzione:
 - Creo un vettore con gli elementi della matrice
 - Powerset sul vettore (tutte le disposizioni semplici possibili)
 - Una soluzione è valida se la somma degli elementi della soluzione è pari a k
 - Se la soluzione è valida verifico che sia di cardinalità massima o minima, in questo caso salvo i dati nei vettori best_card_min e best_card_max
 - Una volta generate tutte le soluzioni i due vettori conterranno rispettivamente un sottoinsieme valido a cardinalità massima e uno a cardinalità minima
 */

void f(int **mat, int r, int c, int k){
    int *vett = malloc(sizeof(int) * r*c);
    int l=0;
    int pos=0,start=0,cnt=0,min_card=k+1,max_card=-1;
    int *sol = malloc(sizeof(int)* r*c);
    int *best_card_min = malloc(sizeof(int) * r*c);
    int *best_card_max = malloc(sizeof(int) * r*c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            vett[l] = mat[i][j];
            l++;
        }
    }
    powerset(pos,vett,sol,r*c,start,cnt,k,&min_card,&max_card,best_card_min,best_card_max);
    printf("Un sottoinsieme valido a somma %d di cardinalita' massima: ",k);
    for(int i=0;i<max_card;i++) printf("%d ",best_card_max[i]);
    printf("\n");
    printf("Un sottoinsieme valido a somma %d di cardinalita' minima: ",k);
    for(int i=0;i<min_card;i++) printf("%d ",best_card_min[i]);
}

int powerset(int pos,int *val,int *sol,int n,int start,int cnt,int sum,int *min_card,int *max_card,int *best_card_min,int *best_card_max) {
    int i,act_sum,cnt_card;
    if (start >= n) {
        act_sum = 0;
        cnt_card = 0;
        for (i = 0; i < pos; i++){
            act_sum+=sol[i];
            cnt_card++;
        }

        if(act_sum==sum && cnt_card>*max_card){
            *max_card = cnt_card;
            for (i = 0; i < pos; i++) best_card_max[i] = sol[i];
        }

        if(act_sum==sum && cnt_card<*min_card){
            *min_card = cnt_card;
            for (i = 0; i < pos; i++) best_card_min[i] = sol[i];
        }

        return cnt+1;
    }
    for (i = start; i < n; i++) {
        sol[pos] = val[i];
        cnt = powerset(pos+1, val, sol, n, i+1, cnt,sum,min_card,max_card,best_card_min,best_card_max);
    }
    cnt = powerset(pos, val, sol, n, n, cnt,sum,min_card,max_card,best_card_min,best_card_max);
    return cnt;
}