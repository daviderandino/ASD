// Data una lista, caricarla al contrario su un'altra lista
// Esempio: L1 = 1,2,3,4,5 , L2 sarà 5,4,3,2,1

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
link Crea_Nodo_head(int n,link h);
link Crea_Nodo_tail(int n,link h);
void stampaLista(lista_t *l);
lista_t *inverti(lista_t *l2);

int main(){
    lista_t *l1 = Crea_Lista();
    lista_t *l2;
    for(int i=1;i<=5;i++) l1->head = Crea_Nodo_tail(i,l1->head);
    l2 = inverti(l1);
    stampaLista(l2);
}

lista_t *inverti(lista_t *l1){
    lista_t *l2 = Crea_Lista();
    link x;
    for(x=l1->head;x!=NULL;x=x->next)
        l2->head = Crea_Nodo_head(x->val,l2->head);
    return l2;
}

lista_t *Crea_Lista(){
    lista_t *l=malloc(sizeof(lista_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}

link Crea_Nodo_head(int n,link h){
    h = newNode(n,h);
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

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%d\n",x->val);
}