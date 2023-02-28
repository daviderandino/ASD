// Date due liste di interi ordinate, fonderle in una lista mantenendo l’ordine

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
link listDelTail(link h);
link listDelKey(link h,int n);
lista_t *unisci_liste(lista_t *l1,lista_t *l2);
link SortListIns(link h,int val);

int main(){
    lista_t *l1 = Crea_Lista();
    lista_t *l2 = Crea_Lista();
    lista_t *l3;
    l1->head = Crea_Nodo_tail(1,l1->head); l1->head = Crea_Nodo_tail(4,l1->head); l1->head = Crea_Nodo_tail(7,l1->head);
    l2->head = Crea_Nodo_tail(2,l2->head); l2->head = Crea_Nodo_tail(3,l2->head); l2->head = Crea_Nodo_tail(5,l2->head);
    // l1 = 1,4,7
    // l2 = 2,3,5
    // l3 sarà 1,2,3,4,5,7
    l3 = unisci_liste(l1,l2);
    stampaLista(l3);
}

lista_t *unisci_liste(lista_t *l1,lista_t *l2){
    lista_t *l3 = Crea_Lista();
    // itero prima su l1 e poi su l2, ad ogni passo faccio inserimento ordinato in l3
    link x;
    for(x=l1->head;x!=NULL;x=x->next)
        l3->head = SortListIns(l3->head,x->val);
    for(x=l2->head;x!=NULL;x=x->next)
        l3->head = SortListIns(l3->head,x->val);
    return l3;
}

link SortListIns(link h,int val){
    link x,p;
    if(h==NULL || h->val>val) return newNode(val,h);
    for(x=h->next,p=h;x!=NULL&&val>x->val;p=x,x=x->next);
    p->next = newNode(val,x);
    return h;
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
