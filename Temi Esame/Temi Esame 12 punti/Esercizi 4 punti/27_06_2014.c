#include<stdlib.h>
#include<stdio.h>

/*
 Si implementi come ADT di I categoria una lista bi-linkata di interi con le seguenti 2 funzioni:
 list_insert (list_t *l, int chiave, int estremo) dove se il parametro estremo vale 0
 l’inserzione avviene in testa, se vale 1 in coda
 list_display (list_t *l, int modo) dove se il parametro modo vale 0 la visualizzazione a video è fatta
 dalla testa alla coda, se vale 1 dalla coda alla testa.
 dove
 typedef struct {nodo_t *head; nodo_t *tail; } list_t;
 mentre nodo_t è una struct la cui definizione è richiesta al candidato.
 */

// fatto ma manca l'implementazione per stampare dalla coda all'indietro, farlo aggiungendo un nodo tail e un nodo prec

typedef struct nodo_t* link;

struct nodo_t{
    link head;
    link next;
    int val;
} typedef nodo_t;

typedef struct {nodo_t *head; nodo_t *tail; } list_t;
link newNode(int n,link next);
list_t *Crea_Lista();
void list_display (list_t *l, int modo);
link Crea_Nodo_tail(int n,link h);
link Crea_Nodo_head(int n,link h);
void list_insert (list_t *l, int chiave, int estremo);


int main(){
    list_t *l;
    l = Crea_Lista();
    list_insert(l,1,0);
    list_insert(l,2,1);
    list_insert(l,3,0);
    list_display(l,0);

}

void list_insert (list_t *l, int chiave, int estremo){
    if(estremo==0) l->head = Crea_Nodo_head(chiave,l->head);
    if(estremo==1) l->head = Crea_Nodo_tail(chiave,l->head);
}

void list_display (list_t *l, int modo){
    link x,p;
    p = NULL;
    if(modo==0){
        for(x=l->head,x!=NULL;p=x;x=x->next)
            printf("%d ",x->val);
    }

}

link Crea_Nodo_tail(int n,link h){
    link x;
    if(h==NULL) return(newNode(n,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(n,NULL);
    return h;
}

link Crea_Nodo_head(int n,link h){
    h = newNode(n,h);
    return h;
}

list_t *Crea_Lista(){
    list_t *l=malloc(sizeof(list_t));
    if(l==NULL){
        return NULL;
    }
    l->head=NULL;
    return l;
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