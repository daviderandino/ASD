#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXRIGHE 1000
#define LENMAX 30

struct corse{
    char cod_tratta[LENMAX],partenza[LENMAX],destinazione[LENMAX],data[LENMAX],ora_part[LENMAX],ora_arr[LENMAX];
    int ritardo;
};

int n_corse;

void riempi_vett(struct corse *lc);
int converti_data(char data[LENMAX]);
int converti_ora(char ora[LENMAX]);
void stampa_contenuti(struct corse *lc);
void ricerca_tratta_lineare(struct corse *lc);
void ricerca_tratta_dicotomica(struct corse *lc);
void ordina_vett_pointer_by_data(struct corse **rif_data);
void ordina_vett_pointer_by_partenza(struct corse **rif_part);
void ordina_vett_pointer_by_arrivo(struct corse **rif_arr);

int main(){
    int choice=-1;
    struct corse lista_corse[MAXRIGHE];
    riempi_vett(lista_corse);
    struct corse *rif_data[MAXRIGHE];
    struct corse *rif_partenze[MAXRIGHE];
    struct corse *rif_arrivi[MAXRIGHE];
    for(int i=0;i<n_corse;i++){
        rif_data[i] = &lista_corse[i];
        rif_partenze[i] = &lista_corse[i];
        rif_arrivi[i] = &lista_corse[i];
    }
    do{
        printf("Cosa vuoi fare? (0 per terminare)\n");
        printf("1.Stampa dei contenuti del log\n");
        printf("2.Ordina vettore per data\n");
        printf("3.Ordina vettore per stazione di partenza\n");
        printf("4.Ordina vettore per stazione di arrivo\n");
        printf("5.Ricerca di una tratta per stazione di partenza\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                stampa_contenuti(lista_corse);
                break;
            case 2:
                ordina_vett_pointer_by_data(rif_data);
                break;
            case 3:
                ordina_vett_pointer_by_partenza(rif_partenze);
                break;
            case 4:
                ordina_vett_pointer_by_arrivo(rif_arrivi);
                break;
            case 5:
                ricerca_tratta_lineare(lista_corse);
                break;
        }
    }
    while(choice!=0);
}

void ordina_vett_pointer_by_data(struct corse **rif_data){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse *temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(rif_data[j]->data,rif_data[j+1]->data)>0){
                flag = 1;
                temp = rif_data[j];
                rif_data[j] = rif_data[j+1];
                rif_data[j+1] = temp;
            }
            else if(strcmp(rif_data[j]->data,rif_data[j+1]->data)==0 && strcmp(rif_data[j]->ora_part,rif_data[j+1]->ora_part)>=0){
                flag = 1;
                temp = rif_data[j];
                rif_data[j] = rif_data[j+1];
                rif_data[j+1] = temp;
            }
        }
    }

    for(i=0;i<n_corse;i++){
        printf("%s %s %s %s %s %s %d\n",rif_data[i]->cod_tratta,rif_data[i]->partenza,
        rif_data[i]->destinazione,rif_data[i]->data,rif_data[i]->ora_part,rif_data[i]->ora_arr,rif_data[i]->ritardo);
    }

}

void ordina_vett_pointer_by_partenza(struct corse **rif_part){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse *temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(rif_part[j]->partenza,rif_part[j+1]->partenza)>0){
                flag = 1;
                temp = rif_part[j];
                rif_part[j] = rif_part[j+1];
                rif_part[j+1] = temp;
            }
        }
    }
    for(i=0;i<n_corse;i++){
        printf("%s %s %s %s %s %s %d\n",rif_part[i]->cod_tratta,rif_part[i]->partenza,
        rif_part[i]->destinazione,rif_part[i]->data,rif_part[i]->ora_part,rif_part[i]->ora_arr,rif_part[i]->ritardo);
    }
}

void ordina_vett_pointer_by_arrivo(struct corse **rif_arr){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse *temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(rif_arr[j]->destinazione,rif_arr[j+1]->destinazione)>0){
                flag = 1;
                temp = rif_arr[j];
                rif_arr[j] = rif_arr[j+1];
                rif_arr[j+1] = temp;
            }
        }
    }

    for(i=0;i<n_corse;i++){
        printf("%s %s %s %s %s %s %d\n",rif_arr[i]->cod_tratta,rif_arr[i]->partenza,
        rif_arr[i]->destinazione,rif_arr[i]->data,rif_arr[i]->ora_part,rif_arr[i]->ora_arr,rif_arr[i]->ritardo);
    }

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
    int data_numerica,ora_part_numerica,ora_arr_numerica;
    FILE *fin = fopen("../corse.txt","r");;
    fscanf(fin,"%d",&n_corse);
    for(int i=0;i<n_corse;i++) {
        fscanf(fin, "%s%s%s%s%s%s%d", lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,&lc[i].ritardo);
    }
    fclose(fin);
}