#include<stdio.h>
#include<stdlib.h>

/*
 -- NON ANCORA COMPLETATO --

 Algoritmo:
 - Sia tess_disp vettore di interi contenente gli indici delle tessere NON UTILIZZATE = {1,4,5,7,8} di dimensione n
 Occhio che il numero di tessere totali può essere maggiore dell'ordine della scacchiera. In questo caso è necessario
 fare le disposizioni utilizzando k oggetti con k<n.

 - Generare tutte le disposizioni semplici, esempio {1,4,5,7,8} , {1,5,4,7,8} ...

 - Posizionarle in maniera ordinata nella scacchiera Board

 - Calcolare il punteggio per ogni soluzione e verificare che sia > punt_max. In caso positivo salvare la matrice

 - Doppia ricorsione per tenere conto delle rotazioni

 */

struct tiles{
    char color1,color2;
    int val1,val2,rotazione;
} typedef t;

int disp(int pos,int *val,int *sol,int *mark, int n, int k,int cnt);
t *alloca_tessere(t *Vett,int *N);
int **alloca_board(int **Board, int *nr, int *nc,t *Vett);
void riempi_tessere_disponibili(int *tess_disp,int **Board,int nr,int nc,int *n,int N);

int main(){
    t *tess_tot;
    int **Board,*tess_disp;
    int N_tot,nr,nc,n_disp,k,cnt;
    tess_tot = alloca_tessere(tess_tot,&N_tot);
    tess_disp = (int *) malloc(N_tot*sizeof(int));
    Board = alloca_board(Board,&nr,&nc,tess_tot);
    riempi_tessere_disponibili(tess_disp,Board,nr,nc,&n_disp,N_tot);

    for(int i=0;i<=n_disp;i++)
        printf("%d\n",tess_disp[i]);

    for(int i=0;i<nr;i++)
        free(Board[i]);
    free(Board);
    free(tess_tot);
    free(tess_disp);
}

int disp(int pos,int *val,int *sol,int *mark, int n, int k,int cnt){
    int i;
    if (pos >= k){
        for (i=0; i<k; i++) printf("%d ", sol[i]);
        printf("\n");
        return cnt+1;
    }
    for (i=0; i<n; i++){
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            cnt = disp(pos+1, val, sol, mark, n, k,cnt);
            mark[i] = 0;
        }
    }
    return cnt;
}

void riempi_tessere_disponibili(int *tess_disp,int **Board,int nr,int nc,int *n,int N){
    int *V1 = (int*) malloc(N*sizeof(int)),cnt=0,cnt2=0,flag;
    for(int i=0;i<nr;i++) {
        for (int j = 0; j < nc; j++) {
            if (Board[i][j] != -1) V1[cnt++] = Board[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        flag = 0;
        for(int j=0;j<N;j++){
            if(i==V1[j]) flag = 1;
        }
        if(flag==0) tess_disp[cnt2++] = i;
    }

    *n = cnt;
}

int **alloca_board(int **Board,int *nr,int *nc, t *Vett){
    FILE *fin = fopen("../board.txt","r");
    int n1,n2;
    fscanf(fin,"%d%d",nr,nc);
    Board = (int **) malloc(*nr*sizeof(int*));
    for(int i=0;i<*nr;i++)
        Board[i] = (int *) malloc(*nc*sizeof(int));
    for(int i=0;i<*nr;i++){
        for(int j=0;j<*nc;j++){
            fscanf(fin,"%d%*c%d",&n1,&n2);
            Board[i][j] = n1;
            Vett[*nc*i+j].rotazione = n2;
        }
    }

    fclose(fin);
    return Board;

}

t *alloca_tessere(t *V,int *N){
    FILE *fin = fopen("../tiles.txt","r");
    fscanf(fin,"%d\n",N);
    V = (t*) malloc(*N*sizeof(t));
    for(int i=0;i<*N;i++){
        fscanf(fin,"%c %d %c %d\n",&V[i].color1,&V[i].val1,&V[i].color2,&V[i].val2);
        V[i].rotazione = 0;
    }
    fclose(fin);
    return V;
}
