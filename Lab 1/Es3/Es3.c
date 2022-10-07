#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXRIGHE 1000
#define LENMAX 30

struct corse{
    char cod_tratta[LENMAX],partenza[LENMAX],destinazione[LENMAX],data[LENMAX],ora_part[LENMAX],ora_arr[LENMAX];
    int ritardo,data_numerica,ora_part_numerica,ora_arr_numerica;
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

int converti_ora(char ora[LENMAX]){
    char s[LENMAX];
    int k=0;
    for(int i=0;i< strlen(ora);i++){
        if(ora[i]!=':'){
            s[k] = ora[i];
            k++;
        }
    }
    s[k] = '\0';
    return atoi(s);
}

void ordina_vett_by_data(struct corse *lc){
    int i, j, l=0, r=n_corse-1, flag = 1;
    struct corse temp;
    for(i = l;i<r && flag==1;i++){
        flag = 0;
        for(j = l; j < r - i + l; j++){
            if(lc[j].data_numerica>lc[j+1].data_numerica){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
            else if(lc[j].data_numerica==lc[j+1].data_numerica && lc[j].ora_part_numerica>=lc[j+1].ora_part_numerica){
                flag = 1;
                temp = lc[j];
                lc[j] = lc[j+1];
                lc[j+1] = temp;
            }
        }
    }
}

void stampa_contenuti(struct corse *lc){
    int choice1,choice2;
    char *filename = "../output.txt";
    printf("Cosa vuoi stampare?\n");
    printf("1.Codici tratta\n2.Stazioni di partenza\n3.Stazioni di arrivo\n4.Date\n5.Ore di partenza\n6.Ore di arrivo\n7.Minuti di ritardo\n");
    scanf("%d",&choice1);
    printf("Dove vuoi stamparli?\n1.Video\n2.File\n");
    scanf("%d",&choice2);
    if(choice2==1){
        switch (choice1) {
            case 1:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].cod_tratta);
                break;
            case 2:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].partenza);
                break;
            case 3:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].destinazione);
                break;
            case 4:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].data);
                break;
            case 5:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].ora_part);
                break;
            case 6:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].ora_arr);
                break;
            case 7:
                for(int i=0;i<n_corse;i++)
                    printf("%s\n",lc[i].ritardo);
                break;
            default:
                break;
        }
    } else{
        FILE *fin = fopen(filename,"w");
        switch (choice1) {
            case 1:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].cod_tratta);
                break;
            case 2:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].partenza);
                break;
            case 3:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].destinazione);
                break;
            case 4:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].data);
                break;
            case 5:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].ora_part);
                break;
            case 6:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].ora_arr);
                break;
            case 7:
                for(int i=0;i<n_corse;i++)
                    fprintf(fin,"%s\n",lc[i].ritardo);
                break;
            default:
                return;
        }
        fclose(fin);
    }
}

void riempi_vett(struct corse *lc){
    int data_numerica,ora_part_numerica,ora_arr_numerica;
    FILE *fin = fopen("../corse.txt","r");;
    fscanf(fin,"%d",&n_corse);
    for(int i=0;i<n_corse;i++) {
        fscanf(fin, "%s%s%s%s%s%s%d", lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,&lc[i].ritardo);
        data_numerica = converti_data(lc[i].data);
        lc[i].data_numerica = data_numerica;
        ora_part_numerica = converti_ora(lc[i].ora_part);
        lc[i].ora_part_numerica = ora_part_numerica;
        ora_arr_numerica = converti_ora(lc[i].ora_arr);
        lc[i].ora_arr_numerica = ora_arr_numerica;
    }
    fclose(fin);
}

int converti_data(char data[LENMAX]){
    char new_data[LENMAX];
    int k=0;
    for(int i=0;i< strlen(data);i++){
        if(isdigit(data[i])){
            new_data[k] = data[i];
            k++;
        }
    }
    new_data[k] = '\0';
    return atoi(new_data);
}