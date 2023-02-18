// Date due liste trasformare la prima lista nell'intersezione delle due iniziali
// Es: L1 = {1,7,3,5} L2 = {1,4,7}
// ---> L1 sarà {1,7}

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo *link;

struct nodo{
    int val;
    link next;
};

typedef struct lista{
    link head;
    link tail;
}lista_t;

link newNode(int n,link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(int n,link h);
void stampaLista(lista_t *l);;
link listDelTail(link h);
link listDelKey(link h,int n);
void intersection(lista_t *L1,lista_t *L2);

int main(){
    lista_t *L1 = Crea_Lista();
    lista_t *L2 = Crea_Lista();
    L1->head = Crea_Nodo_tail(1,L1->head); L1->head = Crea_Nodo_tail(7,L1->head); L1->head = Crea_Nodo_tail(3,L1->head); L1->head = Crea_Nodo_tail(5,L1->head);
    L2->head = Crea_Nodo_tail(1,L2->head); L2->head = Crea_Nodo_tail(4,L2->head); L2->head = Crea_Nodo_tail(7,L2->head);
    intersection(L1,L2);
    stampaLista(L1);
}

void intersection(lista_t *L1,lista_t *L2){
    link x,p,t;
    int found;
    for(x=L1->head;x!=NULL;){
        found = 0;
        for(p=L2->head;p!=NULL;p=p->next)
            if(x->val==p->val) found = 1;
        if(found==0){
            t = x->next;
            L1->head = listDelKey(L1->head,x->val);
            x = t;
        }
        else x=x->next;
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