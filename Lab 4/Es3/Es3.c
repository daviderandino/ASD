#include <stdio.h>
#include <stdlib.h>
/*
 Associo a Zaffiri, Rubini, Topazi e Smeraldi rispettivamente gli indici 0,1,2,3
 Calcolo le disposizioni ripetute con k variabile perchè la collana di dimensione massima può essere minore del numero di pietre totali
 Ad ogni scelta faccio pruning verificando che le condizioni siano rispettate
 */

int disp_rip(int pos,int *mark,int *sol,int n,int k,int previous, int found);
int scelta_valida(int previous,int current);

int main(){
    int val[4]={19,6,8,5};
    int mark[4]={19,6,8,5};
    int k=val[0]+val[1]+val[2]+val[3];
    int *sol = malloc(k*sizeof(int));
    int n=4,pos=0,i,found=0,previous=-1;

    printf("Costruzione di una collana con %d Zaffiri, %d Rubini, %d Topazi, %d Smeraldi...\n",val[0],val[1],val[2],val[3]);
    
    for(i=k;i>=1 && found==0;i--)
        found=disp_rip(pos,mark,sol,n,i,previous,found);

    printf("Lunghezza massima: %d\n",i+1);
    free(sol);
    return 0;
}

int disp_rip(int pos,int *mark,int *sol,int n,int k,int previous,int found){
    int i,flag;
    if (pos>= k) return 1;
    for (i=0;i<n;i++) {
        flag = scelta_valida(previous,i);
        if (mark[i] > 0 && flag == 1) {
            mark[i]--;
            sol[pos] = i;
            if(disp_rip(pos+1, mark, sol, n, k,i,found)) return 1;
            mark[i]++;
        }
    }
    return 0;
}

int scelta_valida(int previous,int current){
    if(previous==-1) // prima pietra
        return 1;
    else if(current==0 && (previous==0 || previous==2)) // l'attuale pietra è uno zaffiro e quella precedente un altro zaffiro o un topazio
        return 1;
    else if(current==1 && (previous==0 || previous==2)) // l'attuale pietra è un rubino e quella precedente uno zaffiro o un topazio
        return 1;
    else if(current==2 && (previous==1 || previous==3)) // l'attuale pietra è un topazio e quella precedente un rubino o uno smeraldo
        return 1;
    else if(current==3 && (previous==1 || previous==3)) // l'attuale pietra è uno smeraldo e quella precedente un rubino o uno smeraldo
        return 1;
    else return 0; // se non entro in nessun if la scelta è da scartare. Ritorno 0 e flag assumerà tale valore
}
