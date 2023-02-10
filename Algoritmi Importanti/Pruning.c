#include<stdio.h>
#include<stdlib.h>

/*
 Dato un insieme S di numeri interi positivi e un intero X, determinare
 tutti i sottoinsiemi Y di S tale che la somma degli elementi di Y sia uguale a X
 Esempio: S = {2,1,6,4} X=7
 Y = {{1,2,4},{1,6}}
 */

int powerset_without_pruning(int pos,int *val,int *sol,int n,int cnt,int X);
void powerset_with_pruning(int pos,int *val,int *sol,int act_sum,int rem_sum,int X);
int promising(int *val,int pos,int p,int r,int X);

int main(){
    int S[] = {2,1,6,4},N=4,X=7;
    int *sol = malloc(N*sizeof(int));
    int pos=0,cnt=0,k=N;
    // cnt = powerset_without_pruning(pos,S,sol,N,cnt,X);

    int act_sum=0,rem_sum=0;
    for(int i=0;i<N;i++) rem_sum+=S[i];
    powerset_with_pruning(pos,S,sol,act_sum,rem_sum,X);
}

// approccio senza pruning: calcolo la somma attuale ad ogni soluzione e poi verifico che act_sum==X,in caso positivo stampo la soluzione
// quindi senza pruning tutte le soluzioni vengono generate

int powerset_without_pruning(int pos,int *val,int *sol,int n,int cnt,int X){
    int j,act_sum;
    if(pos>=n){
        act_sum = 0;
        for(j=0;j<n;j++)
            if(sol[j]!=0) act_sum+=val[j];

        if(act_sum==X){
            for(j=0;j<n;j++)
                if(sol[j]!=0) printf("%d ",val[j]);
            printf("\n");
        }
        return cnt+1;
    }
    sol[pos] = 0;
    cnt = powerset_without_pruning(pos+1,val,sol,n,cnt,X);
    sol[pos] = 1;
    cnt = powerset_without_pruning(pos+1,val,sol,n,cnt,X);
}

// approccio con pruning: prendo un elemento solo se promettente
// se l'elemento è promettente lo si prende (sol[pos]=1), si ricorre sul prossimo aggiornando act_sum e rem_sum
// se l'elemento non è promettente non lo si prendere (sol[pos]=0), si ricorre sul prossimo e act_sum resta invariato, aggiorno rem_sum

void powerset_with_pruning(int pos,int *val,int *sol,int act_sum,int rem_sum,int X) {
    int j;
    if (act_sum==X) {
        for(j=0;j<pos;j++)
            if(sol[j])
                printf("%d ",val[j]);
        printf("\n");
        return;
    }
    if(promising(val,pos,act_sum,rem_sum,X)){
        sol[pos]=1;
        powerset_with_pruning(pos+1,val,sol,act_sum+val[pos],rem_sum-val[pos],X);
        sol[pos]=0;
        powerset_with_pruning(pos+1,val,sol,act_sum, rem_sum-val[pos],X);
    }
}

int promising(int *val,int pos,int act_sum,int rem_sum,int X) {
    return (act_sum+rem_sum>=X)&&(act_sum+val[pos]<=X);
}
