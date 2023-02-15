#include<stdio.h>

/*
 Si scriva in C una funzione ricorsiva in grado di generare tutte le stringhe di lunghezza N costituite dalle 5
    vocali maiuscole ’A’, ’E’, ’I’, ’O’, ’U’ con i seguenti vincoli:
    il valore di N sia un parametro della funzione e sia N ≥ 5
    nella stringa generata ogni vocale compaia almeno una volta.
    All’i-esimo livello di ricorsione:
    la funzione gestisca l’i-esima cella della stringa della soluzione
    le scelte siano le 5 vocali maiuscole.
 */

/*
 A = 0, E = 1, I = 2, O = 3, U = 4
 Utilizzo disposizioni semplici
 Stampo la

 */

#include<stdlib.h>
#include<stdio.h>

int disp_rip(int pos,int *val,int *sol,int n,int k,int cnt);

/*
 Disposizioni ripetute: ogni lettera può essere ripetuta k volte
 (nel testo N si riferisce a k, qui N è la dimensione del vettore val che indica il numero di vocali cioè 5)
 */

int main(){
    int val[] = {0,1,2,3,4},k=6,N=5;
    int *sol = malloc(N*sizeof(int));
    int *mark = malloc(N*sizeof(int));
    int pos=0,cnt=0;
    for(int i=0;i<N;i++) mark[i] = 0;
    disp_rip(pos,val,sol,N,k,cnt);
}

int disp_rip(int pos,int *val,int *sol,int n,int k,int cnt){
    int i,flagA,flagE,flagI,flagO,flagU,flag;
    if(pos>=k){
        flagA = 0; flagE = 0; flagI = 0; flagO = 0; flagU = 0;
        flag = 1;
        for(i=0;i<k;i++){
            if(sol[i]==0) flagA = 1;
            if(sol[i]==1) flagE = 1;
            if(sol[i]==2) flagI = 1;
            if(sol[i]==3) flagO = 1;
            if(sol[i]==4) flagU = 1;
        }
        if(flagA==0 || flagE==0 || flagI==0 || flagO==0 || flagU==0) flag = 0;


    if(flag==1){
        for(i=0;i<k;i++){
            if(sol[i]==0) printf("A");
            if(sol[i]==1) printf("E");
            if(sol[i]==2) printf("I");
            if(sol[i]==3) printf("O");
            if(sol[i]==4) printf("U");
        }
        printf("\n");
    }
        return cnt+1;
    }
    for(i=0;i<n;i++){
        sol[pos] = val[i];
        cnt = disp_rip(pos+1,val,sol,n,k,cnt);
    }
    return cnt;
}