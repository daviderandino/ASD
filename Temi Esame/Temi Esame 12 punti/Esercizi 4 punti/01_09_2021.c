#include<stdio.h>

/*
    Definire una struttura dati adeguata a rappresentare una lista doppio linkata di
    interi come ADT I classe, dove il tipo lista si chiami LIST. La lista definita non
    deve fare uso di sentinelle.
    Indicare esplicitamente in quale modulo/file appare la definizione dei tipi proposti.
    La struttura cos`ı definita `e quella da usare per completare la seconda domanda di
    questo esercizio. Non `e ammesso l’uso di funzioni di libreria.
    Implementare una funzione caratterizzata dal seguente prototipo:
    void purge(LIST l, int div)
    la funzione purge cancella dalla lista tutti i nodi che contengono un numero non
    divisibile per div.

    div = 3
    L = 9 ↔ 8 ↔ 7 ↔ 6 ↔ 5 ↔ 4 ↔ 3 ↔ 2 ↔ 1 ↔ 0
    L = 9 ↔ 6 ↔ 3 ↔ 0

 */

#include<stdlib.h>
#include<stdio.h>

typedef struct nodo *link;

struct nodo{
    int val;
    link next;
};

typedef struct lista{
    link head;
}LIST;

link newNode(int n,link next);
LIST *Crea_Lista();
link Crea_Nodo_tail(int n,link h);
void stampaLista(LIST *l);
link listDelKey(link h, int k);
void purge(LIST l, int div);

int main(){
    LIST *l = Crea_Lista();
    for(int i=9;i>=0;i--) l->head = Crea_Nodo_tail(i,l->head);
    stampaLista(l);
    printf("\n");
    int div=3;
    purge(*l,div);
    stampaLista(l);
}

void purge(LIST l, int div){
    link x,t;
    for(x=l.head;x!=NULL;){
        if(x->val%div!=0){
            t = x->next;
            listDelKey(l.head,x->val);
            x = t;
        }
        else x=x->next;
    }
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

void stampaLista(LIST *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%d\n",x->val);
}

LIST *Crea_Lista(){
    LIST *l=malloc(sizeof(LIST));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
}