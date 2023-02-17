/*
    Sia data una lista non ordinata di interi e un valore intero inteso come soglia. Si scriva una funzione C che divida la lista in
    2 : nella prima lista compaiono gli elementi della lista originaria minori della soglia, nella seconda quelli maggiori o uguali
    alla soglia. Sia mantenuto l’ordine relativo della lista originaria nelle 2 liste così create. Si noti che NON si può far
    riferimento a funzioni di libreria sulle liste. Si usi un ADT di I categoria per le liste con una struct wrapper di tipo
    lista_t. La funzione C sia compatibile con la chiamata effettuata dal seguente frammento del main:
    lista_t *L0, *L1, *L2;
    …
    // acquisizione della lista L0
    …
    L1 = split_list(n, L0, &L2);
    La funzione riceve come parametro la lista originale L0, ritorna la prima lista L1 e, by reference, la seconda L2.
    Esempio: se la lista L0 in ingresso contiene i valori 7, 8, 25, 2, 9, -5, 10, 37 e la soglia è n=18, la prima lista L1 dovrà
    contenere 7, 8, 2, 9, -5, 10 e la seconda L2 25,37.
 */

#include<stdlib.h>
#include<stdio.h>

typedef struct nodo *link;

struct nodo{
    int val;
    link next;
};

typedef struct lista{
    link head;
}lista_t;

link newNode(int n,link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(int n,link h);
void stampaLista(lista_t *l);
lista_t *split_list(int n,lista_t *L0,lista_t **L2);

int main(){
    lista_t *L0 = Crea_Lista();
    lista_t *L1;
    lista_t *L2 = Crea_Lista();
    // 7, 8, 25, 2, 9, -5, 10, 37
    // soglia = 18
    int n=18;
    L0->head = Crea_Nodo_tail(7,L0->head); L0->head = Crea_Nodo_tail(8,L0->head); L0->head = Crea_Nodo_tail(25,L0->head);
    L0->head = Crea_Nodo_tail(2,L0->head); L0->head = Crea_Nodo_tail(9,L0->head); L0->head = Crea_Nodo_tail(-5,L0->head);
    L0->head = Crea_Nodo_tail(10,L0->head); L0->head = Crea_Nodo_tail(37,L0->head);
    // stampaLista(L0);
    L1 = split_list(n, L0, &L2);
    // L1 conterrà  7, 8, 2, 9, -5, 10
    // L2 conterrà 25,37
    stampaLista(L1);
    stampaLista(L2);
}

lista_t *split_list(int n,lista_t *L0,lista_t **L2){
    link x;
    lista_t *L1 = Crea_Lista();
    for(x=L0->head;x!=NULL;x=x->next){
        if(x->val<n) L1->head = Crea_Nodo_tail(x->val,L1->head);
        else (**L2).head = Crea_Nodo_tail(x->val,(**L2).head);
    }
    return L1;
}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link newNode(int n,link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        x->val = n;
        x->next = next;
    }
    return x;
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%d ",x->val);
    printf("\n");
}

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}