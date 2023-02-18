#include<stdio.h>
#include<stdlib.h>

/*
 Date due liste ordinate con possibili duplicati, fare la merge
 L1 = 1 1 2 3 3 5 7
 L2 = 2 4 4 5 6
 L = 1 1 2 2 3 3 4 4 5 5 6 7
 */

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
link listDelHead(link h);
link listDelTail(link h);
link listDelKey(link h,int n);
lista_t *merge(lista_t *l1,lista_t *l2);
int count(lista_t *l);

int main(){
    lista_t *l1 = Crea_Lista();
    lista_t *l2 = Crea_Lista();
    lista_t *L;
    l1->head = Crea_Nodo_tail(1,l1->head); l1->head = Crea_Nodo_tail(1,l1->head);
    l1->head = Crea_Nodo_tail(2,l1->head); l1->head = Crea_Nodo_tail(3,l1->head);
    l1->head = Crea_Nodo_tail(3,l1->head); l1->head = Crea_Nodo_tail(5,l1->head);
    l1->head = Crea_Nodo_tail(7,l1->head); l1->head = Crea_Nodo_tail(8,l1->head);
    l2->head = Crea_Nodo_tail(2,l2->head); l2->head = Crea_Nodo_tail(4,l2->head);
    l2->head = Crea_Nodo_tail(4,l2->head); l2->head = Crea_Nodo_tail(5,l2->head);
    l2->head = Crea_Nodo_tail(6,l2->head);
    L = merge(l1,l2);
    stampaLista(L);
}

lista_t *merge(lista_t *l1,lista_t *l2){
    link x,p;
    link f;
    lista_t *l3 = Crea_Lista();
    int fine = 0;
    for(x=l1->head,p=l2->head;x!=NULL,p!=NULL,fine==0;){
        if(x->val<p->val){
            l3->head = Crea_Nodo_tail(x->val,l3->head);
            if(x->next!=NULL) x= x->next;
            else{
                fine = 1;
                f = p;
            }
        }
        if(x->val>p->val){
            l3->head = Crea_Nodo_tail(p->val,l3->head);
            if(p->next!=NULL) p = p->next;
            else{
                fine = 1;
                f = x;
            }
        }
        if(x->val==p->val){
            l3->head = Crea_Nodo_tail(x->val,l3->head);
            l3->head = Crea_Nodo_tail(p->val,l3->head);
            if(x->next!=NULL) x = x->next;
            else{
                fine = 1;
                f = p;
            }
            if(p->next!=NULL) p = p->next;
            else{
                fine = 1;
                f = x;
            }
        }
    }
    for(x=f;x!=NULL;x=x->next)
        l3->head = Crea_Nodo_tail(x->val,l3->head);

    return l3;


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
        printf("%d ",x->val);
    printf("\n");
}

link listDelHead(link h){
    link t=h;
    if(h==NULL) return NULL;
    h=h->next;
    free(t);
    return h;
}

link listDelTail(link h){
    link x;
    if(h==NULL) return NULL;
    for(x=h;x->next!=NULL;x=x->next);
    x->val = -1;
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