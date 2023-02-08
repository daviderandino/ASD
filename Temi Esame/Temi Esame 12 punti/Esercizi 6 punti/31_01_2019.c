#include<stdio.h>
#include<stdlib.h>
#define N 8

void checkMaxGuadagno_wrapper(int m,int *lunghezza,int *prezzo);
int comb_r(int pos,int *val,int *sol,int n,int k,int start,int cnt,int *prezzi,int *max,int *best);

/*
    Utilizzo il modello delle combinazioni con ripetizione.
    Con i vettori di esempio il nastro ha lunghezza 4 e può essere tagliato in {1,2,3,4} pezzi
    Genero allora tutte le combinazioni possibili utilizzando ogni pezzo k volte ad ogni iterazione del ciclo for
    {1} , {1,1} , {1,2} {2,2,2}.... {4,4,4,4}
    E' possibile effettuare pruning scartando delle soluzioni, poichè l'insieme non posso avere più pezzi che insieme superano
    la lunghezza del nastro (es. se il nastro è lungo 4 allora l'unica soluzione valida con 4 pezzi di nastro è {1,1,1,1})

 */

int main(){
    int m=4;
    int lunghezza[N] = {7,4,8,1,5,2,6,3};
    int prezzo[N] = {17,9,20,1,10,5,17,8};
    checkMaxGuadagno_wrapper(m,lunghezza,prezzo);
}

void checkMaxGuadagno_wrapper(int m,int *lunghezza,int *prezzo){
    int cnt=0,pos=0,start=0,max=0,found;
    int *val = malloc(m*sizeof(int));
    int *prezzi = malloc(m*sizeof(int));

    for(int i=0;i<=m;i++){
        found = 0;
        for(int j=0;j<N;j++){
            if(lunghezza[j]==i){
                found = 1;
                val[i-1]=i;
                prezzi[i-1] = prezzo[j];
            }
            if(found==0) val[i-1] = prezzi[i-1] = -1;
        }
    }

    for(int i=0;i<m;i++)
        printf("Pezzo %d ha prezzo : %d\n",val[i],prezzi[i]);


    int *sol = malloc(m*sizeof(int));
    int *best = malloc(m*sizeof(int));


    for(int k=m;k>=0;k--)
        cnt = comb_r(pos,val,sol,m,k,start,cnt,prezzi,&max,best);

    printf("Soluzione ottima: ");
    for(int i=0;i<m && best[i]!=-1;i++) printf("%d ",best[i]);
    printf("\n");
    printf("Prezzo di vendita: %d",max);

}

int comb_r(int pos,int *val,int *sol,int n,int k,int start,int cnt,int *prezzi,int *max,int *best) {
    int i,act_max,act_len,index;
    if (pos >= k) {
        act_max = act_len = 0;
        for (i=0; i<k; i++){
            if(sol[i]+act_len<=n && sol[i]!=-1){
                act_len+=sol[i];
                act_max+=prezzi[sol[i]-1];
                index = i;
            }
        }

        if(act_max>*max){
            *max = act_max;
            for (i=0; i<=index; i++){
                best[i] = sol[i];
            }
            for(i=index+1;i<n;i++) best[i] = -1;
        }

        return cnt+1;
    }
    for (i=start; i<n; i++) {
        sol[pos] = val[i];
        cnt = comb_r(pos+1, val, sol, n, k, start,cnt,prezzi,max,best);
        start++;
    }
    return cnt;
}