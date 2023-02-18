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

void swap(lista_t *L, int k);

int main(){
    lista_t *L = Crea_Lista();
    for(int i=10;i<=70;i+=10) L->head = Crea_Nodo_tail(i,L->head);

    swap(L,2);
    stampaLista(L);
}

void swap(lista_t *L, int k){
    int dim=0,cnt1=0,cnt2;
    link x,p;
    int t;
    for(x=L->head;x!=NULL;x=x->next) dim++;

    for(x=L->head;x!=NULL;x=x->next){
        cnt2 = 0;
        for(p=L->head;p!=NULL;p=p->next){
            if(dim-cnt2-1==k && cnt1==k){
                t = x->val;
                x->val = p->val;
                p->val = t;
            }
            cnt2++;
        }
        cnt1++;
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