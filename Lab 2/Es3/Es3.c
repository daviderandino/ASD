#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define LENMAX 30

struct corse{
    char cod_tratta[LENMAX],partenza[LENMAX],destinazione[LENMAX],data[LENMAX],ora_part[LENMAX],ora_arr[LENMAX];
    int ritardo;
};

int n_corse;

void stampa_contenuti(struct corse *lc);
void ricerca_tratta_lineare(struct corse *lc);
void ricerca_tratta_dicotomica(struct corse **rif_part);
void ordina_vett_pointer_by_data(struct corse **rif_data);
void ordina_vett_pointer_by_partenza(struct corse **rif_part);
void ordina_vett_pointer_by_arrivo(struct corse **rif_arr);
void ordina_vett_pointer_by_tratta(struct corse **rif_tratta);
void alloca_vett(struct corse **lc);
struct corse** alloca_vett_pointer(struct corse **rif);

int main(){
    int choice=-1;
    struct corse *lista_corse;
    struct corse **rif_data,**rif_partenze,**rif_arrivi,**rif_tratta;
    alloca_vett(&lista_corse);
    rif_partenze = alloca_vett_pointer(rif_partenze);
    rif_arrivi = alloca_vett_pointer(rif_arrivi);
    rif_tratta = alloca_vett_pointer(rif_tratta);
    rif_data = alloca_vett_pointer(rif_data);
    do{
        printf("Cosa vuoi fare? (0 per terminare)\n");
        printf("1.Stampa dei contenuti del log\n");
        printf("2.Ordina vettore per data\n");
        printf("3.Ordina vettore per stazione di partenza\n");
        printf("4.Ordina vettore per stazione di arrivo\n");
        printf("5.Ordina vettore per codice di tratta\n");
        printf("6.Ricerca di una tratta per stazione di partenza\n");
        printf("7.Acquisisci dati da un nuovo file\n");
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
                ordina_vett_pointer_by_tratta(rif_tratta);
                break;
            case 6:
                ricerca_tratta_dicotomica(rif_partenze);
                break;
            case 7:
                for(int i=0;i<n_corse;i++){
                    free(rif_partenze[i]);
                    free(rif_data[i]);
                    free(rif_tratta[i]);
                    free(rif_arrivi[i]);
                }
                free(rif_partenze); free(rif_arrivi); free(rif_data); free(rif_tratta);
                free(lista_corse);
                alloca_vett(&lista_corse);
                rif_partenze = alloca_vett_pointer(rif_partenze);
                rif_arrivi = alloca_vett_pointer(rif_arrivi);
                rif_tratta = alloca_vett_pointer(rif_tratta);
                rif_data = alloca_vett_pointer(rif_data);
                break;
            default:
                break;
        }
    }
    while(choice!=0);
}

struct corse** alloca_vett_pointer(struct corse **rif){
    rif = (struct corse **) malloc(n_corse*sizeof(struct corse *));
    for(int i=0;i<n_corse;i++)
        rif[i] = (struct corse *) malloc(n_corse*sizeof(struct corse));
    return rif;
}

void alloca_vett(struct corse **lc){
    char filename[LENMAX];
    printf("Inserisci il nome del file da cui vuoi estrarre i dati:\n");
    scanf("%s",filename);
    FILE *fin = fopen(filename,"r");;
    if(!fin){
        printf("Errore nome file\n");
        exit(1);
    }
    fscanf(fin,"%d",&n_corse);
    (*lc) = (struct corse*) malloc(n_corse*sizeof(struct corse));
    for(int i=0;i<n_corse;i++) {
        fscanf(fin, "%s%s%s%s%s%s%d", (*lc)[i].cod_tratta,(*lc)[i].partenza,(*lc)[i].destinazione,(*lc)[i].data,(*lc)[i].ora_part,(*lc)[i].ora_arr,&(*lc)[i].ritardo);
    }
    fclose(fin);
}

void ordina_vett_pointer_by_tratta(struct corse **rif_tratta){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse *temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(strcmp(rif_tratta[j]->cod_tratta,rif_tratta[j+1]->cod_tratta)>0){
                flag = 1;
                temp = rif_tratta[j];
                rif_tratta[j] = rif_tratta[j+1];
                rif_tratta[j+1] = temp;
            }
        }
    }
    printf("Vettore di puntatori ordinato con successo in ordine di codice di tratta\n");
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
    printf("Vettore di puntatori ordinato con successo in ordine di data\n");

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
    printf("Vettore di puntatori ordinato con successo in ordine di stazione di partenza\n");
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
    printf("Vettore di puntatori ordinato con successo in ordine di stazione di arrivo\n");
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

void ricerca_tratta_dicotomica(struct corse **rif_part) {
    char partenza[LENMAX];
    int m,k,end=0;
    printf("Inserisci la tratta da cercare: \n");
    scanf("%s", partenza);
    if(islower(partenza[0]))
        partenza[0] = partenza[0] - ('a' - 'A');
    ordina_vett_pointer_by_partenza(rif_part);
    int start_index = 0, end_index = n_corse - 1;
    while (start_index <= end_index && end==0) {
        m = start_index + (end_index - start_index) / 2;
        if (strncmp(rif_part[m]->partenza, partenza, strlen(partenza)) == 0) {
            printf("%s %s %s %s %s %s %d\n", rif_part[m]->cod_tratta, rif_part[m]->partenza, rif_part[m]->destinazione, rif_part[m]->data,rif_part[m]->ora_part, rif_part[m]->ora_arr, rif_part[m]->ritardo);
            k = m + 1;
            while(k<n_corse && strncmp(rif_part[k]->partenza, partenza, strlen(partenza)) == 0){
                printf("%s %s %s %s %s %s %d\n", rif_part[k]->cod_tratta, rif_part[k]->partenza, rif_part[k]->destinazione, rif_part[k]->data, rif_part[k]->ora_part, rif_part[k]->ora_arr, rif_part[k]->ritardo);
                k++;
            }
            k = m - 1;
            while(k>0 && strncmp(rif_part[k]->partenza, partenza, strlen(partenza)) == 0){
                printf("%s %s %s %s %s %s %d\n", rif_part[k]->cod_tratta, rif_part[k]->partenza, rif_part[k]->destinazione, rif_part[k]->data, rif_part[k]->ora_part, rif_part[k]->ora_arr, rif_part[k]->ritardo);
                k--;
            }
            end = 1;
        }
        else if (strcmp(rif_part[m]->partenza, partenza) < 0)
            start_index = m + 1;
        else
            end_index = m - 1;
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
