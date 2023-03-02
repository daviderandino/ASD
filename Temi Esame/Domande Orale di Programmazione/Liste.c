#include"Liste.h"
#include<stdlib.h>
#include<stdio.h>

int main(){
    lista_t *l;
    l = Crea_Lista(l);
    l->head = Crea_Nodo_tail(1,l->head);
    l->head = listDelTail(l->head);
    stampaLista(l);
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

link listDelHead(link h){
    link t=h;
    if(h==NULL) return NULL;
    h=h->next;
    free(t);
    return h;
}

link listDelTail(link h){
    link x,p;
    if(h==NULL) return NULL;
    if(h->next==NULL){
        free(h);
        return NULL;
    }
    for(x=h,p=NULL;x->next!=NULL;p=x,x=x->next);
    p->next = NULL;
    free(x);
    return h;
}

link listDelKey(link h, int k) {
    link x, p;
    if (h == NULL)
        return NULL;
    for (x=h, p=NULL; x!=NULL; p=x, x=x->next) {
        if (x->val==k){
            if (x==h)
                h = x->next;
            else
                p->next = x->next;
            free(x);
            break;
        }
    }
    return h;
}

void inserimentoInSpecificaPos(lista_t *L){
    int k=0;
    link p,x;
    for(x=L->head,p=NULL;x!=NULL;p=x,x=x->next){
        if(k==2){
            p->next = newNode(5,x);
            break;
        }
        k++;
    }
}

link SortListIns(link h, int val) {
    link x, p;
    if (h==NULL ||h->val>val)
        return newNode(val, h);
    for (x=h->next, p=h;
         x!=NULL && val>x->val;
         p=x, x=x->next);
    p->next = newNode(val, x);
    return h;
}