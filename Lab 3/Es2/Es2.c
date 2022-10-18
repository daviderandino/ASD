#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCH 256

typedef struct{
    char **scelte;
    int num_scelte;
} Livello;

void leggi_file(char *file_name);
int princ_molt(int pos, Livello *val, char **sol, int n, int cnt);

int main(){
    char *file_name = "../brani.txt";
    leggi_file(file_name);
    return 0;
}

void leggi_file(char *file_name){
    FILE *fin = fopen(file_name,"r");
    if(!fin) return;
    Livello *val;
    char **sol,n;
    int totali;
    fscanf(fin,"%d",&n);
    // costruzione del vettore di struct "val"
    val = (Livello *) malloc(n*sizeof(Livello));
    for(int i=0;i<n;i++) {
        fscanf(fin, "%d", &val[i].num_scelte);
        val[i].scelte = (char **) malloc(val[i].num_scelte * sizeof(char *));
        for (int j = 0; j < val[i].num_scelte; j++) {
            (val[i].scelte)[j] = (char *) malloc(MAXCH);
            fscanf(fin, "%s", (val[i].scelte)[j]);
        }
    }
    // sol è il vettore delle soluzioni: avrà dimensione n (come il numero di amici poichè viene scelta una canzone a testa)
    sol=(char **) malloc(n* sizeof(char *));
    for(int i=0;i<n;i++)
        sol[i]=(char *) malloc(MAXCH); // sizeof(char) = 1 byte, si può omettere

    // dopo aver costruito il vettore di struct "val" si procede chiamando la funzione ricorsiva princ_molt
    totali = princ_molt(0,val,sol,n,0);
    printf("%d playlist possibili",totali);
    fclose(fin);
}

int princ_molt(int pos, Livello *val, char **sol, int n, int cnt){
    if(pos>=n){ // caso terminale: la dimensione della soluzione è >= di quella richiesta. Può stampare gli elementi di sol.
        for(int i=0;i<n;i++)
            printf("%s ",sol[i]);
        printf("\n");
        return cnt+1; // cnt conta le soluzioni trovate: 1 in più
    }
    for(int i=0;i<val[pos].num_scelte;i++){
        strcpy(sol[pos],(val[pos].scelte)[i]);
        cnt = princ_molt(pos+1,val,sol,n,cnt);
    }
    return cnt;
}
