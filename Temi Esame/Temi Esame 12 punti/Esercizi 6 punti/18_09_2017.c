/*
    P piattaforme, disposte in sequenza in linea retta, sono caratterizzate ognuna da un intero positivo. Ognuno di
    essi indica la lunghezza massima del salto verso destra che può fare il giocatore che si trova su quella
    piattaforma. Non sono permessi salti all’indietro (verso sinistra).
    Si scriva una funzione in grado di determinare, se esiste, una sequenza ottima di salti che il giocatore deve fare
    per spostarsi dalla piattaforma di partenza (indice 0, estremo sinistro) a quella di arrivo (indice P-1, estremo
    destro). Criterio di ottimalità: minimo numero di salti.
    Esempio
    Con P = 5 e la seguente configurazione di piattaforme:
    la soluzione ottima (da 0 a 2 e da 2 a 4) richiede 2 salti:
 */

#include<stdio.h>
#include<stdlib.h>

int comb(int pos,int *val,int *sol,int n,int k,int start,int cnt,int *Platform,int *min_passi,int *best_sol);

int main(){
    int P=5,cnt=0,k,min_passi=P;
    int Platform[] = {2,2,3,2,1};
    int val[] = {0,1,2,3,4};
    int *sol = malloc(P*sizeof(int));
    int *best_sol = malloc(P*sizeof(int));

    for(k=0;k<P;k++)
        comb(0,val,sol,P,k,0,cnt,Platform,&min_passi,best_sol);
     printf("%d salti\n",min_passi-1);

     for(int i=0;i<min_passi;i++) printf("%d ",best_sol[i]);

}

int comb(int pos,int *val,int *sol,int n,int k,int start,int cnt,int *Platform,int *min_passi,int *best_sol){
    int i,isValid,indB,ind;
    if(pos>=k){
        isValid = 1;
        if(sol[0]!=val[0] || sol[k-1]!=val[n-1])  isValid = 0;
        for(i=0;i<k && isValid==1;i++) {
            indB = sol[i-1];
            if(i>0 && i!=k-1 && sol[i]!=Platform[indB]) isValid = 0;
            if(i==k-1 && Platform[indB]+sol[indB]<sol[k-1]) isValid = 0;
        }

        if(isValid==1 && k<*min_passi){
            *min_passi = k;
            for(i=0;i<k;i++) best_sol[i] = sol[i];
        }

        return cnt+1;
    }
    for(i=start;i<n;i++){
        sol[pos] = val[i];
        cnt = comb(pos+1,val,sol,n,k,i+1,cnt,Platform,min_passi,best_sol);
    }
    return cnt;
}