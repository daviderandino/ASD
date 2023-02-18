/*
 Data una lista di interi crescenti, aggiungere tutti gli interi
 consecutivi mancanti
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
void add_numbers(lista_t *l);

int main(){
    lista_t *l = Crea_Lista();
    Crea_Nodo_tail(1,l->head);
    Crea_Nodo_tail(4,l->head);
    Crea_Nodo_tail(10,l->head);
    add_numbers(l);
}

void add_numbers(lista_t *l){
    link x,p;
    for(x=l->head,p=x->next;x!=NULL;x=x->next){
        printf("%d",p->val-x->val);
    }
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