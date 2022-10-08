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
void stampa_contenuti(struct corse *lc);
void ordina_vett_by_data(struct corse *lc);
void ordina_vett_by_partenza(struct corse *lc);
void ordina_vett_by_arrivo(struct corse *lc);
void ordina_vett_by_tratta(struct corse *lc);
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
    printf("5.Ordina vettore per codice di tratta\n");
    printf("6.Ricerca di una tratta per stazione di partenza\n");
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
            ordina_vett_by_tratta(lc);
            break;
        case 6:
            ricerca_tratta_dicotomica(lc);
            break;
        default:
            exit(0);
    }
    while(choice!=0)
        mostra_menu(lc);
}

void ricerca_tratta_lineare(struct corse *lc){
    char partenza[LENMAX];
    printf("Inserisci la stazione da cercare:\n");
    scanf("%s",partenza);
    if(islower(partenza[0]))
        partenza[0] = partenza[0] - 32;
    for(int i=0;i<n_corse;i++){
        if(strncmp(lc[i].partenza,partenza, strlen(partenza))==0)
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
    }
}

void ricerca_tratta_dicotomica(struct corse *lc) {
    char partenza[LENMAX];
    int m,k,end=0;
    printf("Inserisci la tratta da cercare: \n");
    scanf("%s", partenza);
    if(islower(partenza[0]))
        partenza[0] = partenza[0] - ('a' - 'A');
    ordina_vett_by_partenza(lc);
    int start_index = 0, end_index = n_corse - 1;
    while (start_index <= end_index && end==0) {
        m = start_index + (end_index - start_index) / 2;
        if (strncmp(lc[m].partenza, partenza, strlen(partenza)) == 0) {
            printf("%s %s %s %s %s %s %d\n", lc[m].cod_tratta, lc[m].partenza, lc[m].destinazione, lc[m].data,lc[m].ora_part, lc[m].ora_arr, lc[m].ritardo);
            k = m + 1;
            while(k<n_corse && strncmp(lc[k].partenza, partenza, strlen(partenza)) == 0){
                printf("%s %s %s %s %s %s %d\n", lc[k].cod_tratta, lc[k].partenza, lc[k].destinazione, lc[k].data, lc[k].ora_part, lc[k].ora_arr, lc[k].ritardo);
                k++;
            }
            k = m - 1;
            while(k>0 && strncmp(lc[k].partenza, partenza, strlen(partenza)) == 0 && k>0){
                printf("%s %s %s %s %s %s %d\n", lc[k].cod_tratta, lc[k].partenza, lc[k].destinazione, lc[k].data, lc[k].ora_part, lc[k].ora_arr, lc[k].ritardo);
                k--;
            }
            end = 1;
        }
        else if (strncmp(lc[m].partenza, partenza, strlen(partenza)) < 0)
            start_index = m + 1;
        else
            end_index = m - 1;
    }
}

void ordina_vett_by_tratta(struct corse *lc){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(lc[j].cod_tratta,lc[j+1].cod_tratta)>0){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
        }
    }
    printf("Vettore ordinato con successo in ordine di codice di tratta\n");
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
    printf("Vettore ordinato con successo in ordine di stazione di destinazione\n");
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
    printf("Vettore ordinato con successo in ordine di stazione di partenza\n");
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
    printf("Vettore ordinato con successo in ordine di data\n");
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