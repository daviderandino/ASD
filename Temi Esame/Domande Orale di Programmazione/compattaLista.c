// Data una lista di interi con il formato "1 1 1 5 6 6 6 6 6 7 8 8 9 9 9"
// (ordinata, con possibilità di chiavi uguali consecutive)
// dopo aver definito il tipo lista, implementare la funzione (prototipo: "void f(L l)")
// che data in input la lista elimini le chiavi uguali lasciandone solo una

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
link listDelKey(link h,int n);


void f(lista_t l);

int main(){
    lista_t *l = Crea_Lista();
    for(int i=0;i<3;i++) l->head = Crea_Nodo_tail(1,l->head);
    l->head = Crea_Nodo_tail(5,l->head);
    for(int i=0;i<5;i++) l->head = Crea_Nodo_tail(6,l->head);
    l->head = Crea_Nodo_tail(7,l->head); l->head = Crea_Nodo_tail(8,l->head); l->head = Crea_Nodo_tail(8,l->head);
    for(int i=0;i<3;i++) l->head = Crea_Nodo_tail(9,l->head);
    f(*l);
    stampaLista(l);
}

void f(lista_t l){
    link x,t;
    for(x=l.head;x!=NULL;x=x->next){
        for(t=x->next;t!=NULL;t=t->next){
            if(x->val == t->val) listDelKey(l.head,x->val);
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
