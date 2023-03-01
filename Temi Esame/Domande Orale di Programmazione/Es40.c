/*
Date due liste di lunghezza diversa, contare quante volte quella più piccola è contenuta in quella più grande
L1 = {1,2,3,4}
L2 = {3,7,8,1,5,1,2,3,4,3,7,1,2,3,4,5}
 --> 2
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
int countIntersez(lista_t *l1,lista_t *l2);

int main(){
    lista_t *l1 = Crea_Lista();
    lista_t *l2 = Crea_Lista();
    l1->head = Crea_Nodo_tail(1,l1->head); l1->head = Crea_Nodo_tail(2,l1->head); l1->head = Crea_Nodo_tail(3,l1->head);
    l1->head = Crea_Nodo_tail(4,l1->head);
    l2->head = Crea_Nodo_tail(3,l2->head); l2->head = Crea_Nodo_tail(7,l2->head); l2->head = Crea_Nodo_tail(8,l2->head);
    l2->head = Crea_Nodo_tail(1,l2->head); l2->head = Crea_Nodo_tail(5,l2->head); l2->head = Crea_Nodo_tail(1,l2->head);
    l2->head = Crea_Nodo_tail(2,l2->head); l2->head = Crea_Nodo_tail(3,l2->head); l2->head = Crea_Nodo_tail(4,l2->head);
    l2->head = Crea_Nodo_tail(3,l2->head); l2->head = Crea_Nodo_tail(7,l2->head); l2->head = Crea_Nodo_tail(1,l2->head);
    l2->head = Crea_Nodo_tail(2,l2->head); l2->head = Crea_Nodo_tail(3,l2->head); l2->head = Crea_Nodo_tail(4,l2->head);
    l2->head = Crea_Nodo_tail(5,l2->head);
    int k = countIntersez(l1,l2);
    printf("%d\n",k);
}
int countIntersez(lista_t *l1,lista_t *l2){
    int k=0,flag;
    link x=l2->head,t,s;
    while(x!=NULL){
        flag = 1;
        for(t=l1->head,s=x;t!=NULL;t=t->next,s=s->next){
            if(s==NULL) break;
            if(s->val!=t->val) flag = 0;
        }
        if(flag==1) k++;
        x=x->next;
    }
    return k;
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
        printf("%d ",x->val);
    printf("\n");
}
