/*
    Dato un vettore di interi I, di dimensione dimI, e un vettore S, di dimensione dimS, contenente una sequenza di
    somme obiettivo, scrivere una funzione ricorsiva che valuti se sia possibile ottenere le somme riportate in S
    utilizzando gli elementi del vettore I. Non è necessario usare tutti gli elementi di I, ma ogni elemento può
    essere usato al massimo una volta. Una volta trovata una soluzione valida, interrompere la ricerca: non è
    necessario individuare tutte le soluzioni possibili.
    • Si scriva la funzione ricorsiva richiesta.
    • Si giustifichi la scelta del modello combinatorio adottato.
    • Si descrivano i criteri di pruning adottato o il motivo della loro assenza.
 */

#include<stdio.h>
#include<stdlib.h>

int powerset(int pos,int *val,int *sol,int n,int start,int cnt,int *S,int dimS);


int main(){
    int I[] = {1,2,3,4,5,5}, dimI = 6;
    int S[] = {1,7,7}, dimS = 3;
    int pos=0,start=0,cnt;
    int *sol = malloc(dimI*sizeof(int));
    cnt = powerset(pos,I,sol,dimI,start,cnt,S,dimS);


}

int powerset(int pos,int *val,int *sol,int n,int start,int cnt,int *S,int dimS){
    int i,sum,cnt2,flag;
    if (start >= n) {
        sum = 0;
        for (i = 0; i < pos; i++)
            sum+=sol[i];
        cnt2 = 0;
        flag = 0;
        for(int j=0;j<dimS && flag==0;j++) {
            if (sum == S[j] && S[j]!=-1) {
                S[j] = -1;
                flag = 1;
                printf("%d = ",sum);
                for(int k=0;k<pos;k++){
                    if(k==pos-1) printf("%d",sol[k]);
                    else printf("%d+",sol[k]);
                }
                printf("\n");

            }
        }
        for(int k=0;k<dimS;k++){
            if(S[k]==-1) cnt2++;
            if(cnt2==dimS){
                printf("Soluzione valida trovata!");
                exit(0);
            }
        }
        return cnt+1;
    }
    for (i = start; i < n; i++) {
        sol[pos] = val[i];
        cnt = powerset(pos+1, val, sol, n, i+1, cnt,S,dimS);
    }
    cnt = powerset(pos, val, sol, n, n, cnt,S,dimS);
    return cnt;
}
