#include "29_01_2018.h"

/*
    Sia data una lista di interi ordinati in ordine ascendente. Alla lista si accede mediante puntatore alla testa. Si
    scriva una funzione C che, senza usare array o liste di appoggio, completi la sequenza di interi, inserendo nella
    posizione corretta all’interno della lista tutti i numeri mancanti e visualizzi la lista così generata. La chiamata
    alla funzione può essere alternativamente:
    1. n = aggiungi(&head);
    2. n = aggiungi(head);
    dove head rappresenta la testa della lista. Si realizzi una delle 2 alternative motivando la scelta. La funzione
    ritorna come valore intero il numero di nodi aggiunti.
    Esempio: se la lista in input contiene 4, 7, 10, quella in output deve contenere 4,5,6,7,8, 9,10
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    lista_t *l;
    l = Crea_Lista(l);
    int n;
    l->head = Crea_Nodo_tail(4,l->head);
    l->head = Crea_Nodo_tail(7,l->head);
    l->head = Crea_Nodo_tail(10,l->head);

    n = aggiungi(l->head);
    printf("Elementi aggiunti: %d\n",n);
    stampaLista(l);
}

int aggiungi(link head){
    link x;
    link p=NULL;
    int cnt=0;
    for(x=head;x!=NULL;x=x->next){
        if(x->next!=NULL && x->next->val-x->val>0){
            for(int i=x->val+1;i<x->next->val;i++){
                p=newNode(i,head);
                p->next = x->next;
                x->next = p;
                cnt++;
            }
        }
    }
    return cnt;
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
        printf("%d\n",x->val);
}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}
