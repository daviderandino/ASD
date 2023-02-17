/*
    Definire una struttura dati adeguata a rappresentare una lista singola linkata di
    interi come ADT I classe, dove il tipo lista si chiami LIST. Indicare esplicitamente
    in quale modulo/file appare la definizione dei tipi proposti. Non `e ammesso l’uso
    di funzioni di libreria.
    Implementare una funzione caratterizzata dal seguente prototipo:
    void f(LIST l, int *v, int n)
    La funzione riceve una lista di interi e un vettore v di interi di n elementi. La
    funzione cancella dalla lista tutti i nodi contenenti un valore che non appare nel
    vettore v. Non `e ammesso l’uso di funzioni di libreria
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
LIST Crea_Lista();
link Crea_Nodo_tail(int n,link h);
void stampaLista(LIST l);
link listDelKey(link h,int val);

void f(LIST l, int *v, int n);

int main(){
    LIST l = Crea_Lista();
    l.head = Crea_Nodo_tail(3,l.head);
    l.head = Crea_Nodo_tail(10,l.head);
    l.head = Crea_Nodo_tail(6,l.head);
    l.head = Crea_Nodo_tail(3,l.head);
    l.head = Crea_Nodo_tail(1,l.head);
    l.head = Crea_Nodo_tail(4,l.head);
    int n=3;
    int v[] = {1,2,3};
    f(l,v,n);
    stampaLista(l);
}

void f(LIST l, int *v, int n){
    // Doppio ciclo for: itero sulla lista
    // Se l'elemento i-esimo della lista non è presente nel vettore allora va eliminato: lo inserisco nel vettore del
    link x;
    int *del = malloc(n*sizeof(int));
    int found,cnt=0;
    for(x=l.head;x!=NULL;x=x->next) {
        found = 0;
        for(int i=0;i<n;i++)
            if(x->val==v[i]) found = 1;
        if(found==0)
            del[cnt++] = x->val;
    }

    for(int i=0;i<cnt;i++) listDelKey(l.head,del[i]);
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


LIST Crea_Lista(){
    LIST *l=malloc(sizeof(LIST));
    l->head=NULL;
    return *l;
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

void stampaLista(LIST l){
    link x;
    for(x=l.head;x!=NULL;x=x->next)
        printf("%d\n",x->val);
}