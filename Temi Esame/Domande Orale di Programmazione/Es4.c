// Dato un vettore, salvare in una lista gli elementi pari e in un'altra quelli dispari, conservando l'ordine nelle liste.

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
void save(lista_t *l1,lista_t *l2,int *V,int n);

int main(){
    int V[] = {4,7,2,3,5,7,2,4,3},n=9;
    // L1 sarà 4,2,2,4; L2 sarà 7,3,5,7,3
    lista_t *L1 = Crea_Lista();
    lista_t *L2 = Crea_Lista();
    save(L1,L2,V,n);
    stampaLista(L1);
    stampaLista(L2);
}

void save(lista_t *l1,lista_t *l2,int *V,int n){
    for(int i=0;i<n;i++){
        if(V[i]%2==0) l1->head = Crea_Nodo_tail(V[i],l1->head);
        else l2->head = Crea_Nodo_tail(V[i],l2->head);
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
        printf("%d ",x->val);
    printf("\n");
}