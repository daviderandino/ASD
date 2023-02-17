/*
    Si scriva una funzione C in grado di inserire in una lista ordinata alcuni dati anagrafici di una persona, dati da una
    coppia cognome e nome, entrambe stringhe di caratteri di lunghezza massima 20. La chiave di ordinamento sia il
    cognome e, in caso di cognomi identici, il nome. La funzione, di cui il prototipo è:
    int inserisciInOrdine (lista_t *lista, char *cognome, char *nome);
    riceve una lista (tipo lista_t, corrispondente a un ADT di prima categoria), le due stringhe corrispondenti a
    cognome e nome, ritorna, come intero, un valore vero nel caso di inserimento corretto, falso nel caso di dato già
    presente. Si definiscano il tipo lista_t e il tipo per il generico dato in lista, tenendo conto che, per ogni persona,
    vanno generati per la lista duplicati allocati dinamicamente (e separati) per cognome e nome. Il codice deve essere
    scritto esplicitamente, in altri termini è vietato ricorrere a funzioni di libreria.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct node *link;

struct Item{
    char nome[MAX];
    char cognome[MAX];
} typedef Item;

struct node{
    Item val;
    link next;
};

typedef struct lista_{
    link head;
}lista_t;

int inserisciInOrdine (lista_t *lista, char *cognome, char *nome);
lista_t *Crea_Lista();
link newNode(Item val,link next);
link SortListIns(link h,Item val,int *correct);
void Stampa_Lista(lista_t *l);

int main() {
    lista_t *l;
    l = Crea_Lista();
    int correct;
    correct = inserisciInOrdine(l,"Rossi","Mario");
    printf("%d\n", correct);
    correct = inserisciInOrdine(l,"Rossi","Mario");
    printf("%d\n", correct);
    Stampa_Lista(l);
}

int inserisciInOrdine(lista_t *lista, char *cognome, char *nome) {
    int correct;
    Item d;
    strcpy(d.cognome,cognome);
    strcpy(d.nome,nome);
    lista->head = SortListIns(lista->head,d,&correct);
    return correct;
}

lista_t *Crea_Lista() {
    lista_t *l = malloc(sizeof(lista_t));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    return l;
}

link newNode(Item val, link next) {
    link x = malloc(sizeof *x);
    if (x == NULL) return NULL;
    else {
        x->val = val;
        x->next = next;
    }
    return x;
}

link SortListIns(link h, Item val,int *correct) {
    link x, p;
    char key[MAX];
    strcpy(key, val.cognome);
    if (h == NULL || strcmp((h->val.cognome), key) > 0){
        *correct = 1;
        return newNode(val, h);
    }
    if(strcmp(h->val.cognome,key)==0){
        *correct = 0;
        return h;
    }
    for(x=h->next;x!=NULL;x=x->next){
        if(strcmp(x->val.cognome,key)==0) *correct = 0;
        return h;
    }

    for (x = h->next, p = h; x != NULL && strcmp((h->val.cognome), key) > 0; p = x, x = x->next);
    p->next = newNode(val, x);
    *correct = 1;
    return h;
}

void Stampa_Lista(lista_t *l){
    link x=l->head;
    while(x!=NULL){
        printf("Cognome->%s , Nome->%s\n",x->val.cognome,x->val.nome);
        x=x->next;
    }
}