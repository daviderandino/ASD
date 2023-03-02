#ifndef ORALE_LISTE_H
#define ORALE_LISTE_H

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
link Crea_Nodo_head(int n,link h);
link Crea_Nodo_tail(int n,link h);
void stampaLista(lista_t *l);
link listDelHead(link h);
link listDelTail(link h);
link listDelKey(link h,int n);
void inserimentoInSpecificaPos(lista_t *L);
link SortListIns(link h, int val);

#endif //ORALE_LISTE_H
