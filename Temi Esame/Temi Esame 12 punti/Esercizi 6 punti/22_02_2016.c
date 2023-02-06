#include<stdio.h>
#include<stdlib.h>

#define N 4
#define M 5
#define FILENAME "../22_02_2016.txt"

/*
 Sia dato un insieme di n interruttori e un insieme di m lampadine, inizialmente tutte spente. Ogni interruttore comanda un
sottoinsieme delle lampadine: se lo si preme, ogni lampadina da esso controllata commuta di stato, cioè se è accesa si
spegne, se è spenta si accende. L’informazione su quale sottoinsieme di lampadine agisce ogni singolo interruttore è
memorizzata in una matrice di interi di dimensioni n x m. L’elemento [i,j] della matrice vale 1 se l’interruttore i controlla la
lampadina j, 0 altrimenti. Si scriva una funzione ricorsiva in C in grado di determinare l’insieme minimo di interruttori per
accendere tutte le lampadine. Si noti che una lampadina è accesa se e solo se è dispari il numero di interruttori premuti che
la controllano.

-- Soluzione:
 Poichè ci serve un insieme "minimo" utilizzo il modello delle disposizioni semplici con k variabile partendo da 1 fino a M per
 generare tutti i sottoinsiemi di interruttori premuti.
 Utilizzo un vettore J di dimensione M (come le colonne della matrice, cioè come il numero di interruttori)
 Per ogni soluzione conto il numero di lampadine accese dall'interruttore, verificando che Mat[sol[i]][j]==1
 cioè che l'interruttore controlla la lampadina j-esima.
 Se il vettore J ha elementi dispari allora la soluzione è valida.
 */

void disp(int pos,int *val,int *sol,int *mark, int n, int k,int cnt,int Mat[N][M],int *J,int *found);

int main(){
    int Mat[N][M],pos=0,cnt=0,found=0;
    FILE *fin = fopen(FILENAME,"r");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            fscanf(fin,"%d",&Mat[i][j]);
    }
    fclose(fin);
    int *val = malloc(M*sizeof(int));
    int *sol = malloc(M*sizeof(int));
    int *mark = malloc(M*sizeof(int));
    int *J = malloc(M*sizeof(int));
    for(int i=0;i<M;i++){
        mark[i]=0;
        J[i] = 0;
        val[i] = i;
    }
    for(int k=1;k<M;k++) disp(pos,val,sol,mark,M,k,cnt,Mat,J,&found);
}

void disp(int pos,int *val,int *sol,int *mark, int n, int k,int cnt,int Mat[N][M],int *J,int *found){
    if(*found==1) return;
    int i,flag;
    if (pos >= k){
        flag = 0;
        for(i=0;i<k;i++){
            for(int j=0;j<M;j++){
                if(Mat[sol[i]][j]==1) J[j]++;
            }
        }

        for(int j=0;j<M;j++)
            if(J[j]%2==0) flag = 1;

        if(flag==0){
            for(i=0;i<k;i++) printf("%d ",sol[i]);
            printf("\n");
            *found = 1;
        }
        else for(int j=0;j<M;j++) J[j] = 0;
    }
    for (i=0; i<n; i++){
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            disp(pos+1, val, sol, mark, n, k,cnt,Mat,J,found);
            mark[i] = 0;
        }
    }
}