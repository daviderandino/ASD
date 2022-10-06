#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXRIGHE 1000
#define LENMAX 30

struct corse{
    char cod_tratta[LENMAX],partenza[LENMAX],destinazione[LENMAX],data[LENMAX],ora_part[LENMAX],ora_arr[LENMAX];
    int ritardo,data_numerica;
};

int n_corse;

void riempi_lista(struct corse *lc);
int leggi_comando(char input[MAXRIGHE],struct corse *lc);
void stampa_partenze(char fermata[LENMAX],struct corse *lc);
void stampa_capolinea(char capolinea[LENMAX],struct corse *lc);
void stampa_ritardo_tot(char codice[LENMAX],struct corse *lc);
void stampa_intervallo_date(char data1[LENMAX],char data2[LENMAX],struct corse *lc);
void stampa_ritardo_date(char data1[LENMAX],char data2[LENMAX],struct corse *lc);
int converti_data(char data[LENMAX]);

int main(){
    struct corse lista_corse[MAXRIGHE];
    char input[LENMAX];
    riempi_lista(lista_corse);
    printf("Inserisci comando:\n");
    gets(input);
    while(strcmp(input,"fine")!=0){
        leggi_comando(input,lista_corse);
        printf("Inserisci comando:\n");
        gets(input);
    }
}

void riempi_lista(struct corse *lc){
    int data_numerica;
    FILE *fin = fopen("../corse.txt","r");;
    fscanf(fin,"%d",&n_corse);
    for(int i=0;i<n_corse;i++) {
        fscanf(fin, "%s%s%s%s%s%s%d", lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,&lc[i].ritardo);
        data_numerica = converti_data(lc[i].data);
        lc[i].data_numerica = data_numerica;
    }
    fclose(fin);
}

int leggi_comando(char input[MAXRIGHE],struct corse *lc){
    char *s = input,word[LENMAX],word2[LENMAX];
    int i,flag=0;
    while(flag==0 && sscanf(s,"%s%n",word,&i)>0){
        s+=i;
        if(strcmp(word,"partenza")==0){
            flag=1;
            sscanf(s,"%s",word);
            stampa_partenze(word,lc);
        }
        else if(strcmp(word,"capolinea")==0){
            flag=1;
            sscanf(s,"%s",word);
            stampa_capolinea(word,lc);
        }
        else if(strcmp(word,"ritardo_tot")==0){
            flag=1;
            sscanf(s,"%s",word);
            stampa_ritardo_tot(word,lc);
        }
        else if(strcmp(word,"date")==0){
            flag=1;
            sscanf(s,"%s%n",word,&i);
            s+=i;
            sscanf(s,"%s",word2);
            stampa_intervallo_date(word,word2,lc);
        }
        else if(strcmp(word,"ritardo")==0){
            flag=1;
            sscanf(s,"%s%n",word,&i);
            s+=i;
            sscanf(s,"%s",word2);
            stampa_ritardo_date(word,word2,lc);
        }
        else return 0;
    }
}

void stampa_ritardo_date(char data1[LENMAX],char data2[LENMAX],struct corse *lc){
    int data1_num = converti_data(data1),data2_num = converti_data(data2);
    for(int i=0;i<n_corse;i++){
        if(lc[i].data_numerica>=data1_num && lc[i].data_numerica<=data2_num && lc[i].ritardo>0)
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
    }
}

void stampa_intervallo_date(char data1[LENMAX],char data2[LENMAX],struct corse *lc){
    int data1_num = converti_data(data1),data2_num = converti_data(data2);
    for(int i=0;i<n_corse;i++){
        if(lc[i].data_numerica>=data1_num && lc[i].data_numerica<=data2_num)
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
    }
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
    return atoi(new_data);
}

void stampa_partenze(char fermata[LENMAX],struct corse *lc){
    for(int i=0;i<n_corse;i++){
        if(strcmp(lc[i].partenza,fermata) == 0){
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
        }
    }
}

void stampa_capolinea(char capolinea[LENMAX],struct corse *lc){
    for(int i=0;i<n_corse;i++){
        if(strcmp(lc[i].destinazione,capolinea) == 0){
            printf("%s %s %s %s %s %s %d\n",lc[i].cod_tratta,lc[i].partenza,lc[i].destinazione,lc[i].data,lc[i].ora_part,lc[i].ora_arr,lc[i].ritardo);
        }
    }
}

void stampa_ritardo_tot(char codice[LENMAX],struct corse *lc){
    int count_rit = 0;
    for(int i=0;i<n_corse;i++){
        if(strcmp(lc[i].cod_tratta,codice)==0)
            count_rit += lc[i].ritardo;
    }
    printf("Il ritardo complessivo per le corse con codice %s e' %d\n",codice,count_rit);
}