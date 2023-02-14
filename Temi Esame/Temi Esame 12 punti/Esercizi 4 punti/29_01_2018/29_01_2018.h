#ifndef ES4PT_29_01_2018_H
#define ES4PT_29_01_2018_H

typedef struct nodo *link;

struct nodo{
    int val;
    link next;
};

typedef struct lista{
    link head;
    link tail;
}lista_t;

void stampaLista(lista_t *l);
link newNode(int n,link next);
lista_t *Crea_Lista();
link Crea_Nodo_tail(int n,link h);
link Crea_Nodo_head(int n,link h);
int aggiungi(link head);

#endif
