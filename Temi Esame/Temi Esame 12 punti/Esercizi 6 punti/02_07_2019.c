/*
 Sia dato un vettore V di N interi. Si definisce sottosequenza di V di lunghezza k (kN) un qualsiasi n-upla Y di k
elementi di V con indici crescenti, ma non necessariamente contigui i0, i1, · · · , ik-1. La sottosequenza si dice bitonica
crescente/decrescente se i suoi elementi sono ordinati prima in modo crescente e poi decrescente. Esempio: la
sequenza 4, 5, 9, 7, 6, 3, 1 è bitonica.
Si scriva un programma C che, ricevuti come parametri il vettore V e l’intero N calcoli e visualizzi una qualsisasi
sottosequenza bitonica di lunghezza massima.
Esempio: se N=9 e V = [4, 2, 5, 9, 7, 6, 10, 3, 1] una sottosequenza bitonica di lunghezza massima 7 è 4 5 9 7 6 3 1.
 */

#include<stdio.h>
#include<stdlib.h>

void comb(int pos,int *val,int *sol,int n,int k,int start,int *check);

int main(){
    int N=9;
    int V[] = {4,2,5,9,7,6,10,3,1};
    int *sol = malloc(N*sizeof(int));
    int k,pos=0,start=0,check=0;
    for(k=N;k>0 && check==0;k--)
        comb(pos,V,sol,N,k, start,&check);
}

/*
 Combinazioni semplici perchè l'ordine conta
 Per ogni soluzione:
 - Sicuramente sol[1] deve essere maggiore di sol[0]
 - La soluzione deve per forza avere una parte decrescente
 - Verifico che quando inizia ad essere decrescente tutto il resto della soluzione è decrescente
 */

void comb(int pos,int *val,int *sol,int n,int k,int start,int *check){
    if(*check==1) return;
    int i,isValid,flag1;
    if(pos>=k){
        flag1 = 0;
        isValid = 1;
        if(sol[1]<=sol[0]) isValid = 0;

        for(i=2;i<k;i++){
            if(flag1==1 && sol[i]>=sol[i-1]) isValid = 0;
            if(sol[i]<sol[i-1]) flag1=1;
        }

        if(flag1==0) isValid = 0;

        if(isValid==1){
            for(i=0;i<k;i++) printf("%d ",sol[i]);
            printf("\n");
            *check = 1;
        }

        return;
    }
    for(i=start;i<n;i++){
        sol[pos] = val[i];
        comb(pos+1,val,sol,n,k,i+1,check);
    }
}