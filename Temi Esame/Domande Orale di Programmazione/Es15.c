// Dato un vettore di interi e una lista di interi, per ogni valore appartenente al vettore, elimina il nodo avente lo stesso valore

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
void del(lista_t *L,int *v,int n);


int main(){
    lista_t *L = Crea_Lista();
    for(int i=1;i<=10;i++) L->head = Crea_Nodo_tail(i,L->head);
    int v[] = {1,3,5},n=3;
    del(L,v,n);
    stampaLista(L);
}

void del(lista_t *L,int *v,int n){
    link x,p;
    for(int i=0;i<n;i++){
        p = NULL;
        if(v[i]==L->head->val)
            L->head = L->head->next;
        for(x=L->head;x!=NULL;p=x,x=x->next){
            if(x->val==v[i]){
                p->next = x->next;
                free(x);
                break;
            }
        }
    }
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

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
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