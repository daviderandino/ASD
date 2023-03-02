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
void stampaLista(lista_t *l);

int main(){
    lista_t *l = Crea_Lista();
    l->head = Crea_Nodo_tail(1,l->head);
    l->head = Crea_Nodo_tail(4,l->head);
    l->head = Crea_Nodo_tail(10,l->head);
    add_numbers(l);
    stampaLista(l);
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next){
        printf("%d ",x->val);
    }
}

void add_numbers(lista_t *l){
    link x,p;
    int a,b;
    for(x=l->head,p=NULL;x!=NULL;p=x,x=x->next){
        if(p!=NULL){
            a = p->val+1; b = x->val;
            for(int i=a;i<b;i++){
                p->next = newNode(i, x);
                p = p->next;
            }

        }
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

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}
