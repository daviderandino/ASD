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
}

void leggi_file(char *file_name){
    FILE *fin = fopen(file_name,"r");
    if(!fin) return;
    Livello *val;
    char **sol,n;
    int totali;
    fscanf(fin,"%d",&n);
    val = (Livello *) malloc(n*sizeof(Livello));
    sol=(char **) malloc(n* sizeof(char *));
    for(int i=0;i<n;i++)
        sol[i]=(char *) malloc(MAXCH); // sizeof(char) = 1 byte
    for(int i=0;i<n;i++){
        fscanf(fin,"%d",&val[i].num_scelte);
        val[i].scelte = (char **) malloc(val[i].num_scelte*sizeof(char *));
        for(int j=0;j<val[i].num_scelte;j++){
            (val[i].scelte)[j]=(char *) malloc(MAXCH);
            fscanf(fin,"%s",(val[i].scelte)[j]);
        }
    }

    totali = princ_molt(0,val,sol,n,0);
    printf("%d playlist possibili",totali);
    fclose(fin);
}

int princ_molt(int pos, Livello *val, char **sol, int n, int cnt){
    if(pos>=n){
        for(int i=0;i<n;i++)
            printf("%s ",sol[i]);
        printf("\n");
        return cnt+1;
    }
    for(int i=0;i<val[pos].num_scelte;i++){
        strcpy(sol[pos],(val[pos].scelte)[i]);
        cnt = princ_molt(pos+1,val,sol,n,cnt);
    }
    return cnt;
}
