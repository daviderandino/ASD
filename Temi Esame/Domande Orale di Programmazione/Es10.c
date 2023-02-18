// Creare una funzione che, data una lista, restituisca una seconda lista composta di tutti e soli gli
// elementi facenti parte della progressione geometrica (primo, secondo, quarto, ottavo ecc.)

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

lista_t *crea_l2(lista_t *l);

int main(){
    lista_t *l1 = Crea_Lista(); lista_t *l2 = Crea_Lista();
    l1->head = Crea_Nodo_tail(1,l1->head); l1->head = Crea_Nodo_tail(2,l1->head); l1->head = Crea_Nodo_tail(3,l1->head);
    l1->head = Crea_Nodo_tail(4,l1->head); l1->head = Crea_Nodo_tail(5,l1->head); l1->head = Crea_Nodo_tail(6,l1->head);
    l1->head = Crea_Nodo_tail(7,l1->head); l1->head = Crea_Nodo_tail(8,l1->head); l1->head = Crea_Nodo_tail(9,l1->head);
    l2 = crea_l2(l1);
    stampaLista(l2);
}

lista_t *crea_l2(lista_t *l){
    lista_t *l2 = Crea_Lista();
    int k=1,cnt=1;
    link x;
    for(x=l->head;x!=NULL;x=x->next){
        if(cnt==k){
            l2->head = Crea_Nodo_tail(x->val,l2->head);
            k = k*2;
        }
        cnt++;
    }

    return l2;
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