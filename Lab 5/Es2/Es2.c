#include<stdio.h>
#include<stdlib.h>

/*
 -- NON ANCORA COMPLETATO --

 Algoritmo:
 - Sia tess_disp vettore di interi contenente gli indici delle tessere NON UTILIZZATE = {1,4,5,7,8} di dimensione n
 Occhio che il numero di tessere totali può essere maggiore dell'ordine della scacchiera. In questo caso è necessario
 fare le disposizioni utilizzando k oggetti con k<n.

 - Generare tutte le disposizioni semplici, esempio {1,4,5,7,8} , {1,5,4,7,8} ...

 - Posizionarle in maniera ordinata nella scacchiera Board nei posti "liberi". Serve quindi un vettore che contiene gli indici
 occupati {0,2,3,7}. GLI INDICI DELLA MATRICE, NON LE TESSERE!!!

 - Calcolare il punteggio per ogni soluzione e verificare che sia > punt_max. In caso positivo salvare la matrice

 - Doppia ricorsione per tenere conto delle rotazioni

 */

struct tiles{
    char color1,color2;
    int val1,val2,rotazione;
} typedef t;

int disp(int pos,int *val,int *sol,int *mark, int n, int k,int cnt,int nr,int nc,int **Board,int *indici_liberi,int n_ind_liberi,int *p_max,t *tess_tot);
t *alloca_tessere(t *Vett,int *N);
int **alloca_board(int **Board, int *nr, int *nc,t *Vett);
void cerca_tessere_disponibili(int *tess_disp,int **Board,int nr,int nc,int *n,int N,int *indici_liberi);
void stampa_indici_liberi_e_tessere_disponibili(int *indici_liberi,int *tess_disp,int n_ind_liberi,int n_disp);
void dealloca_tutto(t *tess_tot,int *tess_disp,int *indici_liberi,int **Board,int nr);
int calcola_punteggio(int **Board,int nr,int nc,t *tess_tot);

int main(){
    t *tess_tot;
    int **Board,*tess_disp,*indici_liberi;
    int N_tot,nr,nc,n_disp,pos=0,cnt=0,n_ind_liberi;
    int punteggio_max;
    tess_tot = alloca_tessere(tess_tot,&N_tot);
    tess_disp = (int *) malloc(N_tot*sizeof(int));
    indici_liberi = (int *) malloc(N_tot*sizeof(int));
    Board = alloca_board(Board,&nr,&nc,tess_tot);
    cerca_tessere_disponibili(tess_disp,Board,nr,nc,&n_disp,N_tot,indici_liberi);
    n_ind_liberi = N_tot - n_disp + 1;
    stampa_indici_liberi_e_tessere_disponibili(indici_liberi,tess_disp,n_ind_liberi,n_disp);
    int *sol = (int*) malloc(n_disp*sizeof(int));
    int *mark = (int*) malloc(n_disp*sizeof(int));
    for(int i=0;i<n_disp;i++) mark[i] = 0;
    cnt = disp(pos,tess_disp,sol,mark,n_disp,n_disp,cnt,nr,nc,Board,indici_liberi,n_ind_liberi,&punteggio_max,tess_tot);
    dealloca_tutto(tess_tot,tess_disp,indici_liberi,Board,nr);
}

int disp(int pos,int *val,int *sol,int *mark, int n, int k,int cnt,int nr,int nc,int **Board,int *indici_liberi,int n_ind_liberi,int *p_max, t *tess_tot){
    int punteggio;
    if (pos >= k){
        for(int i=0;i<n_ind_liberi;i++) {
            for (int j = 0; j < nr; j++) {
                for (int l = 0; l < nc; l++) {
                    if (nc * j + l == indici_liberi[i]){
                        Board[j][l] = sol[i];
                    }
                }
            }
        }

    punteggio = calcola_punteggio(Board,nr,nc,tess_tot);
    if(punteggio>*p_max) *p_max = punteggio;

    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            printf("%d ",Board[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return cnt+1;
    }
    for (int i=0; i<n; i++){
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            cnt = disp(pos+1,val,sol,mark,n,k,cnt,nr,nc,Board,indici_liberi,n_ind_liberi,p_max,tess_tot);
            mark[i] = 0;
        }
    }
    return cnt;
}

int calcola_punteggio(int **Board,int nr,int nc,t *tess_tot){
    
}

void dealloca_tutto(t *tess_tot,int *tess_disp,int *indici_liberi,int **Board,int nr){
    for(int i=0;i<nr;i++)
        free(Board[i]);
    free(Board);
    free(tess_tot);
    free(tess_disp);
    free(indici_liberi);
}

void stampa_indici_liberi_e_tessere_disponibili(int *indici_liberi,int *tess_disp,int n_ind_liberi,int n_disp){
    printf("Indici liberi:\n");
    for(int i=0;i<n_ind_liberi;i++){
        printf("%d ",indici_liberi[i]);
    }
    printf("\n");

    printf("Tessere libere:\n");
    for(int i=0;i<n_disp;i++)
        printf("%d ",tess_disp[i]);
    printf("\n\n");
}

void cerca_tessere_disponibili(int *tess_disp,int **Board,int nr,int nc,int *n,int N,int *indici_liberi){
    int cnt=0,cnt2=0,flag,cnt3=0;
    int *V = (int*) malloc(N*sizeof(int));
    for(int i=0;i<nr;i++) {
        for (int j = 0; j < nc; j++) {
            if (Board[i][j] != -1){
                V[cnt++] = Board[i][j];
            } else indici_liberi[cnt3++] = nc*i+j;
        }
    }

    for(int i=0;i<N;i++) {
        flag = 0;
        for(int j=0;j<N;j++){
            if(i==V[j]) flag = 1;
        }
        if(flag==0) tess_disp[cnt2++] = i;
    }

    cnt++;
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
