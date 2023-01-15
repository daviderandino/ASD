/*
 Sia data una sequenza di N interi memorizzata in un vettore X = (x0, x1, … xN-1). Si definisce sottosequenza
 di X di lunghezza k (k <=N) un qualsiasi sottovettore Y degli elementi di X con indici crescenti i0, i1, · · · , ik-1
 non necessariamente contigui.
 Esempio: se X = 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, Y = 0, 8, 12, 10, 14, 1, 7, 15 è una sottosequenza di
 lunghezza k=8 di X.
 Si scriva in C una funzione che, ricevuti come parametri il vettore X e la sua lunghezza N, calcoli una qualsiasi
 delle sottosequenze STRETTAMENTE CRESCENTI di X a lunghezza massima e restituisca come risultato la
 sua lunghezza k:
 int maxSubSeq(int *X, int N, int *Y);
 */


/*
 Modello: combinazioni semplici, partendo da k==N e diminuendo k fintanto che trovo una sottosequenza valida.
 */

#include<stdio.h>
#include<stdlib.h>

int maxSubSeq(int *X, int N, int *Y);
int comb(int pos, int *val, int *sol, int n, int k, int start, int cnt,int *Y,int *max);

int main(){
    int X[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15},max;
    int N = sizeof(X)/sizeof(int);
    int *Y = malloc(N*sizeof(int));

    max = maxSubSeq(X,N,Y);

    printf("Max: %d",max);

    free(Y);


}

int maxSubSeq(int *X, int N, int *Y){
    int pos=0,start=0,cnt=0,k=N,max;

    while(k-->0 && cnt!=1)
        cnt = comb(pos,X,Y,N,k,start,cnt,Y,&max);


}

int comb(int pos, int *val, int *sol, int n, int k, int start, int cnt,int *Y,int *max) {
    int i,flag,count;
    if(cnt==1) return cnt;
    if (pos >= k) {
        flag = 1;
        for (i=0; i<k; i++){
            if(sol[i]<=sol[i-1] && i>0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            count=0;
            cnt = 1;
            for (i=0; i<k; i++){
                Y[i] = sol[i];
                printf("%d ",sol[i]);
                count++;
            }
            printf("\n");
            *max = count;
            return cnt;
        }
        return cnt;
    }

    for (i=start; i<n; i++) {
        sol[pos] = val[i];
        cnt = comb(pos+1, val, sol, n, k, i+1, cnt,Y,max);
    }
    return cnt;
}