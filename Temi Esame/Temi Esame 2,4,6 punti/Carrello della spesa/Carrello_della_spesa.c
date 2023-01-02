/*
 Dato un intero K cardinalità e un float B budget, stampare tutti gli insiemi di prodotti
 di cardinalità minima K il cui costo complessivo non superi il budget B a disposizione.
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 25
#define NOMEFILE "../prodotti.txt"

struct prodotti{
    char nome[MAX];
    float prezzo;
} typedef prodotti_t;

prodotti_t *leggi_file(prodotti_t *vp,int *n);

int comb(int pos, prodotti_t *val, int *sol, int n, int k, int start, int cnt,float B,float B_attuale);

int main(){
    prodotti_t *vp;
    int n,K=3,cnt,pos=0,start=0;
    float B=10.00;
    vp = leggi_file(vp,&n);
    int *sol = malloc(n*sizeof(int));
    while(K<n){
        cnt = comb(pos,vp,sol,n,K,start,cnt,B,0);
        K++;
    }

    free(vp);
}

prodotti_t *leggi_file(prodotti_t *vp,int *n){
    FILE *fin = fopen(NOMEFILE,"r");
    fscanf(fin,"%d",n);
    vp = malloc(*n* sizeof(*vp));
    for(int i=0;i<*n;i++)
        fscanf(fin,"%s%f",vp[i].nome,&vp[i].prezzo);
    fclose(fin);
    return vp;
}

// 41 soluzioni senza pruning, ovvero senza verificare i vincoli su prezzo e cardinalità
// 29 soluzioni con pruning

int comb(int pos, prodotti_t *val, int *sol, int n, int k, int start, int cnt,float B,float B_attuale) {
    int i;
    if (pos >= k) {
        if(B_attuale<=B){
            for (i=0; i<k && B_attuale<=B; i++)
                printf("%s ", val[sol[i]].nome);
            printf("\n");
            B_attuale = 0;
            return cnt+1;
        }
        else{
            B_attuale = 0;
            return cnt;
        }
    }
    for (i=start; i<n; i++) {
        sol[pos] = i;
        cnt = comb(pos+1, val, sol, n, k, i+1, cnt,B,B_attuale+val[i].prezzo);
    }
    return cnt;
}
