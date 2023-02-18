#include<stdio.h>
#include<stdlib.h>

/*
Sia data una lista concatenata L. Sia dato un intero k. Si scriva una funzione C che scambi il k-esimo nodo dalla testa
della lista con il k-esimo nodo dalla coda della lista
void swap(list L, int k);
Oltre che l'implementazione della funzione swap, si richiede anche l'esplicita definizione del tipo list e 
dei nodi usati all'interno delle liste. La lista sia un ADT di I classe. Ai fini dell'esercizio, 
non si può fare uso di funzioni di libreria. Negli scambi è lecito o scambiare i valori o scambiare i nodi
Esempio: se la lista contiene 10, 20, 30, 40, 50, 60, 70 e k=0 oppure k=6, dopo lo scambio conterrà 
70, 20, 30, 40, 50, 60, 10. Se la lista contiene 10, 20, 30, 40, 50, 60, 70 e k=2, 
dopo lo scambio conterrà 10, 20, 50, 40, 30, 60, 70. Per k > 6 lo scambio non avviene. 
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
