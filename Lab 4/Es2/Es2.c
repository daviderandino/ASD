#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCH 50

// modificare funzione listDelByDate passando una variabile link by pointer in modo da diminuire la complessità

typedef struct{
    char codice[6],nome[MAXCH],cognome[MAXCH],data_nascita[11],via[MAXCH],citta[MAXCH];
    int cap,data_numerica;
} Item;

typedef struct node *link;

struct node{
    Item val;
    link next;
};

link newNode(Item val, link next);
void stampa_lista(link x,link head);
Item ListSearch(link h, char *cod);
void riempi_lista(char *nome_file,link *hp);
Item listDelkeyR(link *h, char *cod);
link SortListIns(link h,Item val);
link insByInput(link h);
link insByFile(link h);
Item listDelByDate(link *h,Item d,int data1_num,int data2_num);
int convertiData(char *s);

int main(){
    int choice=-1,data1_num,data2_num;
    char *nome_file = "../anagrafica.txt",cod[MAXCH],data1[11],data2[11];
    link x,y,p,head=NULL;
    Item d;
    x = malloc(sizeof(*x));
    riempi_lista(nome_file,&head);

    do{
        printf("Cosa vuoi fare?\n"
               "0.Termina\n"
               "1.Inserimento ordinato di un elemento su lista by input\n"
               "2.Inserimento ordinato di elementi su lista by file\n"
               "3.Ricerca un elemento per codice\n"
               "4.Cancella un elemento per codice\n"
               "5.Cancella un elemento per date\n"
               "6.Stampa lista su file\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                head = insByInput(head);
                break;
            case 2:
                head = insByFile(head);
                break;
            case 3:
                printf("Inserisci il codice da cercare:\n");
                scanf("%s",cod);
                d = ListSearch(head,cod);
                if(strcmp(d.codice,cod)==0)
                    printf("%s %s %s %s %s %s %d\n",d.codice,d.nome,d.cognome,d.data_nascita,d.via,d.citta,d.cap);
                else printf("Non trovato\n");
                break;
            case 4:
                printf("Inserisci il codice dell'elemento da eliminare:\n");
                scanf("%s",cod);
                d = listDelkeyR(&head,cod);
                if(strcmp(d.codice,cod)==0)
                    printf("Elemento eliminato\n%s %s %s %s %s %s %d\n",d.codice,d.nome,d.cognome,d.data_nascita,d.via,d.citta,d.cap);
                else printf("Non trovato\n");
                break;
            case 5:
                d = head->val;
                //y = head; p = NULL;
                printf("Inserisci data 1 (gg/mm/yyyy):\n"); scanf("%s",data1); printf("Inserisci data 2 (gg/mm/yyyy):\n"); scanf("%s",data2);
                data1_num = convertiData(data1); data2_num = convertiData(data2);
                while(strcmp(d.codice,"")!=0){
                    d = listDelByDate(&head,d,data1_num,data2_num);
                    if(strcmp(d.codice,"")!=0) printf("Elemento eliminato: %s %s %s %s %s %s %d\n",d.codice,d.nome,d.cognome,d.data_nascita,d.via,d.citta,d.cap);
                }
                break;
            case 6:
                stampa_lista(x,head);
                break;
            default:
                exit(0);
        }
    } while(choice!=0);
    return 0;
}

/*
Item listDelByDate(link *h,Item d,int data1_num,int data2_num,link *y,link *p){
    for(;*y!=NULL;*p=*y,*y=(*y)->next){
        if((*y)->val.data_numerica>=data1_num && (*y)->val.data_numerica<=data2_num && (*y)->val.codice!=d.codice){
            if(*y==*h) *h = (*y)->next;
            else (*p)->next = (*y)->next;
            return (*y)->val;
        }
    }
    strcpy(d.codice,"");
    return d;
} */

Item listDelByDate(link *h,Item d,int data1_num,int data2_num){
    link p,x;
    for(x=*h,p=NULL;x!=NULL;p=x,x=x->next){
        if(x->val.data_numerica>=data1_num && x->val.data_numerica<=data2_num && x->val.codice!=d.codice){
            if(x==*h) *h = x->next;
            else p->next = x->next;
            return x->val;
        }
    }
    strcpy(d.codice,""); // se non è stato trovato nulla restituisce l'Item dal codice vuoto
    return d;
}

link insByFile(link h){
    Item d;
    FILE *f2 = fopen("../anag2.txt","r");
    if(!f2){
        printf("Errore nome file\n");
        exit(1);
    }
    while(!feof(f2)){
        fscanf(f2,"%s%s%s%s%s%s%d",d.codice,d.nome,d.cognome,d.data_nascita,d.via,d.citta,&d.cap);
        d.data_numerica = convertiData(d.data_nascita);
        h = SortListIns(h,d);
    }
    fclose(f2);
    return h;
}

link insByInput(link h){
    Item d;
    printf("Inserisci codice:\n");scanf("%s",d.codice);printf("Inserisci nome:\n");scanf("%s",d.nome);
    printf("Inserisci cognome:\n");scanf("%s",d.cognome);printf("Inserisci data (gg/mm/yyyy):\n");scanf("%s",d.data_nascita);
    printf("Inserisci via:\n");scanf("%s",d.via);printf("Inserisci citta':\n");scanf("%s",d.citta);
    printf("Inserisci cap:\n");scanf("%d",&d.cap);
    d.data_numerica = convertiData(d.data_nascita);
    h = SortListIns(h,d);
    return h;
}

int convertiData(char *data){
    char s[9];
    s[0] = data[6]; s[1] = data[7]; s[2] = data[8]; s[3] = data[9]; s[4] = data[3];s[5] = data[4]; s[6] = data[0]; s[7] = data[1];
    return atol(s);
}

link newNode(Item val, link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    x->val = val;
    x->next = next;
    return x;
}

void stampa_lista(link x,link head){
    FILE *fout = fopen("../output.txt","w");
    for(x=head;x!=NULL;x=x->next){
        fprintf(fout,"%s %s %s %s %s %s %d\n",x->val.codice,x->val.nome,x->val.cognome,x->val.data_nascita,x->val.via,x->val.citta,x->val.cap);
    }
    fclose(fout);
    printf("Stampa avvenuta con successo\n");
}

Item ListSearch(link h, char *cod){
    link x;
    for(x=h;x!=NULL;x=x->next){
        if(strcmp(cod,x->val.codice)==0)
            return x->val;
    }
}

link SortListIns(link h, Item val){
    link x,p;
    if(h==NULL ||(h->val.data_numerica)>val.data_numerica)
        return newNode(val,h);
    for(x=h;x!=NULL;x=x->next){ // alloco il nuovo elemento nella lista solo se non c'è un altro elemento con lo stesso codice
        if(strcmp(val.codice,x->val.codice)==0){
            printf("Elemento di codice %s gia' presente in lista!\n",val.codice);
            return h;
        }
    }
    for(x=h->next,p=h;x!=NULL && val.data_numerica>(x->val.data_numerica); p=x, x=x->next);
        p->next = newNode(val,x);
    printf("Inserimento avvenuto con successo (codice %s)\n",val.codice);
    return h;
}

void riempi_lista(char *nome_file,link *hp){
    FILE *fin = fopen(nome_file,"r");
    Item d;
    while(!feof(fin)){
        fscanf(fin,"%s%s%s%s%s%s%d",d.codice,d.nome,d.cognome,d.data_nascita,d.via,d.citta,&d.cap);
        d.data_numerica = convertiData(d.data_nascita);
        *hp = SortListIns(*hp,d);
    }
    fclose(fin);
}

Item listDelkeyR(link *h, char *cod){
    link x,p;
    for(x=*h,p=NULL;x!=NULL;p=x,x=x->next){
        if(strcmp(cod,x->val.codice)==0){
            if(x==*h) *h = x->next;
            else p->next = x->next;
            return x->val;
        }
    }
}
