#include<stdio.h>
#include<stdlib.h>

/*
    Sia dato un vettore di float di lunghezza nota n. Ogni float rappresenta un movimento su un conto bancario: se positivo,
    è un’entrata, se negativo un’uscita. Si assuma che tutti i movimenti siano distinti. Dato un ordine per i movimenti, per
    ogni movimento, si definisce saldo corrente il valore ottenuto sommando algebricamente al saldo precedente
    (inizialmente 0) l’importo dell’operazione. Per ogni ordine di movimenti esisterà un saldo corrente massimo e un saldo
    corrente minimo, mentre il saldo finale sarà ovviamente lo stesso, qualunque sia l’ordine.
    Si scriva una funzione C che, utilizzando un algoritmo ricorsivo, determini l’ordinamento del vettore tale da
    minimizzare la differenza tra saldo corrente massimo e saldo corrente minimo. La funzione deve ritornare la sequenza
    ordinata sul vettore di partenza.
 */

/*
 ---SOLUZIONE---
 Calcolo tutte le permutazioni semplici del vettore iniziale.
 Verifico che la nuova soluzione è la migliore, cioè quella col "delta" più basso fino ad ora (ovvero quella con la minor differenza tra saldo
 corrente massimo e saldo corrente minimo)
 In caso affermativo salvo la soluzione nel vettore *best
 Dopo aver generato tutte le soluzioni, *best conterrà quindi la soluzione migliore, e la funzione *bestOrder ritorna il vettore.
 */

int *bestOrder(int *V,int N);
int perm(int pos,int *val,int *sol,int *mark, int n, int cnt,int *best,int *bestDelta);
int max(int *V,int N);

int main(){
    int N = 5,i;
    int *V = malloc(N*sizeof(int));
    V[0] = 1; V[1] = 5; V[2] = -3; V[3] = -2; V[4] = 4;
    printf("---Vettore iniziale---\n");
    for(i=0;i<N;i++) printf("%d ",V[i]);
    printf("\n");
    V = bestOrder(V,N);
    printf("---Vettore finale---\n"); // 5 1 -3 4 -2
    for(i=0;i<N;i++) printf("%d ",V[i]);
    printf("\n");
}

int *bestOrder(int *V,int N){
    int pos=0,cnt=0,bestDelta= max(V,N); // per semplicità inizializziamo bestDelta al valore max. Sicuramente diminuirà o al più resterà invariato
    int *sol = malloc(N*sizeof(int));
    int *mark = malloc(N*sizeof(int));
    int *best = malloc(N*sizeof(int));
    for(int i=0;i<N;i++) mark[i] = 0;
    cnt = perm(pos,V,sol,mark,N,cnt,best,&bestDelta);
    return best;
}

int perm(int pos,int *val,int *sol,int *mark, int n, int cnt,int *best,int *bestDelta){
    int i,actS,actSMax,actSMin,actDelta,flag;
    if (pos >= n){
        actS = 0; actSMax = sol[0]; actSMin = sol[0]; actDelta = 0;
        for (i=0; i<n; i++){
            actS+=sol[i];
            if(actS>=actSMax) actSMax = actS;
            if(actS<=actSMin) actSMin = actS;
        }
        actDelta = abs(actSMax-actSMin);
        if(actDelta<*bestDelta){
            *bestDelta = actDelta;
            for(i=0;i<n;i++) best[i] = sol[i];
        }
        return cnt+1;
    }
    for (i=0; i<n; i++)
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            cnt = perm(pos+1, val, sol, mark, n, cnt,best,bestDelta);
            mark[i] = 0;
        }
    return cnt;
}

int max(int *V,int N){
    int m=V[0];
    for(int i=0;i<N;i++)
        if(V[i]>m) m = V[i];
    return m;
}