#include<stdio.h>
#include<stdlib.h>

int **alloca_matriceV1(char *nome_file,int *nr,int *nc);
void alloca_matriceV2(char *nome_file,int ***m,int *nr,int *nc);
void separa(int **Matr, int nr, int nc,int *Wh,int *Bl);
void stampa_matrice(int **Matr,int nr,int nc);
void stampa_vettori(int cw,int cb,int *Wh,int *Bl);
void free2dr(int **matrix,int nr);

int main(){
    int **Matr,nr,nc;
    char *nome_file = "../mat.txt";
    // Matr = alloca_matriceV1(nome_file,&nr,&nc);
    alloca_matriceV2(nome_file,&Matr,&nr,&nc);
    // stampa_matrice(Matr,nr,nc);
    int c_black = (nr*nc)/2,c_white = nr*nc-c_black;
    int *Wh=malloc(c_white*(sizeof(int)));
    int *Bl=malloc(c_black*(sizeof(int)));;
    separa(Matr,nr,nc,Wh,Bl);
    stampa_vettori(c_white,c_black,Wh,Bl);
}

void separa(int **Matr, int nr, int nc,int *Wh,int *Bl){
    int cb=0,cw=0;
    for(int i=0;i<nr;i++) {
        for (int j = 0; j < nc; j++) {
            if ((i + j) % 2 == 0) Wh[cw++] = Matr[nc * i + j];
            else Bl[cb++] = Matr[nc * i + j];
        }
    }
}

void stampa_vettori(int cw,int cb,int *Wh,int *Bl){
    printf("Vettore caselle bianche:\n");
    for(int i=0;i<cw;i++)
        printf("%d ",Wh[i]);
    printf("\nVettore caselle nere:\n");
    for(int i=0;i<cb;i++)
        printf("%d ",Bl[i]);
    free(Bl);
    free(Wh);
}

int **alloca_matriceV1(char *nome_file,int *nr,int *nc){
    FILE *fin = fopen(nome_file,"r");
    int **m,r,c;
    fscanf(fin,"%d%d",&r,&c);
    m = malloc(r*sizeof(int *));
    for(int i=0;i<r;i++)
        m[i] = malloc(c*sizeof(int));
    for(int i=0;i<r*c;i++){
        fscanf(fin,"%d",&m[i]);
    }
    fclose(fin);
    *nr = r; *nc = c;
    return m;
}

void alloca_matriceV2(char *nome_file,int ***Matr,int *nr,int *nc){
    FILE *fin = fopen(nome_file,"r");
    int **m,r,c;
    fscanf(fin,"%d%d",&r,&c);
    m = (int **) malloc(r*sizeof(int *));
    for(int i=0;i<r;i++)
        m[i] = (int *)malloc(c*sizeof(m));
    for(int i=0;i<r*c;i++)
        fscanf(fin,"%d",&m[i]);
    fclose(fin);
    *Matr = m;
    *nr = r; *nc = c;
}

void stampa_matrice(int **Matr,int nr,int nc){
    for(int i=0;i<nr;i++) {
        for (int j=0;j<nc;j++)
            printf("%d ",Matr[nc*i+j]);
        printf("\n");
    }
}