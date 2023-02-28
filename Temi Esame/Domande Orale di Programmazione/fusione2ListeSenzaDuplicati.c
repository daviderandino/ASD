/*
 Funzione che riceve due liste singolo linkate, ordinate e con possibili elementi ripetuti
 e che restituisce una nuova lista ordinata che contiene gli elementi di entrambe le liste senza duplicati.

 Esempio:
 L1 = {1,1,2,5,6,6,7}
 L2 = {1,3,3,4,7,7,8,9}
 L = {1,2,3,4,5,6,7,8,9}
 */

#include<stdio.h>
#include<stdlib.h>

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
lista_t *f(lista_t *L1, lista_t *L2);
link SortListIns(link h, int val);

int main(){
    lista_t *L1 = Crea_Lista();
    lista_t *L2 = Crea_Lista();
    L1->head = Crea_Nodo_tail(1,L1->head); L1->head = Crea_Nodo_tail(1,L1->head);  L1->head = Crea_Nodo_tail(2,L1->head);
    L1->head = Crea_Nodo_tail(5,L1->head);  L1->head = Crea_Nodo_tail(6,L1->head);  L1->head = Crea_Nodo_tail(6,L1->head);
    L1->head = Crea_Nodo_tail(7,L1->head);
    L2->head = Crea_Nodo_tail(1,L2->head); L2->head = Crea_Nodo_tail(3,L2->head);  L2->head = Crea_Nodo_tail(3,L2->head);
    L2->head = Crea_Nodo_tail(4,L2->head);  L2->head = Crea_Nodo_tail(7,L2->head);  L2->head = Crea_Nodo_tail(7,L2->head);
    L2->head = Crea_Nodo_tail(8,L2->head);  L2->head = Crea_Nodo_tail(9,L2->head);
    lista_t *L3;
    L3 = f(L1,L2);
    stampaLista(L3);
}

lista_t *f(lista_t *L1, lista_t *L2){
    lista_t *L3 = Crea_Lista();
    link x,p=NULL;
    for(x=L1->head;x!=NULL;p=x,x=x->next)
        L3->head = SortListIns(L3->head,x->val);

    for(x=L2->head;x!=NULL;p=x,x=x->next)
        L3->head = SortListIns(L3->head,x->val);

    return L3;
}

link SortListIns(link h, int val) {
    link x, p;
    if (h==NULL ||h->val>val)
        return newNode(val, h);
    for (x=h->next, p=h;
         x!=NULL && val>=x->val;
         p=x, x=x->next);
    if(p->val!=val) p->next = newNode(val, x);
    return h;
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

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%d\n",x->val);
}
