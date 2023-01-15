#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
    Un porto ha n moli di ugual lunghezza intera lun. A ogni molo si accede da entrambi i lati. Una nave è
    caratterizzata da un intero che ne indica lo spazio necessario per attraccare a un molo. Le navi che chiedono di
    attraccare sono k e lo spazio richiesto da ciascuna nave è un intero contenuto in una cella del vettore navi. Si
    scriva in C una funzione ricorsiva che faccia attraccare, se possibile, le k navi agli n moli minimizzando il
    numero di moli utilizzati.
    Esempio: con 4 moli di lunghezza 10 utilizzabili sia a sinistra sia a destra e 6 navi (di dimensioni 8, 3, 5, 2, 5, 2
    e 9), la soluzione che utilizza il minimo numero di moli (2) è:
 */

float checkMoliMinimiGreedy(int *navi,int k,int n,int len_molo,float min);

int main(){
    int navi[] = {8,3,5,2,5,2,9},k=7;
    int n=4,len_molo=10;
    float min=0;

    min = checkMoliMinimiGreedy(navi,k,n,len_molo,min);
    printf("%.0f moli necessari per far attraccare tutte le %d navi",roundf(min),k);

}

float checkMoliMinimiGreedy(int *navi,int k,int n,int len_molo,float min){
    /*
     Soluzione greedy:
     - Ad ogni passo del ciclo for seleziono una nave la cui lunghezza non superi len_molo
     - Al passo successivo seleziono un'altra nave la cui lunghezza non superi lunghezza_nave_attuale + sum(navi_selezionate_precedentemente)
     - Terminato il ciclo for ho una soluzione valida di navi attraccate a mezzo molo
     - Reitero tutto fin quando ho selezionato tutte le navi
 */
    int sum,cnt_neg=0,cnt;
    int *vett = malloc(sizeof(int)*k);
    int *navicopia = malloc(sizeof(int)*k);
    for(int i=0;i<k;i++) navicopia[i] = navi[i];

    while(cnt_neg<k){
        cnt = 0;
        sum = 0;
        for(int i=0;i<k;i++){
            if(navi[i]<=len_molo && navicopia[i]!=-1 && sum+navicopia[i]<=len_molo){
                sum+=navicopia[i];
                vett[cnt] = i;
                cnt++;
                navicopia[i] = -1;
                cnt_neg++;
            }
        }
        if(sum>0){
            printf("Mezzo molo attracca le navi numero: ");
            printf("( ");
            for(int i=0;i<cnt;i++)
                printf("%d ",vett[i]);
            printf(")\n");
        }
        min = min + 0.5;
    }

    return min;

}
