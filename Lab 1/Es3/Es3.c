#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXRIGHE 1000
#define LENMAX 30

struct corse{
    char cod_tratta[LENMAX],partenza[LENMAX],destinazione[LENMAX],data[LENMAX],ora_part[LENMAX],ora_arr[LENMAX];
    int ritardo;
};

int n_corse;

void riempi_vett(struct corse *lc);
void mostra_menu(struct corse *lc);
int converti_data(char data[LENMAX]);
int converti_ora(char ora[LENMAX]);
void stampa_contenuti(struct corse *lc);
void ordina_vett_by_data(struct corse *lc);
void ordina_vett_by_partenza(struct corse *lc);
void ordina_vett_by_arrivo(struct corse *lc);
void ricerca_tratta_lineare(struct corse *lc);
void ricerca_tratta_dicotomica(struct corse *lc);

int main(){
    struct corse lista_corse[MAXRIGHE];
    riempi_vett(lista_corse);
    mostra_menu(lista_corse);
}

void mostra_menu(struct corse *lc){
    int choice;
    printf("Cosa vuoi fare? (0 per terminare)\n");
    printf("1.Stampa dei contenuti del log\n");
    printf("2.Ordina vettore per data\n");
    printf("3.Ordina vettore per stazione di partenza\n");
    printf("4.Ordina vettore per stazione di arrivo\n");
    printf("5.Ricerca di una tratta per stazione di partenza\n");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            stampa_contenuti(lc);
            break;
        case 2:
            ordina_vett_by_data(lc);
            break;
        case 3:
            ordina_vett_by_partenza(lc);
            break;
        case 4:
            ordina_vett_by_arrivo(lc);
            break;
        case 5:
            ricerca_tratta_lineare(lc);
            break;
        default:
            exit(0);
    }
    while(choice!=0)
        mostra_menu(lc);
}

void ricerca_tratta_lineare(struct corse *lc){
    char partenza[LENMAX];
    int flag;
    printf("Inserisci la stazione da cercare:\n");
    scanf("%s",partenza);
    if(islower(partenza[0]))
        partenza[0] = partenza[0] - 32;
    for(int i=0;i<n_corse;i++){
        flag = 1;
        for(int j=0;j< strlen(partenza);j++){
            if(partenza[j]!=(lc[i].partenza)[j])
                flag = 0;
        }
        if(flag==1)
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
    }
}

void ordina_vett_by_arrivo(struct corse *lc){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(lc[j].destinazione,lc[j+1].destinazione)>0){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
        }
    }
}

void ordina_vett_by_partenza(struct corse *lc){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(lc[j].partenza,lc[j+1].partenza)>0){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
        }
    }
}

void ordina_vett_by_data(struct corse *lc){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(lc[j].data,lc[j+1].data)>0){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
            else if(strcmp(lc[j].data,lc[j+1].data)==0 && strcmp(lc[j].ora_part,lc[j+1].ora_part)>0){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
        }
    }
}

void stampa_contenuti(struct corse *lc){
    int choice;
    char *filename = "../output.txt";
    printf("Dove vuoi stamparli?\n1.Video\n2.File\n");
    scanf("%d",&choice);
    if(choice==1){
        for(int i=0;i<n_corse;i++)
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
    }
    else{
        FILE *fin = fopen(filename,"w");
        for(int i=0;i<n_corse;i++)
            fprintf(fin,"%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
        fclose(fin);
    }
}

void riempi_vett(struct corse *lc){
    char *filename = "../corse.txt";
    FILE *fin = fopen(filename,"r");;
    fscanf(fin,"%d",&n_corse);
    for(int i=0;i<n_corse;i++) {
        fscanf(fin, "%s%s%s%s%s%s%d", lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,&lc[i].ritardo);
    }
    fclose(fin);
}
