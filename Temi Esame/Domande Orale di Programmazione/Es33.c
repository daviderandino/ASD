// date due liste ordinate di stringhe, fonderle in una terza mantenendo l'ordinamento

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10
typedef struct nodo *link;

struct nodo{
    char s[MAX];
    link next;
};

typedef struct lista{
    link head;
}lista_t;

link newNode(char s[MAX],link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(char s[MAX],link h);
void stampaLista(lista_t *l);
lista_t *f(lista_t l1,lista_t l2);


int main(){
    lista_t *l1,*l2,*l3;
    l1 = Crea_Lista(); l2 = Crea_Lista();
    l1->head = Crea_Nodo_tail("a",l1->head); l1->head = Crea_Nodo_tail("b",l1->head);
    l1->head = Crea_Nodo_tail("c",l1->head); l1->head = Crea_Nodo_tail("d",l1->head);
    l2->head = Crea_Nodo_tail("e",l2->head); l2->head = Crea_Nodo_tail("f",l2->head);
    l3 = f(*l1,*l2);
    stampaLista(l3);
}

lista_t *f(lista_t l1,lista_t l2){
    lista_t *l3 = Crea_Lista();
    link x,t;
    for(x=l1.head,t=l2.head;x!=NULL&&t!=NULL;){
        if(strcmp(x->s,t->s)<0){
            l3->head = Crea_Nodo_tail(x->s,l3->head);
            x = x->next;
        }
        else if(strcmp(x->s,t->s)>0){
            l3->head = Crea_Nodo_tail(t->s,l3->head);
            t = t->next;
        }
        else if(strcmp(x->s,t->s)==0){
            l3->head = Crea_Nodo_tail(x->s,l3->head);
            l3->head = Crea_Nodo_tail(t->s,l3->head);
            x = x->next; t = t->next;
        }
    }

    if(x!=NULL){
        for(;x!=NULL;x=x->next)
            l3->head = Crea_Nodo_tail(x->s,l3->head);
    }
    if(t!=NULL){
        for(;t!=NULL;t=t->next)
            l3->head = Crea_Nodo_tail(t->s,l3->head);
    }

    return l3;

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

link Crea_Nodo_tail(char s[MAX],link h){
    link x;
    if(h==NULL) return(newNode(s,NULL));
    for(x=h;x->next!=NULL;x=x->next);
    x->next = newNode(s,NULL);
    return h;
}

link newNode(char s[MAX],link next){
    link x = malloc(sizeof *x);
    if(x==NULL) return NULL;
    else{
        strcpy(x->s,s);
        x->next = next;
    }
    return x;
}

void stampaLista(lista_t *l){
    link x;
    for(x=l->head;x!=NULL;x=x->next)
        printf("%s\n",x->s);
}