// Cancellazione ricorsiva da una lista

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
void delRecursive(lista_t *l,int n);

int main(){
    lista_t *l = Crea_Lista();
    for(int i=1;i<=10;i++) l->head = Crea_Nodo_tail(i,l->head);
    delRecursive(l,7);
    stampaLista(l);
}

void delRecursive(lista_t *l,int n){
    // elimino i nodi >=n
    int flag;
    link x,p=NULL;
    for(x=l->head;x!=NULL;p=x,x=x->next){
        flag = 0;
        if(x->val>=n){
            p->next = x->next;
            free(x);
            flag = 1;
            break;
        }
    }
    if(flag==1) delRecursive(l,n); // la chiamo di nuovo solo se nella chiamata precedente è stato cancellato un nodo, altrimenti non c'è più niente da cancellare

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